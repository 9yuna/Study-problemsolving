/*42883번 큰 수 만들기*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size();

    for(int i = 0; i < size - k; i++){
        string max = "0";
        int max_idx = 0;

        for(int j = 0; j < number.size() - size + k + i +1; j++){
            if(max < number.substr(j,1)){
                max = number.substr(j,1);
                max_idx = j;
                if(max == "9") break;
            }
        }
        answer += max;
        number = number.substr(max_idx+1);
    }
    return answer;
}

int main(){
    cout << solution("1924", 2)<<"\n";
    cout << solution("1231234", 3)<<"\n";
    cout << solution("4177252841", 4)<<"\n";
    return 0;
}