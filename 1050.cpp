#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> IntPair;       // itemNum, coefficient
typedef vector<vector<IntPair>> ExpressionList;

const int IMPOSSIBLE = -1, MAX = 1000000001;
char *LOVE = "LOVE";

struct Item{
	char name[51];
	int cost;
	ExpressionList expression;
	bool confirm;
	Item(): Item("ABC"){}
	Item(char *name1): Item(name1, IMPOSSIBLE){}
	Item(char *name1, int cost1): cost(cost1), confirm(false){ strcpy(name, name1); }
};

vector<Item> item;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	item.push_back(Item(LOVE));
	for(int i=0; i<N; i++){
		char name[51];
		int val;
		scanf("%s %d", name, &val);
		if(strcmp(name, LOVE) == 0) item[0].cost = val;
		else item.push_back(Item(name, val));
	}

	for(int i=0; i<M; i++){
		char line[51], left[51], right[51];
		scanf("%s", line);
		int pos = 0, len = strlen(line), start;
		for(pos=0; line[pos]!='='; pos++);
		strncpy(left, line, pos);
		left[pos] = '\0';
		start = ++pos;
		int leftNum = 0;
		for(; leftNum<item.size(); leftNum++)
			if(strcmp(item[leftNum].name, left) == 0) break;
		if(leftNum == item.size()) item.push_back(Item(left));

		vector<IntPair> newExp;
		while(pos < len){
			int C = line[pos]-'0';
			start = ++pos;
			for(; pos<len && line[pos]!='+'; pos++);
			strncpy(right, line+start, pos-start);
			right[pos-start] = '\0';
			int rightNum = 0;
			for(; rightNum<item.size(); rightNum++)
				if(strcmp(item[rightNum].name, right) == 0) break;
			if(rightNum == item.size()) item.push_back(Item(right));

			int termNum = 0;
			for(; termNum<newExp.size(); termNum++)
				if(newExp[termNum].first == rightNum) break;
			if(termNum == newExp.size()) newExp.push_back(IntPair(rightNum, 0));
			newExp[termNum].second += C;

			start = ++pos;
		}
		item[leftNum].expression.push_back(newExp);
	}
	for(auto& i: item)
		i.confirm = i.expression.empty();

	while(!item[0].confirm){
		bool noErase = true;
		for(auto& i: item){
			if(i.confirm) continue;

			for(int j=0; j<i.expression.size();){
				bool eraseExp = true, noRenew = false;
				long long val = 0;
				for(auto& term: i.expression[j]){
					if(!item[term.first].confirm){
						eraseExp = false;
						break;
					}
					if(item[term.first].cost == IMPOSSIBLE) noRenew = true;
					val += 1LL * item[term.first].cost * term.second;
				}
				if(!eraseExp) j++;
				else{
					noErase = false;
					if(!noRenew){
						if(val > MAX) val = MAX;
						if(i.cost==IMPOSSIBLE || i.cost>val) i.cost = val;
					}
					i.expression.erase(i.expression.begin()+j);
				}
			}
			if(i.expression.empty()) i.confirm = true;
		}
		if(!noErase) continue;

		int targetNum = -1, minCost = MAX+1;
		for(int i=0; i<item.size(); i++){
			if(item[i].confirm) continue;
			if(item[i].cost!=IMPOSSIBLE && item[i].cost<minCost){
				targetNum = i;
				minCost = item[i].cost;
			}
		}
		if(targetNum != -1){
			item[targetNum].expression.clear();
			item[targetNum].confirm = true;
		}
		else break;
	}
	printf("%d\n", item[0].cost);
}