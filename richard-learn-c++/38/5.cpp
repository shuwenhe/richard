#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n;
	bool flag = true;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int i = 1;
	while(a[i] < a[i + 1] && i <= n){
		i++;
	}
	int j = 1;
	while(a[j] > a[j + 1] && j <= n - 1){
		j++;
	}
	if(i == n)
		cout<<1<<endl;
	else
		if(j == n)
			cout<<2<<endl;
		else
			cout<<0<<endl;
	return 0;
}
