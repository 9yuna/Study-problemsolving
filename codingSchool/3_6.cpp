/*n칸 확산*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m, k, t;
  int arr[20][20], sum[20][20];
  
  scanf("%d %d %d", &n, &m, &k);
  for(int i=4; i<n+4; i++){
    for(int j=4; j<m+4; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  scanf("%d", &t);
  
  for(int time=0; time<t; time++){
    for(int i=4; i<n+4; i++){
      for(int j=4; j<m+4; j++){
        for(int x = i-k; x<= i+k; x++){
          if(x<4 || x>n+4) continue;
          for(int y=j-k; y<=j+k; y++){
            if(y<4 || y> m+4) continue;
            
            int dist = abs(x-i) + abs(y-j);
            if(dist <= k){
              sum[x][y] += arr[i][j];
            }
          }
        }
      }
    }
    for(int i=4; i<n+4; i++){
      for(int j=4; j<m+4; j++){
        arr[i][j] = sum[i][j];
        sum[i][j]=0;
      }
    }
  }
  
  for(int i=4; i<n+4; i++){
    for(int j=4; j<m+4; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}