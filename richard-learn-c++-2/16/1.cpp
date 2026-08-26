#include<bits/stdc++.h>

using namespace std;

bool cmp(const int &x,const int &y){
	return x > y;
}

int main(){
	int n,a[1001];
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
}
