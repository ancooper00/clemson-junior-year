#include <stdio.h>
#include <stdlib.h>

struct task{
  int
  task_id    /* alphabetic tid can be obtained as 'A'+(task_counter++) */
    arrival_time,
    service_time,
    remaining_time,
    completion_time,
    response_time,
    wait_time;
  struct task *next;
};

//needed helper functions
/*
//FIFO schedule
void fifo(task* head, *fp out){
  //print out top of simulation
  printf("FIFO scheduling results\n\n");
  //call to printing helper function

  task* current = head;
  int cycleTime = 0;
  //for each cycle, go through linked list
  while(current != null){
    //stay with current task, check if a new task has arrived at current time

    //if new task has arrived at current time, put it in waiting.
    //if new task has not yet arrived continue with previous task.
    //when task has completed, move on to next task
  }


}
*/
//SJF schedule

//RR schedule

//result printing function

int main(void){

  //read command line arguments
  //first argument is scheduling policy, 2nd is input file, 3rd is output file
  //read arguments until user enters correct amount (prompt when incorrect)
  if(argc != 4){
    printf("Incorrect number of command line arguments entered. Please try again. \n");
    return 0;
  }

  char* policy[6] = argv[1];
  char* input = argv[2];
  char* output = argv[3];

  //READ OUTPUT FILE
  //make linked list as reading
  struct task* head = NULL;
  head = (struct task*)malloc(sizeof(struct tast));
  struct task* current = head;

  //set task counter
  int taskCount = 0;

  //open input file
  FILE *inf = fopen(input, "r");

  //read until end of file
  while(!EOF){
      //read and initialize node values
      int atime = getc(inf);
      int stime = getc(inf);

      current->arrival_time = atime;
      current->service_time = stime;
      //assign node a task id based on ascii
      current->task_id = 'A'+ taskCount;
      //initialize values to 0 as no action has been taken yet
      current->remaining_time = stime;
      current->completion_time = 0;
      current->response_time = 0;
      current->wait_time = 0;

      //move to next node
      struct task* next = NULL;
      next = (struct task*)malloc(sizeof(struct tast));
      current->next = next;
      current = next;

      taskCount++;
  }

  //switch statement to go to correct type of scheduling policy
  switch(policy){
    case "-fifo":
      //call to fifo function
      break;
    case "-sjf":
      //call to sjf function
      break;
    case "-rr":
      //call to round robin function
      break;
    default:
      break;
  }









  return 0;
}
