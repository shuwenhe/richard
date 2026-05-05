#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	int a = 0;
	for(char c : s){
		if('0'<= c && c <= '9'){
			a++;
			}
	}
	cout<<a<<endl;
	return 0;
}
