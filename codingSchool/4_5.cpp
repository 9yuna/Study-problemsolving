/*이동 알고리즘2*/
#include <stdio.h>

int main() {
  int n, m, k, t, x, y, d, f;
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,-1,1};
  
  scanf("%d %d %d %d", &n, &m, &k, &t);
  for(int p=0; p<k; p++){
    scanf("%d %d %d %d", &x, &y, &d, &f);
    
    for(int time=0; time<t; time++){
        if(d<2){
        long time = f%(2*n -2);
        while(x + time*dx[d] < 1 || x + time*dx[d] > n){
            if(x + time*dx[d] < 1){
                time -= x-1;
                x=1;
                d=1;
            }
            else{
                time -= n-x;
                x = n;
                d=0;
            }
        }
        x+= time*dx[d];
        } else{
        long time = f%(2*m -2);
        while(y + time*dy[d] < 1 || y + time*dy[d] > m){
            if(y + time*dy[d] < 1){
                time -= y-1;
                y=1;
                d=3;
            }
            else{
                time -= m-y;
                y = m;
                d=2;
            }
        }
        y+= time*dy[d];
        }
    }
  
    printf("%d %d\n", x, y);
  }
  return 0;
}