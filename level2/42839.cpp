/*42839번 소수 찾기 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool arr[10000000];

void prime_check(){
    for(int i = 0; i<10000000; i++) arr[i] = true;
    int j;
    arr[0] = arr[1]= false;
    for(int i = 2; i*i <= 9999999; i++){
        if(arr[i] == false) continue;
        for(j = i+i; j<=9999999; j+=i){
            arr[j] = false;
        }
    }
}

int solution(string numbers) {
    prime_check();
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    set<int>set_num;
    set<int>::iterator iter;
    do{
        for(int i = 1; i <= numbers.size(); i++){
            set_num.insert(stoi(numbers.substr(0,i)));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    for(iter = set_num.begin(); iter != set_num.end(); iter++){
        if(arr[*iter]){
            answer++;
        }
    }
    return answer;
}

int main(){
    cout << solution("17")<<"\n";
    cout << solution("011")<<"\n";
    return 0;
}