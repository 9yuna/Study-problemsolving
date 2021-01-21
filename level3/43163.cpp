/*단어변환*/
#include <string>
#include <vector>

using namespace std;

int answer = 100;
string str;
bool check[51];

void dfs(string begin, vector<string>& words, int result){
    if(str == begin){
        answer = min(answer, result);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        int count = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(begin[j] != words[i][j]) count++;
            if(count == 2) break;
        }
        if(count == 1){
            if(!check[i]){
                check[i] = true;
                dfs(words[i], words, result+1);
                check[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    str = target;
    dfs(begin, words, 0);
    if(answer == 100) answer = 0;
    return answer;
}