/*2차원 밀기
#include <stdio.h>

int main() {
  int n, m, temp, temp2;
  int arr[100][100];
  
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  temp = arr[0][m-1];
  for(int i=m-1; i>0; i--){
    arr[0][i] = arr[0][i-1];
  }
  temp2 = arr[n-1][m-1];
  for(int i=n-1; i>1; i--){
    arr[i][m-1] = arr[i-1][m-1];
  }
  arr[1][m-1] = temp;
  
  temp = arr[n-1][0];
  for(int i=0; i<m-1; i++){
    arr[n-1][i] = arr[n-1][i+1];
  }
  arr[n-1][m-2] = temp2;
  for(int i=0; i<n-2; i++){
    arr[i][0] = arr[i+1][0];
  }
  arr[n-2][0] = temp;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}*/

#include <stdio.h>

int main() {
  int n, m, temp;
  int arr[100][100];
  
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  temp = arr[0][0];

  for(int i=0; i<n-1; i++){
      arr[i][0] = arr[i+1][0];
  }
  for(int j=0; j<m-1; j++){
      arr[n-1][j] = arr[n-1][j+1];
  }
  for(int i=n-1; i>0; i--){
      arr[i][m-1] = arr[i-1][m-1];
  }
  for(int j=m-1; j>0; j--){
      arr[0][j] = arr[0][j-1];
  }
  arr[0][1] = temp;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}