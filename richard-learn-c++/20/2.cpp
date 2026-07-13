#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	bool flag = true;
	int i = 2;
	while(i <= n - 1){
		if(n % i == 0){
			flag = false;
			cout<<"no";
			break;
		}
		i = i + 1;
	}
	if(flag == true)
		cout<<"yes";
}
