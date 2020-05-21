
#include <iostream>

using namespace std;

int main(){
    int n, arr[100], answer[100], sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    answer[0] = arr[0];
    sum += arr[0];
    for(int i = 1; i<n; i++){
        answer[i] = arr[i]*(i+1) - sum;
        sum += answer[i];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", answer[i]);
    }
    return 0;
}