#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	bool ball[3] = {true,};
	int s[3][2] = {0, 1, 1, 2, 0, 2};
	while(1){
		char c = getchar();
		if(c == '\n') break;
		int k = c - 'A';
		swap(ball[s[k][0]], ball[s[k][1]]);
	}
	for(int i = 0; i < 3; ++i)
		if(ball[i]) printf("%d\n", i+1);
}