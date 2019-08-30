#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>

using namespace std;

map<char, int> op_map;
int pri[][5]={{0,1,1,1,1},{0,0,0,1,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,0}};

double getNum(vector<char>& n){
    double sum = 0;
    for(int i = 0; i < n.size(); i++){
        sum = sum*10 + n[i]-'0';
    }
    return sum;
}

int main(){
    op_map['%']=0, op_map['+'] = 1, op_map['-'] = 2, op_map['*'] = 3, op_map['/'] = 4;
    string str;
    while(getline(cin,str)){
        if(str == "0") break;
        str += "%";
        stack<char> op;
        stack<double> nu;
        op.push('%');
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9') {
                vector<char> tmp;
                while (str[i] >= '0' && str[i] <= '9') {
                    tmp.push_back(str[i]);
                    i++;
                }
                i--;
                double num = getNum(tmp);
                nu.push(num);
            }else if(str[i]!=' '){
                while(1) {
                    char opr = str[i];
                    char s_top = op.top();
                    if(op.top()=='%'&&str[i]=='%') break;
                    if (pri[op_map[s_top]][op_map[opr]]) {
                        op.push(opr);
                        break;
                    }else {
                        double op1, op2, ans;
                        op1 = nu.top();
                        nu.pop();
                        op2 = nu.top();
                        nu.pop();
                        if (s_top == '+') ans = op1 + op2;
                        else if (s_top == '-') ans = op2 - op1;
                        else if (s_top == '*') ans = op1 * op2;
                        else if (s_top == '/') ans = op2 / op1;
                        nu.push(ans);
                        op.pop();
                    }
                }
            }
        }
        printf("%.2f\n", nu.top());
    }

    return 0;
}