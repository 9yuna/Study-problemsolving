/*역방향회전*/
#include <stdio.h>

int main() {
  int n, x, y;
  int arr[100];
  
  scanf("%d", &n);
  for(int i =0; i<n;i++){
    scanf("%d", &arr[i]);
  }
  scanf("%d %d", &x, &y);
  
  printf("%d", arr[(n+x-y)%n]);

  return 0;
}