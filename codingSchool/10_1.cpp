/*코치배정A*/
#include <stdio.h>

int n, k, t, cnt;
int arr[10];
int selected[10];

void getResult(int idx){
  if(idx >= k){
    cnt++;
    if(cnt == t){
      int ans = 0;
      for(int i=0; i<k; i++){
        ans += arr[selected[i]];
      }
      printf("%d\n", ans);
      return;
    }
  }else{
    for(int i=0; i<n; i++){
      if(idx == 0 || selected[idx-1] < i){
        selected[idx] = i;
        getResult(idx+1);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &t);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  cnt=0;
  getResult(0);
  
  return 0;
}