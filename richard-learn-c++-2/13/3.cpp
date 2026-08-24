#include<bits/stdc++.h>

using namespace std;

int x,k,q[200002],front = 1,rear = 1;

int main(){
	cin>>x>>k;
	q[1] = x;
	for(int i = 1;i <= k;i++){
		q[++rear] = 2 * q[front];
		q[++rear] = 2 * q[front] + 1;
		cout<<q[front]<<endl;
		++front;
	}
}
