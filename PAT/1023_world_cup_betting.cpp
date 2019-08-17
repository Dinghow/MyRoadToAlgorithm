#include<iostream>

using namespace std;

float arr1[3],arr2[3],arr3[3];
char maps[3] = {'W','T','L'};

int findMax(float arr[],int n){
    float max = arr[0];
    int index = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int main(){
    for(int i = 0; i < 3; i++) cin>>arr1[i];
    for(int i = 0; i < 3; i++) cin>>arr2[i];
    for(int i = 0; i < 3; i++) cin>>arr3[i];

    int x = findMax(arr1, 3), y = findMax(arr2, 3), z = findMax(arr3, 3);
    cout<<maps[x]<<" "<<maps[y]<<" "<<maps[z]<<" ";
    printf("%.2f",(arr1[x]*arr2[y]*arr3[z]*0.65-1)*2);

    return 0;
}