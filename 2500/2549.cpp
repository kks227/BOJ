#include <cstdio>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

struct PrevNode{
	string ps; // "": initial status(start | end)
	bool rc; // 0: row, 1: column
	int n, k;
	PrevNode(): ps(""){}
	PrevNode(string p, bool rc1, int n1, int k1): ps(p), rc(rc1), n(n1), k(k1){}
};
typedef pair<string, bool> QNode;
typedef map<string, PrevNode> NodeMap;

struct ResultVals{
	bool rc;
	int n, k;
	ResultVals(){}
	ResultVals(bool rc1, int n1, int k1): rc(rc1), n(n1), k(k1){}
};

string getNext(string curr, bool rc, int n, int k){
	if(rc){
		for(int i=0; i<k; i++)
			for(int j=2; j>=0; j--)
				swap(curr[j*4 + n], curr[(j+1)*4 + n]);
	}
	else{
		for(int i=0; i<k; i++)
			for(int j=2; j>=0; j--)
				swap(curr[n*4 + j], curr[n*4 + j+1]);
	}
	return curr;
}

int main(){
	NodeMap sourceStart, sourceEnd;
	string start = "", end = "";
	for(int i=1; i<=16; i++){
		int n;
		scanf("%d", &n);
		start.push_back(n);
		end.push_back(i);
	}

	sourceStart[start] = PrevNode();
	sourceEnd[end] = PrevNode();
	queue<QNode> Q;
	Q.push(QNode(start, false));
	Q.push(QNode(end, true));
	while(1){
		int qSize = Q.size();
		for(int q=0; q<qSize; q++){
			string curr = Q.front().first;
			bool s = Q.front().second;
			Q.pop();
			NodeMap &source = (s ? sourceEnd : sourceStart);
			NodeMap &opposite = (s ? sourceStart : sourceEnd);
			if(opposite.find(curr) != opposite.end()){
				deque<ResultVals> result;
				for(string t=curr; t!=start;){
					PrevNode &pt = sourceStart[t];
					result.push_front(ResultVals(pt.rc, pt.n, pt.k));
					t = pt.ps;
				}
				for(string t=curr; t!=end;){
					PrevNode &pt = sourceEnd[t];
					result.push_back(ResultVals(pt.rc, pt.n, 4-pt.k));
					t = pt.ps;
				}
				printf("%d\n", result.size());
				for(ResultVals &r: result)
					printf("%d %d %d\n", r.rc+1, r.n+1, r.k);
				return 0;
			}

			for(int i=0; i<4; i++)
				for(int j=1; j<4; j++)
					for(int k=0; k<2; k++){
						string next = getNext(curr, k, i, j);
						if(source.find(next) != source.end()) continue;
						Q.push(QNode(next, s));
						source[next] = PrevNode(curr, k, i, j);
					}
		}
	}
}