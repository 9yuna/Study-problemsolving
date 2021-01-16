/*슬라임*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, result, weight, scnt;
int arr[50][50];
bool check[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int group[50][50];

int dfs(int i, int j){
  int value = 1;
  check[i][j] = true;
  weight += arr[i][j];
  group[i][j] = scnt;

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
  
  int Tc;
  scanf("%d", &Tc);
  
  for(int T=1; T<= Tc; T++){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
      for(int j =0; j<m; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    scanf("%d %d", &x, &y);
    ans.push_back(1);
    int time = -1;
    
    while(ans.size() != 0){
      time++;
      scnt = 0;
      ans.clear();
      memset(check, false, sizeof(check));
      for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
          if(!check[i][j]){
            weight = 0;
            int value = dfs(i,j);
            if(value > 1){ 
              ans.push_back(weight/value);
              scnt++;
            } else{
              group[i][j] = -1;
            }
          }
        }
      }
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(group[i][j] != -1){
            arr[i][j] = ans[group[i][j]];
          }
        }
      }
    }
    
    printf("#%d %d\n",T, time);
  }
  return 0;
}