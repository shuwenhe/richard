#include<bits/stdc++.h>

using namespace std;

int l,m;
bool b[10001];

int main(){
	memset(b,false,sizeof(b));
	scanf("%d%d",&l,&m);
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		for(int j = u;j <= v;j++){
			b[j] = true;
		}
	}
	int ans = 0;
	for(int i = 0;i <= l;i++){
		if(b[i] == false){
			++ans;
		}
	}
	cout<<ans<<endl;
}
