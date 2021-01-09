/*알파윷A*/
#include <stdio.h>

int arr[15];
int n, cnt;
bool isFinished = false;

void getResult(int index){
  if(isFinished == true) return;
  
  if(index >= 10){
    cnt++;
    if(n==cnt){
      for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
      }
      printf("\n");
      isFinished = true;
    }
  }
  else{
    for(int i=1; i<=4; i++){
      arr[index] = i;
      getResult(index+1);
    }
  }
}

int main() {
  scanf("%d", &n);
  getResult(0);
 
  return 0;
}