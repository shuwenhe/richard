#include<bits/stdc++.h>

using namespace std;

int n,m,w[10001],c[101];

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>w[i];
	for(int i = 1;i <= m;i++)
		c[i] = w[i];
	int x = m + 1;
	for(int i = 1; ;i++){
		for(int j = 1;j <= m;j++){
			if(c[j]){
				--c[j];
			}
		}
		for(int j = 1;j <= m;j++){
		        if(!c[j] && x <= n){
				c[j] = w[x];
				++x;
			}	
		}
		bool ok = true;
		for(int j = 1;j <= m;j++){
			if(c[j]){
				ok = false;
			}
		}
		if(ok){
			cout<<i<<endl;
			return 0;
		}
	}

}
