#include <iostream>

using namespace std;

void wyswietl(char tab[][14]);						// funckja do wyswietlania pola
void sprawdzenie(char tab[][14], bool *wygral , char *wygrany);		// funkcja do sprawdzania wygranej

int main(){

// pole gry
char tab[14][14]={
	{' ','|',' ','A',' ','|',' ','B',' ','|',' ','C',' ','|'},// 0
	{'-','+','-','-','-','+','-','-','-','+','-','-','-','+'},// 1
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 2
	{'1','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 3
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 4
	{'-','+','-','-','-','+','-','-','-','+','-','-','-','+'},// 5
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 6
	{'2','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 7
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 8
	{'-','+','-','-','-','+','-','-','-','+','-','-','-','+'},// 9
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 10
	{'3','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 11
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},// 12
	{'-','+','-','-','-','+','-','-','-','+','-','-','-','+'},// 13
};
//	  0   1   2   3   4   5   6   7   8   9  10  11  12  13

int rundy = 1;				// zmienan do rund
bool wygral = false;			// zmienna do sprawdzenia, czy rozgrywka juz zostla zakonczona (wygral ktos)
char wygrany = 0;			// zmienna do okreslenia kto wygral

// petla gry
do{
	
if(rundy%2){				// jesli nieparzysta runda 

wyswietl(tab);				// pokaz pole gry
cout << "Runda gracza X" << endl;	// ktory gracz
char x = 0;				// zmienna do wspolrzednej x
int y = 0;				// zmienna do wspolrzednej y

// przyjecie wspolrzednych 
cout << "Podaj wspolrzedna X (np. A):";
cin  >> x;
cout << "Podaj wspolrzedna Y (np. 1):";
cin >> y;

int wspX = 0 , wspY = 0;		// zmienne do okreslenia w ktore pole wpisujemy X lub O

switch(x){				// w zaleznosci od podanej litery (wartosc w ascii)
case 65:				// A = 65
	wspX = 3;			// pola z lewej
	break;
case 66:				// B = 66
	wspX = 7;			// srodkowe pola
	break;
case 67:				// C = 67
	wspX = 11;			// pola z prawej
	break;
}

switch(y){				// w zaleznosci od cyfry
case 1:								
	wspY = 3;			// pola od gory
	break;
case 2:
	wspY = 7;			// srodkowe pola
	break;
case 3:
	wspY = 11;			// pola od dolu
	break;
}

tab[wspY][wspX] = 'X';			// wpisanie znaku

sprawdzenie(tab, &wygral , &wygrany);	// sprawdzenie czy ktos wygral

rundy++;				// zwiekszenie ilosci rund 

} else {				// jesli parzysta runda 

wyswietl(tab);				// pokaz pole gry
cout << "Runda gracza O" << endl;	// ktory gracz
char x = 0;				// zmienna do wspolrzednej x
int y = 0;				// zmienna do wspolrzednej y

// przyjecie wspolrzednych
cout << "Podaj wspolrzedna X (np. A):";
cin  >> x;
cout << "Podaj wspolrzedna Y (np. 1):";
cin >> y;

int wspX = 0 , wspY = 0;		// zmienne do okreslenia w ktore pole wpisujemy X lub O

switch(x){				// w zaleznosci od podanej litery (wartosc w ascii)
case 65:				// A = 65
	wspX = 3;			// pola z lewej
	break;
case 66:				// B = 66
	wspX = 7;			// srodkowe pola
	break;
case 67:				// C = 67
	wspX = 11;			// pola z prawej
	break;
}

switch(y){				// w zaleznosci od cyfry
case 1:								
	wspY = 3;			// pola od gory
	break;
case 2:
	wspY = 7;			// srodkowe pola
	break;
case 3:
	wspY = 11;			// pola od dolu
	break;
}

tab[wspY][wspX] = 'O';			// wpisanie znaku

sprawdzenie(tab, &wygral , &wygrany);	// sprawdzenie czy ktos wygral

rundy++;				// zwiekszenie ilosci rund 
}

}while(!wygral && rundy < 10);		// petla gry bedzie przerwana jesli zmienna wygral bedzie miala wartosc true lub skoncza sie rundy (czyli pola zostana zapelnione) && - operator logiczny I 

wyswietl(tab);				// wyswietlenie pola

if(wygral){				// jesli ktos wygral 
	cout << "Wygral gracz " << wygrany << "!" << endl;	// wypisz kto wygral
} else {				// jesli nikt nie wygral
cout << "Remis!" << endl;		// wypisz remis
}

return 0;
}

void wyswietl(char tab[][14]){
	system("cls");					// wyczyszczenie konsoli
	for(int i = 0 ; i < 14 ; i++){	// wsp Y
		for (int k = 0 ; k < 14 ; k++){ // wsp X
			cout <<tab[i][k];		// wyswietl cala linijke
		}
		cout << endl;				// a potem przejdz do kolejnej linijki
	}
}

void sprawdzenie(char tab[][14], bool *wygral , char *wygrany){		// sprawdzenie warunkow (jesli pola w linii sa sobie rowne i sa rozne od spacji to ustalany jest zwyciezca)
	
if(tab[3][3]==tab[7][7] && tab[7][7]==tab[11][11] && tab[11][11]!=' '){
	*wygrany = tab[3][3];
	*wygral = true;
}else if(tab[11][3]==tab[7][7] && tab[7][7]==tab[3][11] && tab[3][11] != ' '){
	*wygrany = tab[11][3];
	*wygral = true;
}else if(tab[3][3]==tab[7][3] && tab[7][3]==tab[11][3] && tab[11][3] != ' '){
	*wygrany = tab[3][3];
	*wygral = true;
}else if(tab[3][7]==tab[7][7] && tab[7][7]==tab[11][7] && tab[11][7] != ' '){
	*wygrany = tab[3][7];
	*wygral = true;
}else if(tab[3][11]==tab[7][11] && tab[7][11]==tab[11][11] && tab[11][11] != ' ' ){
	*wygrany = tab[3][11];
	*wygral = true;
}else if(tab[3][3]==tab[3][7] && tab[3][7]==tab[3][11] && tab[3][11] != ' '){
	*wygrany = tab[3][3];
	*wygral = true;
}else if(tab[7][3]==tab[7][7] && tab[7][7]==tab[7][11] && tab[7][11] != ' '){
	*wygrany = tab[7][3];
	*wygral = true;	
}else if(tab[11][3]==tab[11][7] && tab[11][7]==tab[11][11] && tab[11][11] != ' '){
	*wygrany = tab[11][3];
	*wygral = true;
}

}
