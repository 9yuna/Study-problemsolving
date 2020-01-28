/* 42587번 프린터 

큐를 이용하여 기존의 위치와 문서 중요도 정보 저장
우선순위큐를 이용하여 중요도가 높은 문서부터 인쇄 시작

시간 : 30분
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for(int i = 0; i<priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while(!q.empty()) {
        int position = q.front().first;
        int importance = q.front().second;
        q.pop();
        
        if(importance == pq.top()) {
            pq.pop();
            answer += 1;
        
            if(position == location) {
                break;
            }
            
        } else {
            q.push(make_pair(position,importance));
        }
 
    }
    
    return answer;
}

int main(){
    vector<int> pri = {2,1,3,2};
    cout << solution(pri, 2)<<"\n";
    return 0;

}