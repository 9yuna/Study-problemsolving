/*이동 알고리즘*/
#include <stdio.h>

int main() {
  int n, m, q;
  int arr[100][100];
  int y=0, x=0, d, r, ny, nx;
  int dy[4] = {0,0,1,-1};
  int dx[4] = {1,-1,0,0};
  
  scanf("%d %d %d", &n, &m, &q);
  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i =0; i<q; i++){
    scanf("%d %d", &d, &r);
    for(int j = 0; j<r; j++){
      ny = y + dy[d];
      nx = x + dx[d];
      
      if(arr[ny][nx] == -1 || ny < 0 || ny >= n || nx < 0 || nx >= m) break;
      
      y = ny;
      x = nx;
    }
    printf("%d\n", arr[y][x]);
  }
  return 0;
}