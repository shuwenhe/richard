#include<bits/stdc++.h>

using namespace std;

int fac(int n){
	int ans = 1;
	for(int i = 1;i <= n;i++){
		ans *= i;
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	cout<<fac(n)<<endl;
}
