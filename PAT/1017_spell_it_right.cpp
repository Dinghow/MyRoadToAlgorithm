#include<iostream>

using namespace std;

int main(){
    int temp,sum = 0,counter = 0;
    string N;
    int nums[200];

    cin>>N;

    for(int i = 0;i<N.length();i++){
        sum+= N[i]-'0';
    }

    while(sum>0){
        temp = sum%10;
        sum /= 10;
        nums[counter] = temp;
        counter++;
    }
    for(int i = counter;i>0;i--){
        int num = nums[i-1];
        if(num == 1){
            cout<<"one";
        }
        else if(num == 2){
            cout<<"two";
        }
        else if(num == 3){
            cout<<"three";
        }
        else if(num == 4){
            cout<<"four";
        }
        else if(num == 5){
            cout<<"five";
        }
        else if(num == 6){
            cout<<"six";
        }
        else if(num == 7){
            cout<<"seven";
        }
        else if(num == 8){
            cout<<"eight";
        }
        else if(num == 9){
            cout<<"nine";
        }
        else if(num == 0){
            cout<<"zero";
        }
        if(i != 1){
            cout<<" ";
        }
    }

    return 0;
}