/**************************
*Ashlyn Cooper *
*CPSC 2310 Fall 21 *
*UserName: ancoope*
*Instructor: Dr. Yvon Feaster
/*************************/

#include "functions.h"

int main(int argc, char *argv[]){

    //check files are opened correctly

  //check command line arguments
  checkArgs(argc);

  //open input and output files
  //names given from command line
  FILE* input = fopen(argv[1], "r");
  checkFile(input);
  FILE* output = fopen(argv[2], "w");
  checkFile(output);

  //call function create list
  node_t* list = (node_t*)malloc(sizeof(node_t));
  node_t* head = NULL;
  list = createList(input, head);

  //all using a function pointer:
    //call to printList
    //call to printName
    //call to printBDay
    //call to printSong
    //call to printPastime

  //call delete list
  deleteList(list);


  return 0;

}
