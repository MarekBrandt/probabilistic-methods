#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define a  69069
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
int przedzialy_licznosc3[4] = { 0, 0, 0, 0 };
int przedzialy_licznosc4[l_przedzialow];
int index = 0;



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

void zad1() {
	int los = rand() % 100;
	if (los < 20) {
		przedzialy_licznosc3[0]++;
	}
	else if (los < 60) {
		przedzialy_licznosc3[1]++;
	}
	else if (los < 75) {
		przedzialy_licznosc3[2]++;
	}
	else {
		przedzialy_licznosc3[3]++;
	}
}

void zad2() {
	float los = rand() % 100 / 100.0f;

	float result = los * 100 + 50;

	int przedzial = (int)(result)%10;

	przedzialy_licznosc4[przedzial] += 1;

	return;

}


int main() {

	srand(time(NULL));

	// inicjalizacja przedzialow zerami
	for (int i = 0; i < l_przedzialow; i += 1) {
		przedzialy_licznosc[i] = 0;
		przedzialy_licznosc2[i] = 0;
		przedzialy_licznosc4[i] = 0;
	}
	//maksymalna wartosc
	M = pow(2, 31);	

	for (int i = 0; i < n; i += 1) {
		zad1();
		zad2();
	}
	for (int i = 0; i < 4; i += 1) {
		printf(" %d ", przedzialy_licznosc3[i]);
	}
	printf("\n\n");
	for (int i = 0; i < l_przedzialow; i += 1) {
		printf(" %d ", przedzialy_licznosc4[i]);
	}


	return 0;
}