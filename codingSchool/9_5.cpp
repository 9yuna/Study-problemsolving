/*전장속으로E*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, k, x, y, result;
int arr[20][20];
int ans[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(){
  memset(ans, 0, sizeof(ans));
  queue<pair<int, int>> qq;
  qq.push(make_pair(x, y));
  
  while(!qq.empty()){
    int i = qq.front().first;
    int j = qq.front().second;
    qq.pop();
    
    
    for(int t=0; t<4; t++){
      int nx = i + dx[t];
      int ny = j + dy[t];
      
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > k) continue;
      else if(arr[nx][ny] <= k && ans[nx][ny] == 0){
        qq.push(make_pair(nx, ny));
        ans[nx][ny] = ans[i][j]+1;
      }
    }
  }
  
  int minNum = 987987987, minX, minY;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] < k && ans[i][j] != 0){
        if(minNum > ans[i][j] && arr[i][j] >= 1 && arr[i][j] < k){
          minNum = ans[i][j];
          minX = i;
          minY = j;
        }
      }
    }
  }
  result += minNum;
  arr[minX][minY] = 0;
  x = minX;
  y = minY;
  
  bool flag = false;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] < k && arr[i][j] > 0){
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  
  if(flag) bfs();
  else return;
}

int main() {
  scanf("%d", &n);
  k=8;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 9){
        x = i;
        y = j;
      }
    }
  }
  
  result = 0;
  bfs();
  
  printf("%d\n", result);
  
  return 0;
}