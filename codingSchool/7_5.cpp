/*수영장청소E*/
#include <stdio.h>

const int MAX = 15;
int n, m, result;
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

int opening(int x, int y, int rotate){
  int valIndex = arr[x][y];
  int myDir[4] = {0,};
  int ans = 0; 
  
  for(int i=0; i<4; i++) myDir[i] = dir[valIndex][i];
  
  for(int i =0; i<rotate; i++){
    int temp = myDir[3];
    for(int j=3; j>=1; j--){
      myDir[j] = myDir[j-1];
    }
    myDir[0] = temp;
  }
  
  for(int i=0; i<4; i++){
    if(myDir[i] == 1){
      int curX = x, curY = y;
      
      while(true){
        curX += dx[i];
        curY += dy[i];
        
        if(curX < 0 || curX >=n || curY<0 || curY>=m) break;
        
        if(arr[curX][curY] == 0) ans++;
        else if(arr[curX][curY] == 6){
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  result = -1; 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] >= 1 && arr[i][j]<=5){
        for(int k=0; k<4; k++){
          int value = opening(i, j, k);
          if(value > result) result = value;
        }
      }
    }
  }
  
  printf("%d\n", result);

  return 0;
}