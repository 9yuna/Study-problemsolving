/*42860번 조이스틱

: 각 알파벳의 위, 아래 이동 값 중 작은 값을 answer에 더함
모든 문자가 'A'인 temp 변수 생성
반복문1
    temp의 i번 위치의 값을 name과 동일하게 변경
    temp와 name이 같으면, 반복문1 종료
    반복문2(왼쪽으로 이동해야하는지, 오른쪽으로 이동해야하는지 계산)
        왼쪽으로 이동(i에 move값을 더해서 name길이로 나눈 나머지 값)
        오른쪽으로 이동(i에 name길이를 더하고 move값을 빼고 name길이로 나눈 나머지 값)
        둘 중 짧은 쪽으로 이동 후 이동횟수를 answer에 더함

*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0, arr[20], len = name.size();
    string temp(len, 'A');

    for(int a = 0; a < len; a++){
        answer += min(name[a]-'A', 'Z'-name[a]+1);
    }

    while(true){
        temp[i] = name[i];
        
        if(temp == name) break;

        for(int move = 1; move < len; move++){
            if(name[(i+move) % len] != temp[(i+move)%len]){
                i = (i+move)%len;
                answer += move;
                break;
            }
            else if(name[(i+len-move)%len] != temp[(i+len-move)%len]){
                i = (i+len-move)%len;
                answer += move;
                break;
            }
        }
    }
    return answer;
}

int main(){
    cout << solution("BBAABB")<<"\n";
    cout << solution("ABABAAAAABA")<<"\n";
    return 0;
}