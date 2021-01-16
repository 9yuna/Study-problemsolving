/*슬라임D*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, result, weight;
int arr[50][50];
bool check[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int i, int j){
  int value = 1;
  check[i][j] = true;
  weight += arr[i][j];

  for(int k=0; k<4; k++){
    int nx = i + dx[k];
    int ny = j + dy[k];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;
    else {
      int num = abs(arr[i][j] - arr[nx][ny]);
      if(num >= x && num <= y){
        check[nx][ny] = true;
        value += dfs(nx, ny);
      }
    }
  }
  return value;
}


int main() {
  vector<int> ans;
  memset(check, false, sizeof(check));
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j =0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  scanf("%d %d", &x, &y);
   
  for(int i=0; i<n; i++){
    for(int j =0; j<m; j++){
      if(!check[i][j]){
        weight = 0;
        int value = dfs(i,j);
        if(value > 1){ 
          ans.push_back(weight/value);
        }
      }
    }
  }
  
  if(ans.size() == 0){
    printf("-1\n");
    return 0;
  }
  
  sort(ans.begin(), ans.end(), greater<>());
  
  for(int i=0; i<ans.size(); i++){
    printf("%d\n", ans[i]);
  }

  return 0;
}