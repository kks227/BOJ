#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	
	bool map[100][100] = {0};
	int N, x, y, hist[101] = {0};
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &x, &y);
        for(int i=0; i<10; i++)
            memset(&map[y+i][x], 1, 10);
    }

	int result = 0, k;
	stack<int> s;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(map[i][j]) hist[j]++;
			else hist[j] = 0;
		}

		for(int j=0; j<101; j++){
			while(!s.empty() && hist[s.top()] >= hist[j]){
				k = s.top();
				s.pop();
				result = max(result, hist[k]*(s.empty()?j:j-s.top()-1));
			}
			s.push(j);
		}
		while(!s.empty())
			s.pop();
	}
	printf("%d\n", result);

	return 0;
}