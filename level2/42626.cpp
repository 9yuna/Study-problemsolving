/* 42626번 더 맵게*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }

    while(pq.top() < K && pq.size() > 1){
        answer++;
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();
        pq.push(first + (second*2));
    }

    if(pq.top() < K) return -1;
    return answer;
}

int main(){
    vector<int> vec = {1, 2, 3, 9, 10, 12};
    cout << solution(vec, 7)<<"\n";
    return 0;
}