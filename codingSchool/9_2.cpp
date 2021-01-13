/*전장속으로B*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n, x, y;
  int arr[20][20];
  int ans[20][20];
  
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 9){
        x = i;
        y = j;
      }
    }
  }
  
  memset(ans, 0, sizeof(ans));
  for(int i; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] >=1 && arr[i][j] <= 8){
        ans[i][j] = abs(i-x) + abs(j-y);
      }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] == 9){
        printf("* ");
      }else{
        printf("%d ", ans[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}