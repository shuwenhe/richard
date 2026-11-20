#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a[100],k = 0;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
       	sort(a, a + n, greater<int>());
	for(int i = 0;i < n;i++){
		if(i == 0 || a[i] != a[i - 1]){
			a[k++] = a[i];
		}
	}
	if(k == 1){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<a[1]<<endl;
}
