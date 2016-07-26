#include <cstdio>
#include <cstring>
using namespace std;

#define MODULA 100000LL

int N;
char S[201];
long long cache[201][201];
bool overLimit;

long long countCorrect(int start, int end){
	long long &ret = cache[start][end];
	if(ret != -1) return ret;
	if(start == end) return ret = 1;
	if((end-start)%2) return ret = 0;

	ret = 0;
	long long temp;
	if(S[start] == '('){
		for(int i=start+1; i<end; i+=2){
			if(S[i] == ')' || S[i] == '?'){
				temp = countCorrect(start+1, i) * countCorrect(i+1, end);
				if(temp >= MODULA){
					overLimit = true;
					temp %= MODULA;
				}
				ret += temp;
			}
		}
	}
	else if(S[start] == '{'){
		for(int i=start+1; i<end; i+=2){
			if(S[i] == '}' || S[i] == '?'){
				temp = countCorrect(start+1, i) * countCorrect(i+1, end);
				if(temp >= MODULA){
					overLimit = true;
					temp %= MODULA;
				}
				ret += temp;
			}
		}
	}
	else if(S[start] == '['){
		for(int i=start+1; i<end; i+=2){
			if(S[i] == ']' || S[i] == '?'){
				temp = countCorrect(start+1, i) * countCorrect(i+1, end);
				if(temp >= MODULA){
					overLimit = true;
					temp %= MODULA;
				}
				ret += temp;
			}
		}
	}
	else if(S[start] == '?'){
		for(int i=start+1; i<end; i+=2){
			if(S[i] == '?'){
				temp = 3 * countCorrect(start+1, i) * countCorrect(i+1, end);
				if(temp >= MODULA){
					overLimit = true;
					temp %= MODULA;
				}
				ret += temp;
			}
			else if(S[i] == ')' || S[i] == '}' || S[i] == ']'){
				temp = countCorrect(start+1, i) * countCorrect(i+1, end);
				if(temp >= MODULA){
					overLimit = true;
					temp %= MODULA;
				}
				ret += temp;
			}
		}
	}
	//else: ) } ]

	return (ret %= MODULA);
}

int main(){

	scanf("%d %s", &N, S);
	long long result;
	overLimit = false;
	memset(cache, -1, sizeof(long long) * 201 * 201);
	result = countCorrect(0, N);
	printf(overLimit?"%05lld\n":"%lld\n", result);

	return 0;
}