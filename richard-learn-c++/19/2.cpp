#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;                                
	int i = 1;
	while(i <= n){
		if(n % i == 0){
			if(i == n){
				cout<<i<<endl;
			}else{
			cout<<i<<" ";
			}
		}
		i = i+1;
	}
}
