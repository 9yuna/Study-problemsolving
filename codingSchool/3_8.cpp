/*공기청정기*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int Tc, r, c, s, k;
  int arr[100][100], sum[100][100];
  int divs[4] = {1, 5, 13, 25}, air[2] = {0,0};
  
  scanf("%d", &Tc);
  for(int T=1; T<=Tc; T++){
    scanf("%d %d %d %d", &r, &c, &s, &k);
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    memset(air, 0, sizeof(air));
    
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        scanf("%d", &arr[i][j]);
        if(arr[i][j] == -1 && air[0] == 0){
          air[0] = i;
          air[1] = i+1;
        }
      }
    }
    
    int div = divs[k];
    for(int time = 0; time<s; time++){
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
          int cnt=0;
          if(arr[i][j] >= div){
            for(int x = i-k; x<= i+k; x++){
              if(x<0 || x>=r) continue;
              for(int y = j-k; y<= j+k; y++){
                if(y<0 || y>=c) continue;
                if(x == i && y == j) continue;
                if(arr[x][y] == -1) continue;
                if(abs(i-x) + abs(j-y) <= k){
                  sum[x][y] += (arr[i][j]/div);
                  cnt++;
                }
              }
            }
            arr[i][j] -= (arr[i][j]/div)*cnt;
          }
        }
      }
      
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
          arr[i][j] += sum[i][j];
          sum[i][j]=0;
        }
      }
      
      for(int i=air[0]-1; i>0; i--) arr[i][c-1] = arr[i-1][c-1];
      for(int j=c-1; j>0; j--) arr[0][j] = arr[0][j-1];
      for(int i=0; i<=air[0]; i++) arr[i][0] = arr[i+1][0];
      for(int j=0; j<c-2; j++) arr[air[0]][j]= arr[air[0]][j+1];
      arr[air[0]][c-2] = 0;
      
      for(int i = air[1]+1; i<r; i++) arr[i][c-1] = arr[i+1][c-1];
      for(int j=c-1; j>0; j--) arr[r-1][j] = arr[r-1][j-1];
      for(int i=r-1; i>=air[1]; i--) arr[i][0] = arr[i-1][0];
      for(int j=0; j<c-2; j++) arr[air[1]][j] = arr[air[1]][j+1];
      arr[air[1]][c-2] = 0;
    }
    
    int result = 2;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        result+=arr[i][j];
      }
    }
    
    printf("#%d %d\n", T, result);
  }
  return 0;
}