#include<bits/stdc++.h>

using namespace std;

int n,ans = 0;

int main(){
	cin>>n;
	while(n > 0){
		if(n & 1 == 1){
			ans++;
		}
		n >>= 1;
	}
	cout<<ans<<endl;
}
