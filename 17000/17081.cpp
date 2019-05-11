#include <cstdio>
#include <cstring>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX_N = 100;
const int MAX = MAX_N*MAX_N;
const int MAX_NAME = 10;
const int MAX_S = 5000;

enum accType {HR, RE, CO, EX, DX, HU, CU};

int main(){
	unordered_map<char, int> C2D;
	C2D['U'] = 0; C2D['D'] = 1; C2D['L'] = 2; C2D['R'] = 3;
	int R, C, M = 0, I = 0, sr, sc, cr, cc, L = 0, step[MAX_S];
	char map[MAX_N][MAX_N];
	scanf("%d %d\n", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '@'){
				sr = cr = i;
				sc = cc = j;
				map[i][j] = '.';
			}
			else if(map[i][j] == '&' || map[i][j] == 'M') ++M;
			else if(map[i][j] == 'B') ++I;
		}
		getchar();
	}
	while(1){
		char c = getchar();
		if(c == '\n') break;
		step[L++] = C2D[c];
	}

	int mobNum[MAX_N][MAX_N], mAtk[MAX], mDef[MAX], mHp[MAX], mMaxHp[MAX], mExp[MAX];
	int itemNum[MAX_N][MAX_N], iVal[MAX];
	accType iAccType[MAX];
	char mName[MAX][MAX_NAME+1], iType[MAX];
	for(int i = 0; i < M; ++i){
		int r, c;
		scanf("%d %d %s %d %d %d %d", &r, &c, mName[i], mAtk+i, mDef+i, mHp+i, mExp+i);
		--r; --c;
		mobNum[r][c] = i;
		mMaxHp[i] = mHp[i];
	}
	for(int i = 0; i < I; ++i){
		int r, c;
		scanf("%d %d %c", &r, &c, iType+i);
		--r; --c;
		itemNum[r][c] = i;
		if(iType[i] == 'O'){
			char accS[3];
			scanf("%s", accS);
			if(strcmp(accS, "HR") == 0) iAccType[i] = HR;
			else if(strcmp(accS, "RE") == 0) iAccType[i] = RE;
			else if(strcmp(accS, "CO") == 0) iAccType[i] = CO;
			else if(strcmp(accS, "EX") == 0) iAccType[i] = EX;
			else if(strcmp(accS, "DX") == 0) iAccType[i] = DX;
			else if(strcmp(accS, "HU") == 0) iAccType[i] = HU;
			else iAccType[i] = CU;
		}
		else scanf("%d", iVal+i);
	}

	int turn = 0, lv = 1, hp = 20, maxHp = 20, atk = 2, def = 2, exp = 0, maxExp = 5;
	int weapon = 0, armor = 0;
	set<accType> accs;
	bool win = false, lose = false;
	char killer[MAX_NAME+1];
	for(; turn < L; ++turn){
		int nr = cr + roff[step[turn]], nc = cc + coff[step[turn]];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#');
		else{
			cr = nr;
			cc = nc;
		}

		// needle
		if(map[cr][cc] == '^'){
			int damage = 5;
			if(accs.count(DX)) damage = 1;
			hp -= damage;
			if(hp <= 0){
				if(accs.count(RE)){
					accs.erase(RE);
					hp = maxHp;
					cr = sr;
					cc = sc;
				}
				else{
					hp = 0;
					lose = true;
					++turn;
					strcpy(killer, "SPIKE TRAP");
					break;
				}
			}
		}

		// item box
		else if(map[cr][cc] == 'B'){
			int x = itemNum[cr][cc];
			if(iType[x] == 'W') weapon = iVal[x];
			else if(iType[x] == 'A') armor = iVal[x];
			else{
				accType at = iAccType[x];
				if(!accs.count(at) && accs.size() < 4) accs.insert(at);
			}
			map[cr][cc] = '.';
		}

		// nothing
		else if(map[cr][cc] == '.');

		// enemy or boss
		else{
			int x = mobNum[cr][cc];
			bool isBoss = (map[cr][cc] == 'M'), reinFlag = false;
			if(isBoss && accs.count(HU)) hp = maxHp;

			for(int t = 0; ; ++t){
				int myAtk = atk + weapon;
				if(t == 0 && accs.count(CO)) myAtk *= (accs.count(DX) ? 3 : 2);
				int myDamage = max(myAtk - mDef[x], 1);
				mHp[x] -= myDamage;
				if(mHp[x] <= 0){
					int getExp = mExp[x];
					if(accs.count(EX)) getExp = (getExp*1.2 + 1e-6);
					exp += getExp;
					if(exp >= maxExp){
						++lv;
						hp = maxHp = maxHp + 5;
						atk += 2;
						def += 2;
						exp = 0;
						maxExp = lv*5;
					}
					break;
				}

				int yourAtk = mAtk[x];
				int yourDamage = max(yourAtk - (def+armor), 1);
				if(t == 0 && isBoss && accs.count(HU)) yourDamage = 0;
				hp -= yourDamage;
				if(hp <= 0){
					if(accs.count(RE)){
						accs.erase(RE);
						hp = maxHp;
						mHp[x] = mMaxHp[x];
						cr = sr;
						cc = sc;
						reinFlag = true;
					}
					else{
						hp = 0;
						lose = true;
						strcpy(killer, mName[x]);
					}
					break;
				}
			}

			if(reinFlag) continue;

			if(lose){
				++turn;
				break;
			}

			if(accs.count(HR)) hp = min(hp+3, maxHp);
			if(isBoss){
				win = true;
				++turn;
				break;
			}
			map[cr][cc] = '.';
		}
	}

	if(!lose) map[cr][cc] = '@';
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j)
			putchar(map[i][j]);
		puts("");
	}
	printf("Passed Turns : %d\n", turn);
	printf("LV : %d\n", lv);
	printf("HP : %d/%d\n", hp, maxHp);
	printf("ATT : %d+%d\n", atk, weapon);
	printf("DEF : %d+%d\n", def, armor);
	printf("EXP : %d/%d\n", exp, maxExp);
	if(win) puts("YOU WIN!");
	else if(lose) printf("YOU HAVE BEEN KILLED BY %s..\n", killer);
	else puts("Press any key to continue.");
}