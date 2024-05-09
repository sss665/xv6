#include "kernel/param.h"
#include "kernel/fcntl.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/riscv.h"
#include "kernel/fs.h"
#include "user/user.h"



int
main(int argc, char *argv[])
{
    char *p = sbrk(1);
    printf("h%p\n",p);
    *p = 'a';
    char *q = p+4095;
    printf("h%p\n",q);
    *q ='b';
    char a = 'a';
    printf("z%p",&a);
    return 0;
}