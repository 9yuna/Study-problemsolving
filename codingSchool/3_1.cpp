/*밀기 알고리즘*/
#include <stdio.h>

int main() {
  int n,m,q,f,x,y;
  int arr[1000][1000];
  
  scanf("%d %d %d", &n, &m, &q);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int k=0; k<q; k++){
    scanf("%d %d %d", &f, &x, &y);
    if(x == 1){
      for(int i=0; i<y; i++){
        int temp = arr[f][m-1];
        for(int j=m-1; j>0; j--){
          arr[f][j] = arr[f][j-1];
        }
        arr[f][0] = temp;
      }
    } else {
      for(int i=0; i<y; i++){
        int temp = arr[f][0];
        for(int j=0; j<m-1;j++){
          arr[f][j] = arr[f][j+1];
        }
        arr[f][m-1] = temp;
      }
    }
    
    for(int i=0; i<m; i++){
      printf("%d ", arr[f][i]);
    }
    printf("\n");
  }
  
  return 0;
}