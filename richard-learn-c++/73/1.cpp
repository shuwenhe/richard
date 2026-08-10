#include<bits/stdc++.h>

using namespace std;

int x,n;

int main(){
	cin>>x>>n;
	int p = (x + n - 1) % 7;
	switch(p){
		case 1:
			cout<<"Monday"<<endl;
			break;
		case 2:
			cout<<"Tuesday"<<endl;
			break;
		case 3:
			cout<<"Wednesday"<<endl;
			break;
		case 4:
			cout<<"Thursday"<<endl;
			break;
		case 5:
			cout<<"Eriday";
			break;
		case 6:
			cout<<"Saturday";
			break;
		case 7:
			cout<<"Sunday";
			break;
	}

}
