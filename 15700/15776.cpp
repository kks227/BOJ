#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1<<20;
typedef pair<int, int> P;

char S[MAX];
int N, d, sa[MAX], pos[MAX];

struct SuffixNode{
	int sa;
	P rank;
	bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

void constructSA(){
	SuffixNode node[MAX], nodeTemp[MAX];
	for(int i=0; i<N; i++){
		node[i].sa = i;
		node[i].rank = P(S[i]-'0', i<N-1 ? S[i+1]-'0' : -1);
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



int main(){
	scanf("%d %s", &N, S);
	int p1 = 0, p2 = 0;
	for(; p1<N && S[p1]=='1'; p1++);
	if(p1 == N){
		puts("0 0");
		return 0;
	}
	for(p2=p1; p2<N && S[p2]=='0'; p2++);
	if(p2 == N){
		puts("0 0");
		return 0;
	}

	int len = -1, temp = 0;
	vector<int> candidate;
	for(int i=p2; i<=N; i++){
		if(i == N || S[i] == '0'){
			if(len < temp){
				candidate.clear();
				candidate.push_back(i-temp);
				len = temp;
			}
			else if(len == temp)
				candidate.push_back(i-temp);
			temp = 0;
		}
		else temp++;
	}
	if(candidate.size() == 1){
		printf("%d %d\n", p1, candidate[0]-p1);
		return 0;
	}

	constructSA();
	int rpos = -1, result = -1;
	for(int p3: candidate){
		if(rpos < pos[p3]){
			rpos = pos[p3];
			result = p3 - p1;
		}
	}
	printf("%d %d\n", p1, result);
}