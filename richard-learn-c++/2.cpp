#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i = 1,j = 1;
	while (i <= n){
		j = j * 2;
		i = i + 1;
	}
	cout<<j<<endl;
}
