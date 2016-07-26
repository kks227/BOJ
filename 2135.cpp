#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string S;
int len;
int cache[201][201];

int digit(int n){
	int result = 1;
	int power = 10;
	while(n >= power){
		result++;
		power *= 10;
	}
	return result;
}

int RLE(int start, int end){
	int& ret = cache[start][end];
	if(ret != -1) return ret;
	if(end-start <= 4) return ret=(end-start);

	ret = end-start;
	bool flag;
	int minPatLen;
	for(int patLen=1; start+patLen<end; patLen++){
		minPatLen = min(patLen, RLE(start, start+patLen));
		ret = min(ret, minPatLen+RLE(start+patLen, end));
		for(int repeat=2; start+repeat*patLen<=end; repeat++){
			flag = true;
			for(int k=0; k<patLen; k++){
				if(S[start+k] != S[start+(repeat-1)*patLen+k]){
					flag = false;
					break;
				}
			}
			if(!flag) break;
			ret = min(
				ret,
				min(minPatLen*repeat, digit(repeat)+2+minPatLen) + RLE(start+patLen*repeat, end)
				);
		}
	}
	return ret;
}

int main(){

	cin >> S;
	len = S.length();
	memset(cache, -1, 201*201*(sizeof(int)));
	cout << RLE(0, len) << endl;

	return 0;
}