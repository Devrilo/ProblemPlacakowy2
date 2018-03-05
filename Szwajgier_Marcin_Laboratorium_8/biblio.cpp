#include "biblio.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
*Funkcja otwieraj¹ca plik + sprawdza czy uda³o siê go otworzyæ
*@param_in: nazwa pliku, fstream
*/
void otworzPlik(string nazwa, fstream &plik) {
	plik.open(nazwa);
	if (plik.good() == 0) {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
		getchar();
		exit(0);
	}
}

/*
*Funkcja zamykajaca plik
*@param_in: fstream
*/
void zamknijPlik(fstream &plik) {
	plik.close();
}

/*
*Funkcja alokujaca pamiec na tablice dynamiczna i sprawdzajaca czy udalo sie ja zaalokowac
*@param_in: liczba elem
*@return: tablica
*/
int *stworzTablice(int n) {
	int *tab = nullptr;
	try
	{
		tab = new int[n];
	}
	catch (bad_alloc)
	{
		cout << "Nie udalo sie utworzyc tablicy!" << endl;
		getchar();
		exit(0);
	}
	return tab;
}

/*
*Fkcja rozwiazujaca problem plecakowy (same wagi, bez wartosci)
*@param_in: tablica z wejscia, tablica na wyjscie, suma, cztery pomocniki, pojemnosc plecaka, liczba elementow z wejscia
*/
int toDzialaXD(int *tab, int *tab2, int suma, int l1, int l2, int l3, int l4, int n, int k) {
	if (n > suma && suma != 0) {
		suma += tab[l1];
		tab2[l2] = tab[l1];
		l1++;
		if (n > suma) {
			l2++;
		}
	}
	else if (n < suma) {
		suma -= tab[l1 - 1];
		suma += tab[l1];
		tab2[l2] = tab[l1];
		l1++;
	}
	else if (suma == 0) {
		tab2[l2] = tab[l1];
		suma += tab[l1];
		l1++; l2++;
	}
	if (suma == n) {
		cout << n << " = ";
		for (int i = 0; i <= l2; i++)
			cout << tab2[i] << ' ';
		cout << endl;
		return 0;
	}
	if (l1 == k && l3 == k) {
		cout << "BRAK" << endl;
		return 0;
	}
	else if (l1 == k) {
		l3++;
		l2 = l3 - 1;
		l1 = l3;
		suma = 0;
	}
	else if (l3 == k) {
		l4++;
		l1 = l4;
		l2 = 0;
	}
	toDzialaXD(tab, tab2, suma, l1, l2, l3, l4, n, k);
}