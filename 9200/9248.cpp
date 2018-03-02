#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1<<19;

char S[MAX];
int N, sa[MAX], pos[MAX], lcp[MAX];

struct SuffixNode{
	int sa;
	P rank;
	bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

void constructSA(){
	N = strlen(S);
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

int main(){
	scanf("%s", S);
	constructSA();
	constructLCP();
	for(int i=0; i<N; i++)
		printf("%d ", sa[i]+1);
	printf("\nx ");
	for(int i=0; i<N-1; i++)
		printf("%d ", lcp[i]);
}