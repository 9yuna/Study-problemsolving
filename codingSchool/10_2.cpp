/*코치배정B*/
#include <iostream>
#include <queue>

using namespace std;

int n, m, e;
int arr[10][10];
int student[10];
bool visited[10];

int main() {
  scanf("%d %d %d\n", &n, &m, &e);
  char ch;
  for(int i=0; i<m; i++){
    scanf("%c ", &ch);
    student[i] = ch - 'A';
  }
  scanf("\n");
  for(int i=0; i<e; i++){
    char ch1, ch2;
    scanf("%c %c\n", &ch1, &ch2);
    arr[ch1 - 'A'][ch2 - 'A'] = 1;
    arr[ch2 - 'A'][ch1 - 'A'] = 1;
  }
  
  queue<int> q;
  q.push(student[0]);
  
  while(!q.empty()){
    int x = q.front();
    q.pop();
    visited[x] = true;
    
    for(int i=0; i<n; i++){
      if(arr[x][i] == 1 && visited[i] == false){
        for(int j=0; j<m; j++){
          if(i == student[j]){
            q.push(i);
          }
        }
      }
    }
  }
  
  int ans = 1;
  for(int i =0; i<m; i++){
    if(visited[student[i]] == false){
      ans = 0;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}