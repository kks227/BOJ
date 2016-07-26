#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef vector<char> V;
typedef map<V, double> M;

char card[9][4];
M cache;
V basis(9, -1);

double possibility(V pos){
	M::iterator iter = cache.find(pos);
	if(iter != cache.end()) return iter->second;
	if(pos == basis) return cache[pos] = 1.0;
	int cnt = 0;
	double result = 0.0;
	for(int i=0; i<8; i++){
		if(pos[i] == -1) continue;
		for(int j=i+1; j<9; j++){
			if(pos[j] == -1) continue;
			if(card[i][pos[i]] == card[j][pos[j]]){
				pos[i]--; pos[j]--;
				result += possibility(pos);
				cnt++;
				pos[i]++; pos[j]++;
			}
		}
	}
	if(cnt == 0) return cache[pos] = 0.0;
	return cache[pos] = result/cnt;
}

int main(){
	for(int i=0; i<9; i++)
		for(int j=0; j<4; j++){
			char str[3];
			scanf("%s", str);
			card[i][j] = str[0];
		}
	printf("%.6lf\n", possibility(V(9, 3)));
}