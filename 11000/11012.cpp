#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_DEPTH = 18;
const int MAX_ST = 1<<MAX_DEPTH;
const int MAX = 10001;
const int MAX_RANGE = 100001;
const int MAX_NODE = MAX_ST + MAX*MAX_DEPTH;
typedef pair<int, int> P;

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
	void addNode(int y, int val){
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
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M;
		P p[MAX];
		vector<int> xPos;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; ++i){
			scanf("%d %d", &p[i].first, &p[i].second);
			xPos.push_back(p[i].first);
		}
		sort(p, p+N);
		sort(xPos.begin(), xPos.end());
		xPos.resize(unique(xPos.begin(), xPos.end()) - xPos.begin());

		PersistentSegTree PST;
		int tn[MAX_RANGE];
		fill(tn, tn+MAX_RANGE, -1);
		for(int i = 0, j = 0; i < xPos.size(); ++i){
			int x = xPos[i];
			while(j < N && p[j].first == x){
				tn[x] = j + 1;
				PST.addNode(p[j++].second, 1);
			}
		}
		xPos.push_back(MAX_RANGE);

		long long result = 0;
		for(int i = 0; i < M; ++i){
			int x1, x2, y1, y2;
			scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
			int p1 = lower_bound(xPos.begin(), xPos.end(), x1) - xPos.begin() - 1;
			int p2 = upper_bound(xPos.begin(), xPos.end(), x2) - xPos.begin() - 1;
			if(p2 >= 0) result += PST.sum(tn[xPos[p2]], y1, y2+1);
			if(p1 >= 0) result -= PST.sum(tn[xPos[p1]], y1, y2+1);
		}
		printf("%lld\n", result);
	}
}