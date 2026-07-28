#include<bits/stdc++.h>

using namespace std;

int main(){
        int a[1001],n,m;
	long long sum = 0;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n - i;j++){
			if(a[j] < a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(i <= m){
			sum += 2 * a[i];
		}else{
			sum += a[i];
		}
	}
	cout<<sum<<endl;
}
