#include<iostream>
#include<algorithm>

using namespace std;

struct Student{
    string name;
    char gender;
    string id;
    int grade;

    Student(){
        name = " ";
        gender = ' ';
        id = " ";
        grade = 0;
    }

}males[10000], females[10000];

bool ascend(Student x, Student y){
    return x.grade < y.grade;
}

bool descend(Student x, Student y){
    return x.grade > y.grade;
}

int main(){
    int N,p = 0,q = 0;
    int abs_flag = false;

    cin>>N;
    for(int i = 0; i < N; i++){
        Student temp;
        cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
        if(temp.gender == 'F'){
            females[p] = temp;
            p++;
        }
        else{
            males[q] = temp;
            q++;
        }
    }

    sort(males,males+q,ascend);
    sort(females,females+p,descend);

    if(females[0].gender != ' ') cout<<females[0].name<<" "<<females[0].id<<endl;
    else{
        cout<<"Absent"<<endl;
        abs_flag = true;
    }
    if(males[0].gender != ' ') cout<<males[0].name<<" "<<males[0].id<<endl;
    else{
        cout<<"Absent"<<endl;
        abs_flag = true;
    }
    if(abs_flag) cout<<"NA";
    else cout<<females[0].grade-males[0].grade;

    return 0;
}