#include <cstdio>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<double, int, int> Point;

double distance(Point A, Point B){
	return sqrt(pow(get<1>(A)-get<1>(B), 2.0) + pow(get<2>(A)-get<2>(B), 2.0));
}

double ccw(Point A, Point B, Point C){
	return (get<1>(B)-get<1>(A))*(get<2>(C)-get<2>(A)) - (get<2>(B)-get<2>(A))*(get<1>(C)-get<1>(A));
}

bool compare(Point A, Point B){
	if(get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
	if(get<2>(A) == get<2>(B)) return get<1>(A) < get<1>(B);
	return get<2>(A) > get<2>(B);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		vector<Point> p(N);
		for(int i=0; i<N; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			p[i] = Point(0, x, y);
		}
		sort(p.begin(), p.end(), compare);
		for(int i=1; i<N; i++)
			get<0>(p[i]) = (get<1>(p[i])-get<1>(p[0]))/distance(p[0], p[i]);
		sort(p.begin()+1, p.end(), compare);

		vector<Point> s;
		s.push_back(p[0]);
		s.push_back(p[1]);
		int next = 2;
		while(next < N){
			while(s.size() >= 2){
				Point first, second;
				first = s.back();
				second = s[s.size()-2];
				if(ccw(second, first, p[next]) < 0) break;
				s.pop_back();
			}
			s.push_back(p[next++]);
		}

		printf("%d\n", s.size());
		for(int i=0; i<s.size(); i++)
			printf("%d %d\n", get<1>(s[i]), get<2>(s[i]));
	}
}