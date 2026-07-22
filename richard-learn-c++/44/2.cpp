#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],b[1001],n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n - i;j++){
			if(a[j] > a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				t = b[j];
				b[j] = b[j + 1];
				b[j + 1] = t;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(b[i] == 0){
			cout<<a[i]<<" ";
		}
	}
	for(int i = 1;i <= n;i++){
         	if(b[i] == 1){
                        cout<<a[i]<<" ";
                }
        }

}
