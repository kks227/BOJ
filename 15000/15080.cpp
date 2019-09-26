#include <cstdio>
using namespace std;

int main(){
	int h1, h2, m1, m2, s1, s2, result = 0;
	scanf("%d : %d : %d", &h1, &m1, &s1);
	scanf("%d : %d : %d", &h2, &m2, &s2);
	if(s1 <= s2) result += s2-s1;
	else{
		result += s2+60-s1;
		--m2;
	}
	if(m1 <= m2) result += (m2-m1)*60;
	else{
		result += (m2+60-m1)*60;
		--h2;
	}
	if(h1 <= h2) result += (h2-h1)*3600;
	else result += (h2+24-h1)*3600;
	printf("%d\n", result);
}