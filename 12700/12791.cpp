#include <cstdio>
#include <cstring>
using namespace std;

struct Album{
	int year;
	char name[100];
	Album(char *s){
		year = 0;
		while(*s != ' ')
			year = year * 10 + (*s++ - '0');
		strcpy(name, s+1);
	}
};

int main(){
	int Q;
	scanf("%d", &Q);
	Album album[25] = {
		"1967 DavidBowie",
		"1969 SpaceOddity",
		"1970 TheManWhoSoldTheWorld",
		"1971 HunkyDory",
		"1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
		"1973 AladdinSane",
		"1973 PinUps",
		"1974 DiamondDogs",
		"1975 YoungAmericans",
		"1976 StationToStation",
		"1977 Low",
		"1977 Heroes",
		"1979 Lodger",
		"1980 ScaryMonstersAndSuperCreeps",
		"1983 LetsDance",
		"1984 Tonight",
		"1987 NeverLetMeDown",
		"1993 BlackTieWhiteNoise",
		"1995 1.Outside",
		"1997 Earthling",
		"1999 Hours",
		"2002 Heathen",
		"2003 Reality",
		"2013 TheNextDay",
		"2016 BlackStar"
	};
	for(int i=0; i<Q; i++){
		int S, E;
		scanf("%d %d", &S, &E);
		int cnt = 0;
		for(int i=0; i<25; i++)
			if(S <= album[i].year && album[i].year <= E) cnt++;
		printf("%d\n", cnt);
		for(int i=0; i<25; i++)
			if(S <= album[i].year && album[i].year <= E)
				printf("%d %s\n", album[i].year, album[i].name);
	}
}