#include <cstdio>
using namespace std;

struct Node{
	int n, key;
	Node *prev, *next;
	Node():n(0),key(0),prev('\0'),next('\0'){}
	Node(int n1, int k1, Node *p, Node *q):n(n1),key(k1),prev(p),next(q){}
};

struct CircularList{
	int size;
	Node *cur;
	CircularList():size(0),cur('\0'){}
	void insert(int n, int key){
		if(size++){
			Node *temp = new Node(n, key, cur->prev, cur);
			cur->prev->next = temp;
			cur->prev = temp;
		}
		else{
			cur = new Node(n, key, '\0', '\0');
			cur->next = cur->prev = cur;
		}
	}
	void remove(){
		if(size == 0) return;
		if(--size){
			Node *temp = cur;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->next;
			delete temp;
		}
		else cur = '\0';
	}
};

int main(){
	int N;
	scanf("%d", &N);
	CircularList cList;
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		cList.insert(i+1, n);
	}
	for(int i=0; i<N; i++){
		printf("%d ", cList.cur->n);
		int next = cList.cur->key;
		cList.remove();
		if(i == N-1) break;
		if(next > 0){
			for(int i=1; i<next; i++)
				cList.cur = cList.cur->next;
		}
		else{
			for(int i=0; i<-next; i++)
				cList.cur = cList.cur->prev;
		}
	}
}