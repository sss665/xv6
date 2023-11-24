#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int p[2];
    pipe(p);
    for(int i=2;i<=35;i++){
        write(p[1],&i,4);
    }
    close(p[1]);
    while(1){
            int j;
            int m;
            int n=0;
            int num[35];
            read(p[0],&j,4);
            printf("prime %d\n",j);
            while(read(p[0],&m,4)!=0){
                if(m%j!=0){
                    num[n] = m;
                    n++;
                }
            }
            close(p[0]);
            if(n==0){
                break;
            }
            pipe(p);
            for(int i=0;i<n;i++){
                write(p[1],&num[i],4);
            }
            close(p[1]);
            if(fork()==0){
                continue;
            }
            wait(0);
            break;
    }
    exit(0);
    
}
