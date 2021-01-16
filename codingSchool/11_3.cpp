/*슬라임c*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, x, y, result;
int arr[50][50];
bool check[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int i, int j){
    int value = 1;
    check[i][j] = true;

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
        int value = dfs(i,j);
        if(value > 1) result += value;
      }
    }
  }
  
  printf("%d\n", result);

  return 0;
}