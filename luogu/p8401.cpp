#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a[2001],b[2001];
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	int c = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] * 5 - b[i] * 3 > 40){
			c++;
		}
	}
	cout<<c;
	if(c == n){
		cout<<"+"<<endl;
	}
}
