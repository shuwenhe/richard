#include<bits/stdc++.h>

using namespace std;

int main(){
        char s[100];
        int n,l,ans = 0,base = 1;
        scanf("%s",s + 1);
        l = strlen(s + 1);
        for(int i = l;i >= 1;i--){
                int t = s[i] - '0';
		if(t <= 9){
			ans += t * base;
		}else{
			ans += (t - 7) * base;
		}
		base *= 16;
        }
        cout<<ans;
}
