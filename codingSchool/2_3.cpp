/*역방향 밀기*/
#include <stdio.h>

int main() {
  int n,k,num;
  int arr[1000];
  
  scanf("%d %d", &n, &k);
  for(int i =0; i<n;i++){
    scanf("%d", &arr[i]);
  }
  
  for(int i=0; i<k; i++){
    num = arr[0];
    for(int j=0; j<n-1;j++){
      arr[j] = arr[j+1];
    }
    arr[n-1] = num;
  }
  
  for(int i=0; i<n;i++){
    printf("%d ", arr[i]);
  }
  return 0;
}