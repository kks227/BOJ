#include <cstdio>
using namespace std;

struct Node{
	char c;
	Node *next;
	Node():c('?'),next('\0'){}
	Node(char c1, Node *p):c(c1),next(p){}
};

struct CircularList{
	int size;
	Node *cur;
	CircularList():size(0),cur('\0'){}
	void insert(char key){
		if(size++){
			Node *temp = new Node(key, cur->next);
			cur->next = temp;
		}
		else{
			cur = new Node(key, '\0');
			cur->next = cur;
		}
	}
	bool confirm(int move, char key){
		for(int i=0; i<move; i++)
			cur = cur->next;
		if(cur->c!='?' && cur->c!=key) return false;
		cur->c = key;
		return true;
	}
};

int main(){
	int N, K;
	bool success = true, exist[26] = {0};
	scanf("%d %d", &N, &K);
	CircularList cList;
	for(int i=0; i<N; i++)
		cList.insert('?');
	for(int i=0; i<K; i++){
		int S;
		char c;
		scanf("%d %c", &S, &c);
		success &= cList.confirm(N-S%N, c);
	}
	for(int i=0; i<N; i++){
		if(cList.cur->c!='?' && exist[cList.cur->c-'A']) success = false;
		exist[cList.cur->c-'A'] = true;
		cList.cur = cList.cur->next;
	}
	if(!success){
		puts("!");
		return 0;
	}
	for(int i=0; i<N; i++){
		putchar(cList.cur->c);
		cList.cur = cList.cur->next;
	}
	puts("");
}