#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<double, double> P;

int main(){
	P p[4];
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p[0].first, &p[0].second, &p[1].first, &p[1].second, &p[2].first, &p[2].second, &p[3].first, &p[3].second) > 0){
		int x, y, z;
		if(p[0] == p[2]){
			x = 0; y = 1; z = 3;
		}
		else if(p[0] == p[3]){
			x = 0; y = 1; z = 2;
		}
		else if(p[1] == p[2]){
			x = 1; y = 0; z = 3;
		}
		else{
			x = 1; y = 0; z = 2;
		}
		P m((p[y].first+p[z].first)/2, (p[y].second+p[z].second)/2);
		printf("%.3lf %.3lf\n", 2*m.first-p[x].first, 2*m.second-p[x].second);
	}
}