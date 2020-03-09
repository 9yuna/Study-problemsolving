#include <iostream>

using namespace std;

int main(){
    int array[10] = {1,10,5,8,7,6,4,3,2,9};

    for(int i = 0; i<10; i++){
        int min = 999, min_idx = 0;
        for(int j = i; j<10; j++){
            if(min > array[j]){
                min = array[j];
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = min;
        array[min_idx] = temp;
    }

    for(int i = 0; i<10; i++){
        cout << array[i] <<" ";
    }

    return 0;
}