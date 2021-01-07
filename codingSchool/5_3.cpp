/*밀기 알고리즘3*/
#include <stdio.h>

int main() {
  int n, m, q, t, x, y, w, c;
  int arr[101][101][101];
  
  scanf("%d %d %d", &n, &m, &q);
  for(int k=0; k<q; k++){
    scanf("%d", &t);
    if(t == 1){ // 가장 위 = 0
      scanf("%d %d %d %d", &x, &y, &w, &c);
      int cnt = 0;
      for(cnt = 0; cnt<101; cnt++){
        if(arr[x][y][cnt] == 0){
          break;
        }
      }
      
      for(int i=cnt*c; i>0; i--){
        arr[x][y][i] = arr[x][y][i-c];
      }
      
      for(int j=0; j<c; j++){
        arr[x][y][j] = w;
      }
    } else if(t == 2){
      scanf("%d %d %d %d", &x, &y, &w, &c);
      
      for(int i=0; i<101; i++){
        if(arr[x][y][i] == 0){
          for(int j=0; j<c; j++){
            arr[x][y][i+j] = w;
          }
          break;
        }
      }
      
    } else if(t == 3){
      scanf("%d %d %d", &x, &y, &c);
      for(int j=0; j<c; j++){
        for(int i=0; i<101; i++){
          arr[x][y][i] = arr[x][y][i+1];
          if(arr[x][y][i] == 0) break;
        }
      }
    }else {
      scanf("%d %d",&x, &y);
      printf("%d\n", arr[x][y][0]);
    }
  }
  return 0;
}