#include <cstdio>
#include <cstring>

int main(){
	char S[7001], T[501];
	int stack[10];
	bool result;
	int top, Ttop, len, temp;
	while(gets(S)){
		result = true;
		len = strlen(S);
		top = -1;
		Ttop = 0;
		for(int i=0; i<len;){
			switch(S[i]){
				// special character: &lt; &gt; &amp; &xHEX;
			case '&':
				i++;
				if(i==len){
					result = false;
					break;
				}
				else if(S[i]=='l' || S[i]=='g'){
					result = (i+2<len && S[i+1]=='t' && S[i+2]==';');
					i+=3;
				}
				else if(S[i]=='a'){
					result = (i+3<len && S[i+1]=='m' && S[i+2]=='p' && S[i+3]==';');
					i+=4;
				}
				else if(S[i]=='x'){
					temp = ++i;
					for(; i<len && S[i]!=';'; i++)
						if(!(S[i]>='0'&&S[i]<='9' || S[i]>='A'&&S[i]<='F' || S[i]>='a'&&S[i]<='f')) break;
					if(i==len){
						result = false;
						break;
					}
					if(S[i]!=';'){
						result = false;
						break;
					}
					if(i==temp || (i-temp)%2){
						result = false;
						break;
					}
					i++;
				}
				else result = false;
				break;

				// tag
			case '<':
				i++;
				if(i==len){
					result = false;
					break;
				}
				// closing
				if(S[i]=='/'){
					if(top==-1){
						result = false;
						break;
					}
					i++;
					for(; i<len && S[i]!='>'; i++);
					if(i==len){
						result = false;
						break;
					}
					if(!result) break;
					int cnt = Ttop-stack[top];
					if(strncmp(S+i-cnt, T+stack[top], cnt)!=0){
						result = false;
						break;
					}
					Ttop = stack[top--];
					i++;
				}
				// opening
				else{
					stack[++top] = Ttop;
					for(; i<len && S[i]!='>'; i++){
						if(S[i] == '/'){
							result = (i+1<len && S[i+1]=='>');
							i++;
							break;
						}
						if(!(S[i]>='0'&&S[i]<='9' || S[i]>='a'&&S[i]<='z')){
							result = false;
							break;
						}
						T[Ttop++] = S[i];
					}
					if(!result) break;
					if(i==len){
						result = false;
						break;
					}
					if(S[i]!='>'){
						result = false;
						break;
					}
					// self-closing
					if(S[i-1]=='/') Ttop = stack[top--];
					i++;
				}
				break;

				// must be not appeared: prehandled at case '<'
			case '>':
				result = false;
				break;

				// other characters
			default:
				i++;
			}
			if(!result) break;
		}
		if(top!=-1) result = false;
		printf("%svalid\n", result?"":"in");
	}

	return 0;
}