#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max (int a, int b){
  if (a > b) return a;
  else return b;
}

int lcs_length (char *A, char *B){
  // Need a 2-D int array L,
  int i, j;
  int m = strlen(A), n = strlen(B);

  //modifed original code to use a different implementation of the 2d array for ease of access
  int L[m+1][n+1]; //create 2d array

  for (i=0;i<= m; i++){
    for (j=0; j<= n;j++){
      if (i == 0 || j == 0){
        L[i][j] = 0;
      }
      else if (A[i-1]==B[j-1]){
        L[i][j]= 1+L[i-1][j-1];
      }
      else {
        L[i][j]= max(L[i-1][j],L[i][j-1]);
      }
    }
  }

// Write the code to navigate the array L to
//print the LCS and to return the length of the LCS
  int index = L[m][n];
  //create our lcs string
  char lcs_string[index+1];
  lcs_string[index] = '\0';

  //start from the bottom right corner and store characters in lcs one by one
  i = m; j = n;
  while((i > 0) && (j > 0)){
    //if current character in both strings are the same, part of lcs
    if(A[i-1] == B[j-1]){
      lcs_string[index-1] = A[i-1]; //puts character in the string
      //decrement indices for the 2d array and lcs_string array
      i--;
      j--;
      index--;
    }
    //move in the direction of the larger length value
    else if(L[i-1][j] > L[i][j-1]){
      i--;
    }
    else{
      j--;
    }
  }
  //print results
  printf("LCS is %s with length %d\n", lcs_string, L[m][n]);
  return 0;
}

int main(void){
  char A[] = "nematode knowledge";
  char B[] = "empty bottle";

  lcs_length(A, B);
  return 0;
}
