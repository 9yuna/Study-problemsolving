/*수영장청소A*/
#include <stdio.h>

int n, k, cnt=0;
int arr[5];
int degree[4] = {0, 90, 180, 270};
bool isFinished = false;

void getResult(int index){
  if(isFinished) return;
  
  if(index >= n){
    cnt++;
    
    if(cnt == k){
      for(int i=0; i<n; i++){
        printf("%d ", degree[arr[i]]);
      }
      printf("\n");
      isFinished = true;
    }
  }
  else{
    for(int i=0; i<4; i++){
      arr[index] = i;
      getResult(index+1);
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  getResult(0);
  
  return 0;
}