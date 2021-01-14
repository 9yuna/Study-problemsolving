/*코치배정*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, t, k, cnt, minNum;
vector<int> graph[10];
int q_cnt[10];
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
      int x = 0, y = 0;
      for(int j=0; j<n; j++){
        if(color[j] == 1){
          x += q_cnt[j];
        } else{
          y += q_cnt[j];
        }
      }
      
      if(minNum > abs(x-y)) minNum = abs(x-y);
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
  
  int Tc; 
  cin>> Tc;
  for(int T=1; T<=Tc; T++){
    for(int i=0; i<n; i++){
      graph[i] = {};
    }
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
    
    minNum = 987987987;
    for(int i=1; i<n; i++){
      k = i;
      getResult(0);
    }
    
    if(minNum == 987987987) cout << "#"<< T<< " -1\n";
    else cout << "#"<<T<<" " << minNum <<"\n";
  }
  return 0;
}