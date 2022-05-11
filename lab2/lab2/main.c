#include <stdio.h>
#include <math.h>

#define a  69069
#define c 1
#define n 100000
#define x0 15
#define l_przedzialow 10
#define p 7
#define q 3
int tablica_bitow[31] = { 1,0,1,1,0,1,0 };

long long M;

long long wygenerowane[n];
int przedzialy_licznosc[l_przedzialow];
int przedzialy_licznosc2[l_przedzialow];
int index = 0;

long long gen_liniowy() {
	long long next;
	next = (a * wygenerowane[index] + c) % M;
	index++;
	wygenerowane[index] = next;
	int przedzial = next%10;
	przedzialy_licznosc[next/(M/10)] += 1;

	return next;
}

long long przesuwny() {
	for (int i = 7; i < 31; i += 1) {
		tablica_bitow[i] = tablica_bitow[i - p] ^ tablica_bitow[i - q];
	}

	long long liczba = 0;
	for (int i = 0; i <31; i += 1) {
		liczba += pow(2, i) * tablica_bitow[i];
	}

	for (int i = 0; i < 7; i++) {
		tablica_bitow[i] = tablica_bitow[i + 24];
	}

	int przedzial = M/10;
	przedzialy_licznosc2[liczba/(przedzial)] += 1;
}


int main() {

	// inicjalizacja przedzialow zerami
	for (int i = 0; i < l_przedzialow; i += 1) {
		przedzialy_licznosc[i] = 0;
		przedzialy_licznosc2[i] = 0;
	}
	//maksymalna wartosc
	M = pow(2, 31);
	//inicjalizacja pierwszej
	wygenerowane[0] = x0;
	for (int i = 0; i < n; i += 1) {
		gen_liniowy();
		//printf(" %lu ", gen_liniowy());
	}
	for (int i = 0; i < l_przedzialow; i += 1) {
		printf(" %d ", przedzialy_licznosc[i]);
	}
	for (int i = 0; i < n; i += 1) {
		przesuwny();
	}
	printf("\n\n");
	for (int i = 0; i < l_przedzialow; i += 1) {
		printf(" %d ", przedzialy_licznosc2[i]);
	}


	return 0;
}