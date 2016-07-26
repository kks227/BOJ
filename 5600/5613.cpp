#include <cstdio>
using namespace std;

int main(){
	int val;
	scanf("%d\n", &val);
	while(1){
		char op;
		scanf("%c", &op);
		if(op == '=') break;
		int next;
		scanf("%d\n", &next);
		if(op == '+') val += next;
		else if(op == '-') val -= next;
		else if(op == '*') val *= next;
		else val /= next;
	}
	printf("%d\n", val);
}