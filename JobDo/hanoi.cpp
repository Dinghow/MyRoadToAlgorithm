#include<iostream>

using namespace std;

int counter;
void hanoi(int n, char s, char m, char d){
    if(n == 1) {
        cout << "Move disk " << n << " from " << s << " to " << d << endl;
        counter++;
    }
    else{
        hanoi(n-1, s, d, m);
        cout << "Move disk " << n << " from " << s << " to " << d << endl;
        counter++;
        hanoi(n-1, m, s, d);
    }
}

int main(){
    int n;
    while(cin>>n){
        counter = 0;
        hanoi(n,'A','B','C');
        cout<<"Totally moved "<<counter<<" times"<<endl;
    }
    return 0;
}