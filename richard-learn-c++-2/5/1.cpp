#include<bits/stdc++.h>

using namespace std;

int l,r;

int calc(int x){
	int y = 0;
	while(x != 0){
		if(x % 10 == 2){
			y++;
		}
		x /= 10;
	}
	return y;
}

int main(){
	int ans = 0;
	cin>>l>>r;
	for(int i = l;i <= r;i++){
		ans += calc(i);
	}
	cout<<ans<<endl;
}
