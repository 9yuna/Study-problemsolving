/*디퓨저D*/
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
queue<pair<int, int>> q;
int arr[100][100];
int dist[100][100];
bool check[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(){
  
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    
    q.pop();
    
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;
      
      if(dist[nx][ny] == 0){
        dist[nx][ny] = dist[x][y] + 1;
        check[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
    }
  }
  
}
int main() {
  scanf("%d %d", &n, &m);
  
  memset(dist, 0, sizeof(dist));
  memset(check, false, sizeof(check));
  for(int i = 0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 1) check[i][j] = true;
      if(arr[i][j] == 2){
        q.push(make_pair(i, j));
        check[i][j] = true;
      }
    }
  }
  
  BFS();
  
  int ans = 0;
  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      if(check[i][j] == false){
        ans = -1;
        break;
      } else if(ans < dist[i][j]){
        ans = dist[i][j]; 
      }
    }
    if(ans == -1) break;
  }
  
  printf("%d\n", ans);
  
  return 0;
}