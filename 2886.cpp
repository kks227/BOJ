#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

inline int distSquare(int x1, int y1, int x2, int y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	char map[100][100];
	vector<P> X, L;
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'X') X.push_back(P(i, j));
			else if(map[i][j] == 'L') L.push_back(P(i, j));
		}
	}

	vector<T> pairs;
	for(int i=0; i<X.size(); i++)
		for(int j=0; j<L.size(); j++)
			pairs.push_back(T(distSquare(X[i].first, X[i].second, L[j].first, L[j].second), i, j));
	sort(pairs.begin(), pairs.end());

	int result = 0;
	while(!pairs.empty()){
		int dist = get<0>(pairs[0]);
		int sn = get<2>(pairs[0]);
		vector<int> pn;
		for(int i=0; i<pairs.size(); i++){
			if(get<0>(pairs[i]) != dist) break;
			if(get<2>(pairs[i]) == sn) pn.push_back(get<1>(pairs[i]));
		}
		for(int i=0; i<pairs.size(); ){
			if(get<2>(pairs[i])==sn || find(pn.begin(), pn.end(), get<1>(pairs[i]))!=pn.end())
				pairs.erase(pairs.begin() + i);
			else i++;
		}
		if(pn.size() >= 2) result++;
	}
	printf("%d\n", result);
}