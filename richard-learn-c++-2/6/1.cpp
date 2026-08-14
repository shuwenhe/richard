#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
	cin>>n;
	int x = 0;
	x += n / 100;n %= 100;
	x += n / 50;n %= 50;
	x += n / 10;n %= 10;
	x += n / 5;n %= 5;
	x += n;
	cout<<x<<endl;
}
