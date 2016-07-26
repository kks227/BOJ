#include <iostream>
using namespace std;

class Score{
public:
	int result;
	int sco[3];
	Score(){
		result = 0;
		sco[0] = sco[1] = sco[2] = 0;
	}
	void SetResult(){
		for(int i=0; i<3; i++)
			result += (i+1)*sco[i];
	}
	bool operator ==(const Score& other)const{
		if(result != other.result) return false;
		if(sco[2] != other.sco[2]) return false;
		if(sco[1] != other.sco[1]) return false;
		return true;
	}
	bool operator >(const Score& other)const{
		if(result > other.result) return true;
		if(result < other.result) return false;
		if(sco[2] > other.sco[2]) return true;
		if(sco[2] < other.sco[2]) return false;
		if(sco[1] > other.sco[1]) return true;
		return false;
	}
};

int main(){

	int N, n;
	cin >> N;
	Score S[3];
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin >> n;
			S[j].sco[n-1]++;
		}
	}
	for(int i=0; i<3; i++)
		S[i].SetResult();

	int rank[3] = {1, 1, 1};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==j) continue;
			if(S[j] > S[i]) rank[i]++;
		}
	}
	int winner, cnt=0;
	for(int i=0; i<3; i++){
		if(rank[i] == 1){
			cnt++;
			winner = i;
		}
	}

	if(cnt > 1) cout << 0;
	else cout << winner+1;
	cout << ' ' << S[winner].result << endl;

    return 0;
}