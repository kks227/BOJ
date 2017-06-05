#include <cstdio>
#include <cmath>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, result = INT_MAX, r[2];
	P p[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &p[i].second);
		p[i].first = abs(p[i].second);
	}
	sort(p, p+N);
	for(int i=0; i<N-1; i++){
		int temp = abs(p[i].second + p[i+1].second);
		if(result > temp){
			result = temp;
			r[0] = p[i].second;
			r[1] = p[i+1].second;
			if(r[0] > r[1]) swap(r[0], r[1]);
		}
	}
	printf("%d %d\n", r[0], r[1]);
}