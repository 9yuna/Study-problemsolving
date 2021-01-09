/*수영장B*/
#include <stdio.h>

const int MAX = 15;
int n, m;
int arr[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[6][4] = {
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 1, 0},
  {1, 1, 0, 0},
  {1, 1, 0, 1},
  {1, 1, 1, 1}
};

void opening(int x, int y){
  int valIndex = arr[x][y];
  
  for(int i=0; i<4; i++){
    if(dir[valIndex][i] == 1){
      int curX = x, curY = y;
      
      while(true){
        curX += dx[i];
        curY += dy[i];
        
        if(curX < 0 || curX >=n || curY<0 || curY>=m) break;
        
        if(arr[curX][curY] == 0) arr[curX][curY] = 8;
        else break;
      }
    }
  }
  return;
}

int main() {
  scanf("%d %d", &n, &m);
  
  int x, y;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j]>=1 && arr[i][j] <=5){
        x = i;
        y = j;
      }
    }
  }
  
  opening(x, y);
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}