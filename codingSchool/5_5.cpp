/*단체 이동*/
#include <stdio.h>
#include <string.h>

int main() {
  int n, m, k, t, x, y, d;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int nextdir[4] = {1, 0, 3, 2};
  int people[101][3];
  int arr[101][101][101];
  memset(arr, 0, sizeof(arr));
  scanf("%d %d %d %d", &n, &m, &k, &t);
  for(int i=1; i<=k; i++){
    scanf("%d %d %d", &x, &y, &d);
    people[i][0] = x;
    people[i][1] = y;
    people[i][2] = d;
    if(arr[x][y][0] == 0){
      arr[x][y][0] = i;
    }else {
      for(int j=1; j<101; j++){
        if(arr[x][y][j] == 0){
          arr[x][y][j] = i;
          break;
        }
      }
    }
  }
  
  for(int time = 0; time <t; time++){
    for(int p = 1; p <= k; p++){
      x = people[p][0], y = people[p][1], d = people[p][2]; 
      
      int cnt = 0;
      for(cnt = 0; cnt<101; cnt++){
        if(arr[x][y][cnt] == 0){
          break;
        }
      }
      
      if(cnt < 2){
        int nx = x+dx[d], ny = y+dy[d];
        if(nx < 1 || nx > n || ny < 1 || ny>m){
          d = nextdir[d];
          people[p][2] = d;
          nx = x+dx[d];
          ny = y+dy[d];
        }
        arr[x][y][0] = 0;
        x = nx;
        y = ny;
        for(int cnt2 =0; cnt2 < 101; cnt2++){
          if(arr[x][y][cnt2] == 0){
            arr[x][y][cnt2] = p;
            break;
          }
        }
        people[p][0] = x;
        people[p][1] = y;
      } else{
        int nx = x+dx[d], ny = y+dy[d];
        if(nx < 1 || nx > n || ny < 1 || ny>m){
          d = nextdir[d];
          nx = x+dx[d];
          ny = y+dy[d];
          people[p][2] = d;
        }
        int cnt2 =0;
        for(cnt2 =0; cnt2 < 101; cnt2++){
          if(arr[nx][ny][cnt2] == 0){
            break;
          }
        }
        for(int i = 0; i<cnt; i++){
          arr[nx][ny][i+cnt2] = arr[x][y][i];
          people[arr[x][y][i]][0] = nx;
          people[arr[x][y][i]][1] = ny;
          arr[x][y][i] = 0;
        }
        x = nx;
        y = ny;
      }
    }
  }
  
  for(int i=1; i<=k; i++){
    printf("%d %d\n", people[i][0], people[i][1]);
  }
  
  return 0;
}