#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	for(int i = 0;i <= a;i++){
		if(2 * i + 4 * (a - i) == b){
			cout<<i<<" "<<a - i<<endl;
		}
	}
}
