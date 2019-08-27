#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct Time{
    int h;
    int m;
    int s;
};

struct Person{
    string id;
    Time in;
    Time out;
}p[1000];

bool s_in(Person &a, Person &b){
    if(a.in.h != b.in.h) return a.in.h < b.in.h;
    else if(a.in.m != b.in.m) return a.in.m < b.in.m;
    else return a.in.s < b.in.s;
}

bool s_out(Person &a, Person &b){
    if(a.out.h != b.out.h) return a.out.h > b.out.h;
    else if(a.out.m != b.out.m) return a.out.m > b.out.m;
    else return a.out.s > b.out.s;
}

int main(){
    int M;
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>p[i].id;
        scanf("%d:%d:%d %d:%d:%d",&p[i].in.h,&p[i].in.m,&p[i].in.s,&p[i].out.h,&p[i].out.m,&p[i].out.s);
    }
    sort(p,p+M,s_in);
    cout<<p[0].id<<" ";
    sort(p,p+M,s_out);
    cout<<p[0].id;

    return 0;
}