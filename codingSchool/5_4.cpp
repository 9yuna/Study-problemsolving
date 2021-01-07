/*이동 알고리즘2*/
#include <stdio.h>

int main() {
  int n, m, k, t, x, y, d, f;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  
  scanf("%d %d %d %d", &n, &m, &k, &t);
  for(int people = 0; people <k; people++){
    scanf("%d %d %d %d", &x, &y, &d, &f);
    for(int time =0; time<t; time++){
      int nx, ny;
      for(int move=0; move<f; move++){
        nx = x+dx[d];
        ny = y+dy[d];
        if(nx <1 || nx>n || ny <1 || ny>m) break;
        x = nx;
        y = ny;
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}