export build_dir=`pwd`/../libprotobuf/android
export sysroot=`pwd`/../arm-24-toolchain-clang-32/sysroot
export PATH=`pwd`/../arm-24-toolchain-clang-32/bin:$PATH
export CC="arm-linux-androideabi-clang --sysroot $sysroot"
export CXX="arm-linux-androideabi-clang++ --sysroot $sysroot"

./configure \
--host=arm-linux-androideabi \
--with-protoc=/home/tonki/mysoft/bin/protoc \
--with-sysroot="$sysroot" \
--disable-shared \
--prefix="$build_dir/armeabi-v7a" \
--enable-cross-compile \
CFLAGS="-march=armv7-a -D__ANDROID_API__=24" \
CXXFLAGS="-frtti -fexceptions -march=armv7-a -D__ANDROID_API__=24" \
LIBS="-llog -lz -lc++_static"

make -j2
make install
