#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,x,r = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x;
		r ^= x;
	}
	cout<<r<<endl;
}
