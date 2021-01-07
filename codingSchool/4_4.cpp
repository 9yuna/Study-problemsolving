/*2차원 큰 이동*/
#include <stdio.h>

int main() {
  int n, m, x, y, d, t;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &d, &t);
  
  if(d < 2){ 
    t %= 2*n -2;
    while(x + t*dx[d] < 1 || x + t*dx[d] > n){
      if(x + t*dx[d] < 1){
          t -= x-1;
          x=1;
          d=1;
      }
      else if(x + t*dx[d] > n){
          t -= n-x;
          x = n;
          d=0;
      }
    }
    x+= t*dx[d];
  }
  else{
    t %= 2*m -2; 
    while(y + t*dy[d] < 1 || y + t*dy[d] > m){
      if(y + t*dy[d] < 1){
          t -= y-1;
          y=1;
          d=3;
      }
      else if(y + t*dy[d] > m){
          t -= m-y;
          y = m;
          d=2;
      }
    }
    y += t*dy[d];
  }
  
  printf("%d %d\n",x, y);
  return 0;
}