#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    string test("source code");
    string test1;
    int b;
    test1="source code1";
    test1="source code2";
    string test2(4,'SSS');
    string test3("12345",1,3);
    string test4();
    test1.append("123");
    b = test1.compare(test2);

    test1.swap(test2);
    string tmp=test1.substr(2,4);



    return 0;
}