#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[100001];
	int n,t;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= n - i;j++){
			if(a[j] > a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	cout<<a[n]<<" "<<a[n - 1]<<" "<<a[n - 2]<<endl;
}
