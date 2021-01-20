/*전화번호 목록*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i<phone_book.size(); i++){
        for(int j = i+1; j<phone_book.size(); j++){
            int size = min(phone_book[i].size(), phone_book[j].size());
            int cnt = 0;
            
            for(int k=0; k<size; k++){
                if(phone_book[i].at(k) == phone_book[j].at(k)){
                    cnt++;
                }
            }
            if(cnt == size){
                answer = false;
                break;
            }
        }
        if(!answer) break;
    }
    
    return answer;
}