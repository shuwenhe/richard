//这段代码是错误的！！！！！！！！！！！！！！！！！！

#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	bool flag = true;
	for(int i = 1;i <= n;i++){
		for(int j = n;j >= 1;j--){
			if(a[i] == a[j]){
				flag = true;
			}else{
				flag = false;
			}
		}
	}
	if(flag == true){
		cout<<1;
	}else{
		cout<<0;
	}
}
