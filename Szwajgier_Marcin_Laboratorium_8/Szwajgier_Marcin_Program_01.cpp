#include "biblio.h"

int main() {
	// inicjalizacja: fstream, zestawy, pojemnosc, liczba elem, pomocnik, suma wag, liczniki
	fstream plik; int z, n, k, a, suma, l1 = 0, l2 = 0, l3 = 0, l4 = 0;
	otworzPlik("plik.txt", plik);
	plik >> z;
	for (int i = 0; i < z; i++) {
		plik >> n >> k;
		int *tab = stworzTablice(k); int *tab2 = stworzTablice(k);
		suma = 0;
		for (int j = 0; j < k; j++) {
			plik >> a;
			tab[j] = a;
		}
		toDzialaXD(tab, tab2, suma, l1, l2, l3, l4, n, k);
		delete[] tab; delete[] tab2;
	}
	zamknijPlik(plik);
	system("pause");
	return 0;
}
	
