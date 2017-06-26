#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
srand(time(NULL));

int n = 0,			// zmienna do ilosci rund
	odgadniete = 0; // zmienna do odgadnietych rund

cout << "Odgadnij czy rownanie jest poprawne!"<<endl;
cout << "Napisz T jesli jest poprawne lub N jesli nie jest poprawne"<<endl;
cout << "Podaj ilosc rund: ";
cin >> n;		// zmienna do ilosci rund

// petla gry ; dziala n razy
for (int i = 0 ; i <n ; i++){

system ("cls");// wyczyszczenie konsoli
cout << "Pozostalo " << n-i <<" rund" << endl; // wyswietlenie ilosci pozostalych rund
cout << "Odganij czy rownanie jest poprawne!"<<endl;
cout << "Napisz T jesli jest poprawne lub N jesli nie jest poprawne"<<endl;

int a = rand()%100+1;		// pierwsza losowa liczba z zakresu 1-100
int b = rand()%100+1;		// druga losowa liczba z zakresu 1-100

int dzialanie = rand()%2;	// zmienna do losowania dzialania 0 - dodawanie 1 - odejmowanie

int wynik = 0;				// zmienna do wyniku dzialania 
	
switch(dzialanie){			// jesli zmienna dzialanie ma wartosc...
case 0:						// 0 to liczby beda sumowane
	wynik = a+b;
	break;
case 1:						// 1 to liczby beda odejmowane
	wynik = a-b;
	break;
}

int losowa = rand()%301-100;	// zmienna losowa przyrownywana do odgadywanego dzialania z zakresu -100 do 200

if(losowa%2)			// jesli reszta z dzielenia liczby losowej > 0 (czyli 1 bo %2)
	losowa = wynik;		// to losowa przyjmuje wartosc wyniku dzialania (chodzi o to, aby bylo 50% szans na to, aby rownanie bylo prawdziwe)

switch(dzialanie){		// jesli zmienna dzialanie ma wartosc ...
case 0:							// 0 to ...
	cout << a <<"+"<<b<<"="<<losowa<<"?" << endl;	// cout czesci od dodawania
	break;
case 1:							// to ...
	cout << a <<"-"<<b<<"="<<losowa<<"?" << endl;	// cout czesci od odejmowania
	break;
}

char litera = 0; 		// zmienna do przechowywania odpowiedzi

cout << "T/N?:";	
cin >> litera;			// przyjecie odpowiedzi

// jesli (podane T I wynik == losowej) LUB (podane N I wynik rozny od losowej)
if ( (litera == 'T' && wynik == losowa) || (litera == 'N' && wynik != losowa) ){	
	cout << "Zgadles!" << endl;			// to poprawna odpowiedz
	odgadniete++;					// zwiekszenie odgadnietych rund
	system("pause");				// oczekiwanie na wcisniecie przycisku
}else{
	cout << "Niestety nie zgadles!" << endl; 	// a jesli nie to zla odpowiedz
	system("pause");				// oczekiwanie na wcisniecie przycisku
}
}

system("cls"); //wyczyszczenie konsoli
cout << "Odgadles poprawnie " << odgadniete << " razy!" << endl;	// wyswietlenie ilosci odgadnietych rund
return 0;
}
