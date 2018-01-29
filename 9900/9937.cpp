#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Line{
	long long A, B, C;
	Line(): Line(1, 1, 1){}
	Line(long long a, long long b, long long c): A(a), B(b), C(c){}
};

int main(){
	int N;
	vector<Line> L, H, V;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a < 0){ a *= -1; b *= -1; c *= -1; }
		if(a == 0) H.push_back(Line(a, b, c));
		else if(b == 0) V.push_back(Line(a, b, c));
		else L.push_back(Line(a, b, c));
	}
	sort(L.begin(), L.end(), [](Line &L1, Line L2){
		return L1.A*L2.B > L1.B*L2.A;
	});
	auto iter = L.begin();
	for(; iter != L.end(); iter++)
		if(iter->B > 0) break;
	L.insert(iter, V.begin(), V.end());
	L.insert(L.begin(), H.begin(), H.end());

	int g[300000] = {0}, gcnt[300000] = {1}, gsum[300001] = {0}, G = 0;
	for(int i=1; i<N; i++){
		Line &L1 = L[i-1], &L2 = L[i];
		if(L1.A*L2.B == L1.B*L2.A && L1.B*L2.C == L1.C*L2.B && L1.A*L2.C == L1.C*L2.A) continue;
		if(L1.A*L2.B != L1.B*L2.A) G++;
		g[i] = G;
		gcnt[g[i]]++;
	}
	G++;
	for(int i=0; i<G; i++)
		gsum[i+1] = gsum[i] + gcnt[i];

	int result = 0;
	for(int i=0; i<N; i++){
		int gn = g[i];
		if(gn == 0 || gn == G-1) continue;
		result = (1LL*gsum[gn]*(gsum[G]-gsum[gn+1]) + result) % MOD;
	}
	printf("%d\n", result);
}