/*42746번 가장 큰 수 

next_permutation을 활용하여 구현시, 시간 초과 발생

두 개의 string을 합친 문자 비교해서 큰 순으로 정렬
vec의 처음 숫자가 0이라면 "0"을 반환
아니면, 처음부터 끝까지 문자열을 합쳐서 반환
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    
    for(int i = 0; i<numbers.size(); i++){
        vec.push_back(to_string(numbers[i]));
    }

    sort(vec.begin(), vec.end(), cmp);

    if(vec[0]=="0") return "0";

    for(int i = 0; i<vec.size(); i++){
        answer += vec[i];
    }
    return answer;
}

int main(){
    vector<int> a = {3, 30, 34, 5, 9};
    cout << solution(a)<<"\n";
    return 0;
}