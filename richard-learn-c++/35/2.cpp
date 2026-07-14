#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[101];
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
       	for(int i = 1;i <= n;i++){
		if(a[i] > a[n]){
			sum+=1;
		}
	}
	cout<<sum<<endl;
}
