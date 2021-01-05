/*확산 알고리즘*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m, k, t;
  int arr[5][5], sum[5][5];
  int div[5] = {1, 5, 13, 25, 41};
  
  scanf("%d %d %d", &n, &m, &k);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
      sum[i][j] = 0;
    }
  }
  scanf("%d", &t);
  
  for(int time =0; time<t; time++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        int cnt = 0, num = arr[i][j]/div[k];
      
        for(int x = i-k; x <= i+k; x++){
          if(x<0 || x>=n) continue;
          for(int y = j-k; y <= j+k; y++){
            if(y<0 || y>=m) continue;
            if(x==i && y==j) continue;
            
            if(abs(i-x) + abs(j-y) <= k){
              sum[x][y] += num;
              cnt++;
            }
          }
        }
        arr[i][j] -= (num*cnt);
      }
    }
    
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        arr[i][j] += sum[i][j];
        sum[i][j]=0;
      }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}