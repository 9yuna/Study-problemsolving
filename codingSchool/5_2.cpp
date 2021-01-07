/*3차원 배열 사용*/
#include <stdio.h>

int main() {
  int n, m, q, t, x, y, w;
  int arr[101][101][101];
  
  scanf("%d %d %d", &n, &m, &q);
  
  for(int k=0; k<q; k++){
    scanf("%d", &t);
    if(t == 1){ // 가장 위 = 0번
      scanf("%d %d %d", &x, &y, &w);
      int cnt = 0;
      for(cnt = 0; cnt<101; cnt++){
        if(arr[x][y][cnt] == 0){
          break;
        }
      }
      
      for(int i=cnt+1; i>0; i--){
        arr[x][y][i] = arr[x][y][i-1];
      }
      arr[x][y][0] = w;
      
    } else if(t == 2){ // 가장 아래 = 마지막
      scanf("%d %d %d", &x, &y, &w);
      
      for(int i=0; i<101; i++){
        if(arr[x][y][i] == 0){
          arr[x][y][i] = w;
          break;
        }
      }
      
    }else if(t==3){
      scanf("%d %d", &x, &y);
      for(int i=0; i<101; i++){
        arr[x][y][i] = arr[x][y][i+1];
        if(arr[x][y][i] == 0) break;
      }
    } else {
      scanf("%d %d", &x, &y);
      printf("%d\n", arr[x][y][0]);
    }
  }
  
  return 0;
}