/*42585번 쇠막대기

()인 레이저가 있을 때, 레이저를 제외한 (의 개수가 나누어진 쇠막대의 개수가된다.
따라서 (이 있을 때, cnt의 값을 증가시키고
)인 경우 cnt의 값을 감소시킨다.
    이전 값이 '('이면 answer에 cnt값을 더하고
    아니면, answer에 1을 더한다.( 막대의 끝이라서 )

시간 : 20분

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0, cnt=0;

    for(int i = 0; i < arrangement.size(); i++){
        if(arrangement[i] == '('){
            cnt++;
        }
        else{
            cnt--;
            if(arrangement[i-1]=='('){
                answer+=cnt;
            }
            else{
                answer++;
            }
            
        }
    }

    return answer;
}

int main(){
    cout <<solution("()(((()())(())()))(())")<<"\n";
    return 0;
}