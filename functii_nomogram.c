//Dobre Andrei-Teodor 314CA
#include <stdio.h>
#define MAX 100

int verif(int n, int m, int linii[MAX][MAX], int coloane[MAX][MAX],
		  int grid[n][m], int nr_grupuri_c[MAX], int nr_grupuri_l[MAX])

{
	//verificare linii
	for (int i = 0; i < n; i++) {
		int grup = 0;//la fiecare schimbare a liniei resetam valoarea grupului
		int dimensiune = 0;// ~/~ dimensiunii

		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				dimensiune++;
			} else if (grid[i][j] == 0) {
				if (dimensiune > 0) {
					if (dimensiune != linii[i][grup])
						return 0; //dimensiunea grupului nu corespunde
					dimensiune = 0;
					grup++;
				}
			}
		}
		//citirea liniei s-a terminat
		//ne asiguram si pentru cazurile in care linia se termina in 1
		if (dimensiune > 0) {
			if (dimensiune != linii[i][grup])
				return 0; //dimensiunea grupului nu corespunde
		}

		//Daca linia se incheie in 1 se mai formeaza un grup
		if (grid[i][m - 1] == 1)
			grup++;

		if (grup != nr_grupuri_l[i])
			return 0; //nr de grupuri nu corespunde
	}

	//verificam coloanele
	for (int j = 0; j < m; j++) {
		int grup = 0;
		int dimensiune = 0;

		for (int i = 0; i < n; i++) {
			if (grid[i][j] == 1) {
				dimensiune++;
			} else if (grid[i][j] == 0) {
				if (dimensiune > 0) {
					if (dimensiune != coloane[j][grup])
						return 0;
					dimensiune = 0;
					grup++;
				}
			}
		}

		if (dimensiune > 0) {
			if (dimensiune != coloane[j][grup])
				return 0;
		}

		//daca coloana se incheie in 1 se mai formeaza un grup
		if (grid[n - 1][j])
			grup++;

		if (grup != nr_grupuri_c[j])
			return 0;
	}

	//daca grid-ul trece de toate verificarile returnam valoarea 1
	//adica grid-ul este corect
	return 1;
}
