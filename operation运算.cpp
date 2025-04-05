#include<iostream>
using namespace std;

int main(){
	double a,b,d;
	char c;
	cin>>c;
	cin>>a>>b>>d;
	if(c == '+'){
		cout<<a+b+d;
	}else if(c == '-'){
		cout<<a-b+d;
	}else if(c == '*'){
		cout<<a*b*d;
	}else if(c == '/'){
		cout<<a/b/d;
	}
}
