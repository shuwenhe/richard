#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n,s = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		if(a[i] < a[i + 1]){
			s++;
		}
	}
	if(s == n - 1){
		cout<<1;
	}else{
		if(s == 0){
			cout<<2<<endl;
		}else{
			cout<<0<<endl;                
		}
	}
}
