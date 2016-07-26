#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string S1, S2, S3;
int len1, len2, len3;

int cache[101][101][101];

int LCS(int start1, int start2, int start3){
	int& ret = cache[start1][start2][start3];
	if(ret != -1) return ret;
	if(start1 == len1 || start2 == len2 || start3 == len3) return ret=0;

	ret = 0;
	if(S1[start1] == S2[start2] && S1[start1] == S3[start3]) ret = LCS(start1+1, start2+1, start3+1) + 1;
	ret = max(ret, LCS(start1+1, start2, start3));
	ret = max(ret, LCS(start1, start2+1, start3));
	ret = max(ret, LCS(start1, start2, start3+1));
	return ret;
};

int main(){

	cin >> S1 >> S2 >> S3;
	len1 = S1.length();
	len2 = S2.length();
	len3 = S3.length();
	memset(cache, -1, 101*101*101*sizeof(int));
	cout << LCS(0, 0, 0) << endl;

	return 0;
}