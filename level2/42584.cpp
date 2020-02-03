/* 42584번 주식가격 

answer의 마지막 인덱스 값은 무조건 0
prices를 뒤에서부터 탐색
    현재 위치 값을 cur 변수에 넣음
    cur이 prices의 다음배열 값보다 크면, answer의 현재 위치 값은 1
    cur값이 작거나 같으면,
        checkIdx에 answer[i+1]과 현재 위치 +1 값을 넣는다.
        checkIdx값이 pSize-1보다 작고 cur값이 price[checkIdx]값과 같거나 작으면,
            checkIdx에 answer[checkIdx]를 넣음
        answer[i]에 checkIdx - i를 넣음 

시간 : 50분
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int pSize = prices.size();
    vector<int> answer(pSize);
    answer[pSize-1] = 0;

    for(int i = pSize -2; i>= 0; i--){
        int cur = prices[i];
        
        if(cur > prices[i+1]){
            answer[i] = 1;
            continue;
        }

        int checkIdx = answer[i+1]+i+1;
        while(checkIdx < (pSize-1) && cur <= prices[checkIdx]){
            checkIdx += answer[checkIdx];
        }
        answer[i] = checkIdx - i;
    }
    return answer;
}

int main(){
    vector<int> p = {1, 2, 3, 2, 3};
    vector<int> ans = solution(p);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i]<<" ";
    }
    return 0;
}