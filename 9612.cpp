#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef map<string, int> M;

int main(){
	int N;
	cin >> N;
	M cnt;
	int rcnt = 0;
	string rs = "";
	for(int i=0; i<N; i++){
		string word;
		cin >> word;
		if(cnt.find(word) == cnt.end()) cnt[word] = 1;
		else{
			cnt[word]++;
			if(rcnt < cnt[word] || rcnt == cnt[word] && rs < word){
				rcnt = cnt[word];
				rs = word;
			}
		}
	}
	cout << rs << ' ' << rcnt << endl;
}