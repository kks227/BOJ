#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const double PI = 3.14159265358979323846;
typedef pair<int, int> P;

inline long long d2(int x, int y){ return 1LL*x*x + 1LL*y*y; }
inline long long cross(int x1, int y1, int x2, int y2){ return 1LL*x1*y2 - 1LL*x2*y1; }

int main(){
	int N;
	long long L = 0;
	vector<P> pos;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		long long temp = d2(x, y);
		if(temp > L){
			L = temp;
			pos.clear();
			pos.push_back(P(x, y));
		}
		else if(temp == L) pos.push_back(P(x, y));
	}
	if(pos.size() == 1){
		puts("360");
		return 0;
	}
	int M = pos.size();
	pos.push_back(pos[0]);

	double result = 0;
	for(int i=0; i<M; i++){
		int x1 = pos[i].first, y1 = pos[i].second, x2 = pos[i+1].first, y2 = pos[i+1].second;
		double theta = acos((1LL*x1*x2 + 1LL*y1*y2)/double(L));
		long long c = cross(x1, y1, x2, y2);
		if(c < 0) theta = PI*2 - theta;
		result = max(result, theta);
	}
	printf("%.10lf\n", result*180/PI);
}