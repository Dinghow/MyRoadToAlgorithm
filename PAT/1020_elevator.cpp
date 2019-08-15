#include<iostream>

using namespace std;
int floors[10000];

int main(){
    fill(floors,floors+10000,-1);
    floors[0] = 0;
    int N;
    int sum = 0;
    cin>>N;
    for(int i = 1; i <= N; i++){
        int temp;
        cin>>temp;
        floors[i] = temp;
    }

    for(int i = 0; i < N; i++){
        sum += floors[i] > floors[i+1]? 4*(floors[i]-floors[i+1]):6*(floors[i+1]-floors[i]);
    }

    sum+=5*N;

    cout<<sum;

    return 0;
}