#include<bits/stdc++.h>

using namespace std;

int m,n,k,l,d,h[1001],s[1001];

int main(){
	int x,y,p,q;
	cin>>m>>n>>k>>l>>d;
	memset(h,0,sizeof(h));
	memset(s,0,sizeof(s));
	for(int i = 1;i <= d;i++){
		cin>>x>>y>>p>>q;
		if(x == p){
			++s[min(y,q)];
		}else{
			++h[min(x,p)];
		}
	}
	for(int i = 1;i <= m;i++){
		p[i] = i;
	}
	for(int i = 1;i <= m;i++){
		for(int j = i + 1;j <= m;j++){
			if(h[j] > h[i]){
				swap(h[i],h[j]),
				swap(p[i],p[j]);
			}
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = i + 1;j <= k;j++){
			if(p[j] < p[i]){
				swap(p[i],p[j]);
			}
		}
	}
	for(int i = 1;i <= k;i++){
		printf("%d",p[i]);
		if(i != k){
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i = 1;i <= m;i++){
                p[i] = i;
        }
	for(int i = 1;i <= m;i++){
                for(int j = i + 1;j <= m;j++){
                        if(h[j] > h[i]){
                                swap(h[i],h[j]),
                                swap(p[i],p[j]);
                        }
                }
        }
        for(int i = 1;i <= l;i++){
                for(int j = i + 1;j <= l;j++){
                        if(p[j] < p[i]){
                                swap(p[i],p[j]);
                        }
                }
        }
        for(int i = 1;i <= l;i++){
                printf("%d",p[i]);
                if(i != k){
                        cout<<" ";
                }
        }
}
