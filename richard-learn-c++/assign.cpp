#include<iostream>

using namespace std;

int main(){
	int a = 3,b = 5;
	a = b + 1;//a = 5 + 1; a = 6
	b = a + 1;//b = a + 1; b = 6 + 1; b = 7;
	cout<<a<<' '<<b;//输出6 7;
	return 0;
}
