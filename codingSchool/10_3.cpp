/*코치배정c*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, e, cnt;
int color[10];
bool check[10];
vector<int> graph[10];

void dfs(int node, int coach){
  check[node] = true;
  cnt++;
  
  for(int i=0; i< graph[node].size(); i++){
    if(check[graph[node][i]] == false && color[graph[node][i]] == coach){
      dfs(graph[node][i], coach);
    }
  }
  return;
}
int main() {
  cin >> n >> m >> e;
  
  if(n==m){
    cout << "0\n";
    return 0;
  }
  
  for(int i=0; i<m; i++){
    char ch;
    cin >> ch;
    color[ch-'A'] = 1;
  }
  
  for(int i=0; i<e; i++){
    char ch1, ch2;
    cin >> ch1 >> ch2;
    
    graph[ch1 - 'A'].push_back(ch2 - 'A');
    graph[ch2 - 'A'].push_back(ch1 - 'A');
  }
  
  cnt=0;
  for(int i=0; i<n; i++) check[i] = false;
  for(int i=0; i<n; i++){
    if(color[i] == 1){
      dfs(i, 1);
      
      if(cnt < m){
        cout << "0\n";
        return 0;
      }
      break;
    }
  }
  
  cnt = 0;
  for(int i=0; i<n; i++){
    if(color[i] == 0){
      dfs(i, 0);
      
      if(cnt < (n-m)){
        cout << "0\n";
        return 0;
      }
      break;
    }
  }
  
  cout << "1\n";
  
  return 0;
}