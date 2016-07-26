#include <iostream>
#include <string>
using namespace std;

bool AisOlderThanB(int Aday, int Amonth, int Ayear, int Bday, int Bmonth, int Byear){
	if(Ayear < Byear) return true;
	if(Ayear > Byear) return false;
	if(Amonth < Bmonth) return true;
	if(Amonth > Bmonth) return false;
	return (Aday < Bday);
}

int main(){

	int N;
	cin >> N;
	string name, young_name, old_name;
	int day, month, year, young_day, old_day, young_month, old_month, young_year, old_year;

	cin >> name >> day >> month >> year;
	young_name = old_name = name;
	young_day = old_day = day;
	young_month = old_month = month;
	young_year = old_year = year;

	for(int i=1; i<N; i++){
		cin >> name >> day >> month >> year;
		if(AisOlderThanB(day, month, year, old_day, old_month, old_year)){
			old_name = name;
			old_day = day;
			old_month = month;
			old_year = year;
		}
		if(AisOlderThanB(young_day, young_month, young_year, day, month, year)){
			young_name = name;
			young_day = day;
			young_month = month;
			young_year = year;
		}
	}
	cout << young_name << endl << old_name << endl;

    return 0;
}