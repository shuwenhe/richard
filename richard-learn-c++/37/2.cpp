#include<bits/stdc++.h>

using namespace std;

int main(){
	int q[101]n,m,k,t,a,b;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		q[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		cin>>a;
		q[a] = 1;
	}
	cin>>k;
	for(int i = 1;i <= k;i++){
		cin>>a>>b;
		t = q[a];
		q[a] = q[b];
		q[b] = t;
	}
	for(int i = 1;i <= n;i++){
		if(q[i] == 1){
			cout<<i<<" ";
		}
	}
}
