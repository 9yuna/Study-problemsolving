/*코치배정D*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, t, cnt;
vector<int> graph[10];
int q_cnt[10];
int color[10];
bool visited[10];

void dfs(int node, int coach){
  visited[node] = true;
  cnt++;
  
  for(int i=0; i< graph[node].size(); i++){
    if(visited[graph[node][i]] == false && color[graph[node][i]] == coach){
      dfs(graph[node][i], coach);
    }
  }
  return;
}

int main() {
  cin >> n;
  
  
  for(int i=0; i<n; i++){
    cin >> q_cnt[i];
    
    int cnt;
    cin >> cnt;
    
    char ch;
    for(int j=0; j<cnt; j++){
      cin >> ch;
      graph[i].push_back(ch-'A');
    }
  }
  
  cin >> t;
  int min = 987987987;
  for(int i=0; i<t; i++){
    memset(color, 0, sizeof(color));
    int select, ans = 0;
    cin >> select;
    
    char ch;
    for(int j=0; j<select; j++){
      cin >> ch;
      color[ch-'A'] = 1;
    }
    
    if(select == n){
      continue;
    }
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int j=0; j<n; j++){
      if(color[j] == 1){
        dfs(j, 1);
        
        if(cnt < select){
          ans = -1;
        }
        break;
      }
    }
    
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int j=0; j<n; j++){
      if(color[j] == 0){
        dfs(j, 0);
        
        if(cnt < (n-select)){
          ans = -1;
        }
        break;
      }
    }
    
    if(ans == -1){
      continue;
    } else{
      int x = 0, y = 0;
      for(int j=0; j<n; j++){
        if(color[j] == 1){
          x += q_cnt[j];
        } else{
          y += q_cnt[j];
        }
      }
      
      if(min > abs(x-y)) min = abs(x-y);
    }
  }
  
  if(min == 987987987) cout << "-1\n";
  else cout << min <<"\n";
  return 0;
}