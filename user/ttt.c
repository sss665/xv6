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
    int fd = open("f", O_WRONLY | O_CREATE);
    close(fd);
    return 0;

}