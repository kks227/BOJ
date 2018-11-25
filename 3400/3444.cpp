#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
const int INF = 1e9;
const int MAX = 100000;
const int MAX_VAL = MAX+1;
typedef pair<int, int> P;

struct SplayNode{
	SplayNode *lchild, *rchild, *parent;
	int val, size;
	bool lazyFlip;
	bool dummy;

	SplayNode(): SplayNode(0){}
	SplayNode(int val1): SplayNode(val1, nullptr){}
	SplayNode(int val1, SplayNode *p): lchild(nullptr), rchild(nullptr), parent(p), val(val1){
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
	SplayNode *ptr[MAX_VAL];

	SplayTree(): root(nullptr){
		fill(ptr, ptr+MAX_VAL, nullptr);
	}
	~SplayTree(){
		if(root) delete root;
	}

	void initialize(int n, int *A){
		if(root) delete root;

		root = new SplayNode(-INF); // the leftmost dummy
		SplayNode *curr = root;
		for(int i = 0; i < n; ++i){
			ptr[A[i]] = curr->rchild = new SplayNode(A[i], curr);
			curr = curr->rchild;
		}
		curr->rchild = new SplayNode(INF, curr); // the rightmost dummy
		root->dummy = curr->rchild->dummy = true;
		for(int i = n; i > 0; --i)
			update(ptr[i]);
		update(root);

		//splay(ptr[(n+1)/2]);
	}

	void debug(SplayNode *x){
		printf("visit %d\n  size %d", x->val, x->size);
		if(x->lchild) printf(" (L %d %d)", x->lchild->val, x->lchild->size);
		else printf(" (L -)");
		if(x->rchild) printf(" (R %d %d)", x->rchild->val, x->rchild->size);
		else printf(" (R -)");
		puts("");

		if(x->lchild) debug(x->lchild);
		if(x->rchild) debug(x->rchild);
	}

	void inorder(){ inorder(root); puts(""); }
	void inorder(SplayNode *x){
		propagate(x);
		if(x->lchild) inorder(x->lchild);
		if(!x->dummy) printf("%d ", x->val);
		if(x->rchild) inorder(x->rchild);
	}

	void flip(int s, int e){ // flip [s, e)
		SplayNode *x = gather(s, e);
		x->lazyFlip = !x->lazyFlip;
	}

	int getIndex(int val){
		splay(ptr[val]);
		return root->lchild->size - 1;
	}

	void findKth(int k){ // k is 0-based
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
	while(1){
		int N, A[MAX];
		scanf("%d", &N);
		if(N == 0) break;

		P p[MAX];
		for(int i = 0; i < N; ++i){
			p[i].second = i;
			scanf("%d", &p[i].first);
		}
		stable_sort(p, p+N);
		for(int i = 0; i < N; ++i)
			A[p[i].second] = i+1;

		SplayTree ST;
		ST.initialize(N, A);
		for(int i = 0; i < N; ++i){
			int k = ST.getIndex(i+1);
			printf("%d ", k+1);
			ST.flip(i, k+1);
		}
		puts("");
	}
}