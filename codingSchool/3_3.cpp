/*밀기 알고리즘*/
#include <stdio.h>

int main() {
  int n, m, u, d;
  int arr[100][100];
  
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  scanf("%d %d", &u, &d);
  
  int temp = arr[0][0];
  for(int i=0; i<u; i++) arr[i][0] = arr[i+1][0];
  for(int j=0; j<m; j++) arr[u][j] = arr[u][j+1];
  for(int i=u; i>0; i--) arr[i][m-1] = arr[i-1][m-1];
  for(int j=m-1; j>0; j--) arr[0][j] = arr[0][j-1];
  arr[0][1] = temp;
  
  temp = arr[d][0];
  for(int j=0; j<m; j++) arr[d][j] = arr[d][j+1];
  for(int i=d; i<n; i++) arr[i][m-1] = arr[i+1][m-1];
  for(int j=m-1; j>0; j--) arr[n-1][j] = arr[n-1][j-1];
  for(int i=n-1; i>d; i--) arr[i][0] = arr[i-1][0];
  arr[d+1][0] = temp;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}