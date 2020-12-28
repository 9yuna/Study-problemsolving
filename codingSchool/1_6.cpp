/*경계 처리*/
#include <stdio.h>

int main() {
  int n,m;
  int arr[100][100];
  int y,x,d,r,ny,nx;
  int dy[4] = {0,0,1,-1};
  int dx[4] = {1,-1,0,0};
  
  scanf("%d %d", &n, &m);
  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  scanf("%d %d %d %d", &y, &x, &d, &r);
  
  for(int i=0; i<r; i++){
    ny = y + dy[d];
    nx = x + dx[d];

    if(ny < 0 || ny >= n || nx < 0 || nx >= m) break;
    
    y = ny;
    x = nx;
  }
  printf("%d\n",arr[y][x]);
  
  return 0;
}