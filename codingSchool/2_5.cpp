/*1차원 조회*/
#include <stdio.h>

int main() {
  int n;
  int arr[1000];
  int answer[1000];
  
  scanf("%d", &n);
  
  for(int i =0; i<n; i++){
    scanf("%d", &arr[i]);
    answer[i] = 0;
  }
  
  if(arr[0] == arr[1]){
    answer[0]=1;
  }
  for(int i =1; i<n-1; i++){
    if(arr[i] == arr[i-1]){
      answer[i]=1;
    }
    if(arr[i] == arr[i+1]){
      answer[i]=1;
    }
  }
  if(arr[n-2]==arr[n-1]){
    answer[n-1]=1;
  }
  
  for(int i =0; i<n; i++){
    printf("%d ", answer[i]);
  }
  return 0;
}