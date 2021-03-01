#include<stdio.h>

//10. Tipareste un numar precizat de sume partiale din dezvoltarea
//   sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

void citire(int *x, int *n) {
	printf("Dati x-ul: \n");
	scanf_s("%d", x);

	printf("Dati n: ");
	scanf_s("%d", n);
}

long double detTermen(int x, int i) {
	int putere, fact;
	putere = x;
	fact = 1;

	for (int j = 1; j < 2 * i - 1; j++) {
		putere *= x;
		fact *= j;
	}

	fact *= 2 * i - 1;

	long double termen = (long double)putere / fact;
	if (i % 2 == 0) {
		termen = -termen;
	}

	//printf("putere: %d fact: %d\n", putere, fact);

	return termen;
}


void detSumePartiale(int x, int n) {
	long double sum = 0;
	for (int i = 1; i <= n; i++) {
		 sum += detTermen(x, i);

		printf("Suma partiala a primilor %i termeni: %f\n", i, sum);
	}
}

int main() {
	int x, n;

	x = n = 0;
	citire(&x, &n);

	detSumePartiale(x, n);
	return 0;
}