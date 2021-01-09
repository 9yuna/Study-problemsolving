/*수영장청소*/
#include <stdio.h>

const int MAX = 15;
int n, m, result, valCnt;
int arr[MAX][MAX];
int val[MAX];
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

bool isFinished = false;

int opening(int x, int y, int rotate){
  int valIndex = arr[x][y];
  int myDir[4] = {0,};
  int ans = 0; 
  
  for(int i=0; i<4; i++) myDir[i] = dir[valIndex][i];
  
  if(valIndex != 5){
    for(int i =0; i<rotate; i++){
      int temp = myDir[3];
      for(int j=3; j>=1; j--){
        myDir[j] = myDir[j-1];
      }
      myDir[0] = temp;
    }
  }
  
  for(int i=0; i<4; i++){
    if(myDir[i] == 1){
      int curX = x, curY = y;
      
      while(true){
        curX += dx[i];
        curY += dy[i];
        
        if(curX < 0 || curX >=n || curY<0 || curY>=m) break;
        
        if(arr[curX][curY] == 0){
          ans++;
          arr[curX][curY] = 8;
        }
        else if(arr[curX][curY] == 6){
          break;
        }
      }
    }
  }
  return ans;
}

void getResult(int index){
  if(index >= valCnt){
    int id = 0, sum =0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j] >= 1 && arr[i][j]<=5){
          sum += opening(i, j, val[id]);
          id++;
        }
      }
    }
    if(sum > result) result = sum;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j] == 8) arr[i][j] = 0;
      }
    }
  }
  else{
    for(int i=0; i<4; i++){
      val[index] = i;
      getResult(index+1);
    }
  }
}


int main() {
  int Tc;
  scanf("%d", &Tc);
  
  for(int T=1; T<=Tc; T++){
    result = -1;
    valCnt = 0;
    int wallCnt = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        scanf("%d", &arr[i][j]);
        if(arr[i][j]>=1 && arr[i][j] <=5) valCnt++;
        if(arr[i][j] == 6) wallCnt++;
      }
    }
    
    getResult(0);
    
    int answer = n*m - result - valCnt - wallCnt;
    if(answer<0) answer = 0;
    printf("#%d %d\n", T, answer);
  }
  return 0;
}