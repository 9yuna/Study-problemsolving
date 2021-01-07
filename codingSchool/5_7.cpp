/*철새*/
#include <stdio.h>
#include <string.h>

int n, k, Tc, answer;
int arr[15][15];
int x[20];
int y[20];
int d[20];
int bird[15][15][20];
int num[15][15];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int nextdir[4] = {1, 0, 3, 2};

int in_range(int x, int y){
  if(x>=0 && x < n && y>=0 && y<n) return 1;
  else return 0;
}

int get_num(int sx, int sy, int idx){
  for(int i=0; i<num[sx][sy]; i++){
    if(bird[sx][sy][i] == idx) return i;
  }
  return -1;
}

void push_back(int sx, int sy, int sidx, int ex, int ey){
  for(int i=sidx; i<num[sx][sy]; i++){
    int idx = bird[sx][sy][i];
    x[idx] = ex;
    y[idx] = ey;
    bird[ex][ey][num[ex][ey]] = idx;
    num[ex][ey]++;
  }
  num[sx][sy] = sidx;
}

void push_front(int sx, int sy, int sidx, int ex, int ey){
  int eidx = num[ex][ey];
  int len = num[sx][sy] - sidx;
  
  for(int i=eidx+len-1; i>=len; i--){
    bird[ex][ey][i] = bird[ex][ey][i-len];
  }
  
  for(int i=0; i<len; i++){
    int idx = bird[sx][sy][i+sidx];
    x[idx] = ex;
    y[idx] = ey;
    bird[ex][ey][i] = idx;
  }
  num[ex][ey] += len;
  num[sx][sy] = sidx;
}

void move(int idx){
  int nx = x[idx] + dx[d[idx]];
  int ny = y[idx] + dy[d[idx]];
  
  if(in_range(nx, ny) == 0 || arr[nx][ny] == 2){
    d[idx] = nextdir[d[idx]];
    nx = x[idx] + dx[d[idx]];
    ny = y[idx] + dy[d[idx]];
  }
  
  int sx = x[idx];
  int sy = y[idx];
  int sidx = get_num(sx, sy, idx);
  
  if(arr[nx][ny] == 0){
    push_front(sx, sy, sidx, nx, ny);
  } else if(arr[nx][ny] == 1){
    push_back(sx, sy, sidx, nx, ny);
  }
}

int check(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(num[i][j] >= 4) return 1;
    }
  }
  return 0;
}

int main(){
  scanf("%d", &Tc);
  for(int T=1; T<=Tc; T++){
    memset(num, 0, sizeof(num));
    memset(arr, 0, sizeof(arr));
    memset(bird, 0, sizeof(bird));
    
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    
    for(int i=1; i<=k; i++){
      scanf("%d %d %d", &x[i], &y[i], &d[i]);
      num[x[i]][y[i]] = 1;
      bird[x[i]][y[i]][0] = i;
    }
    
    answer = -1;
    for(int i=1; i<=1000; i++){
      for(int j=1; j<=k; j++){
        move(j);
        
        if(check() == 1){
          answer = i;
          break;
        }
      }
      if(answer != -1) break;
    }
    printf("#%d %d\n", T, answer);
  }
  return 0;
}

/*
#include <stdio.h>
#include <string.h>

int Tc, n, k, x, y, d, time;
int arr[12][12];
int birdarr[12][12][12];
int birdCnt[12][12];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int nextdir[4] = {1, 0, 3, 2};
int birds[11][3];

bool check(){
  for(int i=0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(birdCnt[i][j] > 4){
        return true;
      }
    }
  }
  return false;
}  


int main() {
  scanf("%d", &Tc);
  for(int T=1; T<=Tc; T++){
    memset(arr, 0, sizeof(arr));
    memset(birdarr, 0, sizeof(birdarr));
    memset(birds, 0, sizeof(birds));
    memset(birdCnt, 0, sizeof(birdCnt));
    int answer = -1;
    
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
      }
    }


    for(int i=1; i<=k; i++){
      scanf("%d %d %d", &birds[i][0], &birds[i][1], &birds[i][2]);
      birdCnt[birds[i][0]][birds[i][1]]++;
      birdarr[birds[i][0]][birds[i][1]][0] = i;
    }
    

    for(time = 1; time <= 15; time++){
      for(int i=1; i<=k; i++){
        x = birds[i][0], y = birds[i][1], d = birds[i][2];

        int nx = x+dx[d], ny = y+dy[d];
        int cnt = 0;
        for(cnt =0; cnt < birdCnt[x][y]; cnt++){
          if(birdarr[x][y][cnt] == i) break;
        }
        
        if(birdCnt[x][y] - cnt <= 1){
          if(nx < 1 || nx > n || ny < 1 || ny>n || arr[nx][ny] == 2){
            d = nextdir[d];
            birds[i][2] = d;
            nx = x+dx[d];
            ny = y+dy[d];
          }
          
          birdarr[x][y][cnt] = 0;
          birdCnt[x][y]--;
          if(arr[nx][ny] == 1){
            birdarr[nx][ny][birdCnt[nx][ny]] = i;
            birdCnt[nx][ny]++;  
          } else{
            for(int tt = birdCnt[nx][ny]-1; tt>=1; tt--){
              birdarr[nx][ny][tt] = birdarr[nx][ny][tt-1];
            }
            birdarr[nx][ny][0] = i;
            birdCnt[nx][ny]++;
          }
          birds[i][0] = nx;
          birds[i][1] = ny;
        } else {
          if(nx < 1 || nx > n || ny < 1 || ny>n || arr[nx][ny] == 2){
            d = nextdir[d];
            birds[i][2] = d;
            nx = x+dx[d];
            ny = y+dy[d];
          }
          
          if(arr[nx][ny] == 1){
            for(int j = cnt; j<birdCnt[x][y]; j++){
              birdarr[nx][ny][birdCnt[nx][ny]] = birdarr[x][y][j];
              birdCnt[nx][ny]++;
              birds[birdarr[x][y][j]][0] = nx;
              birds[birdarr[x][y][j]][1] = ny;
              birdarr[x][y][j]=0;
            }
          } else{
            for(int i=0; i<cnt; i++){
              for(int tt = birdCnt[nx][ny]; tt>0; tt--){
                birdarr[nx][ny][tt] = birdarr[nx][ny][tt-1];
              }
              birdCnt[nx][ny]++;
            }
            for(int j = 0; j<cnt; j++){
              birdarr[nx][ny][j] = birdarr[x][y][j+cnt];
              birds[birdarr[x][y][j]][0] = nx;
              birds[birdarr[x][y][j]][1] = ny;
              birdarr[x][y][j+cnt]=0;
            }
          }
          birdCnt[x][y] -= (birdCnt[x][y]-cnt);
        }
        
        if(check() == true){
          answer = i;
          break;
        }
      }
      if(answer != -1) break;
    }
    
    if(time > 1000) answer = -1;
    
    printf("#%d %d\n", T, answer);
  }
  return 0;
}*/