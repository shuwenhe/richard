#include<bits/stdc++.h>

using namespace std;

int n,ans = 0;

int main(){
	cin>>n;
	for(int i = 1;i <= 30;i++){
		if((n & (1 << (i - 1))) > 0){
			ans++;
		}
	}
	cout<<ans<<endl;
}
