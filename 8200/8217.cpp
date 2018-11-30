#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 300000;

struct FenwickTree{
	int size;
	long long arr[MAX+1];
	FenwickTree(): FenwickTree(1){}
	FenwickTree(int size1): size(size1){ fill(arr, arr+MAX+1, 0); }
	void add(int pos, int k){
		while(pos <= size){
			arr[pos] += k;
			pos += pos & -pos;
		}
	}
	long long getVal(int pos){
		long long result = 0;
		while(pos > 0){
			result += arr[pos];
			pos -= pos & -pos;
		}
		return result;
	}
};



int main(){
	int N, M, K, target[MAX], q[MAX][3];
	vector<int> pos[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int o;
		scanf("%d", &o);
		pos[o-1].push_back(i);
	}
	for(int i = 0; i < N; ++i)
		scanf("%d", target+i);
	scanf("%d", &K);
	for(int i = 0; i < K; ++i)
		scanf("%d %d %d", &q[i][0], &q[i][1], &q[i][2]);

	int lo[MAX] = {0}, hi[MAX];
	fill(hi, hi+N, K+1);
	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < N; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		FenwickTree FT(M);
		for(int i = 0; i < K; ++i){
			if(q[i][0] <= q[i][1]){
				FT.add(q[i][0], q[i][2]);
				FT.add(q[i][1]+1, -q[i][2]);
			}
			else{
				FT.add(1, q[i][2]);
				FT.add(q[i][1]+1, -q[i][2]);
				FT.add(q[i][0], q[i][2]);
			}

			for(int k: G[i+1]){
				long long temp = 0;
				for(int j: pos[k])
					if((temp += FT.getVal(j+1)) >= target[k]) break;
				(temp >= target[k] ? hi : lo)[k] = i+1;
			}
		}
	}

	for(int i = 0; i < N; ++i){
		if(lo[i] == K) puts("NIE");
		else printf("%d\n", hi[i]);
	}
}