#include <iostream>
#include <string>
using namespace std;

#define Adrian_MAX 3
#define Bruno_MAX 4
#define Goran_MAX 6

int main(){

	string Adrian = "ABC", Bruno = "BABC", Goran = "CCAABB";
	string answer;
	int len, score[3]={0}, rank[3]={0};
	cin >> len >> answer;
	for(int i=0; i<len; i++){
		if(Adrian[i%Adrian_MAX] == answer[i]) score[0]++;
		if(Bruno[i%Bruno_MAX] == answer[i]) score[1]++;
		if(Goran[i%Goran_MAX] == answer[i]) score[2]++;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==j) continue;
			if(score[i] < score[j]) rank[i]++;
		}
	}
	for(int i=0; i<3; i++){
		if(rank[i] == 0){
			cout << score[i] << endl;
			break;
		}
	}
	if(rank[0] == 0) cout << "Adrian" << endl;
	if(rank[1] == 0) cout << "Bruno" << endl;
	if(rank[2] == 0) cout << "Goran" << endl;

	return 0;
}