#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 262144;
typedef pair<int, int> P;

struct SegTree{
	int size, start;
	unsigned int cnt[SIZE];
	void init(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(cnt, 0, sizeof(cnt));
	}
	void inc(int a){
		a += start;
		while(a > 0){
			cnt[a]++;
			a /= 2;
		}
	}
	unsigned int get(int a, int b){
		if(a+1 == b) return cnt[start+a];
		unsigned int result = 0;
		a += start;
		b += start;
		while(1){
			if(a%2){
				result += cnt[a];
				a = a/2+1;
			}
			else a /= 2;
			if(b%2) result += cnt[b-1];
			b /= 2;
			if(a+1 == b) return result + cnt[a];
			if(a >= b) return result;
		}
	}
};

int main(){
	int T;
	scanf("%d", &T);
	SegTree ST;
	for(int t=0; t<T; t++){
		int N, range = 0;
		scanf("%d", &N);
		P point[75000];
		for(int i=0; i<N; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			point[i] = P(y, x);
		}

		int tempY[75000];
		sort(point, point+N);
		for(int i=0; i<N; i++){
			if(i>0 && point[i].first != point[i-1].first) range++;
			tempY[i] = range;
		}
		for(int i=0; i<N; i++){
			point[i].first = -point[i].second;
			point[i].second = tempY[i];
		}
		sort(point, point+N);

		unsigned int result = 0;
		ST.init(range+1);
		for(int i=0; i<N; i++){
			int y = point[i].second;
			result += ST.get(0, y+1);
			ST.inc(y);
		}
		printf("%u\n", result);
	}
}