/*중복조회*/
#include <stdio.h>
#include <string.h>

int main() {
  int n, x, y, cnt=0;
  int arr[101][101];
  memset(arr, 0, sizeof(arr));
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &x, &y);
    arr[x][y]++;
    if(arr[x][y] > 1){
      if(arr[x][y] == 2){
        cnt+=2;
      }
      else{
        cnt++;
      }
    }
  }
  printf("%d\n", n-cnt);
  return 0;
}