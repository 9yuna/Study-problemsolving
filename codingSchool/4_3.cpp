/*1차원 큰 이동*/
#include <stdio.h>

int main() {
  int d, n, x, t;
  int dx[2] = {-1, 1};
  
  scanf("%d %d %d %d", &n, &x, &d, &t);
  
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
  printf("%d %d\n", x, d);
  return 0;
}