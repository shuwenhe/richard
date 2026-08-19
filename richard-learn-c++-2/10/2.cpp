#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];
long long s[10001];

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	s[0] = 0;
	for(int i = 1;i <= m;i++){
		int l,r;
		cin>>l>>r;
		int L1 = 0,R1 = n + 1;
		while(L1 + 1 < R1){
			int M = (L1 + R1) / 2;
			if(a[M] < 1)
				L1 = M;
			else
				R1 = M;
		}
		int L2 = 0,R2 = n + 1;
		while(L2 + 1 < R2){
			int M = (L2 + R2) / 2;
			if(a[M] <= r)
				L2 = M;
			else
				R2 = M;
		}
		cout<<L2 - R1 + 1<<" "<<s[L2] - s[R1 - 1]<<endl;
	}
}
