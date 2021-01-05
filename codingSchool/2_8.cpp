/*회전탑*/
#include <stdio.h>
#include <string.h>

int main() {
  int T;
  int n, m, k, a,d,c, answer;
  int arr[52][52];
  int check[52][52];
  
  scanf("%d", &T);
  
  for(int Tc=1; Tc<=T; Tc++){
    answer=0;
    memset(arr,0,sizeof(arr));
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=1; i<n+1; i++){
      for(int j=1; j<m+1; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    
    for(int cnt=0; cnt<k; cnt++){
      scanf("%d %d %d", &a, &d, &c);
      if(d==0){
        for(int count=0; count<c; count++){
          for(int i=a; i<n+1; i=i+a){
            int temp = arr[i][m];
            for(int j=m; j>1; j--){
              arr[i][j] = arr[i][j-1];
            }
            arr[i][1] = temp;
          }
        }
      } else{
        for(int count=0; count<c; count++){
          for(int i=a; i<n+1; i=i+a){
            int temp = arr[i][1];
            for(int j=1; j<m; j++){
              arr[i][j] = arr[i][j+1];
            }
            arr[i][m] = temp;
          }
        }
      }
      
      int tempLeft, tempRight;
      
      for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
          tempLeft = j-1;
          tempRight = j+1;
          
          if(j==1) tempLeft = m;
          if(j==m) tempRight = 1;
          
          if(arr[i][j] != 0 && (arr[i][j]==arr[i-1][j] || arr[i][j] == arr[i+1][j] || arr[i][j] == arr[i][tempLeft] || arr[i][j] == arr[i][tempRight])){
            check[i][j] = 1;
          } else{
            check[i][j] = 0;
          }
        }
      }
      
      int remove = 0, sum=0, sum_cnt=0;
      for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
          if(check[i][j]==1){
            remove++;
            arr[i][j] = 0;
          }else if(check[i][j] == 0 && arr[i][j] != 0){
            sum += arr[i][j];
            sum_cnt++;
          }
        }
      }
      
      if(remove == 0){
        int avg = (sum/sum_cnt);
        for(int i=1; i<n+1; i++){
          for(int j=1; j<m+1; j++){
            if(arr[i][j]!=0){
              if(arr[i][j] > avg){  
                arr[i][j]--;
              }else if(arr[i][j] < avg){
                arr[i][j]++;
              }
            }
          }
        }
      }
    }
    
    for(int i=1; i<n+1; i++){
      for(int j=1; j<m+1; j++){
        answer+=arr[i][j];
      }
    }
    
    printf("#%d %d\n", Tc, answer);
    
  }
  
  return 0;
}