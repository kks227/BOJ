#include <cstdio>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;

struct Node{
	char c;
	Node *l, *r;
	Node(): Node('\0', nullptr, nullptr){}
	Node(int c1): Node(c1, nullptr, nullptr){}
	Node(int c1, Node *l1, Node *r1): c(c1), l(l1), r(r1){}
};

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		stack<Node*> S;
		while(1){
			char c = getchar();
			if(islower(c)){
				Node *node = new Node(c);
				S.push(node);
			}
			else if(isupper(c)){
				Node *a, *b;
				a = S.top(); S.pop();
				b = S.top(); S.pop();
				Node *node = new Node(c, b, a);
				S.push(node);
			}
			else break;
		}

		queue<Node*> Q;
		Q.push(S.top());
		stack<char> result;
		while(!Q.empty()){
			Node *node = Q.front();
			Q.pop();
			result.push(node->c);
			if(node->l) Q.push(node->l);
			if(node->r) Q.push(node->r);
		}
		while(!result.empty()){
			putchar(result.top());
			result.pop();
		}
		puts("");
	}
}