/*전장속으로A*/
#include <stdio.h>

int main() {
  int n, min = 987987987;
  int arr[20][20];
  
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] != 0 && min > arr[i][j]){
        min = arr[i][j];
      }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] == min){
        printf("%d %d\n", i+1, j+1);
        return 0;
      }
    }
  }
  return 0;
}