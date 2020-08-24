/* 43162번 네트워크*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> check;

void dfs(vector<vector<int>> computers, int where){
    check[where] = true;

    for(int i = 0; i<computers.size(); i++) {
        if(check[i]==true || computers[where][i] == 0) continue;
        else dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        check.push_back(false);
    }

    for(int i=0; i<n; i++){
        if(check[i] == false){
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> vec = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << solution(3, vec) <<"\n";
    return 0;
}