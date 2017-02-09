#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
// #define TIMEMODIFIER 100000000L
#define TIMEMODIFIER 1000000L
#define TIMEUPPERBOUND 999999999


int main(int argc, char *argv[])
{
  while (--argc > 1 && !fork());
  // sleep(argc = atoi(argv[argc]));
  struct timespec timer1, timer2;
  long num = atol(argv[argc]);
  long multNum = (num*TIMEMODIFIER);
  timer1.tv_sec = multNum/TIMEUPPERBOUND;
  timer1.tv_nsec = (multNum%TIMEUPPERBOUND);
  nanosleep(&timer1, &timer2);
  printf("%ld\n", num);
  // printf("%d\n", argc);
  wait(0);
  return 0;
}
