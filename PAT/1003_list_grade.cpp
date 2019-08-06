#include<iostream>
#include<stdio.h>
#include <algorithm>

using namespace std;
struct Student{
    string name;
    string id;
    int score;
}stu[10000];

bool cmp(Student x, Student y){
    return x.score > y.score;
}

int main(){
    int N;
    int grade1,grade2;
    bool empty_flag = true;

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>stu[i].name>>stu[i].id>>stu[i].score;
    }
    cin>>grade1>>grade2;

    sort(stu,stu+N,cmp);
    for(int i = 0; i < N; i++){
        if(stu[i].score>=grade1 && stu[i].score<=grade2){
            empty_flag = false;
            cout<<stu[i].name<<" "<<stu[i].id<<endl;
        }
    }
    if(empty_flag) cout<<"NONE";

    return 0;
}