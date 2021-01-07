/*중복조회2*/
#include <stdio.h>
#include <string.h>

int main() {
  int n, x, y, sum=0;
  int arr[101][101];
  memset(arr, 0, sizeof(arr));
  
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d %d", &x, &y);
    if(arr[x][y] == 0){
      sum += i;
      arr[x][y]++;
    }
  }
  
  printf("%d\n", sum);
  return 0;
}