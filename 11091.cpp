#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		char c;
		bool check[26] = {0};
		while((c=getchar()) != '\n'){
			if(isupper(c)) c = tolower(c);
			if(islower(c)) check[c-'a'] = true;
		}
		bool success = true;
		for(int i=0; i<26; i++)
			if(!check[i]){
				success = false;
				break;
			}
		if(success) puts("pangram");
		else{
			printf("missing ");
			for(int i=0; i<26; i++)
				if(!check[i]) putchar(i+'a');
			puts("");
		}
	}
}