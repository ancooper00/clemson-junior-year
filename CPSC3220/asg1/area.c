/*
Names: Ashlyn Cooper and Dawson Imhoff
CPSC 3220 HW1
*/

//routine will calculate the sqaure area
//multiply num1 and num2
//print its own pid, its parent pid, and calculation result
//exit

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
  //arg 0 and arg 1 are the paths to the executable
  //arg 2 and 3 are the numbers to calculate
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);

  //calculate areas
  int area = num1 * num2;

  //get process ids
  pid_t parent = getppid();
  pid_t current = getpid();

  //print results
  printf("Child1: pid %d, ppid %d, area is %d\n", current, parent, area);
}
