#include <math.h>
#include <iostream>

#define n 100000
#define l_przedzialow 4


int licznosc[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int licznosc1[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
float prawdopodobienstwa[4][4] = { {0.15, 0, 0, 0.2}, {0.05, 0, 0.1, 0}, {0, 0.1, 0, 0.05}, {0.2, 0, 0, 0.15} };
float prawd_x[4] = { 0, 0, 0, 0 };
float prawd_y[4][4];

int znal_x;
int znal_y;



void generujOdX(int x) {
	float los = rand() % 100;
	los = los / 100;
	//std::cout << los << std::endl;
	if (los < prawd_y[x][0]) {
		licznosc[x][0]++;
	}
	else if (los < prawd_y[x][0] + prawd_y[x][1]) {
		licznosc[x][1]++;
	}
	else if (los < prawd_y[x][0] + prawd_y[x][1] + prawd_y[x][2]) {
		licznosc[x][2]++;
	}
	else {
		licznosc[x][3]++;
	}
}

void generuj() {

	float los = rand() %100;
	los = los / 100;
	//std::cout << los << std::endl;
	if (los < prawd_x[0]) {
		generujOdX(0);
	}
	else if (los < prawd_x[0] + prawd_x[1]) {
		generujOdX(1);
	}
	else if (los < prawd_x[0]+ prawd_x[1]+ prawd_x[2]) {
		generujOdX(2);
	}
	else {
		generujOdX(3);
	}
}

void dodatkowe() {

	float max = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (prawdopodobienstwa[i][j] > max) max = prawdopodobienstwa[i][j];
		}
	}

	max = max + 0.001;

	while (true) {
		float los = rand() % (int)(max*100);
		los = los / 100;
		int x = rand() % 4;
		int y = rand() % 4;
		if (prawdopodobienstwa[x][y] > los) {
			licznosc1[x][y]++;
			break;
		}
	}	
}




int main() {

	srand(time(NULL));

	

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			prawd_x[i] += prawdopodobienstwa[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			prawd_y[i][j] = prawdopodobienstwa[i][j] / prawd_x[i];
		}
	}

	

	for (int i = 0; i < n; i += 1) {
		dodatkowe(); 
		generuj();
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << licznosc[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << licznosc1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}