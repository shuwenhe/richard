#include<bits/stdc++.h>

using namespace std;

int n,a[101];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		bool ok = false;
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				if(i != j && i != k && j != k)
					if(a[i] == a[j] + a[k])
						ok = true;
	if(ok)
		++ans;
	}
	cout<<ans<<endl;
}
