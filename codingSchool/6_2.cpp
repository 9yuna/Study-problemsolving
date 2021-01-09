/*알파윷B*/
#include <stdio.h>

int main() {
  int n;
  int arr[25] = {0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 55, 60, 65, 70, 75, 80, 85, 90, 95, 500, 1000};
  int k=0;
  
  scanf("%d", &n);
  
  for(int i=0; i<n; i++){
    int move;
    scanf("%d", &move);
    k= k+ move;
    if(k>21) k = 21;
    printf("%d ", arr[k]);
    if(k>20) break;
  }
  
  return 0;
}