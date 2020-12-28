/*#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> simulation_data) {
    int answer = 0;
    int arr[20];
    int check = 0;
    int size = simulation_data.size();
    queue<int> q;
    int time = 0;

    for(int i=0; i<20; i++){
        arr[i]=0;
    }

    while(true){      
        for(int i=0; i<size; i++){
            if(simulation_data[i][0] == time){
                q.push(simulation_data[i][1]);
                check = i;
            }
        }

        for(int i=0; i<N; i++){
            if(arr[i] == 0 && !q.empty()){
                arr[i] = q.front();
                q.pop();
            }
        }

        if(!q.empty()){
            answer+= q.size();
        }

        time++;

        for(int i=0; i<N;i++){
            if(arr[i]!= 0){
                arr[i]--;
            }
        }

        if(check == size -1){
            break;
        }
    }

    while(!q.empty()){
        for(int i=0; i<N; i++){
            if(arr[i] == 0 && !q.empty()){
                arr[i] = q.front();
                q.pop();
            }
        }

        if(!q.empty()){
            answer+= q.size();
        }

        time++;

        for(int i=0; i<N;i++){
            if(arr[i]!= 0){
                arr[i]--;
            }
        }
    }

    return answer;
}


int main(){
    vector<vector<int>> a = {{2, 3}, {5, 4}, {6, 3}, {7, 4}};
    cout << "solution : " <<solution(1, a)<< "\n";
    return 0;
}




#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int num, vector<int> cards) {
    int answer = 0;
    reverse(cards.begin(), cards.end());
    int arr[10001] = {0,};

    for(int i =0; i<cards.size(); i++){
        arr[cards[i]] = 1;
    }

    for(int i=0; i<cards.size(); i++){
        for(int j=2; j<num; j++){
            if(cards[i]* j > num+1){
                break;
            }
            if(arr[cards[i] * j] == 0){
                arr[cards[i]*j] = j;
            }
        }
    }
    
    for(int i=0; i<=num; i++){
        for(int j=0; j<=num;j++){
            if(arr[i]!=0 && arr[j]!= 0){
                if(arr[i+j] > arr[i]+arr[j]){
                    arr[i+j] = arr[i]+arr[j];
                }
            }
        }
    }

    answer = arr[num];

    return answer;
}

int main(){
    vector<int> a = {1,4,6};
    cout << "solution : " <<solution(8, a)<< "\n";
    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<vector<int>> products) {
    long long day = 0;

    for(int i = 0; i<n; i++){
        int max =0, max_idx = 0;
        for(int j=0; j<products.size(); j++){
            if(products[j][0] >= products[j][2]){
                if((max < (products[j][2]*products[j][1])) && (products[j][0] >= products[j][2]*2)){
                    max = products[j][2]*products[j][1];
                    day += max;
                    max_idx = j;
                }
                else {
                    day+= products[j][2]*products[j][1];
                }
            }
            else {
                day += products[j][0]*products[j][1];
            }
        }

        for(int j=0; j<products.size(); j++){
            if(j != max_idx){
                products[j][0] -= products[j][2];
                if(products[j][0] < 0)
                    products[j][0] = 0;
            }
            else {
                products[j][0] -= (products[j][2]*2);
                day += (products[j][2]*products[j][1]);
            }
        }
    }

    return day;
}

int main(){
    vector<vector<int>> a = {{6, 5, 1}, {11, 3, 2}, {7, 10, 3}};
    cout << "solution : " <<solution(3, a)<< "\n";
    return 0;
}