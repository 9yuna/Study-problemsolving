/* 42578번 위장*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(vector<string> i: clothes)
        m[i[1]]++;
    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++){
        answer *= (iter->second+1);
    }
    return (answer-1);
}

int main(){
    vector<vector<string>> vec = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(vec)<<"\n";
    return 0;
}