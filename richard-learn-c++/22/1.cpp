#include<bits/stdc++.h>

using namespace std;

int main(){
	int x,sum = 0;
	for( ; ; ){
		cin>>x;
		if(x == 0){
			break;
		}
		sum = sum + x;
	}
	cout<<sum<<endl;
}
