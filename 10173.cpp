#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		char line[81], nemo[4] = {'n', 'e', 'm', 'o'};
		gets(line);
		if(strcmp(line, "EOI") == 0) break;
		int len = strlen(line);
		for(int i=0; i<len; i++)
			line[i] = tolower(line[i]);
		puts(search(line, line+len, nemo, nemo+4) != line+len ? "Found" : "Missing");
	}
}