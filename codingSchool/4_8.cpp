/*조회 알고리즘2*/
#include <stdio.h>

int main() {
  int n, k, t, x, y, age;
  long sum=0;
  int arr[1010][1010];
  
  scanf("%d %d %d", &n, &k, &t);
  for(int i=0; i<n; i++){
    scanf("%d %d %d", &x, &y, &age);
    if(arr[x][y] > age){
        continue;
    }else {
      if(arr[x][y] != 0){
        sum -= arr[x][y];
      }
      arr[x][y] = age;
      sum += arr[x][y];
    }
  }
  
  for(int time =0; time<t; time++){
    for(int i=0; i<k; i++){
      scanf("%d %d %d", &x, &y, &age);
      if(arr[x][y] > age){
        continue;
      }else {
        if(arr[x][y] != 0){
          sum -= arr[x][y];
        }
        arr[x][y] = age;
        sum += arr[x][y];
      }
    }
    printf("%ld\n", sum);
  }
  return 0;
}