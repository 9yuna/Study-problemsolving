/*디퓨저A*/

#include <stdio.h>

struct p{
  int x;
  int y;
};
int n, m, k, t, diff_len, cnt;
int arr[101][101];
int selected[11];
p diff[11];
  
void getResult(int idx){
  if(idx >= k){
    cnt++;
    if(cnt == t){
      for(int i=0; i<k; i++){
        printf("%d %d\n", diff[selected[i]].x, diff[selected[i]].y);
      }
    }
  }
  else{
    for(int i=0; i<diff_len; i++){
      if(idx == 0 || selected[idx-1] < i){
        selected[idx] = i;
        getResult(idx+1);
      }
    }
  }
}

int main() {
  
  scanf("%d %d %d %d", &n, &m, &k, &t);

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 2){
        diff[diff_len].x = i;
        diff[diff_len].y = j;
        diff_len++;
      }
    }
  }
  
  getResult(0);
  
  return 0;
}

/*
#include <stdio.h>

int n, m, k, t, bottle, num;
int arr[101][101];
int bottles[11][2];
int selected[11];
bool isFinished;
  
void getResult(int x, int cnt){
  if(isFinished) return;
  
  if(cnt >= k){
    num++;
    if(num == t){
      for(int i=0; i<bottle; i++){
        if(selected[i] == 1){
          printf("%d %d\n", bottles[i][0], bottles[i][1]);
        }
      }
      isFinished = true;
    }
    return;
  }
  else if(x<bottle){
    selected[x] = 1;
    getResult(x+1, cnt+1);
    selected[x] = 0;
    getResult(x+1, cnt);
  }
}

int main() {
  
  scanf("%d %d %d %d", &n, &m, &k, &t);

  bottle = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 2){
        bottles[bottle][0] = i;
        bottles[bottle][1] = j;
        bottle++;
      }
    }
  }
  
  num=0;
  isFinished = false;
  getResult(0,0);
  
  return 0;
}*/