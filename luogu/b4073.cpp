#include<bits/stdc++.h>

using namespace std;

int main(){
	int w,n;
	cin>>w>>n;
	int a[6] = {0, 4, 6, 9, 10, 17};
	if(w <= 500){
		cout<<20;
		return 0;
	}else{
		int cnt = (w - 500 + 500 - 1) / 500;
		cout<<20 + cnt * a[n]<<endl;
	}
}
