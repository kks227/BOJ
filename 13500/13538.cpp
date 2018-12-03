#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_DEPTH = 20;
const int MAX_ST = 1<<MAX_DEPTH;
const int MAX = 500001;
const int MAX_NODE = MAX_ST + MAX*MAX_DEPTH;

struct Node{
    int val, ns, ne, nNum, lNum, rNum;
    Node(): Node(-1, -1, -1){}
    Node(int ns1, int ne1, int nNum1): val(0), ns(ns1), ne(ne1), nNum(nNum1), lNum(-1), rNum(-1){}
};

struct PersistentSegTree{
    int TN, ncnt, root[MAX];
    Node node[MAX_NODE];
    PersistentSegTree(): TN(0), ncnt(0){
        fill(root, root+MAX, -1);
        // make 0-th complete binary tree
        root[TN++] = initialize(0, MAX_ST/2);
    }

    int initialize(int s, int e){
        Node &curr = node[ncnt] = Node(s, e, ncnt);
        ncnt++;
        if(s+1 < e){
            int mid = (s+e)/2;
            curr.lNum = initialize(s, mid);
            curr.rNum = initialize(mid, e);
        }
        return curr.nNum;
    }

    void addNode(int y, int val = 1){
        int temp = ncnt;
        root[TN] = addNode(node[root[TN-1]], y, val, 0, MAX_ST/2);
        ++TN;
    }
    int addNode(Node &shadow, int y, int val, int s, int e){
        if(e <= y || y < s) return shadow.nNum;

        Node &curr = node[ncnt] = Node(s, e, ncnt);
        ncnt++;
        if(s+1 == e) curr.val = shadow.val + val;
        else{
            int mid = (s+e)/2;
            curr.lNum = addNode(node[shadow.lNum], y, val, s, mid);
            curr.rNum = addNode(node[shadow.rNum], y, val, mid, e);
            curr.val = node[curr.lNum].val + node[curr.rNum].val;
        }
        return curr.nNum;
    }
    int sum(int tn, int s, int e){
        return sum(node[root[tn]], s, e);
    }
    int sum(Node &curr, int s, int e){
        if(e <= curr.ns || curr.ne <= s) return 0;
        if(s <= curr.ns && curr.ne <= e) return curr.val;
        return sum(node[curr.lNum], s, e) + sum(node[curr.rNum], s, e);
    }

    int getXorMax(int s, int e, int k){
        return getXorMax(node[root[s-1]], node[root[e]], k, MAX_DEPTH-2);
    }
    int getXorMax(Node &sNode, Node &eNode, int k, int d){
        if(eNode.ns+1 == eNode.ne) return eNode.ns; // d == 0

        int b = k & 1<<d;
        if(b == 0){
            if(node[eNode.rNum].val - node[sNode.rNum].val > 0)
                return getXorMax(node[sNode.rNum], node[eNode.rNum], k, d-1);
            else
                return getXorMax(node[sNode.lNum], node[eNode.lNum], k, d-1);
        }
        else{
            if(node[eNode.lNum].val - node[sNode.lNum].val > 0)
                return getXorMax(node[sNode.lNum], node[eNode.lNum], k, d-1);
            else
                return getXorMax(node[sNode.rNum], node[eNode.rNum], k, d-1);
        }
    }

    void remove(int k){
        TN -= k;
    }

    int getLessOrEqual(int s, int e, int k){
        return sum(node[root[e]], 0, k+1) - sum(node[root[s-1]], 0, k+1);
    }

    int getKth(int s, int e, int k){
        return getKth(node[root[s-1]], node[root[e]], k);
    }
    int getKth(Node &sNode, Node &eNode, int k){
        if(eNode.ns+1 == eNode.ne) return eNode.ns;

        int pivot = node[eNode.lNum].val - node[sNode.lNum].val;
        if(k < pivot)
            return getKth(node[sNode.lNum], node[eNode.lNum], k);
        else
            return getKth(node[sNode.rNum], node[eNode.rNum], k - pivot);
    }
};

int main(){
    int Q;
    scanf("%d", &Q);
    PersistentSegTree PST;
    for(int i = 0; i < Q; ++i){
        int o, s, e, k;
        scanf("%d", &o);
        if(o == 1){
            scanf("%d", &k);
            PST.addNode(k);
        }
        else if(o == 2){
            scanf("%d %d %d", &s, &e, &k);
            printf("%d\n", PST.getXorMax(s, e, k));
        }
        else if(o == 3){
            scanf("%d", &k);
            PST.remove(k);
        }
        else if(o == 4){
            scanf("%d %d %d", &s, &e, &k);
            printf("%d\n", PST.getLessOrEqual(s, e, k));
        }
        else{
            scanf("%d %d %d", &s, &e, &k);
            printf("%d\n", PST.getKth(s, e, k-1));
        }
    }
}