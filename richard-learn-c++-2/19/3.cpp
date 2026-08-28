#include<bits/stdc++.h>

using namespace std;

struct Node{
	int v;
	Node *next;
}*h1,*t1,*h2,*t2,a[100001],b[100001];

Node * Merge(Node *h1,*h2){
	Node *h3 = NULL,*t3 = NULL;
	while(h1 && h2){
		if(h1 -> v < h2 -> v){
			t3 -> next = h1;
			t3 = h1;
			Node *x = h1;
			h1 = h1 -> next;
			x -> next = NULL;
		}else{
			t3 -> next = h2;
                        t3 = h2;
                        Node *x = h2;
                        h2 = h2 -> next;
                        x -> next = NULL;
		}
	}
	while(h1){
		t3 -> next = h1;
                t3 = h1;
                Node *x = h1;
                h1 = h1 -> next;
                x -> next = NULL;
	}
	while(h2){
		t3 -> next = h2;
                t3 = h2;
                Node *x = h2;
                h2 = h2 -> next;
                x -> next = NULL;
	}
}

int n,m;

int main(){
	cin>>n>>m;
	h1 = t1 = NULL;
	for(int i = 1;i <= n;i++){
		cin>>a[i].v;
		if(h1 == NULL){
			h1 = t1 = &a[i];
		}else{
			t1 -> next = &a[i];
			t1 = &a[i];
		}
	}
	for(int i = 1;i <= m;i++){
                cin>>b[i].v;
                if(h2 == NULL){
                        h2 = t2 = &b[i];
                }else{
                        t2 -> next = &b[i];
                        t2 = &b[i];
                }
        }
	Node *h3 = Merge(h1,h2);
	for(Node *v = h3;v;v = v -> next)
		cout<<v -> v;
}
