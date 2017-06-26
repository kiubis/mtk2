#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath> // do pow()

using namespace std;

double srednia (int *tab, int n);

int main(){
cout << "Autorem programu jest xxx ddd" << endl;

// zadeklarowanie zmiennej do ilosci licz
int n = 0;

cout << "Podaj ilosc liczb: ";
cin >> n;		//przyjecie od uzytkownika ilosci liczb

int *tab = new int[n]; // utworzenie n-elementowej tablicy int'ow

srand(time(NULL));
for (int i = 0 ; i < n ; i++){
	tab[i]=rand()%21; // wypelnienie tablicy liczbami losowymi 0-20 na calej przestrzeni tablicy
}

double wynik=srednia (tab,n);

cout << "Srednia geometryczna wynosi: "<<wynik << endl;

delete []tab; 		// usuniecie wczesniej stworzonej tablicy (wymagane jak cos tworzysz operatorem new)

}

double srednia(int *tab, int n){
	double iloczyn = 1;
	// policzenie tego co jest pod pierwiastkiem
	for (int i = 0 ; i < n ; i++){
		iloczyn*=tab[i];
	}
	
	// zwrocenie pierwiastka n-tego stopnia z iloczynu liczb
	return pow(iloczyn,(1./(double)n)); // pow zwraca liczbe podniesiona do potegi

}
