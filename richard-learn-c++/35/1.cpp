#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[101];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = n;i >= 1;i--){
		if(a[i] > 80){
			cout<<a[i]<<endl;
		}else{
			cout<<80<<endl;
		}
	}
}
