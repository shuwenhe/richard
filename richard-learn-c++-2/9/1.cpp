#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];

int calc1(int x){
	int L = 0,R = n + 1;
	while(L + 1 < R){
		int M = (L + R) / 2;
		if(a[M] < x){
			L = M;
		}else{
			R = M;
		}
	}
	return L;
}

int calc2(int x){
	int L = 0,R = n + 1;
	while(L + 1 < R){
		int M = (L + R) / 2;
		if(a[M] <= x){
			L = M;
		}else{
			R = M;
		}
	}
	return L;
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= m;i++){
		int x;
		cin>>x;
		int y = calc1(x),z = calc2(x);
		cout<<y<<" "<<z - y<<" "<<n - z<<endl;
	}
}
