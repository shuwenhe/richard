#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[100001],b[100001],c[100001];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>b[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == 100 && b[i] == 100 && c[i] == 100){
			cnt1++;
		}else{
			int cnt = 0;
			if(a[i] >= 95)cnt++;
			if(b[i] >= 95)cnt++;
			if(c[i] >= 95)cnt++;
			if(cnt >= 2 && a[i] >= 90 && b[i] >= 90 && c[i] >= 90){
				cnt2++;
			}
		}
	}
	cout<<cnt1<<" "<<cnt2<<endl;
}
