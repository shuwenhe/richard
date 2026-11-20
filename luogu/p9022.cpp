#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	string a;

	while(cin>>s && s != "99999"){
		int sum = (s[0] - '0') + (s[1] - '0');
		if(sum == 0){

		}else if(sum % 2 == 1){
			a = "left";
		}else{
			a = "right";
		}
		cout<<a<<" "<<s.substr(2,3)<<endl;
	}
}
