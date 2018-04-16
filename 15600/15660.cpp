#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef function<P(int, int)> PairFunction;
const bool b[7][4][4] = {
	{1,1,1,1,},
	{1,1,0,0, 1,1,0,0,},
	{1,0,0,0, 1,0,0,0, 1,1,0,0,},
	{0,1,0,0, 0,1,0,0, 1,1,0,0,},
	{1,0,0,0, 1,1,0,0, 0,1,0,0,},
	{0,1,0,0, 1,1,0,0, 1,0,0,0,},
	{1,1,1,0, 0,1,0,0,}
};
PairFunction rot[] = {
	[](int i, int j){ return P(i, j); },
	[](int i, int j){ return P(j, 3-i); },
	[](int i, int j){ return P(3-i, 3-j); },
	[](int i, int j){ return P(3-j, i); }
};

struct Node{
	int k, r, i, j;
	Node(): Node(0, 0, 0, 0){}
	Node(int k1, int r1, int i1, int j1): k(k1), r(r1), i(i1), j(j1){}
	vector<P> getPos(){
		vector<P> result;
		for(int ii=0; ii<4; ii++){
			for(int jj=0; jj<4; jj++){
				if(!b[k][ii][jj]) continue;
				int rr, cc;
				tie<int, int>(rr, cc) = rot[r](ii, jj);
				rr += i; cc += j;
				result.push_back(P(rr, cc));
			}
		}
		return result;
	}
};

int R, C, map[500][500];
vector<pair<int, Node>> node;

void cover(int k, int r, int i, int j){
	int temp = 0;
	vector<P> cell;
	for(int ii=0; ii<4; ii++){
		for(int jj=0; jj<4; jj++){
			if(!b[k][ii][jj]) continue;

			int rr, cc;
			tie<int, int>(rr, cc) = rot[r](ii, jj);
			rr += i; cc += j;
			if(rr < 0 || rr >= R || cc < 0 || cc >= C) return;
			temp += map[rr][cc];
			cell.push_back(P(rr, cc));
		}
	}
	node.push_back({temp, Node(k, r, i, j)});
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	for(int k=0; k<7; k++)
		for(int r=0; r<4; r++)
			for(int i=-3; i<R; i++)
				for(int j=-3; j<C; j++)
					cover(k, r, i, j);
	sort(node.begin(), node.end(), [](auto &p, auto &q){
		return (p.first < q.first);
	});

	int result = 0;
	for(int i=node.size()-1; i>0; i--){
		if(node[i].first + node[i-1].first <= result) break;
		vector<P> ip = node[i].second.getPos();
		for(int j=i-1; j>=0; j--){
			bool flag = true;
			vector<P> jp = node[j].second.getPos();
			for(auto &p: ip){
				for(auto &q: jp){
					if(p == q){
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag){
				result = max(node[i].first + node[j].first, result);
				break;
			}
		}
	}
	printf("%d\n", result);
}