/*디퓨저E*/
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
      
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || arr[nx][ny] == 1) continue;
      
      if(dist[nx][ny] == 0){
        dist[nx][ny] = dist[x][y] + 1;
        check[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int answer(){
  int ans = 0;
  for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      if(check[i][j] == false && arr[i][j] != 1 && arr[i][j] != 2){
        ans = -1;
        break;
      } else if((ans < dist[i][j]) && (arr[i][j] != 2)){
        ans = dist[i][j]; 
      }
    }
    if(ans == -1) break;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  
  queue<pair<int, int>> diff;
  int diff_num = 0;
  for(int i = 0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 2){
        diff_num++;
        diff.push(make_pair(i, j));
      }
    }
  }
  
  int result = 999999999;
  
  for(int i=0; i<diff_num; i++){
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));  
    int x = diff.front().first;
    int y = diff.front().second;
    diff.pop();
    check[x][y] = true;
    q.push(make_pair(x,y));
    BFS();
    
    int count = answer();
    if(result > count) result = count;
  }

  printf("%d\n", result);
  
  return 0;
}