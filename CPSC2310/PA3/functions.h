/**************************
*Ashlyn Cooper *
*CPSC 2310 Fall 21 *
*UserName: ancoope*
*Instructor: Dr. Yvon Feaster
/*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct birthday_t{
  int m;
  int d;
  int y;
  char month[50];
} birthday_t;

typedef struct node_t{
  node_t* next;

  char fName[50];
  char lName[50];
  char favSong[50];
  char pastime[50];
  birthday_t bDay;
}node_t;



/* Parameters: node - node_t pointer holding data for a person
*              head- node_t pointer representing front of list
* Return: void
* This function adds a node to the linked list
*/
void add(node_t* node, node_t* head);

/* Parameters: input - file pointer representing the input file
*
* Return: node_t pointer - returns a node representing one person's info
* This function reads data from the input file. Allocates memory for the node
* that will be added to the linked list. The function also checks the validity
* of the birthday.
*/
node_t* readNodeInfo(FILE* input);

/* Parameters:
*
* Return:
*
*/
node_t* createList(FILE* input, node_t* head);

/* Parameters:
*
* Return:
*
*/
//void printList(FILE* output, node_t* list);

/* Parameters:
*
* Return:
*
*/
void printName(FILE* output, node_t* list);

/* Parameters:
*
* Return:
*
*/
//void printBDay(FILE* output,node_t*);

/* Parameters:
*
* Return:
*
*/
void printSong(FILE* o, node_t* l);

/* Parameters:
*
* Return:
*
*/
void printPastime(FILE* o, node_t* l);

/* Parameters:
*
* Return:
*
*/
void printBorder(FILE* output);

/* Parameters:
*
* Return:
*
*/
//void print(void (*fp)(FILE*,node_t*),FILE*, node_t*);

/* Parameters:
*
* Return:
*
*/
void checkArgs(int args);

/* Parameters:
*
* Return:
*
*/
void checkFile(FILE* fp);

/* Parameters:
*
* Return:
*
*/
void deleteList(node_t** );

/* Parameters:
*
* Return:
*
*/
bool checkDate(bday_t bDay);

/* Parameters:
*
* Return:
*
*/
bool isLeapYear(int y);

#endif
