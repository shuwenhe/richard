#include<bits/stdc++.h>

using namespace std;

int n,m;
int sum = 0;

int solve(int x,int y){
	int ans = 1;
	for(int i = 1;i <= y;i++){
		ans *= x;
	}
	return ans;
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		sum += solve(i,m);
	}
	cout<<sum;
}
