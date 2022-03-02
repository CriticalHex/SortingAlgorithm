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
		std::cout << "Well don't you think you're clever.\n\n";
		bool incorrect = true;
		int attempts = 0;
		int arr2[100];
		for (int i = 0; i < 100; i++) { // Reassign array slots with a random integer 1-100
			arr2[i] = toSort[i];
		}
		std::sort(arr2, arr2 + 100);
		do {
			//cout << "Attempting bogo sort...\n";
			std::random_shuffle(toSort, toSort + 10);
			attempts += 1;
			int correct = 0;
			for (int i = 0; i < 100; i++) { // Reassign array slots with a random integer 1-100
				if (toSort[i] == arr2[i]) {
					correct += 1;
				}
			}
			if (correct == 100) {
				incorrect = false;
			}
		} while (incorrect == true);
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