/*1829번 카카오프렌즈 컬러링북

: bfs를 활용하여 문제 해결
check 2차원 배열을 생성하여 picture값을 복사함
2차원 배열을 전체 탐색
    picture과 check의 값이 모두 0이 아닐때, 
        number_of_area의 값 증가
        bfs 함수 호출
        리턴된 값이 최대 값인지 확인하여 큰 값 저장
bfs 함수
    현재 위치를 queue에 넣음
    queue 빌 때까지 반복문 진행
        현재 위치에서 상하좌우의 위치 값이 같으면 queue에 넣음

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int M,N;
vector<vector<int>> check;

int bfs(int x, int y, int num){
    queue<pair<int, int>> q;
    int result = 1;
    check[x][y] = 0;
    q.push(make_pair(x,y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx <M && ny>=0 && ny<N){
                if(check[nx][ny] == num){
                    check[nx][ny] = 0;
                    result++;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    check = picture;
    M = m; N = n;

    for(int i=0; i<m; i++){
        for(int j = 0; j<n;j++){
            if(picture[i][j]!=0 && check[i][j]!=0){
                number_of_area++;
                int temp = bfs(i, j, picture[i][j]);
                if(max_size_of_one_area < temp) max_size_of_one_area = temp;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<vector<int>> p = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

    vector<int> ans = solution(6,4,p);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }
    return 0;
}