#include <iostream>
//#include "person.pb.h"
#include "mg.pb.h"
#include <unistd.h>

 #include <fcntl.h>


//#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <libprotobuf/android/armeabi-v7a/include/google/protobuf/io/zero_copy_stream_impl.h>


using namespace google::protobuf::io;
void gb()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    char buf[1024] = {'\0'};
    int buf_len = 0;
    MAGIC_CODE msg;
    msg.set_key(7890);
    msg.set_macaddress(123456);
    msg.set_serilnumber(7890);
    msg.set_mgaction(MAGIC_CODE_MagicCodeAction_VERIFYMAGICCODE);
//    msg.SerializeWithCachedSizes();
    int fd = open("myfile", O_WRONLY|O_CREAT,0600);
    if(fd<0){
        printf("fd error\n");
        return;
    }
    google::protobuf::io::ZeroCopyOutputStream* raw_output = new OstreamOutputStream(fd);

    auto* coded_output = new CodedOutputStream(raw_output);
    msg.SerializeWithCachedSizes(coded_output);


    MAGIC_CODE rev;






}
int main(){
    gb();
    return 0;
}