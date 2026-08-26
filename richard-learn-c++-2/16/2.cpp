#include<bits/stdc++.h>

using namespace std;

int n,a[100001],c[100001],r[100001];

bool cmp(const int &x,const int &y){
	if(a[x] != a[y])
		return a[x] < a[y];
	return x < y;
}

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i],c[i] = i;
	sort(c + 1,c + n + 1,cmp);
	for(int i = 1;i <= n;i++)
		cout<<a[c[i]]<<" ";
	cout<<endl;
	for(int i = 1;i <= n;i++)
		r[c[i]] = i;
	for(int i = 1;i <= n;i++)
		cout<<r[i]<<" ";
}
