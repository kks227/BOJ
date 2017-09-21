#include <cstdio>
#include <algorithm>
using namespace std;

struct Stat{
	int val[3];
	bool operator <(const Stat &O){
		for(int i=0; i<3; i++)
			if(val[i] != O.val[i]) return val[i] < O.val[i];
		return false;
	}
};

int main(){
	int N, K, result = 3000000;
	Stat stat[100];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &stat[i].val[j]);
	sort(stat, stat+N);

	for(int i=K-1; i<N; i++){
		for(int j=0; j<=i; j++){
			int cnt = 0, temp[100];
			for(int k=0; k<=i; k++)
				if(stat[k].val[1] <= stat[j].val[1]) temp[cnt++] = stat[k].val[2];
			if(cnt < K) continue;

			sort(temp, temp+cnt);
			result = min(result, stat[i].val[0] + stat[j].val[1] + temp[K-1]);
		}
	}
	printf("%d\n", result);
}