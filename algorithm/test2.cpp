#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int k, vector<int> score){
    int answer = 0;

    vector<int> aa;
    for(int i =0; i<score.size()-1; i++){
        int sub = score[i] - score[i+1];
        aa.push_back(sub);
    }

    sort(aa.rbegin(), aa.rend());

    vector<int> find;
    int cnt = 1;


    for(int i =0; i<aa.size()-1; i++){
        if(aa[i] == aa[i+1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        if(cnt >= k){
            find.push_back(aa[i]);
        }
    }

    find.erase(unique(find.begin(), find.end()), find.end());

    vector<int> index;
    for(int i =0; i<find.size(); i++){
        int stand = find[i];
        for(int j =0; j<score.size()-1; j++){
            int sub = score[j] - score[j+1];
            if(stand == sub){
                index.push_back(j);
                index.push_back(j+1);
            }
        }
    }

    cout << "index1 : ";
    for(int i =0; i<index.size(); i++){
        cout << index[i] << " ";
    }
    cout << "\n";

    sort(index.begin(), index.end());
    index.erase(unique(index.begin(), index.end()), index.end());

    cout << "index2 : ";
    for(int i =0; i<index.size(); i++){
        cout << index[i] << " ";
    }
    cout << "\n";

    answer = score.size() - index.size();

    return 0;
}


int main(){

    vector<int> a = {1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100};
    solution(2, a);

    return 0;

}
