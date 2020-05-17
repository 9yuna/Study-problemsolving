

#include <iostream>

using namespace std;

int main(){
    int n, m;
    int arr[100] = {0,};

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum <= m){
                    result = sum > result ? sum : result;
                }
            }
        }
    }

    printf("%d\n", result);
    return 0;
}