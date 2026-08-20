#include<bits/stdc++.h>

using namespace std;

int n,m,k[100001],b[100001];

long long calc(int x){
	long long y = 0;
	for(int i = 1;i <= n;i++){
		if(b[i] <= x){
			y += (x - b[i]) / k[i] + 1;
		}
	}
	return y;
}

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>k[i]>>b[i];
	cin>>m;
	int L = 0,R = 100000000;
	while(L + 1 < R){
		int M = (L + R) / 2;
		if(calc(M) < m)
			L = M;
		else
			R = M;
	}
	cout<<R<<endl;
}
