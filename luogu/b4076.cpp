#include<bits/stdc++.h>

using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int a[6] = {1,2,3,4,5,6};
	for(int i = 1;i <= 6;i++){
		if(a[i] >= x && a[i] >= y){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
