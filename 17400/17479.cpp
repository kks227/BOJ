#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
	int A, B, C;
	unordered_map<string, int> normal, special;
	unordered_set<string> service;
	cin >> A >> B >> C;
	for(int i = 0; i < A; ++i){
		string name;
		int price;
		cin >> name >> price;
		normal[name] = price;
	}
	for(int i = 0; i < B; ++i){
		string name;
		int price;
		cin >> name >> price;
		special[name] = price;
	}
	for(int i = 0; i < C; ++i){
		string name;
		cin >> name;
		service.insert(name);
	}

	int Q, specialCnt = 0, serviceCnt = 0;
	long long normalTotal = 0, total = 0;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
		string name;
		cin >> name;
		if(service.find(name) != service.end()) ++serviceCnt;
		else if(special.find(name) != special.end()){
			++specialCnt;
			total += special[name];
		}
		else{
			normalTotal += normal[name];
			total += normal[name];
		}
	}
	if(serviceCnt > 1 || serviceCnt > 0 && total < 50000 || specialCnt > 0 && normalTotal < 20000) cout << "No\n";
	else cout << "Okay\n";
}