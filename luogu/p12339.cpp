#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int cnt = 0;
	for(int i = 0;i <= 24;i++){
		cnt += n + i;
	}
	cout<<cnt<<endl;
}
