#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b,c,d,e;
	a = n / 10000;
	b = n / 1000 % 10;
	c = n / 100 % 10;
	d = n / 10 % 10;
	e = n % 10;
	if(a < 7 && b < 7 && c < 7 && d < 7 && e < 7){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}
