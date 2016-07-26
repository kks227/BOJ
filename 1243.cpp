#include <cstdio>
#include <cstring>
using namespace std;

int N, L, len[50], cache[2][50][16][31];
char word[50][16];
bool isPalindrome[50];

// cut==0이면 onRight==false, wordNum==0
int cntPalindrome(bool onRight, int wordNum, int cut, int remain){
	int &ret = cache[onRight][wordNum][cut][remain];
	if(ret != -1) return ret;
	if(remain == 0){
		if(cut == 0) return ret = 1;
		if(cut == len[wordNum]) return ret = isPalindrome[wordNum];
		if(onRight){
			for(int i=0; i<cut/2; i++)
				if(word[wordNum][i] != word[wordNum][cut-i-1]) return ret = 0;
		}
		else{
			for(int i=0; i<cut/2; i++)
				if(word[wordNum][len[wordNum]-cut+i] != word[wordNum][len[wordNum]-i-1]) return ret = 0;
		}
		return ret = 1;
	}
	ret = 0;
	if(cut == 0){
		for(int i=0; i<N; i++){
			if(isPalindrome[i])
				if(len[i]*2 <= remain) ret += cntPalindrome(false, 0, 0, remain-len[i]*2);
			if(len[i] <= remain)
				ret += cntPalindrome(false, i, len[i], remain-len[i]);
		}
	}
	else{
		if(onRight){
			for(int i=0; i<N; i++){
				if(i==wordNum && len[i]==cut) continue;
				if(len[i] > remain) continue;
				if(len[i] < cut){
					bool flag = true;
					for(int j=0; j<len[i]; j++)
						if(word[i][j] != word[wordNum][cut-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(true, wordNum, cut-len[i], remain-len[i]);
				}
				else if(len[i] == cut){
					bool flag = true;
					for(int j=0; j<cut; j++)
						if(word[i][j] != word[wordNum][cut-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(false, 0, 0, remain-len[i]);
				}
				else{
					bool flag = true;
					for(int j=0; j<cut; j++)
						if(word[i][j] != word[wordNum][cut-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(false, i, len[i]-cut, remain-len[i]);
				}
			}
		}
		else{
			for(int i=0; i<N; i++){
				if(i==wordNum && len[i]==cut) continue;
				if(len[i] > remain) continue;
				if(len[i] < cut){
					bool flag = true;
					for(int j=0; j<len[i]; j++)
						if(word[wordNum][len[wordNum]-cut+j] != word[i][len[i]-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(false, wordNum, cut-len[i], remain-len[i]);
				}
				else if(len[i] == cut){
					bool flag = true;
					for(int j=0; j<cut; j++)
						if(word[wordNum][len[wordNum]-cut+j] != word[i][len[i]-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(true, 0, 0, remain-len[i]);
				}
				else{
					bool flag = true;
					for(int j=0; j<cut; j++)
						if(word[wordNum][len[wordNum]-cut+j] != word[i][len[i]-j-1]){
							flag = false;
							break;
						}
					if(flag) ret += cntPalindrome(true, i, len[i]-cut, remain-len[i]);
				}
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		scanf("%s", word[i]);
		len[i] = strlen(word[i]);
		isPalindrome[i] = true;
		for(int j=0; j<len[i]/2; j++)
			if(word[i][j] != word[i][len[i]-j-1]){
				isPalindrome[i] = false;
				break;
			}
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", cntPalindrome(false, 0, 0, L));
}