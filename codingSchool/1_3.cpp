/*회전 알고리즘*/
#include <stdio.h>

int main() {
  int n, q,d,y,x;
  int arr[100];
  
  scanf("%d %d", &n, &q);
  
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  x=0;
  for(int i=0; i<q; i++){
    scanf("%d %d", &d, &y);
    if(d == 2){
      x = (n+x-(y%n))%n;
    }else{
      x = (x+y)%n;
    }
    printf("%d\n",arr[x]);
  }

  return 0;
}