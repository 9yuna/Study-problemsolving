/*회전판과 로봇*/
#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  
  int n,m,x,y;
  int arr[500][500];
  int dy[4] = {0,0,1,-1};
  int dx[4] = {1,-1,0,0};
  
  for(int Tc = 1; Tc <= T; Tc++){
    int score = 0, k, l, dir, dir_cnt, roulette_num = 0;
    int roulette[8];
    char move;
    
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    x--;
    y--;
    
    score = arr[y][x];
    arr[y][x] = 0;
    scanf("%d", &k);
    for(int i =0; i<k;i++){
      scanf("%d", &roulette[i]);
    }
    
    scanf("%d\n", &l);
    for(int t = 0; t<l; t++){
      scanf("%c %d %d\n", &move, &dir, &dir_cnt);
      
      int move_cnt;
      while(dir_cnt > k) dir_cnt -= k;
      if(dir == 2){
        if(roulette_num + dir_cnt >= k){
          roulette_num = roulette_num + dir_cnt -k;
        } else {
          roulette_num = roulette_num + dir_cnt;
        }
        move_cnt = roulette[roulette_num];
      } else {
        if(roulette_num - dir_cnt < 0){
          roulette_num = roulette_num - dir_cnt + k;
        } else {
          roulette_num = roulette_num - dir_cnt;
        }
        move_cnt = roulette[roulette_num];
      }
      
      int d;
      if(move == 'E'){
        d = 0;
      } else if(move == 'W'){
        d = 1;
      } else if(move == 'S'){
        d = 2;
      } else {
        d = 3;
      }
      
      for(int i =0; i<move_cnt; i++){
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if(arr[ny][nx] == -1 || ny < 0 || ny >= m || nx < 0 || nx >= n){
          break;
        }
        
        y = ny;
        x = nx;
        score += arr[y][x];
        arr[y][x] = 0;
      }
    }
    printf("#%d %d %d %d\n", Tc, score, x+1, y+1);
  }
  return 0;
}