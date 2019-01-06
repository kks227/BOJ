#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 50;
typedef pair<int, int> P;

int main(){
	int R, C;
	char map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}
	vector<P> result;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == '#') continue;
			bool flag = false;
			if(i == 0 || map[i-1][j] == '#'){
				if(i+2 < R && map[i+1][j] == '.' && map[i+2][j] == '.')
					flag = true;
			}
			if(j == 0 || map[i][j-1] == '#'){
				if(j+2 < C && map[i][j+1] == '.' && map[i][j+2] == '.')
					flag = true;
			}
			if(flag) result.push_back(P(i+1, j+1));
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	for(auto &p: result)
		printf("%d %d\n", p.first, p.second);
}