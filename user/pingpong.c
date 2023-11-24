#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2];
  pipe(p);
  char buff = '1';
  if(fork()==0){

    int n;
    int pid;
    n = read(p[0],&buff,1);
    if(n==1){
        pid = getpid();
        printf("%d: received ping\n",pid);
        write(p[1],&buff,1);
    }
  }
  else{
    int m;
    int pid;
    write(p[1],&buff,1);
    wait(0);
    m = read(p[0],&buff,1);
    if(m==1){
        pid = getpid();
        printf("%d: received pong\n",pid);
    }
  }
  exit(0);
}
