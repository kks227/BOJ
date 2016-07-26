#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define MAX 32768

typedef vector<int> intVector;
typedef map<int, int> intMap;
typedef stack<int> intStack;

int main(){

	int T, pos, ptr, loop, end, len;
	char op[128001], line[128001], c;
	bool error, eoi;
	intVector SNtoP, ENtoP; 
	intMap SPtoN, EPtoN;
	intStack S;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++){
		pos = loop = 0;
		error = eoi = false;
		SNtoP.clear();
		ENtoP.clear();
		while(!eoi){
			gets(line);
			if(strcmp(line, "end") == 0){
				end = pos;
				op[end] = '\0';
				break;
			}
			if(error) continue;

			len = strlen(line);
			for(int i=0; i<len; i++){
				switch(line[i]){
				case '>':
					if(pos==0 || op[pos-1] != '<') op[pos++] = '>';
					else pos--;
					break;
				case '<':
					if(pos==0 || op[pos-1] != '>') op[pos++] = '<';
					else pos--;
					break;
				case '+':
					if(pos==0 || op[pos-1] != '-') op[pos++] = '+';
					else pos--;
					break;
				case '-':
					if(pos==0 || op[pos-1] != '+') op[pos++] = '-';
					else pos--;
					break;
				case '.':
					op[pos++] = '.';
					break;
				case '[':
					SNtoP.push_back(pos);
					ENtoP.push_back(-1);
					SPtoN[pos] = loop;
					S.push(loop++);
					op[pos++] = '[';
					break;
				case ']':
					if(S.empty()){
						error = true;
						break;
					}
					if(op[pos-1] != '['){
						ENtoP[S.top()] = pos;
						EPtoN[pos] = S.top();
						S.pop();
						op[pos++] = ']';
					}
					else{
						S.pop();
						loop--;
						pos--;
					}
					break;
				case '%':
					while(line[i++]);
				}
			}
		}
		printf("PROGRAM #%d:\n", t);
		if(error || !S.empty()){
			puts("COMPILE ERROR");
			while(!S.empty()) S.pop();
			continue;
		}

		unsigned char buffer[MAX] = {0};
		pos = ptr = 0;
		while(pos != end){
			switch(op[pos]){
			case '>':
				ptr++;
				if(ptr == MAX) ptr = 0;
				break;
			case '<':
				ptr--;
				if(ptr == -1) ptr = MAX-1;
				break;
			case '+':
				buffer[ptr]++;
				break;
			case '-':
				buffer[ptr]--;
				break;
			case '.':
				putchar(buffer[ptr]);
				break;
			case '[':
				if(!buffer[ptr]) pos = ENtoP[SPtoN[pos]];
				break;
			case ']':
				if(buffer[ptr]) pos = SNtoP[EPtoN[pos]];
			}
			pos++;
		}
		puts("");
	}

	return 0;
}