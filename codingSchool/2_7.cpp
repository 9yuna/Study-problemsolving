/*조회 알고리즘*/
#include <stdio.h>

int main() {
  int n,m;
  int arr[102][102];
  int answer[102][102];
  
  scanf("%d %d", &n, &m);
  for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
      if(arr[i][j] == arr[i-1][j] || arr[i][j] == arr[i][j+1] || arr[i][j] == arr[i+1][j] || arr[i][j] == arr[i][j-1]){
        answer[i][j] = 1;
      } else {
        answer[i][j] = 0;
      }
    }
    if(arr[i][1] == arr[i][m]){
      answer[i][1] = answer[i][m] = 1;
    }
  }
  
  for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
      printf("%d ", answer[i][j]);
    }
    printf("\n");
  }
  return 0;
}