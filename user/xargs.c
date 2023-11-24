#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"


int
main(int argc, char *argv[])
{
    char *arg[MAXARG]; 
    char a[32];
    for(int i=0;i<argc-1;i++){
        arg[i] = argv[i+1];
    }
    int i = 0;
    while(read(0,&a[i],1)){
        if(a[i]=='\n'){
            a[i] = 0;
            arg[argc-1] = a;
            if(fork()==0){
                exec(arg[0],arg);
            }
            else{
                wait(0);
            }
            i=-1;
        }
        i++;
    }
    exit(0);
}