#include <cstdio>
#include <algorithm>
using namespace std;
const char INF = 127;
const int MAX = 100000;

struct SplayNode{
	SplayNode *lchild, *rchild, *parent;
	char val;
	int size;
	bool lazyFlip;
	bool dummy;

	SplayNode(): SplayNode(0){}
	SplayNode(char val1): SplayNode(val1, nullptr){}
	SplayNode(char val1, SplayNode *p): lchild(nullptr), rchild(nullptr), parent(p), val(val1){
		size = 1;
		lazyFlip = false;
		dummy = false;
	}
	~SplayNode(){
		if(lchild) delete lchild;
		if(rchild) delete rchild;
	}
};

struct SplayTree{
	SplayNode *root;

	SplayTree(): root(nullptr){}
	~SplayTree(){ if(root) delete root; }

	int initialize(){
		if(root) delete root;

		root = new SplayNode(-INF); // the leftmost dummy
		SplayNode *curr = root;
		int n = 0;
		while(1){
			char c = getchar();
			if(c == '\n') break;
			curr->rchild = new SplayNode(c, curr);
			curr = curr->rchild;
			++n;
		}
		curr->rchild = new SplayNode(INF, curr); // the rightmost dummy
		root->dummy = curr->rchild->dummy = true;
		update(root);
		return n;
	}

	void flip(int s, int e){ // flip [s, e)
		SplayNode *x = gather(s, e);
		x->lazyFlip = !x->lazyFlip;
	}

	void shift(int s, int e, int k){ // rotate [s, e) k times
		SplayNode *x = gather(s, e);
		if(k >= 0){
			k %= (e-s);
			if(k == 0) return;
			flip(s, e);
			flip(s, s+k);
			flip(s+k, e);
		}
		else{
			k = -k % (e-s);
			if(k == 0) return;
			flip(s, e);
			flip(s, e-k);
			flip(e-k, e);
		}
	}

	char findKth(int k){ // k is 0-based
		++k; // because of the leftmost dummy node

		SplayNode *x = root;
		propagate(x);
		while(1){
			while(x->lchild && x->lchild->size > k){
				x = x->lchild;
				propagate(x);
			}
			if(x->lchild) k -= x->lchild->size;
			if(k-- == 0) break;
			x = x->rchild;
			propagate(x);
		}
		splay(x);
		return root->val;
	}

	SplayNode* gather(int s, int e){ // gather all indexes in [s, e) as a continuous range
		findKth(e);
		SplayNode *x = root;
		findKth(s-1);
		splay(x, root);
		return root->rchild->lchild;
	}

	void update(SplayNode *x){
		x->size = 1;
		if(x->lchild) x->size += x->lchild->size;
		if(x->rchild) x->size += x->rchild->size;
	}

	void propagate(SplayNode *x){
		// lazy propagation: flip
		if(x->lazyFlip){
			swap(x->lchild, x->rchild);
			x->lazyFlip = false;
			if(x->lchild) x->lchild->lazyFlip = !x->lchild->lazyFlip;
			if(x->rchild) x->rchild->lazyFlip = !x->rchild->lazyFlip;
		}
	}

	void splay(SplayNode *x, SplayNode *g = nullptr){ // make x as the root node
		SplayNode *y;
		while(x->parent != g){
			SplayNode *p = x->parent;
			if(p->parent == g){
				rotate(x);
				break;
			}
			SplayNode *pp = p->parent;
			if((p->lchild == x) == (pp->lchild == p)){
				rotate(p);
				rotate(x);
			}
			else{
				rotate(x);
				rotate(x);
			}
		}

		if(!g) root = x;
	}

	void rotate(SplayNode *x){ // push up x to the upper level
		SplayNode *p = x->parent, *y;
		propagate(p);
		propagate(x);

		if(x == p->lchild){
			p->lchild = y = x->rchild;
			x->rchild = p;
		}
		else{
			p->rchild = y = x->lchild;
			x->lchild = p;
		}

		x->parent = p->parent;
		p->parent = x;
		if(y) y->parent = p;
		if(x->parent){
			if(p == x->parent->lchild) x->parent->lchild = x;
			else x->parent->rchild = x;
		}
		else root = x;

		update(p);
		update(x);
	}
};



int main(){
	SplayTree ST;
	int N = ST.initialize(), Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int o, x, y;
		scanf("%d %d", &o, &x);
		if(o == 1){
			scanf("%d", &y);
			ST.shift(0, y+1, -x);
		}
		else if(o == 2){
			scanf("%d", &y);
			ST.shift(x, N, N-y-1);
		}
		else if(o == 3){
			printf("%c\n", ST.findKth(x));
		}
	}
}