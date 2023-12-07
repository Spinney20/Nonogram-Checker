//Dobre Andrei-Teodor 314CA
#include <stdio.h>
#include "functii_nomogram.h"
#define MAX 100

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t) {
		int n, m;
		scanf("%d %d", &n, &m);

		//citirea instructiunilor pt. linii
		int linii[MAX][MAX];
		int nr_grupuri_l[MAX];
		for (int i = 0; i < n; i++) {
			//citim mai intai nr de grupuri pt fiecare linie intr-un vector
			scanf("%d", &nr_grupuri_l[i]);
			for (int j = 0; j < nr_grupuri_l[i]; j++)
				//continuam cu citirea dimensiunii grupurilor intr-o matrice
				scanf("%d", &linii[i][j]);
		}

		//citirea instructiunilor pt. coloane
		int coloane[MAX][MAX];
		int nr_grupuri_c[MAX];
		for (int i = 0; i < m; i++) {
			//citim mai intai nr de grupuri pt fiecare coloana in alt vector
			scanf("%d", &nr_grupuri_c[i]);
			for (int j = 0; j < nr_grupuri_c[i]; j++)
				//continuam cu citirea dimensiunii grupurilor in alta matrice
				scanf("%d", &coloane[i][j]);
		}

		int grid[n][m];

		//citim matricea grid
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				scanf("%d", &grid[i][j]);
		}

		//verificam matricea grid
		if (verif(n, m, linii, coloane, grid, nr_grupuri_c, nr_grupuri_l))
			printf("Corect\n");
		else
			printf("Eroare\n");

		t--;
	}
	return 0;
}
