#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int g(int x) {
  return x+3;
}

int f(int x) {
  return g(x);
}

void main(void) {
  int a0;
  write(1,"#",3);
  asm volatile("mv %0, a0" : "=r" (a0) );
  printf("%d\n",a0);
  exit(0);
}
