#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX_H = 19;
const int MAX = 1<<MAX_H;
const int INF = 1e9;

struct SuffixNode{
	int sa;
	P rank;
	bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

struct SuffixArray{
	char S[MAX+1];
	int N, sa[MAX], pos[MAX], lcp[MAX];

	void constructSA(){
		SuffixNode node[MAX], nodeTemp[MAX];
		for(int i=0; i<N; i++){
			node[i].sa = i;
			node[i].rank = P(S[i]-'a', i<N-1 ? S[i+1]-'a' : -1);
		}
		sort(node, node+N);

		for(int d=2; d<N; d*=2){
			int M = 0, temp = node[0].rank.first;
			node[0].rank.first = pos[node[0].sa] = 0;

			for(int i=1; i<N; i++){
				if(P(temp, node[i-1].rank.second) == node[i].rank) node[i].rank.first = M;
				else{
					temp = node[i].rank.first;
					node[i].rank.first = ++M;
				}
				pos[node[i].sa] = i;
			}
			M++;

			int cnt[MAX+1] = {0};
			for(int i=0; i<N; i++){
				int j = node[i].sa + d;
				node[i].rank.second = (j < N ? node[pos[j]].rank.first : -1);
				cnt[node[i].rank.second+1]++;
			}
			for(int i=1; i<M+1; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				nodeTemp[--cnt[node[i].rank.second+1]] = node[i];

			fill(cnt, cnt+M+1, 0);
			for(int i=0; i<N; i++)
				cnt[nodeTemp[i].rank.first]++;
			for(int i=1; i<M; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				node[--cnt[nodeTemp[i].rank.first]] = nodeTemp[i];
		}

		for(int i=0; i<N; i++){
			sa[i] = node[i].sa;
			pos[sa[i]] = i;
		}
	}

	void constructLCP(){
		for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
			if(pos[i] == N-1) continue;
			for(int j=sa[pos[i]+1]; S[i+k]==S[j+k]; k++);
			lcp[pos[i]] = k;
		}
	}
};

int main(){
	SuffixArray SA;
	scanf("%s", &SA.S);
	int N = SA.N = strlen(SA.S);
	reverse(SA.S, SA.S+N);
	SA.constructSA();
	SA.constructLCP();

	int B[MAX_H][MAX] = {0};
	copy(SA.lcp, SA.lcp+N-1, B[0]);
	for(int h=1; h<MAX_H; h++)
		for(int i=0, p=1<<h; i<N-p; i++)
			B[h][i] = min(B[h-1][i], B[h-1][i+p/2]);

	char T[MAX*2+1] = {0};
	for(int i=N-1; i>=0; i--){
		T[i*2+1] = SA.S[i];
		T[i*2] = '.';
	}
	int M = N*2, A[MAX*2+1] = {0};
	T[M++] = '.';
	for(int i=0, R=-1, p=-1; i<M; i++){
		A[i] = (i <= R ? min(A[2*p-i], R-i) : 0);
		while(i-A[i]-1 >= 0 && i+A[i]+1 < M && T[i-A[i]-1] == T[i+A[i]+1]) A[i]++;
		if(i+A[i] > R){
			R = i+A[i];
			p = i;
		}
	}

	long long result;
	unordered_set<int> cache[MAX];
	for(int i=0; i<M; i++){
		for(int j=0; j<(A[i]+1)/2; j++){
			int len = A[i] - j*2;
			int pivot = SA.pos[i/2-len/2];
			int s = pivot, e = pivot;
			for(int h=MAX_H-1; h>=0; h--){
				int p = 1 << h;
				if(s >= p && B[h][s-p] >= len) s -= p;
				if(e+p <= N && B[h][e] >= len) e += p;
			}
			int cnt = e-s+1;
			if(cache[s].find(len) == cache[s].end()){
				cache[s].insert(len);
				result = max(1LL*cnt*len, result);
			}
			else break;
		}
	}
	printf("%lld\n", result);
}