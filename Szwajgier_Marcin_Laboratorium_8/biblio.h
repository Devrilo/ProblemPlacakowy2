#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void otworzPlik(string nazwa, fstream &plik);
void zamknijPlik(fstream &plik);
int *stworzTablice(int n);
int toDzialaXD(int *tab, int *tab2, int suma, int l1, int l2, int l3, int l4, int n, int k);

