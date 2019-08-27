#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
typedef long long LL;

using namespace std;

LL convertTen(string num, LL radix, LL limit){
    LL sum = 0;
    for(int i = 0; i < num.size(); i++){
        sum = sum*radix + (isdigit(num[i])?num[i]-'0':num[i]-'a'+10);
        if(sum<0||sum>limit) return -1;
    }
    return sum;
}

LL findRadix(string num, LL val){
    char m = *max_element(num.begin(),num.end());
    LL left = (isdigit(m)?m-'0':m-'a'+10)+1;
    LL right = max(val,left);
    while(left<=right){
        LL mid = (left+right)>>1;
        LL temp = convertTen(num, mid,val);
        if(temp == val) return mid;
        else if(temp > val || temp<0) right = mid - 1;
        else left = mid + 1;

    }
    return -1;
}

int main(){
    string N1, N2;
    int tag;
    LL rad;

    cin>>N1>>N2>>tag>>rad;
    if(tag == 2) swap(N1,N2);
    LL val = convertTen(N1, rad, LONG_LONG_MAX);
    LL radix = findRadix(N2, val);
    if(radix == -1) cout<<"Impossible";
    else cout<<radix;

    return 0;

}