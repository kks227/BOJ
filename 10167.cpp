#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;
const int SIZE = 8192;
typedef tuple<int, int, int> P;

struct SegTree{
	int size, start;
	long long sum[SIZE], lsum[SIZE], rsum[SIZE], maxsum[SIZE];
	SegTree(int n): size(n){
		start = 1;
		while(start < size) start *= 2;
		clear();
	}
	void clear(){
		memset(sum, 0, sizeof(sum));
		memset(lsum, 0, sizeof(lsum));
		memset(rsum, 0, sizeof(rsum));
		memset(maxsum, 0, sizeof(maxsum));
	}
	void renew(int n, int w){
		int c = start + n;
		sum[c] = lsum[c] = rsum[c] = maxsum[c] += w;
		c /= 2;
		while(c > 0){
			int l = c*2;
			int r = l+1;
			sum[c] = sum[l] + sum[r];
			lsum[c] = max(lsum[l], sum[l]+lsum[r]);
			rsum[c] = max(rsum[r], sum[r]+rsum[l]);
			maxsum[c] = max(max(rsum[l]+lsum[r], sum[c]), max(maxsum[l], maxsum[r]));
			c /= 2;
		}
	}
};

int main(){
	int N, range = 0;
	long long result = 0;
	scanf("%d", &N);
	P point[3000];
	for(int i=0; i<N; i++){
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		point[i] = P(x, y, w);
		result = max(result, 1LL*w);
	}

	int tempX[3000];
	sort(point, point+N);
	for(int i=0; i<N; i++){
		if(i>0 && get<0>(point[i]) != get<0>(point[i-1])) range++;
		tempX[i] = range;
	}

	for(int i=0; i<N; i++){
		get<0>(point[i]) = get<1>(point[i]);
		get<1>(point[i]) = tempX[i];
	}
	sort(point, point+N);

	SegTree ST(range+1);
	for(int i=0; i<N; i++){
		if(i>0 && get<0>(point[i]) == get<0>(point[i-1])) continue;
		ST.clear();
		for(int j=i; j<N; j++){
			ST.renew(get<1>(point[j]), get<2>(point[j]));
			if(j==N-1 || get<0>(point[j]) != get<0>(point[j+1]))
				result = max(result, ST.maxsum[1]);
		}
	}
	printf("%lld\n", result);
}