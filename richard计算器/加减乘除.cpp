#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a,b;
	char n;
	cin>>a>>n>>b;
	if(n == '+'){
		cout<<a<<"+"<<b<<"="<<a+b;
	}
	if(n == '-'){
		cout<<a<<"-"<<b<<"="<<a-b;
	}
	if(n == '*'){
		cout<<a<<"*"<<b<<"="<<a*b;
	}
	if(n == '/'){
		cout<<"需要小数结果请按1，需要带有余数的结果请按2"<<endl;
		int k;
		cin>>k;
		if(k == 1){
			double i,j;
			i = a;
			j = b;
			cout<<a<<"/"<<b<<"="<<i/j;
		}
		if(k == 2){
			cout<<a<<"/"<<b<<'='<<a/b<<"......"<<a%b;
		}
	}
}
