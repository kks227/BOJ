#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

inline int ccw(P A, P B, P C){
	return (B.second-A.second)*(C.first-A.first) - (B.first-A.first)*(C.second-A.second);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		printf("Data Set %d:\n", t);

		int x = 0, y = 0;
		bool notConstant = false, basic = false;
		stack<bool> s, isX;
		bool exist[51][51] = {0}; // [x][y]
		while(1){
			char opcode[11];
			scanf("%s", opcode);
			if(strcmp(opcode, "endprogram") == 0) break;
			if(strcmp(opcode, "loop") == 0){
				char var;
				scanf(" %c", &var);
				isX.push(var=='x');
				isX.top() ? x++ : y++;
				s.push(basic);
				basic = false;
			}
			else if(strcmp(opcode, "endloop") == 0){
				if(basic) exist[x][y] = notConstant = true;
				basic = s.top();
				s.pop();
				isX.top() ? x-- : y--;
				isX.pop();
			}
			else if(strcmp(opcode, "basic") == 0) basic = true;
		}

		if(notConstant){
			for(int k=0; k<=100; k++){
				int left=51, right=-1;
				for(int i=0; i<=50; i++)
					if(i<=50 && k-i<=50 && exist[i][k-i]){
						left = min(left, i);
						right = max(right, i);
					}
				for(int i=left+1; i<right; i++)
					exist[i][k-i] = false;
			}
			for(int i=0; i<=50; i++)
				for(int j=0; j<=50; j++)
					if(exist[i][j]){
						for(int p=0; p<=i; p++)
							for(int q=0; q<=j; q++)
								exist[p][q] = false;
						exist[i][j] = true;
					}

			vector<P> candidate;
			for(int i=50; i>=0; i--)
				for(int j=50; j>=0; j--)
					if(exist[i][j]) candidate.push_back(P(i, j));
			vector<P> result;
			if(candidate.size() > 2){
				stack<P> gscan;
				gscan.push(P(0, 0));
				gscan.push(candidate.front());
				for(int i=1; i<candidate.size(); i++){
					while(gscan.size() >= 2){
						P first, second;
						first = gscan.top();
						gscan.pop();
						second = gscan.top();
						if(ccw(second, first, candidate[i]) < 0){
							gscan.push(first);
							break;
						}
					}
					gscan.push(candidate[i]);
				}
				while(gscan.size() > 1){
					result.push_back(gscan.top());
					gscan.pop();
				}
				reverse(result.begin(), result.end());
			}
			else result = candidate;
			for(int i=0; i<result.size(); i++){
				if(i) printf(" + ");
				int xd = result[i].first, yd = result[i].second;
				if(xd == 1) printf("x");
				else if(xd > 1) printf("x^%d", xd);
				if(yd == 1) printf("y");
				else if(yd > 1) printf("y^%d", yd);
			}

			bool init = true;
			for(int i=50; i>=0; i--){
				for(int j=50; j>=0; j--)
					if(exist[i][j]){
						init = false;
						break;
					}
			}
			puts("");
		}
		else printf("%d\n", basic);

		puts("");
	}
}