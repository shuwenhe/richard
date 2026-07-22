#include<bits/stdc++.h>

using namespace std;

int a[101],n;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	for(int i = 100;i >= 1;i--){
		for(int j = 1;j <= a[i];j++){
			cout<<i<<" ";
		}
	}
}                                                                                                                                                                                                                                    
