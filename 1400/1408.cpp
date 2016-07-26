#include <cstdio>
using namespace std;
 
int main(){

	int Shour, Sminute, Ssecond;
	int Chour, Cminute, Csecond;
	int Lhour, Lminute, Lsecond;
	scanf("%02d:%02d:%02d", &Chour, &Cminute, &Csecond);
	scanf("%02d:%02d:%02d", &Shour, &Sminute, &Ssecond);
	int start_time, current_time, left_time;
	start_time = 3600*Shour + 60*Sminute + Ssecond;
	current_time = 3600*Chour + 60*Cminute + Csecond;
	left_time = start_time - current_time;
	if(left_time < 0) left_time += 86400;
	Lhour = left_time / 3600;
	left_time %= 3600;
	Lminute = left_time / 60;
	Lsecond = left_time % 60;
	printf("%02d:%02d:%02d\n", Lhour, Lminute, Lsecond);

    return 0;
}