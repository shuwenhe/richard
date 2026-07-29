#include<bits/stdc++.h>

using namespace std;

char s[110];
int a = 0,b = 0,c = 0;
int main(){
	scanf("%s",s + 1);
	int l = strlen(s + 1);
	for(int i = 1;i <= l;i++){
		if(s[i] == 'a'){
			a++;
		}else if(s[i] == 'b'){
			b++;
		}else{
			c++;
		}
	}
	if(a >= b && a >= c){
		cout<<a<<endl;
	}else if(b >= c){
		cout<<b<<endl;
	}else{
		cout<<c<<endl;
	}
}
