/*정방향밀기*/
#include <stdio.h>

int main() {
  int n, num;
  int arr[1000];
  
  scanf("%d", &n);
  for(int i =0; i<n;i++){
    scanf("%d", &arr[i]);
  }
  
  num = arr[n-1];
  for(int i=n-1; i>0; i--){
    arr[i] = arr[i-1];
  }
  arr[0] = num;
  
  for(int i =0; i<n;i++){
    printf("%d ",arr[i]);
  }
  
  return 0;
}