#include<iostream>
#include<stdio.h>

using namespace std;

struct Fraction{
    long int num;
    long int den;
}numbers[100];

long int GCD(long int a, long int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    return b == 0? a:GCD(b, a%b);
}

int main(){
    int N;
    Fraction sum;
    cin>>N;
    for(int i = 0; i<N; i++){
        scanf("%ld/%ld",&numbers[i].num,&numbers[i].den);
    }

    sum = numbers[0];

    for(int i = 1;i<N;i++){
        sum.num = sum.num*numbers[i].den+sum.den*numbers[i].num;
        sum.den = sum.den*numbers[i].den;
        int gcd = sum.num > sum.den ? GCD(sum.num, sum.den):GCD(sum.den, sum.num);
        sum.num/=gcd;
        sum.den/=gcd;
    }

    long int temp = sum.num/sum.den;
    if(temp!=0) sum.num -= sum.den*temp;

    if(sum.num == 0) cout<<temp;
    else if(temp == 0) cout<<sum.num<<'/'<<sum.den;
    else cout<<temp<<' '<<sum.num<<'/'<<sum.den;

    return 0;
}