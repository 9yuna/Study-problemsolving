/*알파윷c*/
#include <stdio.h>

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


int main() {
  int n, index = 0;
  scanf("%d", &n);
  
  for(int i=0; i<11; i++){
    for(int j=1; j<=5; j++){
      moving[temp[i][0]][j] = temp[i][j];
    }
  }
  
  for(int i=0; i<n; i++){
    int m;
    scanf("%d", &m);
    
    bool flag = false;
    
    for(int j=0; j<11; j++){
      if(index == temp[j][0]){
        flag = true;
        break;
      }
    }
    
    if(flag) {
      index = moving[index][m];
    } else{
      index += m;
      if(index >= 21) index = 21;
    }
    
    printf("%d ", arr[index]);
    if(index == 21) break;
  }
  return 0;
}