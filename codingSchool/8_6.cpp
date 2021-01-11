/*디퓨저*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct p{
  int x;
  int y;
};
int n, m, k, diff_len, cnt, result;
queue<pair<int, int>> q;
int arr[100][100];
int dist[100][100];
int selected[11];
bool check[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
p diff[11];

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

void getResult(int idx){
  if(idx >= k){
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    for(int i=0; i<k; i++){
      q.push(make_pair(diff[selected[i]].x, diff[selected[i]].y));
      check[diff[selected[i]].x][diff[selected[i]].y] = true;
      dist[diff[selected[i]].x][diff[selected[i]].y] = 0;
    }
    BFS();
    int count = answer();
    if(count != -1 && result > count) result = count;
    return;
  }
  else if(idx < k){
    for(int i=0; i<diff_len; i++){
      if(idx == 0 || selected[idx-1] < i){
        selected[idx] = i;
        getResult(idx+1);
      }
    }
  }
}


int main() {
  
  int Tc;
  scanf("%d", &Tc);
  
  for(int T=1; T<=Tc; T++){
    scanf("%d %d %d", &n, &m, &k);
    diff_len = 0;
    
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        scanf("%d", &arr[i][j]);
        if(arr[i][j] == 2){
          diff[diff_len].x = i;
          diff[diff_len].y = j;
          diff_len++;
        }
      }
    }
    result = 987654321;
    getResult(0);
    if(result == 987654321) printf("#%d %d\n", T, -1);
    else printf("#%d %d\n", T, result);
  }
  return 0;
}