#include<bits/stdc++.h>

using namespace std;

int n,s[100001],top = 0;

char str[100011];

int main(){
	cin>>n>>str + 1;
	for(int i = 1;i <= n;i++)
		if(str[i] == '(')
			s[++top] = 0;
	        else
			if(str[i] == '[')
				s[++top] = 1;
	                else{
				if(!top){
					cout<<"No"<<endl;
					return 0;
				}
				if(str[i] == ')')
					if(!s[top])
						--top;
				        else{
						cout<<"No"<<endl;
						return 0;
					}
				else
					if(s[top])
						--top;
				        else{
						cout<<"No"<<endl;
						return 0;
					}
			}
	if(top)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}

