#include<iostream>

using namespace std;

int main(){
    string number;
    int i = 0;
    bool zero_flag = true;
    cin>>number;
    if(number[0]=='-'){
        cout << "Fu ";
        i = 1;
    }
    for(i;i<number.length();i++){
        int pos = number.length()-i;
        if(number.length()==1 && number[i]=='0') cout<<"ling ";
        if(i>1){
           if(number[i]!='0' && number[i-1]=='0'){
               if(pos != 4) cout<<"ling ";
               if(pos == 4 && zero_flag) cout<<"ling ";
           }
        }
        switch(number[i]){
            case '1':
                cout<<"yi ";
                break;
            case '2':
                cout<<"er ";
                break;
            case '3':
                cout<<"san ";
                break;
            case '4':
                cout<<"si ";
                break;
            case '5':
                cout<<"wu ";
                break;
            case '6':
                cout<<"liu ";
                break;
            case '7':
                cout<<"qi ";
                break;
            case '8':
                cout<<"ba ";
                break;
            case '9':
                cout<<"jiu ";
                break;
        }
        if(pos == 9) cout<<"Yi ";
        if(pos == 5){
            if(number.length()<9) cout<<"Wan ";
            else if(!zero_flag) cout<<"Wan ";
        } 
        if(number[i]!='0'){
            if(pos != 9) zero_flag = false;
            if(pos == 8 || pos == 4) cout<<"Qian ";
            if(pos == 7 || pos == 3) cout<<"Bai ";
            if(pos == 6 || pos == 2) cout<<"Shi ";
        }
    }
    
    return 0;
}