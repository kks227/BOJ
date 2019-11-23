#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		char S[MAX+1];
		scanf("%s", S);
		int L = strlen(S), result = 0;
		for(int i = 0, j = L-1; i < j; ++i, --j){
			if(S[i] != S[j]){
				if(S[i+1] != S[j] && S[i] != S[j-1]){
					result = 2;
					break;
				}
				bool flag = false;
				for(int k = 0; k < 2 && !flag; ++k){
					int s = i, e = j;
					if(k == 0) ++s;
					else --e;
					flag = true;
					for(int x = s, y = e; x < y; ++x, --y){
						if(S[x] != S[y]){
							flag = false;
							break;
						}
					}
				}
				result = (flag ? 1 : 2);
				break;
			}
		}
		printf("%d\n", result);
	}
}