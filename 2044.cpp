#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

struct window{
	int width, height, len, offset;
	char title[11];
};

bool compareWindow(window A, window B){
	return strcmp(A.title, B.title) < 0;
}

int main(){
	int M, N;
	char screen[100][101];
	scanf("%d %d\n", &M, &N);
	for(int i=0; i<M; i++)
		gets(screen[i]);

	vector<window> w;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(screen[i][j] == '+'){
				int start, end, curW, curH;
				window temp;

				for(start=j+3; !islower(screen[i][start]); start++);
				for(end=start+1; islower(screen[i][end]); end++);
				strncpy(temp.title, &screen[i][start], end-start);
				temp.title[end-start] = '\0';
				temp.len = end-start;
				temp.offset = start-j;

				for(curW=end+2; screen[i][curW]!='+'; curW++);
				temp.width = curW-j-1;
				for(curH=i+1; screen[curH][j]!='+'; curH++);
				temp.height = curH-i-1;

				screen[i][j] = screen[i][curW] = screen[curH][j] = screen[curH][curW] = '.';
				w.push_back(temp);
			}
		}
	}

	for(int i=0; i<M; i++)
		memset(screen[i], '.', N);
	sort(w.begin(), w.end(), compareWindow);
	
	int x1=0, x2, y1=0, y2;
	for(int cw=0; cw<w.size(); cw++){
		x2 = x1 + w[cw].width+1;
		y2 = y1 + w[cw].height+1;
		screen[y1][x1] = screen[y1][x2] = screen[y2][x1] = screen[y2][x2] = '+';
		for(int i=y1+1; i<y2; i++){
			screen[i][x1] = screen[i][x2] = '|';
			memset(&screen[i][x1+1], '.', w[cw].width);
		}
		for(int i=x1+1; i<x2; i++)
			screen[y1][i] = screen[y2][i] = '-';
		screen[y1][x1 + w[cw].offset-1] = screen[y1][x1 + w[cw].offset+w[cw].len] = '|';
		memcpy(&screen[y1][x1 + w[cw].offset], w[cw].title, w[cw].len);
		x1++;
		y1++;
	}
	for(int i=0; i<M; i++)
		puts(screen[i]);
}