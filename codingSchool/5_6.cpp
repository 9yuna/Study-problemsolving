/*이동 알고리즘 3*/
#include <stdio.h>
#include <string.h>

int main() {
  int n, m, k, t, x, y, d;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int nextdir[4] = {1, 0, 3, 2};
  int arr[101][101][101];
  int box[101][3];
  int boxCnt[101][101];
  
  memset(arr, 0, sizeof(arr));
  memset(boxCnt, 0, sizeof(boxCnt));
  scanf("%d %d %d %d", &n, &m, &k, &t);
  for(int i=1; i<=k; i++){
    scanf("%d %d %d", &x, &y, &d);
    box[i][0] = x;
    box[i][1] = y;
    box[i][2] = d;
    arr[x][y][boxCnt[x][y]] = i;
    boxCnt[x][y]++;
  }
  
  for(int time = 0; time<t; time++){
    for(int boxnum = 1; boxnum<=k; boxnum++){
      x = box[boxnum][0], y = box[boxnum][1], d = box[boxnum][2];
      int nx = x + dx[d];
      int ny = y + dy[d];
      int cnt = 0;
      for(cnt =0; cnt < boxCnt[x][y]; cnt++){
        if(arr[x][y][cnt] == boxnum) break;
      }
      if(boxCnt[x][y] - cnt <= 1){
        if(nx < 1 || nx > n || ny < 1 || ny>m){
          d = nextdir[d];
          box[boxnum][2] = d;
          nx = x+dx[d];
          ny = y+dy[d];
        }
        arr[x][y][cnt] = 0;
        boxCnt[x][y]--;
        x = nx;
        y = ny;
        arr[x][y][boxCnt[x][y]] = boxnum;
        boxCnt[x][y]++;
        box[boxnum][0] = x;
        box[boxnum][1] = y;
      } else {
        if(nx < 1 || nx > n || ny < 1 || ny>m){
          d = nextdir[d];
          box[boxnum][2] = d;
          nx = x+dx[d];
          ny = y+dy[d];
        }
        
        for(int i = cnt; i<boxCnt[x][y]; i++){
          arr[nx][ny][boxCnt[nx][ny]] = arr[x][y][i];
          boxCnt[nx][ny]++;
          box[arr[x][y][i]][0] = nx;
          box[arr[x][y][i]][1] = ny;
          arr[x][y][i]=0;
        }
        boxCnt[x][y] -= (boxCnt[x][y]-cnt);
        x = nx;
        y = ny;
      }
    }
  }
  
  for(int i=1; i<=k; i++){
    printf("%d %d\n", box[i][0], box[i][1]);
  }
  
  return 0;
}