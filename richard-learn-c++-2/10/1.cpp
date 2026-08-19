#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];
long long s[100001];

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	s[0] = 0;
	for(int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		int l;
		long long x;
		cin>>l>>x;
		int L = l - 1,R = n + 1;
		while(L + 1 < R){
			int M = (L + R) / 2;
			if(s[M] - s[l - 1] <= x){
				L = M;
			}else{
				R = M;
			}
		}
		if(L < l){
			cout<<"-1"<<endl;
		}else{
			cout<<L<<endl;
		}
	}
}
