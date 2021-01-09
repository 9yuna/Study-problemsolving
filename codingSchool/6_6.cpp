/*알파윷*/
#include <stdio.h>
#include <string.h>

int arr[35] = {
  0, 5, 10, 15, 20, 50,
  30, 35, 40, 45, 100, 
  55, 60, 65, 70, 75, 
  80, 85, 90, 95, 500,
  1000, 275, 250, 300, 
  150, 175, 150, 125, 350, 400
};
int moving[35][6];
int temp[15][6] = {
  {5, 22, 23, 24, 25, 26},
  {10, 27, 28, 24, 29, 30},
  {22, 23, 24, 25, 26, 15},
  {23, 24, 25, 26, 15, 16},
  {24, 29, 30, 20, 21, 21},
  {25, 26, 15, 16, 17, 18},
  {26, 15, 16, 17, 18, 19},
  {27, 28, 24, 29, 30, 20},
  {28, 24, 29, 30, 20, 21},
  {29, 30, 20, 21, 21, 21},
  {30, 20, 21, 21, 21, 21}
};
int current[5]={0,0,0,0,0};
int data[10];
int who[10];
int maxScore = -987987987;
bool isFinished = false;

int runThisGame(){
  int result = 0;
  for(int i=1; i<=4; i++) current[i] = 0;
  
  for(int i=0; i<10; i++){
    int d = data[i];
    int w = who[i];
    
    if(current[w] == 21) return -1;
    
    bool flag = false;
    
    for(int j=0; j<11; j++){
      if(current[w] == temp[j][0]){
        flag = true;
        break;
      }
    }
    
    if(flag){
      current[w] = moving[current[w]][d];
    } else{
      current[w] += d;
      if(current[w] >= 21) current[w] = 21;
    }
    
    for(int j=1; j<=4; j++){
      if(w != j && current[w] == current[j] && current[j] != 21){
        return -1;
      }
    }
  }
  
  for(int i=1; i<=4; i++){
    result += arr[current[i]];
  }
  return result;
}

void getResult(int index){
  if(index >= 10){
    int value = runThisGame();
    if(value > maxScore){
      maxScore = value;
    }
  }
  else{
    for(int i=1; i<=4; i++){
      who[index] = i;
      getResult(index+1);
    }
  }
  return;
}

int main() {
  for(int i=0; i<11; i++){
    for(int j=1; j<=5; j++){
      moving[temp[i][0]][j] = temp[i][j];
    }
  }
  
  int t;
  scanf("%d", &t);
  
  for(int i=1; i<=t; i++){
    for(int j=0; j<10; j++) scanf("%d", &data[j]);
    maxScore = -987987987;
    isFinished = false;
    getResult(0);
    
    printf("#%d %d\n", i, maxScore);
  }
  
  return 0;
}