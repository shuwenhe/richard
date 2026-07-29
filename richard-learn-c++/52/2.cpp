#include<bits/stdc++.h>

using namespace std;

int main(){
	char ch;
	int sum = 0;
	for(scanf("%c",&ch);ch != '\n';scanf("%c",&ch)){
		if(ch != ' '){
			sum++;
		}
	}
	printf("%d\n",sum);
}
