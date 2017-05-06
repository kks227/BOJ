#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct Node{
	int r, c;
	vector<int> cell;
	Node(): Node(0){}
	Node(int d){
		r = c = -1;
		cell.resize(d*d);
	}
};

int main(){
	char comm[6];
	int D, N;
	while(scanf("%s %d %d", comm, &D, &N) > 0){
		Node S[2];
		for(int k=0; k<2; k++){
			S[k] = Node(D);
			for(int i=0; i<D; i++){
				for(int j=0; j<D; j++){
					char val[4];
					scanf("%s", val);
					if(val[0] == 'X'){
						S[k].r = i;
						S[k].c = j;
					}
					else sscanf(val, "%d", &S[k].cell[i*D+j]);
				}
			}
		}

		map<vector<int>, int> M[2];
		for(int k=0; k<2; k++){
			queue<Node> Q;
			M[k][S[k].cell] = 0;
			Q.push(S[k]);
			for(int i=0; i<N/2+(N%2&&k); i++){
				int qSize = Q.size();
				for(int j=0; j<qSize; j++){
					Node curr = Q.front();
					Q.pop();
					int cr = curr.r, cc = curr.c, p = cr*D+cc;
					for(int d=0; d<4; d++){
						int nr = cr+roff[d], nc = cc+coff[d], np = nr*D+nc;
						if(nr < 0 || nr >= D || nc < 0 || nc >= D) continue;

						swap(curr.cell[p], curr.cell[np]);
						if(M[k].find(curr.cell) == M[k].end()){
							curr.r = nr; curr.c = nc;
							M[k][curr.cell] = i+1;
							Q.push(curr);
						}
						swap(curr.cell[p], curr.cell[np]);
					}
				}
			}
		}

		int result = N+1;
		for(auto iter1: M[0]){
			auto iter2 = M[1].find(iter1.first);
			if(iter2 != M[1].end())
				result = min(result, iter1.second + iter2->second);
		}
		if(result <= N) printf("SOLVABLE WITHIN %d MOVES\n\n", result);
		else printf("NOT SOLVABLE WITHIN %d MOVES\n\n", N);
		scanf("%s", comm);
	}
}