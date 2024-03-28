/*
Names: Ashlyn Cooper and Dawson Imhoff
CPSC 3220 HW1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define NUM_THREADS   2

//struct that stores data input by the user
typedef struct userInput{
  int num1;
  int num2;
  char message[100];
}input;

//function that is called by one thread to calculate the ratio of the inputs
void* thread_ratio_function(void *userData){
  input *my_userData = (input*)userData;
  //make a pointer to ratio so we can return it to main
  double *ratio;
  *ratio = ((double)((*my_userData).num1) / ((*my_userData).num2));

  //get thread id
  pthread_t self_id =  pthread_self();
  //print thread results
  printf("Thread 1: tid is %ld, ratio is %0.2f\n", (long)self_id, *ratio);

  pthread_exit(ratio);

}

//function thread uses to reverse message
void* thread_message_reverse(void *userData){
  input *my_userData = (input*)userData;
  //dynamically allocate memory for message
  char *my_message;
  my_message = (char*)malloc(sizeof(char));

  int temp;
  pthread_t self_id =  pthread_self();
  strcpy(my_message, (*my_userData).message);

  //reverse the string
  int len = strlen(my_message); // use strlen() to get the length of str string

    // use for loop to iterate the string
    for (int i = 0; i < len/2; i++)
    {
        // temp variable use to temporary hold the string
        temp = my_message[i];
        my_message[i] = my_message[len - i - 1];
        my_message[len - i - 1] = temp;
    }

  //print results
  printf("Thread 2: tid is %ld, message is \"%s\"\n\n", (long)self_id, my_message);

  pthread_exit(my_message);

}

int main(int argc, char * argv[]){

  //check command line argument
  if(argc != 4){
    printf("Error: incorrect number of command line arguments. Exiting program.\n");
    exit(0);
  }

  //initialize struct with user input
  input *userData;
  userData = malloc(sizeof(input));
  (*userData).num1 = atoi(argv[1]);
  (*userData).num2 = atoi(argv[2]);
  strcpy((*userData).message, argv[3]);

  //pointers for later so parent process can print results
  double *ratio;
  char *message;
  message = (char*)malloc(sizeof(char));

  //call fork system call to create first 2 processes
  int pid = fork();

  if (pid == 0) {
     // child process executing area process
      execl("./area", "area", argv[1], argv[2], NULL);
  }
  else {
    wait(NULL);
    // create second child process
    int pid2 = fork();

    if(pid2 == 0) {
      //print results of perimeter child process
      execl("./perimeter", "perimeter", argv[1], argv[2], NULL);
    }

    //wait for child processes to finish
    wait(NULL);

    //create 2 threads from parent
    int ret;
    pthread_t threads[NUM_THREADS];

    //make the two threads
    ret = pthread_create(&threads[0], NULL, &thread_ratio_function, (void*) userData);
    //wait until first thread finishes
    sleep(1);
    ret = pthread_create (&threads[1], NULL, &thread_message_reverse, (void*) userData);

    //get results from thread calculations
    pthread_join(threads[0], (void*)&ratio);
    pthread_join(threads[1], (void*)&message);

  }
  //print out parent process information
  pid_t parentID = getpid();
  printf("Parent: pid %d, ratio: %0.2f, message: \"%s\"\n\n", parentID, *ratio, message);

  //free dynamically allocated data
  free(userData);
  free(message);

  return 0;
}
