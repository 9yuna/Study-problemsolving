/*이동 복습*/
#include <stdio.h>

int main() {
  int n, m, q, d, r;
  int arr[100][100];
  int dx[4] = {0,0,1,-1};
  int dy[4] = {1, -1, 0, 0};
  
  scanf("%d %d %d", &n, &m, &q);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  int x=0, y=0;
  for(int t=0; t<q; t++){
    scanf("%d %d", &d, &r);
    for(int i=0; i<r; i++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      
      if(arr[nx][ny] == -1) break;
      if(nx<0 || nx>=n || ny<0 || ny>=m) break;
      
      x = nx;
      y=ny;
    }
    printf("%d\n", arr[x][y]);
  }
  return 0;
}