#include<iostream>

using namespace std;

int main(){
    double n;
    while(cin>>n){
        double b_x, b_y, b_z;
        b_x = n/5;
        b_y = n/3;
        b_z = n*3;
        for(int x = 0; x <= b_x; x++)
            for(int y = 0; y <= b_y; y++)
                for(int z = 0; z <= b_z; z++){
                    if(x+y+z == 100 && 5*x+3*y+z/3 < n){
                        cout<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
                    }
                }
    }
    return 0;
}