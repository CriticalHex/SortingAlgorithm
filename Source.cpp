#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>

int main() {
	srand(time(NULL));
	int iter = 0;
	int toSort[100] = {};
	int input = 0;
	for (int i = 0; i < 100; i++) {
		toSort[i] = rand() % 100 + 1;
		std::cout << toSort[i] << " ";
	}
	std::cout << "\n\nPick your sorter: 1 for Bubble, and 2 for Shell: ";
	std::cin >> input;

	if (input == 1) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (toSort[i] <= toSort[j]) {
					int save = toSort[i];
					toSort[i] = toSort[j];
					toSort[j] = save;
					iter += 1;
				}
			}
		}
	}
	else if (input == 2) {
		int gap = 100 / 2;
		while (gap > 0) {
			for (int j = 0; j < 100; j++) {
				for (int i = j + gap; i < 100; i += gap) {

					int save = toSort[i];

					while (i >= gap && toSort[i - gap] > save) {
						toSort[i] = toSort[i - gap];
						i -= gap;
						iter++;
					}

					toSort[i] = save;
				}
			}
				gap = gap / 2;
		}
	}
	else if (input == 3) {
		std::cout << "Well don't you think you're clever.";
	}
	else {
		std::cout << "Try again...";
	}
	std::cout << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << toSort[i] << " ";
	}
	std::cout << "\n\n" << "Sorts preformed: " << iter << "\n\n";
}