#include<iostream>

using namespace std;
long int arr1[1000000];
long int arr[2000000];

int main(){
    int N,M;
    int p = 0,q = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr1[i];
    }
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>arr1[i+N];
    }
    for(int i = 0; i<M+N;i++){
        if(p<N && q<M){
            if(arr1[p] < arr1[q+N]){
                arr[i] = arr1[p];
                p++;
            }
            else{
                arr[i] = arr1[q+N];
                q++;
            }
        }
        else if(p<N){
            arr[i] = arr1[p];
            p++;
        }
        else if(q<M){
            arr[i] = arr1[q+N];
            q++;
        }
    }

    cout<<arr[(M+N-1)/2];

    return 0;
}