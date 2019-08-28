#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 50;

char E[MAX+1];
int oppo[MAX];

int compress(int s, int e){
	int result = 0;
	for(int i = s; i < e; ++i){
		if(E[i] == '('){
			result += (E[i-1]-'0') * compress(i+1, oppo[i]) - 1;
			i = oppo[i];
		}
		else ++result;
	}
	return result;
}

int main(){
	stack<int> S;
	scanf("%s", E);
	for(int i = 0; E[i]; ++i){
		if(E[i] == '(') S.push(i);
		else if(E[i] == ')'){
			oppo[S.top()] = i;
			S.pop();
		}
	}
	printf("%d\n", compress(0, strlen(E)));
}