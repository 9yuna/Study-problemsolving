/*1차원 확산*/
#include <stdio.h>

int main() {
  int n, i=0;
  int arr[1002];
  bool check[1002] = {0,};
  
  scanf("%d", &n);
  for(int i=1; i<n+1;i++){
    scanf("%d", &arr[i]);
    if(arr[i] == 1){
      check[i] = true;
    }
  }
  
  
  for(i=i; i<n+1; i++){
    if(check[i] == true){
      arr[i-1] = 1;
      arr[i+1] = 1;
    }
  }
  
  for(int i=1; i<n+1; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}