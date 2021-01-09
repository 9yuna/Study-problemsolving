/*알파윷D*/
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
int arr_check[35];
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

int horse[5]={0,0,0,0,0};
int move[10];


int main() {
  int n;
  scanf("%d", &n);
  memset(arr_check, 0, sizeof(arr_check));
  
  for(int i=0; i<11; i++){
    for(int j=1; j<=5; j++){
      moving[temp[i][0]][j] = temp[i][j];
    }
  }
  
  for(int i =0; i<n; i++){
    scanf("%d", &move[i]);
  }
  
  for(int i=0; i<n; i++){
    int horse_num;
    scanf("%d", &horse_num);
    
    int index = horse[horse_num];
    int m = move[i];
    bool flag = false;
    
    for(int j=0; j<11; j++){
      if(index == temp[j][0]){
        flag = true;
        break;
      }
    }
    
    arr_check[index]=0;
    if(flag){
      index = moving[index][m];
    } else{
      index += m;
      if(index >= 21) index = 21;
    }
    
    if(arr_check[index] != 0){
      printf("-1\n");
      return 0;
    }
    arr_check[index] = 1;
    if(index == 21){
      arr_check[index] = 0;
    }
    horse[horse_num] = index;
  }
  
  int sum = 0;
  for(int i=1; i<=4; i++){
    sum += (arr[horse[i]]);
  }
  
  printf("%d\n", sum);
  
  return 0;
}