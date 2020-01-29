/*42583번 다리를 지나는 트럭

다리 위 트럭의 남은 거리에 대한 queue와 다리 위 트럭 무게에 대한 queue를 이용

다리 위 트럭 중 남은 거리가 있는지에 대한 체크를 먼저 진행
    다리 밖으로 나간다면, 거리에 대한 큐와 무게에 대한 큐에서 제외
    아직 다리 위라면, 길이를 -1하고 큐에 다시 추가

대기중인 트럭이 있다면, 다리가 무게를 견딜 수 있는지 확인
    견딜 수 있다면, 거리 큐와 무게 큐에 추가 후 truck_weights의 맨앞 삭제
    견딜 수 없다면, 패스

시간 증가

대기중인 트럭이 없고, 다리위의 트럭도 없다면, 함수종료

시간 : 60분
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, currentWeight = 0;

    queue<int> bridge_weight, bridge_truck_len;
    while (true) {
        int size = bridge_truck_len.size();
        for (int i = 0; i < size; i++){
            int length = bridge_truck_len.front();
            bridge_truck_len.pop();
            if (length <= 1) {
                currentWeight -= bridge_weight.front();
                bridge_weight.pop();
                continue;
            }
            bridge_truck_len.push(length - 1);
        }

        if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight) {
            bridge_weight.push(truck_weights.at(0));
            currentWeight += truck_weights.at(0);
            bridge_truck_len.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;

        if (truck_weights.size() == 0 && bridge_weight.size() == 0)
            break;
    }
    return answer;

}

int main(){
    vector<int> vec = {7,4,5,6};
    cout << solution(2, 10, vec)<<"\n";
    return 0;
}