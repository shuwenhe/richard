#include<biys/stdc++.h>

using namespace std;

int n,a[100001];
long long k;

long long calc(long long x){
	long long y = 0;
	for(int i = 1;i <= n;i++)
		if(a[i] <= x)
			y += x - a[i];
	return y;
}

int main(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	long long L = 1,R = ((long long)(1e13) + (long long))(1e8) + 1;
	while(L + 1 < R){
		long long M = (L + R) / 2;
		if(calc(M) <= k)
			L = M;
		else
			R = M;
	}
}
