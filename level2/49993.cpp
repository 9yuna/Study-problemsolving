/* 49993번 스킬트리 

스킬트리에서 선행스킬을 check에 저장
check와 선행스킬 순서 비교
    현재 스킬이 일치하면, 이전에 배워야하는 스킬이 있는지 확인
    이전에 배워야하는 스킬이 있는데 배우지 않았다면, pass 를 false로 변경
pass값이 true이면, answer값 증가

시간 : 40분
*/
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> check;
    
    for(int i = 0; i<skill_trees.size(); i++){
        for(int j = 0; j<skill_trees[i].size(); j++){
            for(int k = 0; k<skill.size(); k++){
                if(skill_trees[i][j] == skill[k]){
                    check.push_back(skill_trees[i][j]);
                    break;
                }
            }
        }
    
    bool pass = true;
    
    for(int i = 0; i<check.size(); i++){
        for(int j = 0; j<skill.size(); j++){
            if(check[i] == skill[j]){
                if(check[i-1] != skill[j-1]){
                    pass = false;
                    break;
                }
            }
        }
    }
    check.clear();
    if(pass) answer++;
    }
    return answer;
}