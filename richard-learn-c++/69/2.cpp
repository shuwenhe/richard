#include<bits/stdc++.h>

using namespace std;

int a[101];
int n,m;

int findmax(int l,int r){
	int ans = a[l];
	for(int i = l + 1;i <= r;i++){
		if(a[i] > ans){
			ans = a[i];
		}
	}
	return ans;
}
int findmin(int l,int r){
        int ans = a[l];
        for(int i = l + 1;i <= r;i++){
                if(a[i] < ans){
                        ans = a[i];
                }
        }
        return ans;
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= m;i++){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt == 2){
			printf("%d\n",findmax(l,r));
		}else{
			printf("%d\n",findmin(l,r));
		}
	}
}
