#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int peach = 1;
	for(int i = 1;i <= n;i++){
		peach = (peach + 1) * 2;
	}
	cout<<peach<<endl;
}
