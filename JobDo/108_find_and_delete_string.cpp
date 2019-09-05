#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1,str2;
    string in = "in";
    string blan = " ";
    while(getline(cin,str1)){
        str2 = str1;
        for(int i = 0; i< str2.size(); i++){
            str2[i] = tolower(str2[i]);
        }
        int pos;
        do{
            pos = str2.find(in, 0);
            if (pos != string::npos) {
                str1.erase(pos, 2);
                str2.erase(pos, 2);
            }
        }while(pos!=string::npos);
        do{
            pos = str2.find(blan, 0);
            if (pos != string::npos) {
                str1.erase(pos, 1);
                str2.erase(pos, 1);
            }
        }while(pos!=string::npos);

        cout<<str1<<endl;
    }

    return 0;
}