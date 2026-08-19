#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= m;i++){
		int x;
		scanf("%d",&x);
		int L = 0,R = n + 1;
		while(L + 1 < R){
			int M = (L + R) / 2;
			if(a[M] < x){
				L = M;
			}else{
				R = M;
			}
		}
		if(R <= n && a[R] == x){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
