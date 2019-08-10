#include<iostream>

using namespace std;

int counter = 0;

struct Team{
    string name;
    string password;
    bool modified;

    Team(){
        name = " ";
        password = " ";
        modified = false;
    }
}teams[1000];

void passCheck(Team& t){
    for(int i = 0; i<t.password.size();i++){
        switch(t.password[i]){
            case '1':
                t.password[i] = '@';
                t.modified = true;
                break;
            case '0':
                t.password[i] = '%';
                t.modified = true;
                break;
            case 'l':
                t.password[i] = 'L';
                t.modified = true;
                break;
            case 'O':
                t.password[i] = 'o';
                t.modified = true;
                break;
        }
    }
    if(t.modified) counter++;
}

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>teams[i].name>>teams[i].password;
        passCheck(teams[i]);
    }

    if(counter) {
        cout << counter << endl;
        for (int i = 0; i < N; i++) {
            if (teams[i].modified)
                cout << teams[i].name << " " << teams[i].password << endl;
        }
    }
    else if( N > 1) cout<<"There are "<< N <<" accounts and no account is modified"<<endl;
    else if( N == 1) cout<<"There is 1 account and no account is modified"<<endl;

    return 0;
}