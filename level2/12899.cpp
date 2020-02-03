/*12899번 124 나라의 숫자

: 1,2,4가 n을 3으로 나누며
몫은 다시 n에 저장하고 n을 나눈 나머지는 string에 붙임
3으로 나눈 나머지에서 1,2는 그대로 붙이고 0이면 4를 붙임.
나머지가 0이면, 3으로 나눈 몫에서 1을 빼야함

시간 : 50분
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char digit[] = {'4','1','2'};
    int num;

    while(n>0){
        num = n%3;
        n/=3;

        if(num == 0){
            n--;
        }
        
        answer = digit[num] + answer;
    }

    return answer;
}

int main(){
    cout << solution(4);
    return 0;
}