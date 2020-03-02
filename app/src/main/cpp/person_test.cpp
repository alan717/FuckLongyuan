#include <iostream>
#include "person.pb.h"
//#include "msg.pb.h"
#include <fstream>

int main(){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::cout<<"test protobuf"<<std::endl;
    tutorial::Person person;
    person.set_id(23);
    person.set_email("alikai812@qq.com");
    person.set_name("tonki");
    std::ofstream ofs("person.data", std::ios_base::out | std::ios_base::binary);
    person.SerializeToOstream(&ofs);
//    std::ifstream ifs("",std::ios_base::);

    {
        // Read the existing address book.
        std::ifstream input("person.data", std::ios::in | std::ios::binary);
        tutorial::Person ps;
        if (!ps.ParseFromIstream(&input)) {
            std::cerr << "Failedto parse address book." << std::endl;
            return -1;
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}