#include <stdlib.h>
#include <stdio.h>

//swap for selection sort
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
//selection sort function
void sort(int array[], int n){
  int min_index;
  //go through the array moving the boundary in each iteration
  for(int i = 0; i < n - 1; i++){
    //find the minimum element in the unsorted array
    min_index = i;
    for(int j = i+1; j < n; j++){
      if(array[j] < array[min_index]){
        min_index = j;
      }
    }
    //swap the found min element with the first element in the array
    swap(&array[min_index], &array[i]);
  }
}

//helper function to find the max of two elements
int max(int a, int b){
  return (a > b) ? a : b;
}

int main(void) {
/* Assume the indices of the array are from 0 to N - 1.
Define DP[i] to be the length of the LIS which is ending at array element with index i.
To compute DP[i] we look at all indices j < i and check both if DP[j] + 1 > DP[i] and
array[j] < array[i] (we want it to be increasing).
If this is true we can update the current optimum for DP[i].
To find the global optimum for the array, take the maximum value from DP[0...N - 1]. */

/*We can use that idea of a longest common subsequence as a method to extract the LIS.
If we can create an array that is a sorted version of our original sequence of numbers, it
follows that the lis of our array must be present as a subsequence of the sorted array.
*/

//inorder to make our sorted array, we will perform a selection sort
//to do this sort we will use the functions created above main

int array[] = {2, 6, -1, -3, 4, -7, 8, 9};
int N = sizeof(array)/sizeof(int); //length of the string
//copy original array into 2 new arrays that we can manipulate
int sorted[N];
int original[N];

for(int i = 0; i < N; i++){
  sorted[i] = array[i];
  original[i] = array[i];
}
//make a sorted array using our sort function
sort(sorted, N);
//int DP[N];

int LCS[N+1][N+1]; //create a 2d array to help find length of LCS of sorted and unsorted strings

//build the 2-d array in bottom up fashion
int i,j;
for(i = 0; i <= N; i++){
  for(j = 0; j <= N; j++){
    //if we are at the first element
    if((i == 0) || (j == 0)){
      LCS[i][j] = 0;
    }
    //compare elements of the two strings
    else if(sorted[i-1] == original[j-1]){
      //increment length if they are the same
      LCS[i][j] = LCS[i-1][j-1] + 1;
    }
    else{
      LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
    }
  }
}

//bottom right corner of 2d array is max length
printf("Length of LIS is %d\n", LCS[N][N]);
//Write the code to extract the LIS; you may need to augment the given program as you see fit.

int index = LCS[N][N];

//create an array to store the LIS string
int lis[index+1];

//start at the bottom right corner of LCS 2d array and store characters in lis array one by one
i = N;
j = N;
while ((i>0) && (j>0)){
  //if the current character in both strings are the same
  //current is part of LIS
  if(sorted[i - 1] == original[j-1]){
    //current character goes in array
    lis[index-1] = sorted[i-1];
    //reduce our values
    i--;
    j--;
    index--;
  }
  //if not same go in direction that has the larger of two values
  else if(LCS[i-1][j] > LCS[i][j-1]){
    i--;
  }
  else{
    j--;
  }
}

printf("LIS is ");
for(int k = 0; k < LCS[N][N]; k++){
  printf("%d ", lis[k]);
}
printf("\n");

return 0;
}
