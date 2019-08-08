#include<iostream>
#include<algorithm>

using namespace std;
struct Student{
    int id;
    string name;
    int score;
}stu[100000];

bool cmp1(Student x, Student y){
    return x.id < y.id;
}

bool cmp2(Student x, Student y){
    if(x.name.compare(y.name)) return x.name < y.name;
    else return x.id < y.id;
}

bool cmp3(Student x, Student y){
    if(x.score != y.score) return x.score < y.score;
    else return x.id < y.id;
}

int main(){
    int N,col;

    cin>>N>>col;
    for(int i = 0; i < N; i++){
        cin>>stu[i].id>>stu[i].name>>stu[i].score;
    }

    switch(col){
        case 1:
            sort(stu,stu+N,cmp1);
            break;
        case 2:
            sort(stu,stu+N,cmp2);
            break;
        case 3:
            sort(stu,stu+N,cmp3);
            break;
    }

    for(int i = 0; i < N; i++){
        printf("%06d",stu[i].id);
        cout<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
    }

    return 0;
}