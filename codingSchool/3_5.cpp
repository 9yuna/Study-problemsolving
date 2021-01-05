/*2차원 확산*/
#include <stdio.h>

int main() {
  int n, m, t;
  long arr[102][102], copyarr[102][102];
  
  scanf("%d %d", &n, &m);
  for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
      scanf("%d", &arr[i][j]);
      copyarr[i][j] = arr[i][j];
    }
  }
  scanf("%d", &t);
  
  for(int time = 0; time < t; time++){
    for(int i=1; i<n+1; i++){
      for(int j=1; j<m+1; j++){
        copyarr[i-1][j] += arr[i][j];
        copyarr[i][j-1] += arr[i][j];
        copyarr[i+1][j] += arr[i][j];
        copyarr[i][j+1] += arr[i][j];
      }
    }
    
    for(int i=1; i<n+1; i++){
      for(int j=1; j<m+1; j++){
        arr[i][j] = copyarr[i][j];
      }
    }
  }
  
  for(int i=1; i<n+1; i++){
    for(int j=1; j<m+1; j++){
      printf("%ld ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}