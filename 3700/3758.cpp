#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;

struct Team{
	int score[MAX], sum, cnt, latest, id;
	Team(): Team(0){}
	Team(int id1): id(id1), sum(0), cnt(0), latest(0){ fill(score, score+MAX, 0); }
	bool operator <(const Team& O)const{
		if(sum != O.sum) return sum > O.sum;
		if(cnt != O.cnt) return cnt < O.cnt;
		return latest < O.latest;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, K, id, M;
		Team team[MAX];
		scanf("%d %d %d %d", &N, &K, &id, &M);
		--id;
		for(int i = 0; i < N; ++i)
			team[i].id = i;
		for(int i = 0; i < M; ++i){
			int tn, pn, s;
			scanf("%d %d %d", &tn, &pn, &s);
			--tn; --pn;
			if(team[tn].score[pn] < s){
				team[tn].sum += s - team[tn].score[pn];
				team[tn].score[pn] = s;
			}
			++team[tn].cnt;
			team[tn].latest = i+1;
		}
		sort(team, team+N);
		for(int i = 0; i < N; ++i){
			if(team[i].id == id){
				printf("%d\n", i+1);
				break;
			}
		}
	}
}