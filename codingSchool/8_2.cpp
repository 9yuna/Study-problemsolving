/*디퓨저B*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, m;
int arr[100][100];
int dist[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  queue<pair<int,int>> q;
  scanf("%d %d", &n, &m);
  memset(dist, 0, sizeof(dist));
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 1) dist[i][j] = -1;
      if(arr[i][j] == 2){
        q.push(make_pair(i, j));
      }
    }
  }
  
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    
    q.pop();
    
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      
      if(dist[nx][ny] == 0 && arr[nx][ny] != 2 ){
        dist[nx][ny] = dist[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  
  int ans =0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] != 2 && dist[i][j] == 0){
        ans = -1;
        break;
      } else{
        if(ans < dist[i][j]) ans = dist[i][j];
      }
    }
    if(ans == -1) break;
  }
  printf("%d\n", ans);
  return 0;
}