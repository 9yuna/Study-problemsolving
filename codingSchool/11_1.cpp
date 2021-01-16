/*슬라임a*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, x, y;
int arr[50][50];
int main() {
  int sum = 0, sum_cnt =0;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  scanf("%d %d", &x, &y);
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] >= x && arr[i][j] <= y){
        sum += arr[i][j];
        sum_cnt++;
      }
    }
  }
  
  if(sum_cnt == 0) printf("-1\n");
  else printf("%d\n", sum/sum_cnt);
  
  return 0;
}