#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct RuleNode{
	bool type; // 0: nonterminal, 1: terminal
	int next;
	string s;
	RuleNode(): RuleNode(""){}
	RuleNode(int next1): type(false), next(next1){}
	RuleNode(string s1): type(true), s(s1){}
};
typedef vector<RuleNode> Rule;

vector<Rule> rule[15];
int cnt[15], tcnt;
bool initFlag;

void print(int curr){
	if(curr == 0) --tcnt;
	if(curr == 0 && cnt[0] == 2){
		++cnt[0];
		print(9);
		cout << '!';
	}
	else{
		int k = cnt[curr]++;
		cnt[curr] %= rule[curr].size();
		for(RuleNode &rn: rule[curr][k]){
			if(rn.type){
				string w = rn.s;
				if(initFlag){
					initFlag = false;
					w[0] -= 'a'-'A';
				}
				cout << ' ' << w;
			}
			else print(rn.next);
		}
		if(curr == 0) cout << '.';
	}
	if(curr == 9) initFlag = true;
}



int main(){
	const char NamHyeonWoo[12] = {'t', 'h', 'e', 'h', 'o', 'l', 'y', 'g', 'r', 'a', 'i', 'l'};
	
	// (0)taunt
	rule[0].push_back(Rule(1, 1));
	rule[0].push_back(Rule(1, 0)); rule[0][1].push_back(1);
	rule[0].push_back(Rule(1, 9));
	rule[0].push_back(Rule(1, 1));

	// (1)sentence
	rule[1].push_back(Rule(1, 6)); rule[1][0].push_back(2);
	rule[1].push_back(Rule(1, 5)); rule[1][1].push_back(2);
	rule[1].push_back(Rule(1, 6)); rule[1][2].push_back(12); rule[1][2].push_back(9);

	// (2)noun-phrase
	rule[2].push_back(Rule(1, 12)); rule[2][0].push_back(3);

	// (3)modified-noun
	rule[3].push_back(Rule(1, 9));
	rule[3].push_back(Rule(1, 4)); rule[3][1].push_back(9);

	// (4)modifier
	rule[4].push_back(Rule(1, 13));
	rule[4].push_back(Rule(1, 14)); rule[4][1].push_back(13);

	// (5)present-rel
	rule[5].push_back(Rule(1, RuleNode("your"))); rule[5][0].push_back(7); rule[5][0].push_back(10);

	// (6)past-rel
	rule[6].push_back(Rule(1, RuleNode("your"))); rule[6][0].push_back(8); rule[6][0].push_back(11);

	// (7)present-person
	rule[7].push_back(Rule(1, RuleNode("steed")));
	rule[7].push_back(Rule(1, RuleNode("king")));
	rule[7].push_back(Rule(1, RuleNode("first-born")));

	// (8)past-person
	rule[8].push_back(Rule(1, RuleNode("mother")));
	rule[8].push_back(Rule(1, RuleNode("father")));
	rule[8].push_back(Rule(1, RuleNode("grandmother")));
	rule[8].push_back(Rule(1, RuleNode("grandfather")));
	rule[8].push_back(Rule(1, RuleNode("godfather")));

	// (9)noun
	rule[9].push_back(Rule(1, RuleNode("hamster")));
	rule[9].push_back(Rule(1, RuleNode("coconut")));
	rule[9].push_back(Rule(1, RuleNode("duck")));
	rule[9].push_back(Rule(1, RuleNode("herring")));
	rule[9].push_back(Rule(1, RuleNode("newt")));
	rule[9].push_back(Rule(1, RuleNode("peril")));
	rule[9].push_back(Rule(1, RuleNode("chicken")));
	rule[9].push_back(Rule(1, RuleNode("vole")));
	rule[9].push_back(Rule(1, RuleNode("parrot")));
	rule[9].push_back(Rule(1, RuleNode("mouse")));
	rule[9].push_back(Rule(1, RuleNode("twit")));

	// (10)present-verb
	rule[10].push_back(Rule(1, RuleNode("is")));
	rule[10].push_back(Rule(1, RuleNode("masquerades as")));

	// (11)past-verb
	rule[11].push_back(Rule(1, RuleNode("was")));
	rule[11].push_back(Rule(1, RuleNode("personified")));

	// (12)article
	rule[12].push_back(Rule(1, RuleNode("a")));

	// (13)adjective
	rule[13].push_back(Rule(1, RuleNode("silly")));
	rule[13].push_back(Rule(1, RuleNode("wicked")));
	rule[13].push_back(Rule(1, RuleNode("sordid")));
	rule[13].push_back(Rule(1, RuleNode("naughty")));
	rule[13].push_back(Rule(1, RuleNode("repulsive")));
	rule[13].push_back(Rule(1, RuleNode("malodorous")));
	rule[13].push_back(Rule(1, RuleNode("ill-tempered")));

	// (14)adverb
	rule[14].push_back(Rule(1, RuleNode("conspicuously")));
	rule[14].push_back(Rule(1, RuleNode("categorically")));
	rule[14].push_back(Rule(1, RuleNode("positively")));
	rule[14].push_back(Rule(1, RuleNode("cruelly")));
	rule[14].push_back(Rule(1, RuleNode("incontrovertibly")));

	string line;
	while(getline(cin, line)){
		cout << "Knight:";
		string word;
		int wcnt = 0, hgcnt = 0;
		stringstream ss(line);
		while(ss >> word){
			cout << ' ' << word;
			bool flag = false;
			for(char c: word){
				if(isalpha(c)){
					flag = true;
					if(hgcnt < 12 && c + (isupper(c) ? 'a'-'A' : 0) == NamHyeonWoo[hgcnt]) ++hgcnt;
				}
			}
			if(flag) ++wcnt;
		}
		cout << '\n';

		tcnt = (wcnt+2)/3;
		if(hgcnt == 12){
			--tcnt;
			cout << "Taunter: (A childish hand gesture).\n";
		}
		for(; tcnt > 0; ){
			cout << "Taunter:";
			initFlag = true;
			print(0);
			cout << '\n';
		}
		cout << '\n';
	}
}