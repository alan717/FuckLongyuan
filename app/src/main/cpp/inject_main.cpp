#include <cstdio>
#include <cstdlib>

#include "inject.h"

int main(int argc,char **argv){
#ifdef DEBUG

#endif

    printf("inject tool");
    if(argc <3)
    {
        printf("[-]./inject pid lib.so\n");
        exit(1);
    }
    pid_t pid =atoi(argv[1]);
    char *library=argv[2];
    printf("[*] %d,%s",pid,library);
    if(injectlib_entry(pid,library)==0)
    {

        printf("[+]inject ok!\n"
               "see log!\n");
        exit(0);
    }else
    {
        printf("[-]inject faild!");
        exit(1);
    }

}