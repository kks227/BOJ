#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;
const int INF = 1e9;
const int MAX = 100000;
typedef tuple<long long, long long, long long> LazyNode;

struct SplayNode{
    SplayNode *lchild, *rchild, *parent;
    int size;
    long long val, sum;
    LazyNode lazy;
    bool dummy;

    SplayNode(): SplayNode(0){}
    SplayNode(long long val1): SplayNode(val1, nullptr){}
    SplayNode(long long val1, SplayNode *p): lchild(nullptr), rchild(nullptr), parent(p), val(val1){
        sum = val1;
        size = 1;
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
    ~SplayTree(){
        if(root) delete root;
    }

    void initialize(int n){
        if(root) delete root;

        SplayNode *temp;
        root = new SplayNode(); // the leftmost dummy
        root->dummy = true;
        for(int i = 1; i <= n; ++i){
            int val;
            scanf("%d", &val);
            temp = new SplayNode(val);
            temp->lchild = root;
            root->parent = temp;
            root = temp;
            update(root);
        }
        temp = new SplayNode();
        temp->lchild = root;
        root->parent = temp;
        root = temp;
        root->dummy = true;
        update(root);
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

    void inorder(){ inorder(root); /*puts("");*/ }
    void inorder(SplayNode *x){
        propagate(x);
        if(x->lchild) inorder(x->lchild);
        //if(!x->dummy) printf("%d ", x->val);
        if(x->rchild) inorder(x->rchild);
    }

    void rangeUpdate(int s, int e, int k){
        SplayNode *x = gather(s, e);
        int L = x->size;
        x->sum = 1LL*k*L;
        x->lazy = LazyNode(k, 0, 0);
    }

    void rangeAdd(int s, int e, int k){
        SplayNode *x = gather(s, e);
        int L = x->size;
        long long a, b, c;
        tie(a, b, c) = x->lazy;
        x->sum += 1LL*k*L*(L+1)/2;
        x->lazy = LazyNode(a, b+k, c+k);
    }

    void insert(int pos, int k){
        findKth(pos);
        SplayNode *x = root->lchild;
        propagate(x);
        while(x->rchild){
            x = x->rchild;
            propagate(x);
        }
        x->rchild = new SplayNode(k, x);
        update(x);
        splay(x->rchild);
    }

    long long getSum(int s, int e){
        SplayNode *x = gather(s, e);
        return x->sum;
    }

    SplayNode* gather(int s, int e){ // gather all indexes in [s, e) as a continuous range
        findKth(e);
        SplayNode *x = root;
        findKth(s-1);
        splay(x, root);
        return root->rchild->lchild;
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

    void update(SplayNode *x){
        x->size = 1;
        x->sum = x->val;
        if(x->lchild){
            x->size += x->lchild->size;
            x->sum += x->lchild->sum;
        }
        if(x->rchild){
            x->size += x->rchild->size;
            x->sum += x->rchild->sum;
        }
    }

    void propagate(SplayNode *x){
        int L = x->size, lsize = (x->lchild ? x->lchild->size : 0), rsize = L-1-lsize;
        long long a1, b1, c1;
        tie(a1, b1, c1) = x->lazy;
        if(a1 == 0 && b1 == 0 && c1 == 0) return;

        // k-th(0-based) element get incremented as b1 + k*c1
        if(a1 > 0){
            x->val = a1 + b1 + c1*lsize;
            if(x->lchild){
                x->lchild->lazy = x->lazy;
                x->lchild->sum = a1*lsize + b1*lsize + c1*lsize*(lsize-1)/2;
            }
            if(x->rchild){
                x->rchild->lazy = LazyNode(a1, b1+(lsize+1)*c1, c1);
                x->rchild->sum = a1*rsize + (b1+(lsize+1)*c1)*rsize + c1*rsize*(rsize-1)/2;
            }
        }
        else{
            x->val += b1 + c1*lsize;
            if(x->lchild){
                long long a2, b2, c2;
                tie(a2, b2, c2) = x->lchild->lazy;
                x->lchild->lazy = LazyNode(a2, b2 + b1, c2 + c1);
                x->lchild->sum += b1*lsize + c1*lsize*(lsize-1)/2;
            }
            if(x->rchild){
                long long a2, b2, c2;
                tie(a2, b2, c2) = x->rchild->lazy;
                x->rchild->lazy = LazyNode(a2, b2 + b1+(lsize+1)*c1, c2 + c1);
                x->rchild->sum += (b1+(lsize+1)*c1)*rsize + c1*rsize*(rsize-1)/2;
            }
        }
        x->lazy = LazyNode(0, 0, 0);
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
    int N, Q;
    scanf("%d %d", &N, &Q);
    SplayTree ST;
    ST.initialize(N);
    for(int i = 0; i < Q; ++i){
        int o;
        scanf("%d", &o);
        if(o == 1){
            int s, e, k;
            scanf("%d %d %d", &s, &e, &k);
            ST.rangeUpdate(s-1, e, k);
        }
        else if(o == 2){
            int s, e, k;
            scanf("%d %d %d", &s, &e, &k);
            ST.rangeAdd(s-1, e, k);
        }
        else if(o == 3){
            int pos, k;
            scanf("%d %d", &pos, &k);
            ST.insert(pos-1, k);
        }
        else{
            int s, e;
            scanf("%d %d", &s, &e);
            printf("%lld\n", ST.getSum(s-1, e));
        }
    }
}