#include<bits/stdc++.h>

using namespace std;

int n,q[1000001],a[1001],ans[1001],front = 1,rear;

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	rear = n;
	for(int i = 1;i <= n;i++){
		q[i] = i;
	}
	for(int t = 1;rear >= front;t++){
		int x = q[front];
		++front;
		--a[x];
		if(a[x] == 0)
			ans[x] = t;
		else
			q[++rear] = x;
	}
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<" ";
	}
}
