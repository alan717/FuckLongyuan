cmake_minimum_required(VERSION 3.3)
project(Anti-debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# the version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

find_library( # Defines the name of the path variable that stores the
              # location of the NDK library.
              log-lib

              # Specifies the name of the NDK library that
              # CMake needs to locate.
              log )
include_directories(${PROJECT_SOURCE_DIR}/)
add_library(${PROJECT_NAME} android-anti-debug.cpp)
target_link_libraries(${PROJECT_NAME} ${log-lib} )

#===================== testpb
if("${ANDROID_ABI}" STREQUAL "armeabi-v7a")
  message(STATUS "BUILD testpb only for armeabi-v7a")
  add_library(libprotobuf STATIC IMPORTED)
  set_target_properties(libprotobuf PROPERTIES IMPORTED_LOCATION
          ${CMAKE_SOURCE_DIR}/libprotobuf/android/${ANDROID_ABI}/lib/libprotobuf-lite.a)
  include_directories(${CMAKE_SOURCE_DIR}/libprotobuf/android/include)
  add_executable(testpb main.cpp msg.pb.cc)
  #target_link_libraries(testpb ${CMAKE_SOURCE_DIR}/libprotobuf/android/lib/${ANDROID_ABI}/libprotobuf-lite.a)
  target_include_directories(testpb PRIVATE
        ${CMAKE_SOURCE_DIR}/libprotobuf/android/armeabi-v7a/include)
  target_link_libraries(testpb  PRIVATE libprotobuf log)
  else()
  message(STATUS "NOT BUILD :${ANDROID_ABI}")
endif()
#====================== myinject

add_executable(myinject inject_main.cpp inject.cpp)
target_include_directories(myinject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/)
target_link_libraries(myinject log)
#====================== libhook
if(NOT "${ANDROID_ABI}" STREQUAL "SSS")
  message(STATUS "HOOK LIB MAIN CONTENT")
  add_library(hook hook.cpp)
else()
  message(STATUS "HOOK LIB ELSE CONNTENT")
endif()
