#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n,max = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n - 1;i++){
		for(int j = i + 1;j <= n;j++){
			if(a[j] - a[i] > max){
				max = a[j] - a[i];
			}
		}
	}
	cout<<ma<<endl;
}
