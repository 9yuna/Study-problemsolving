/*구명보트*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0, front = 0, end = people.size() - 1;
    
    while(front <= end){
        if(people[front] + people[end] <= limit){
            front++;
            end--;
        }else{
            end--;
        }
        answer++;
    }
    
    return answer;
}