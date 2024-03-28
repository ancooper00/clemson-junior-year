/*
Names: Ashlyn Cooper and Dawson Imhoff
CPSC 3220 HW1
*/

//routine will calculate the perimeter using num1 and num2
//prints its own pid, parent id, and result
//exits
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

  //calculate perimeter
  int perimeter = (2 * num1) + (2 * num2);

  //get process ids
  pid_t parent = getppid();
  pid_t current = getpid();

  //print result
  printf("Child2: pid %d, ppid %d, perimeter is %d\n\n", current, parent, perimeter);
}
