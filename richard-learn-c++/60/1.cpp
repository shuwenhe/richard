#include<bits/stdc++.h>

using namespace std;

char s[110];
int a[150];
int n,la,x;

int main(){
	for(int i = 1;i <= 149;i++)
		a[i] = 0;
	scanf("%s",s + 1);
	la = strlen(s + 1);
	for(int i = 1;i <= la;i++){
		a[i] = s[la - i + 1] - '0';
	}
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&x);
		for(int j = 1;j <= la;j++){
			a[j] *= x;
		}
		for(int j = 1;j <= la;j++){
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
		}
		while(a[la + 1] > 0){
			la++;
			a[la + 1] = a[la] / 10;
			a[la] %= 10;
		}
	}
	while(a[la] == 0 && la > 1){
		la--;
	}
	for(int i = la;i >= 1;i--){
		cout<<a[i];
	}
	cout<<endl;
}
