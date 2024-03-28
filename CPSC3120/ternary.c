#include <stdio.h>

int ternarySearch(int key,int arr[],int start,int arrLength){

  //if the array size is >= 0 in first case (greater than start after)
  if(arrLength >= start){
    //find the two mid points where we split our three sections
    int m1 = start + (arrLength-start) / 3;
    int m2 = arrLength - (arrLength-start) / 3;

    //check if the key is present at either of the mid points
    if(arr[m1] == key) return m1;
    if(arr[m2] == key) return m2;

    //if key is not at the midpoints, check which third it is in
    //repeat search in that region
    if(key < arr[m1]){
      //key is between the start and m1
      return ternarySearch(key, arr, start, m1-1);
    }
    else if(key > arr[m2]){
      //key is in last third (m2 and end)
      return ternarySearch(key, arr, m2+1, arrLength);
    }
    else{
      //key is in the middle third
      return ternarySearch(key, arr, m1+1, m2-1);
    }
  }
  //key isnt found return -1
  return -1;
}

int main(){
  int l, r, p, key;
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  l = 0;
  r = 10;

  key = 5;
  p = ternarySearch(key, arr, l, r);
  printf("Index is: %d\n", p);

}
