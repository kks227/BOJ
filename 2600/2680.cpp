#include <cstdio>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	map<int, char> d2c;
	map<char, int> c2d;
	d2c[36] = ' '; c2d[' '] = 36;
	d2c[37] = '$'; c2d['$'] = 37;
	d2c[38] = '%'; c2d['%'] = 38;
	d2c[39] = '*'; c2d['*'] = 39;
	d2c[40] = '+'; c2d['+'] = 40;
	d2c[41] = '-'; c2d['-'] = 41;
	d2c[42] = '.'; c2d['.'] = 42;
	d2c[43] = '/'; c2d['/'] = 43;
	d2c[44] = ':'; c2d[':'] = 44;

	for(int t=0; t<T; t++){
		bool QR[38*4] = {0};
		getchar();
		for(int i=0; i<38; i++){
			char c = getchar();
			int n = (isdigit(c) ? c-'0' : c-'A'+10);
			for(int j=0; j<4; j++)
				if(n & 1<<j) QR[i*4+(3-j)] = true;
		}

		int cnt = 0, pos = 0;
		vector<char> result;
		while(1){
			int mode = 0, count = 0;
			for(int i=0; i<4; i++)
				mode = mode*2 + QR[pos++];
			if(mode == 1){ // numeric
				for(int i=0; i<10; i++)
					count = count*2 + QR[pos++];
				for(int i=0; i<count; i+=3){
					int val = 0, loop = 10, p10 = 1;
					if(count-i == 2) loop = 7;
					else if(count-i == 1) loop = 4;
					for(int j=0; j<loop; j++)
						val = val*2 + QR[pos++];
					for(int j=1; j<min(count-i, 3); j++)
						p10 *= 10;
					for(int j=0; j<min(count-i, 3); j++){
						result.push_back(val/p10+'0');
						val %= p10;
						p10 /= 10;
					}
				}
			}
			else if(mode == 2){ // alphanumeric
				for(int i=0; i<9; i++)
					count = count*2 + QR[pos++];
				for(int i=0; i<count; i+=2){
					int val = 0, loop = 11, p45 = 1;
					if(count-i == 1) loop = 6;
					for(int j=0; j<loop; j++)
						val = val*2 + QR[pos++];
					for(int j=1; j<min(count-i, 2); j++)
						p45 *= 45;
					for(int j=0; j<min(count-i, 2); j++){
						int temp = val/p45;
						if(temp < 10) result.push_back(temp+'0');
						else if(temp < 36) result.push_back(temp-10+'A');
						else result.push_back(d2c[temp]);
						val %= p45;
						p45 /= 45;
					}
				}
			}
			else if(mode == 4){ // 8 bit byte
				for(int i=0; i<8; i++)
					count = count*2 + QR[pos++];
				for(int i=0; i<count; i++){
					int val = 0;
					for(int j=0; j<8; j++)
						val = val*2 + QR[pos++];
					if(val == '\\'){
						result.push_back('\\');
						result.push_back('\\');
					}
					else if(val == '#'){
						result.push_back('\\');
						result.push_back('#');
					}
					else if(val >= 0x20 && val <= 0x7F) result.push_back(val);
					else{
						result.push_back('\\');
						int p16 = 16;
						for(int j=0; j<2; j++){
							int temp = val/p16;
							if(temp < 10) result.push_back(temp+'0');
							else result.push_back(temp-10+'A');
							val %= p16;
							p16 /= 16;
						}
					}
				}
			}
			else if(mode == 8){ // Kanji
				for(int i=0; i<8; i++)
					count = count*2 + QR[pos++];
				for(int i=0; i<count; i++){
					int val = 0;
					for(int j=0; j<13; j++)
						val = val*2 + QR[pos++];
					result.push_back('#');
					int p16 = 16*16*16;
					for(int j=0; j<4; j++){
						int temp = val/p16;
						if(temp < 10) result.push_back(temp+'0');
						else result.push_back(temp-10+'A');
						val %= p16;
						p16 /= 16;
					}
				}
			}
			else break; // termination

			cnt += count;
		}
		printf("%d ", cnt);
		for(char c: result)
			putchar(c);
		puts("");
	}
}