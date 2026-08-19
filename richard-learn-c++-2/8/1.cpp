#include<bits/stdc++.h>

using namespace std;

int n,k,a[1001];

int main(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(a[j] < a[i])
				swap(a[i],a[i + 1]);
	int x = k;
	for(int i = 1;i <= n;i++){
		if(x >= a[i]){
			x -= a[i];
		}else{
			cout<<i - 1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
}
