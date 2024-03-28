/**************************
*Ashlyn Cooper *
*CPSC 2310 Fall 21 *
*UserName: ancoope*
*Instructor: Dr. Yvon Feaster
/*************************/

#include "functions.h"


void add(node_t* node, node_t* head){

    //check for first insertion of node
    if(head->next == NULL){
      head->next = node;
    }
    //if not beginning list
    //loop thorugh list to find end node and add there
    else{
      //create a current node
      node_t *current = head;

      while(current->next != NULL){
        //if at the end, add node
        if(current->next == NULL){
          current->next = newNode
        }
        //move current to next node
        current = current->next;
      }
    }

}

node_t* readNodeInfo(FILE* input){
  //create new node representing a new person
  node_t* newPerson = (node_t*)malloc(sizeof(node_t));

  //for each scanset conversion, scan until ","
  //scan in last name
  scanf("%[^,]s", newPerson->lName);
  //scan in first name
  scanf("%[^,]s", newPerson->fName);
  //scan in birthday
  scanf("%[^,]d", newPerson->bDay->m);
  scanf("%[^,]d", newPerson->bDay->d);
  scanf("%[^,]d", newPerson->bDay->y);
  //scan in favorite song
  scanf("%[^,]s", newPerson->favSong);
  //scan in hobby
  scanf("%[^\n]s", newPerson->pastime);

  //set month string based on month digit
  int month = newPerson.bDay.m
  switch(month){
    case 1:
      newPerson.bDay.month = "January";
      break;
    case 2:
      newPerson.bDay.month = "February";
      break;
    case 3:
      newPerson.bDay.month = "March";
      break;
    case 4:
      newPerson.bDay.month = "April";
      break;
    case 5:
      newPerson.bDay.month = "May";
      break;
    case 6:
      newPerson.bDay.month = "June";
      break;
    case 7:
      newPerson.bDay.month = "July";
      break;
    case 8:
      newPerson.bDay.month = "August";
      break;
    case 9:
      newPerson.bDay.month = "September";
      break;
    case 10:
      newPerson.bDay.month = "October";
      break;
    case 11:
      newPerson.bDay.month = "November";
      break;
    case 12:
      newPerson.bDay.month = "December";
      break;
    default:
      break;
  }

  //return node representing person
  return newPerson;
}

node_t* createList(FILE* input, node_t* head){

  //while loop
  while(!feof(input)){
    //read each line of the file
    node_t* newNode = readNodeInfo(input);
    //check birthday
    bool validDate = checkDate(newNode.bDay);
    //add to list
    if(validDate){
      add(newNode, head);
    }
  }

  //return head of list
  return head;

}

//void printList(FILE* output, node_t* list);

void printName(FILE* output,node_t* list){
  //check if list is empty, if so print error
  if(list == NULL){
    fprintf(stderr, "Error: List is empty\n");
    exit(1);
  }
  //if list is not empty
  else{
    //print the border
    printBorder(output);
    //print header for list
    fprintf(output, "NAMES:\n");

    //print all names until reaching end of list
    while(list != NULL){
      fprintf(output, "%s, %s\n", list->lName, list->fName);

      //move to next item in list
      list = list->next;
    }

    //print the border
    printBorder(output);
  }
}

//void printBDay(FILE* output ,node_t *);

void printSong(FILE* o,node_t * l){
  //check if list is empty, if so print error
  if(l == NULL){
    fprintf(stderr, "Error: List is empty\n");
    exit(1);
  }
  //if list is not empty
  else{
    //print the border
    printBorder(o);

    //print all names and songs until reaching end of list
    while(l != NULL){
      fprintf(o,"%s %s's favorite song is %s.\n",l->fName,l->lName,l->favSong);

      //move to next item in list
      l = l->next;
    }

    //print the border
    printBorder(o);
  }
}

void printPastime(FILE* o,node_t * l){
  //check if list is empty, if so print error
  if(l == NULL){
    fprintf(stderr, "Error: List is empty\n");
    exit(1);
  }
  //if list is not empty
  else{
    //print the border
    printBorder(o);

    //print all names until reaching end of list
    while(list != NULL){
      fprintf(o,"%s %s's favorite pastime is %s.\n",l->fName,l->lName,l->pastime);

      //move to next item in list
      l = l->next;
    }

    //print the border
    printBorder(o);
  }
}

void printBorder(FILE* output){
  //print a line of 80 '*'
  for(int i = 0; i < 80; i++{
    fprintf(output, "*");
  }
  //print the new line character
  fprintf(output, "\n");
}

//void print(void (*fp)(FILE*,node_t*),FILE*, node_t*);

void checkArgs(int args){
  if(args > 2){
    fprintf(stderr, "Too many command line arguments \n");
    exit(1);
  }
  else{
    return;
  }
}

void checkFile(FILE* fp){
  if(fp == NULL){
    fprintf(stderr, "Problem opening file, exiting program.\n");
    exit(1);
  }
  return;
}

void deleteList(node_t* head){
  node_t* temp;

  while(head != NULL){
    temp = head;
    head = head->next;
    free(temp);
  }
}

bool checkDate(bday_t bDay){
  //check year bounds
  if((bDay.y < 1900) || (bDay.y > 2020)){
    return false;
  }
  //check month bounds
  else if ((bDay.m < 1) || (bDay.m > 12)){
    return false;
  }
  //check date based on month
  //April, June, September, and November have 30 days
  if((bDay.m==4)||(bDay.m==6)||(bDay.m==9)||(bDay.m==11){
    if((bDay.d <= 30) && (bDay.d >= 1)){
      return true;
    }
    else return false;
  }
  //check february
  else if(bDay.m == 2){
    if(isLeapYear(bDay.y)){
      if((bDay.d <= 29) && (bDay.d >=1)){
        return true;
      }
      else return false;
    }
    else{
      if((bDay.d <= 28) && (bDay.d >=1)){
        return true;
      }
      else return false;
    }
  }
  //check remaining months with 31 days
  else{
    if((bDay.d <= 31) && (bDay.d >=1)){
      return true;
    }
    else return false;
  }
}

bool isLeapYear(int y){
  //is year divisible by 4
  if((y % 4) == 0){

    //is year divisible by 100
    if((y % 100) == 0){
      //if divisible by 100, also divisible by 400?
      if( (y % 400) == 0){
        return true;
      }
      else{
        return false;
      }

    }

    return true;
  }
  else return false;

}
