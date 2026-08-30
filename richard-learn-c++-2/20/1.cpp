#include<bits/stdc++.h>

using namespace std;

struct Node{
	int v;
	Node *next;
}*head,*tail,a[1001];

int n;

int main(){
	cin>>n;
	head = tail = NULL;
	for(int i= 1;i <= n;i++){
		cin>>a[i].v;
		if(head == NULL){
			head = tail = &a[i];
		}else{
			tail -> next = &a[i];
			tail = &a[i];
		}
	}
	Node *x = head,*y = x->next;
	while(y){
		Node *z = y->next;
		y->next = x;
		x = y;y = z;
	}
	head->next = NULL;
	swap(head,tail);
	for(Node *p = head;p;p = p->next){
		cout<<p->v<<" ";
	}
}
