#include <cstdio>
#include <algorithm>
using namespace std;

int L, C;
char A[15], P[16];
bool isVowel[26];

void backtrack(int pos, int prev, int consonant, int vowel){
	// L개의 문자를 다 쓴 경우: 조건에 맞으면 현재 암호 출력하고 리턴
	if(pos == L){
		if(consonant >= 2 && vowel >= 1) puts(P);
		return;
	}

	// 아직 사용하지 않은 암호들 하나씩 시도
	for(int i=prev+1; i<C; i++){
		P[pos] = A[i];
		backtrack(pos+1, i, consonant + !isVowel[A[i]-'a'], vowel + isVowel[A[i]-'a']);
		// P[pos]는 어차피 다시 덮어씌워질 것이므로 안 돌려놔도 됨
	}
}

int main(){
	scanf("%d %d", &L, &C);
	for(int i=0; i<C; i++)
		scanf(" %c", A+i);
	sort(A, A+C);
	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
	backtrack(0, -1, 0, 0);
}