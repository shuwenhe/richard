#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n;
	bool flag = true;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n - 1;i++){
		if(a[i] > a[i + 1]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<1<<endl;
	}else{
		flag = true;
		for(int i = 1;i <= n - 1;i++){
			if(a[i] < a[i + 1]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<2<<endl;
		}else{
			cout<<0<<endl;
		}
	}
}


