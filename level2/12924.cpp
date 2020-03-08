/* 12924번 숫자의 표현 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, nums = 1, sum = 0;
    while(true){
        sum = 0;
        for(int i = 1; i <= nums; i++) sum += i;
        if(sum > n) break;
        if((n - sum)%nums++ == 0) answer++;
    }
    return answer;
}

int main(){
    cout << solution(15)<<"\n";
    return 0;
}