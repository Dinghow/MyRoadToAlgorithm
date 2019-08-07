#include<iostream>
#include<map>

using namespace std;

int main(){
    int M,N;
    map<int, int> img;
    
    cin>>M>>N;
    
    for(int i = 0;i<M;i++)
        for(int j =0;j<N;j++){
            int temp;
            cin>>temp;
            img[temp]++;
            if(img[temp]>M*N/2){
                cout<<temp;
                return 0;
            }
        }
    return 0;
}