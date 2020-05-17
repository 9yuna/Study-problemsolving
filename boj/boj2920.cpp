

#include <iostream>

using namespace std;

int main(){
    int asc = 0, desc = 0;
    int arr[9];

    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<7; i++){
        if(arr[i] > arr[i+1]){
            desc++;
        }
        else if(arr[i] < arr[i+1]){
            asc++;
        }
    }

    if(asc == 7) {
        printf("ascending\n");
    }
    else if(desc == 7) {
        printf("descending\n");
    }
    else {
        printf("mixed\n");
    }
    return 0;
}