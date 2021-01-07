/*밀렵꾼*/
#include <stdio.h>
#include <string.h>

int Tc, r, c, m, x, y, d, f, w;
int arr[102][102], copyarr[102][102];
int pig[10002][6];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void move(){
  memset(copyarr, 0, sizeof(copyarr));
  for(int i=1; i<=m; i++){
    if(pig[i][0] == 0){
      if(pig[i][3] < 3){
        int x = pig[i][1], y = pig[i][2], d = pig[i][3], ff = pig[i][4];
        while(x + ff*dx[d] < 1 || x + ff*dx[d] > r){
          if(x + ff*dx[d] < 1){
              ff -= x-1;
              x=1;
              d=2;
          }
          else{
              ff -= r-x;
              x = r;
              d=1;
          }
        }
        x+= ff*dx[d];
        pig[i][1] = x;
        pig[i][3] = d;
        if(copyarr[x][y] == 0){
          copyarr[x][y] = i;
        } else {
          if(pig[copyarr[x][y]][5] > pig[i][5]){
            pig[i][0] = -1;
            continue;
          } else {
            pig[copyarr[x][y]][0] = -1;
            copyarr[x][y] = i;
          }
        }
      } else {
        int x = pig[i][1], y = pig[i][2], d = pig[i][3], ff = pig[i][4];
        while(y + ff*dy[d] < 1 || y + ff*dy[d] > c){
          if(y + ff*dy[d] < 1){
              ff -= y-1;
              y=1;
              d=4;
          }
          else{
              ff -= c-y;
              y = c;
              d=3;
          }
        }
        y+= ff*dy[d];
        pig[i][2] = y;
        pig[i][3] = d;
        if(copyarr[x][y] == 0){
          copyarr[x][y] = i;
        } else {
          if(pig[copyarr[x][y]][5] > pig[i][5]){
            pig[i][0] = -1;
            continue;
          } else {
            pig[copyarr[x][y]][0] = -1;
            copyarr[x][y] = i;
          }
        }
      }
    }
    
  }
  
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      arr[i][j] = copyarr[i][j];
      copyarr[i][j] = 0;
    }
  }
}  


int main() {
  scanf("%d", &Tc);
  
  for(int T=1; T<=Tc; T++){
    memset(arr, 0, sizeof(arr));
    memset(copyarr, 0, sizeof(copyarr));
    memset(pig, 0, sizeof(pig));
    
    scanf("%d %d %d", &r, &c, &m);
    for(int i=1; i<=m; i++){
      scanf("%d %d %d %d %d", &x, &y, &d, &f, &w);
      arr[x][y] = i;
      pig[i][1] = x;
      pig[i][2] = y;
      pig[i][3] = d;
      pig[i][5] = w;
      if(d < 3){
        pig[i][4] = (f%(2*r -2));
      } else {
        pig[i][4] = (f%(2*c -2));
      }
    }
    
    int ans = 0;
    for(int time = 1; time <= c; time++){
      move();
      for(int j=r; j>=1; j--){
        if(arr[j][time] != 0 && pig[arr[j][time]][0] == 0){
          ans += pig[arr[j][time]][5];
          pig[arr[j][time]][0] = -1;
          arr[j][time] = 0;
          break;
        }
      }
    }
    
    printf("#%d %d\n", T, ans);
  }
  return 0;
}