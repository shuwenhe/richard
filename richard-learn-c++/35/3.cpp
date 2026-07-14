#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[101];
	int t = 0,sum = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum += a[i];
	}
	for(int i = 1;i <= n;i++){
		if(a[i] * n >= sum){
			t++;
		}
	}
	cout<<t<<endl;
}
