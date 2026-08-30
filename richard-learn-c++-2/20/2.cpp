#include<bits/stdc?++.h>

using namespace std;

struct Node{
	int v;
	Node *next;
}a[101];

int n,m;

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		a[i].v = i;
		if(i == n){
			a[i].next = &a[i];
		}else{
			a[i].next = a[i + 1];
		}
		if(i == 1){
			a[i].prev = &a[n];
		}else{
			a[i].prev = &a[i - 1];
		}
	}
	Node *p = &a[n];
	int x = 0;
	while(p){
		p = p->next;
		++x;
		if(x == m){
			cout<<p->v;
			if(p->next == p){
				break;
			}else{
				Node *l = p->prev,*r = p->next;
				l->next = r;r->prev = l;
				p->prev = p->next = NULL;
				x = 0;
				p = l; 

			}
		}
	}
}
