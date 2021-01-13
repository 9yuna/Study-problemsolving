/*전장속으로*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, level, x, y, result, killCnt;
int arr[20][20];
int ans[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> qq;

void bfs(){
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ans[i][j] = 0;
    }
  }

  qq.push(make_pair(x, y));
  
  while(!qq.empty()){
    int i = qq.front().first;
    int j = qq.front().second;
    qq.pop();
    
    
    for(int t=0; t<4; t++){
      int nx = i + dx[t];
      int ny = j + dy[t];
      
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > level) continue;
      if(arr[nx][ny] <= level && ans[nx][ny] == 0){
        qq.push(make_pair(nx, ny));
        ans[nx][ny] = ans[i][j]+1;
      }
    }
  }
  
  int minNum = 987987987, minX, minY;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] > 0 && arr[i][j] < level && ans[i][j] != 0){
        if(minNum > ans[i][j]){
          minNum = ans[i][j];
          minX = i;
          minY = j;
        }
      }
    }
  }
  
  if(minNum != 987987987){
    killCnt++;
    result += minNum;
    arr[minX][minY] = 0;
    x = minX;
    y = minY;
    if(killCnt >= level){
      level++;
      killCnt=0;
    }
  } else if(minNum == 987987987){
    return;
  }
  bfs();
}

int main() {
  int Tc;
  scanf("%d", &Tc);
  
  for(int T=1; T<=Tc; T++){
    scanf("%d", &n);
    level = 2;
    killCnt = 0;
    
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
        if(arr[i][j] == 9){
          x = i;
          y = j;
          arr[i][j] = 0;
        }
      }
    }
    result = 0;
    bfs();
    
    printf("#%d %d\n", T, result);  
  }
  return 0;
}