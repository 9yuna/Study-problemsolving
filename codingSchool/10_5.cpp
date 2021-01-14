/*코치배정E*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, t, k, cnt, case_cnt;
vector<int> graph[10];
int color[10];
bool visited[10];
int selected[10];

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

void getResult(int idx){
  if(idx >= k){
    int ans = 0;
    
    memset(color, 0, sizeof(color));
    for(int i=0; i<k; i++){
      color[selected[i]] = 1;
    }
    
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int j=0; j<n; j++){
      if(color[j] == 1){
        dfs(j, 1);
        if(cnt < k){
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
        
        if(cnt < (n-k)){
          ans = -1;
        }
        break;
      }
    }
    
    if(ans == -1){
      return;
    } else{
      case_cnt++;
      return;
    }
  }else{
    for(int i=0; i<n; i++){
      if(idx == 0 || selected[idx-1] < i){
        selected[idx] = i;
        getResult(idx+1);
      }
    }
  }
}

int main() {
  cin >> n;
  
  
  for(int i=0; i<n; i++){
    int cnt;
    cin >> cnt;
    
    char ch;
    for(int j=0; j<cnt; j++){
      cin >> ch;
      graph[i].push_back(ch-'A');
    }
  }
  
  case_cnt = 0;
  for(int i=1; i<n; i++){
    k = i;
    getResult(0);
  }
  
  cout << case_cnt <<"\n";
  return 0;
}