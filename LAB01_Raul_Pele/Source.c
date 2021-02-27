/*

9. Citeste un sir de numere naturale nenule terminat cu 0 si determina
numarul cifrelor 0 in care se termina numarul produs al numerelor citite.

*/
#include<stdio.h>

int factorK(int x, int k) {
	/*Returneaza de cate ori apare factorul k in descompunerea in factori a numarului x
	
	preconditii: x, k - tip int
	postconditii: functia returneaza un numar intreg reprezentand numarul de aparitii a factorului k in 
		descompunerea in factori
	*/
	int nrK = 0;
	
	while (x % k == 0 ) {
		nrK++;
		x /= k;
	}

	return nrK;
}

int min(int a, int b) {
	/*Returneaza minimul dintre a si b
	preconditii: a, b - tip int
	postconditii: returneaza min(a, b) - tip int
	 */

	if (a <= b) {
		return a;
	}
	return b;
}

int citire() {
	//Vom rezolva problema la citire. Pe parcursul citirii numerelor, vom determina
	//pentru fiecare numar de cate ori apare 2 si 5 in descompunerea in factori primi a numarului.
	//Numarul de 0-uri de la finalul produsului coincide cu minimul dintre aparitiile lui
	//2 si 5 in descompunerea in factori. (de cate ori este numarul divizibil cu 10)

	//postconditii: Functia returneaza numarul de zero-uri de la finalul produsului numerelor citite.

	int nr2 = 0, nr5 = 0, x;
	scanf_s("%d", &x);

	while (x != 0) {
		nr2 += factorK(x, 2);
		nr5 += factorK(x, 5);
		scanf_s("%d", &x);
	}

	return min(nr2, nr5);
}

void detZero() {
	//Determina numarul de zero-uri de la produsul unui sir de numere si il afiseaza pe ecran

	printf("Numarul de zero-uri de la finalul numarului rezultat este: %d\n", citire());
}

void afisMeniu() {
	//Functia care afiseaza meniul utilizatorului

	printf("\n");
	printf("1. Determinare numar zero-uri de la sfarsitul produsului unor numere.\n");
	printf("2. Exit\n\n");
}

int readOp() {
	//Citeste un numar zecimal reprezentand optiunea aleasa de utilizator
	//postconditii: functia returneaza un numar de tip int reprezentand optiunea

	int op;

	printf("Dati o optiune: ");
	scanf_s("%d", &op);

	return op;
	
}

void run() {
	//Functia principala care ruleaza programul
	int op;
	
	while (1) {
		afisMeniu();
		op = readOp();

		switch (op) {
		case 1:
			detZero();
			break;

		case 2:
			return;
		}
	}

}

int main() {
	run();
	return 0;
}