#include <cstdio>
#include <cctype>
#include <stack>
#include <unordered_map>
using namespace std;
const int MAX = 1000000;

int N;
char I[MAX], P[2][MAX], PL[2];
unordered_map<char, int> C2N, OpN;
bool val[10];

bool backtrack(int pos){
	if(pos == N){
		bool result[2];
		for(int k = 0; k < 2; ++k){
			stack<bool> S;
			for(int i = 0; i < PL[k]; ++i){
				char c = P[k][i];
				if(islower(c)) S.push(val[C2N[c]]);
				else if(c == '~'){
					bool temp = S.top(); S.pop();
					S.push(!temp);
				}
				else{
					bool t1 = S.top(); S.pop();
					bool t2 = S.top(); S.pop();
					S.push(c == '&' ? t1&t2 : (c == '^' ? t1^t2 : t1|t2));
				}
			}
			result[k] = S.top();
		}
		return result[0] == result[1];
	}

	if(!backtrack(pos+1)) return false;
	val[pos] = true;
	if(!backtrack(pos+1)) return false;
	val[pos] = false;
	return true;
}



int main(){
	OpN['~'] = 0;
	OpN['&'] = 1;
	OpN['^'] = 2;
	OpN['|'] = 3;

	int T;
	scanf("%d\n", &T);
	for(int t = 1; t <= T; ++t){
		int threshold = -1, s[2] = {0,}, e[2] = {0,};
		bool binaryOpFlag = false;
		N = 0;
		C2N.clear();
		while(1){
			char c = getchar();
			if(c == '\n') break;
			if(c != ' '){
				if(e[1] == MAX-1) while(1);
				I[e[1]++] = c;
				if(islower(c) && C2N.find(c) == C2N.end()) C2N[c] = N++;
			}
		}
		I[e[1]] = '\0';

		for(int i = 0; ; ++i){
			if(islower(I[i])){
				if(binaryOpFlag || threshold == -1){
					binaryOpFlag = false;
					threshold = i;
				}
				else{
					for(++threshold; I[threshold] == ')'; ++threshold);
					break;
				}
			}
			else if(I[i] == '&' || I[i] == '^' || I[i] == '|') binaryOpFlag = true;
		}
		s[1] = e[0] = threshold;

		for(int k = 0; k < 2; ++k){
			stack<char> S;
			PL[k] = 0;
			for(int i = s[k]; i < e[k]; ++i){
				if(islower(I[i])) P[k][PL[k]++] = I[i];
				else if(I[i] == '(') S.push('(');
				else if(I[i] == ')'){
					while(S.top() != '('){
						P[k][PL[k]++] = S.top();
						S.pop();
					}
					S.pop();
				}
				else if(S.empty() || S.top() == '(') S.push(I[i]);
				else{
					while(!S.empty() && S.top() != '('){
						int p = OpN[S.top()], q = OpN[I[i]];
						if(p < q){
							P[k][PL[k]++] = S.top();
							S.pop();
						}
						else break;
					}
					S.push(I[i]);
				}
			}
			while(!S.empty()){
				P[k][PL[k]++] = S.top();
				S.pop();
			}
			P[k][PL[k]] = '\0';
		}

		fill(val, val+N, false);
		printf("Data set %d: %s\n", t, backtrack(0) ? "Equivalent" : "Different");
	}
}