
#include <iostream>

using namespace std;

int main(){
    int n, score, min = 1000, max = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> score;
        min = score < min ? score : min;
        max = score > max ? score : max;
    }
    printf("%d\n", max - min);
    return 0;
}