#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void
main(int argc, char *argv[])
{
  if(argc!=2){
    write(2, "error\n", strlen("error\n"));
    exit(1);
  }
  else{
    sleep(atoi(argv[1]));
  }
  exit(0);
}
