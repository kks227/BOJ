#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 20001;
typedef vector<string> Code;

int getCode(Code &code){
	int lcnt = 0;
	while(1){
		string line, s = "", word;
		getline(cin, line);
		if(line == "***END***") break;
		stringstream ss(line);
		while(ss >> word) s += word + " ";
		if(!s.empty()){
			lcnt++;
			code.push_back(s);
		}
	}
	return lcnt;
}

struct SuffixNode{
	int sa;
	P rank;
	bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

struct SuffixArray{
	vector<pair<string, int>> code;
	int N, sa[MAX], pos[MAX], lcp[MAX];

	void constructSA(){
		vector<pair<string, int>> tempCode(code);
		sort(tempCode.begin(), tempCode.end());
		int rtemp[MAX], rcnt = 0;
		for(int i=0; i<N; i++){
			rtemp[tempCode[i].second] = rcnt;
			if(i < N-1 && tempCode[i].first != tempCode[i+1].first) rcnt++;
		}

		SuffixNode node[MAX], nodeTemp[MAX];
		for(int i=0; i<N; i++){
			node[i].sa = i;
			node[i].rank = P(rtemp[i], i<N-1 ? rtemp[i+1] : -1);
		}
		sort(node, node+N);

		for(int d=2; d<N; d*=2){
			int M = 0, temp = node[0].rank.first;
			node[0].rank.first = pos[node[0].sa] = 0;

			for(int i=1; i<N; i++){
				if(P(temp, node[i-1].rank.second) == node[i].rank) node[i].rank.first = M;
				else{
					temp = node[i].rank.first;
					node[i].rank.first = ++M;
				}
				pos[node[i].sa] = i;
			}
			M++;

			int cnt[MAX+1] = {0};
			for(int i=0; i<N; i++){
				int j = node[i].sa + d;
				node[i].rank.second = (j < N ? node[pos[j]].rank.first : -1);
				cnt[node[i].rank.second+1]++;
			}
			for(int i=1; i<M+1; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				nodeTemp[--cnt[node[i].rank.second+1]] = node[i];

			fill(cnt, cnt+M+1, 0);
			for(int i=0; i<N; i++)
				cnt[nodeTemp[i].rank.first]++;
			for(int i=1; i<M; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				node[--cnt[nodeTemp[i].rank.first]] = nodeTemp[i];
		}

		for(int i=0; i<N; i++){
			sa[i] = node[i].sa;
			pos[sa[i]] = i;
		}
	}

	void constructLCP(){
		for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
			if(pos[i] == N-1) continue;
			for(int j=sa[pos[i]+1]; i+k < N && j+k < N && code[i+k].first==code[j+k].first; k++);
			lcp[pos[i]] = k;
		}
	}
};

int main(){
	int N, lines[100], myLines;
	cin >> N;
	Code code[100], myCode;
	string fname[100], cutter = "\n";
	cin.ignore(256, '\n');
	for(int i=0; i<N; i++){
		getline(cin, fname[i]);
		lines[i] = getCode(code[i]);
	}
	myLines = getCode(myCode);

	int result = 0;
	vector<string> rfname;
	for(int i=0; i<N; i++){
		SuffixArray SA;
		for(int j=0; j<lines[i]; j++)
			SA.code.push_back({code[i][j], j});
		SA.code.push_back({cutter, lines[i]});
		for(int j=0; j<myLines; j++)
			SA.code.push_back({myCode[j], lines[i]+1+j});
		SA.N = lines[i] + myLines + 1;
		SA.constructSA();
		SA.constructLCP();

		int temp = 0;
		for(int j=0; j<SA.N-1; j++)
			if((SA.sa[j] > lines[i]) != (SA.sa[j+1] > lines[i])) temp = max(SA.lcp[j], temp);
		if(temp > result){
			result = temp;
			rfname.clear();
			rfname.push_back(fname[i]);
		}
		else if(temp == result) rfname.push_back(fname[i]);
	}
	cout << result;
	if(result > 0)
		for(string &s: rfname) cout << ' ' << s;
	cout << endl;
}