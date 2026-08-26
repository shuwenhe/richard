#include<bits/stdc++.h>

using namespace std;

struct Info{
	int v,pos;
}c[100001];
int n,a[100001];

bool cmp(const Info & x,const Info &y){
	if(x.v != y.v){
		return x.v < y.v;
	}
	return x.pos < y.pos;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++){
		c[i].v = a[i];
		c[i].pos = i;
	}
	sort(c + 1,c + n + 1,cmp);
	for(int i = 1;i <= n;i++){
		cout<<c[i].v<<" ";
	}
	for(int i = 1;i <= n;i++){
		r[c[i].pos] = i;
	}
	for(int i = 1;i <= n;i++){
		cout<<r[i]<<" ";
	}
}
