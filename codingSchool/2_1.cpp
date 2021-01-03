/*단순밀기*/
#include <stdio.h>

int main() {
  int n, num;
  int arr[1000];
  
  scanf("%d", &n);
  arr[0] = 0;
  for(int i = 1; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  for(int i =0; i<n;i++){
    printf("%d ", arr[i]);
  }
  return 0;
}