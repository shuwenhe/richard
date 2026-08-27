#include<bits/stdc++.h>

using namespace std;

int main(){
	int a = 10,b = 11;
	int &c = a;
	c = b;
	c = 12;
	cout<<a<<" "<<b<<" "<<c<<endl;
}
