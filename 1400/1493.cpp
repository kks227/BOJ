#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long limit[20], need[20];

vector<int> v3(int a, int b, int c){
	vector<int> V(3);
	V[0] = a;
	V[1] = b;
	V[2] = c;
	return V;
}

void setMinCubes(vector<int> s1, int i){
	sort(s1.begin(), s1.end());
	int cSize = 1<<i;
	if(s1[0] == 0) return;
	else if(i == 0){
		need[0] += 1LL * s1[0] * s1[1] * s1[2];
		return;
	}
	else if(s1[0] < cSize) setMinCubes(s1, i-1);
	else{
		need[i] += 1LL * (s1[0]/cSize) * (s1[1]/cSize) * (s1[2]/cSize);
		vector<int> s2(3);
		for(int i=0; i<3; i++)
			s2[i] = s1[i] % cSize;
		setMinCubes(v3(s1[0], s1[1], s2[2]), i-1);
		setMinCubes(v3(s2[0], s1[1], s1[2]-s2[2]), i-1);
		setMinCubes(v3(s1[0]-s2[0], s2[1], s1[2]-s2[2]), i-1);
	}
}

int main(){
	int L, W, H, N;
	scanf("%d %d %d %d", &L, &W, &H, &N);
	vector<int> S = v3(L, W, H);
	for(int i=0; i<N; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		limit[p] += q;
	}
	setMinCubes(S, 19);

	long long result = 0;
	for(int i=19; i>0; i--){
		if(limit[i] < need[i]){
			need[i-1] += (need[i]-limit[i])*8;
			need[i] = limit[i];
		}
		result += need[i];
	}
	if(limit[0] < need[0]) result = -1;
	else result += need[0];
	printf("%lld\n", result);
}