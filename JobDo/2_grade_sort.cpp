#include<iostream>
#include<stdio.h>
#include <algorithm>

using namespace std;
struct Student{
    int id;
    int score;
}stu[100];

bool cmp(Student x, Student y){
    if( x.score != y.score) return x.score < y.score;
    else return x.id < y.id;
}

int main(){
    int N;

    cin>>N;
    for(int i = 0; i < N; i++){
        scanf("%d %d",&stu[i].id,&stu[i].score);
    }
    sort(stu,stu+N,cmp);
    for(int i = 0; i < N; i++){
        cout<<stu[i].id<<" "<<stu[i].score<<endl;
    }
    return 0;
}