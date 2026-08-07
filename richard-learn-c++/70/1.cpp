#include<bits/stdc++.h>

using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	int ma = max(a,b);
	ma = max(ma,c);
	cout<<ma<<endl;
	return 0;
}
