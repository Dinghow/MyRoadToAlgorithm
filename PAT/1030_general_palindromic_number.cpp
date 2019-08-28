#include<iostream>
#include<vector>
typedef long long LL;

using namespace std;

int main(){
    LL n, r;
    cin>>n>>r;
    vector<LL> num;

    if(!n){
        cout<<"Yes"<<endl;
        cout<<0;
    }
    else {
        while (n > 0) {
            LL tmp = n % r;
            n /= r;
            num.push_back(tmp);
        }
        int flag = 1;
        for (int i = 0; i < num.size() / 2; i++) {
            if (num[i] != num[num.size() - i - 1]) flag = 0;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No"<<endl;
        for (int i = num.size()-1; i >= 0; i--) {
            cout << num[i];
            if (i != 0) cout << " ";
        }
    }

    return 0;
}