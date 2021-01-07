/*단순 밀기*/
#include <stdio.h>

int main() {
  int n;
  int arr[1001]={0,};
  
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i+1]);
  }  
  
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}