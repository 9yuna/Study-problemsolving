/*n명 이동*/
#include <stdio.h>

int main() {
  int n, m, k, t;
  int x, y, d, f;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  scanf("%d %d %d %d", &n, &m, &k, &t);
  
  for(int p=0; p<k; p++){
    scanf("%d %d %d %d", &x, &y, &d, &f);
    int nx, ny;
    for(int time =0; time<t; time++){
      for(int cnt=0; cnt<f; cnt++){
        nx = x + dx[d];
        ny = y + dy[d];
        if(nx<1 || nx>n || ny <1 || ny>m) break;
        x = nx;
        y = ny;
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}