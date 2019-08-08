#include<iostream>
#include<stack>

using namespace std;

char format(int c){
    if(c>=0 && c<=9) return c+'0';
    else if(c==10) return 'A';
    else if(c==11) return 'B';
    else if (c==12) return 'C';
}

void thirSys(int dec){
    stack<char> temp;
    while(dec!=0){
        char rem = format(dec%13);
        temp.push(rem);
        dec/=13;
    }
    if(temp.size()==1) cout<<'0';
    while(!temp.empty()){
        cout<<temp.top();
        temp.pop();
    }
}

int main(){
    int mars[3];
    cout<<'#';
    for(int i = 0;i<3;i++){
        cin>> mars[i];
        thirSys(mars[i]);
    }
}
