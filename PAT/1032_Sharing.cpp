#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, int> num;
map<int, string> name;

int main(){
    char sta1[6], sta2[6], ad1[6], ad2[6];
    char tmp;
    int N;
    scanf("%s %s %d",&sta1,&sta2,&N);
    int k = 0;
    int p[100000];
    bool mark[100000];
    fill(p,p+2*N,-1);
    fill(mark,mark+2*N,false);
    for(int i = 0; i < N; i++){
        scanf("%s %c %s",&ad1,&tmp,&ad2);
        int a, b;
        map<string, int>::iterator it1, it2;
        it1 = num.find(ad1);
        if(it1 == num.end()){
            num[ad1] = k;
            name[k] = ad1;
            a = k;
            k++;
        }
        else a = it1->second;
        it2 = num.find(ad2);
        if(it2 == num.end()){
            num[ad2] = k;
            name[k] = ad2;
            b = k;
            k++;
        }
        else b = it2->second;
        p[a] = b;
    }
    int st1 = num.find(sta1)->second, st2 = num.find(sta2)->second;
    while(name[st1] != "-1"){
        mark[st1] = true;
        st1 = p[st1];
    }
    bool flag = false;
    while(name[st2] != "-1"){
        if(mark[st2]){
            flag = true;
            break;
        }
        mark[st2] = true;
        st2 = p[st2];
    }
    cout<<(flag?name[st2]:"-1")<<endl;
}