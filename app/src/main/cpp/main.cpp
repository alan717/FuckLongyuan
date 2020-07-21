#include <iostream>
//#include "person.pb.h"
#include "msg.pb.h"
#include <fstream>






void gb()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    char buf[1024] = {'\0'};
    int buf_len = 0;
    msg_t msg1;
    msg1.set_id(1001);

    // *) serialize phrase => object to byte array
    msg1.SerializeToArray(buf, sizeof(buf));
    buf_len = msg1.ByteSize();
    msg_t msg2;
    // *) deserialize phrase => byte array to object
    msg2.ParseFromArray(buf, buf_len);
    assert(msg1.id() == msg2.id());
}
int main(){
gb();
    return 0;
}