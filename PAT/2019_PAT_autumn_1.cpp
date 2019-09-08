#include<iostream>
#include<algorithm>
#include<vector>

using  namespace std;

int K[5],m[5];

struct Ans{
	int n;
	int A;
	Ans(int s_n, int s_A):n(s_n),A(s_A){}
};

bool cmp(Ans &a, Ans &b){
	if(a.n != b.n) return a.n<b.n;
	else return a.A < b.A;
}

int sumDigit(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n/=10;
	}
	return sum;
}

int GCD(int a, int b){
	return b==0?a:GCD(b,a%b);
}

int main(){
	int N;
	cin>>N;
	for(int i = 0; i < N; i++){
		cin>>K[i]>>m[i];
	}

	for(int i = 0; i < N; i++){
		vector<Ans> ans;
		cout<<"Case "<<i+1<<endl;
		int num = 1;
		int k = K[i];
		while(k>0){
			num*=10;
			k--;
		}
		int a = num-1, b = num/10;
		bool flag = true;
		for(int j = b; j <= a; j++){
			int sum = sumDigit(j);
			if(sum == m[i]){
				int sum_n = sumDigit(j+1);
				int n = sum_n;
				if(sum < n){
					int tmp = sum;
					sum = n;
					n = tmp;
				}
				if(GCD(sum, n)>2){
					flag = false;
					ans.push_back(Ans(sum_n, j));
				}
			}
		}
		if(flag) cout<<"No Solution"<<endl;
		else{
			sort(ans.begin(),ans.end(),cmp);
			for(int i = 0; i < ans.size(); i++){
				cout<<ans[i].n<<" "<<ans[i].A<<endl;
			}
		}
	}

	return 0;
}