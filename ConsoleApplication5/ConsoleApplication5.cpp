#include "pch.h"
// Nathan Stucki, Section 6, stookler@yahoo.com
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double ComputeWinnings(int slot);

double SingleChipInsert(double slotNum) {
	int randNum = 0;
	int slotNumInt = 0;
	double userInput3 = 0;
	const int RANDOM_SEED = 42;

	srand(RANDOM_SEED);

	slotNumInt = slotNum;

	cout << "*** Dropping chip into slot " << slotNumInt << " ***" << endl;
	cout << fixed << setprecision(1) << "Path: [";
	cout << slotNum << ", ";
	for (int i = 1; i < 13; ++i) {
		
		if (slotNum >= 0.5 && slotNum <= 7.5) {
			randNum = 0;
			randNum = rand() % 2;
			if (randNum == 0) {
				slotNum = slotNum - 0.5;
			}
			else if (randNum == 1) {
				slotNum = slotNum + 0.5;
				}
		}
		else if (slotNum == 0) {
			slotNum = slotNum + 0.5;
		}
		else if (slotNum == 8) {
			slotNum = slotNum - 0.5;
		}
		if (i < 12) {
			cout << slotNum << ", ";
		}
		else if (i == 12) {
			cout << slotNum;
		}
	} cout << "]" << endl;
	slotNumInt = slotNum;
	cout << "Winnings: $";
	cout << fixed << setprecision(2) << ComputeWinnings(slotNumInt) << endl << endl;
	return 0;
}
double ComputeWinnings(int slot) {

	double WINNINGS[9];

	WINNINGS[0] = 100.00;
	WINNINGS[1] = 500.00;
	WINNINGS[2] = 1000.00;
	WINNINGS[3] = 0.00;
	WINNINGS[4] = 10000.00;
	WINNINGS[5] = 0.00;
	WINNINGS[6] = 1000.00;
	WINNINGS[7] = 500.00;
	WINNINGS[8] = 100.00;

	return WINNINGS[slot];
}
int main() {
	int userInput = 0;
	int userInput2 = 0;
	int randNum = 0;
	int numChips = 0;
	double userInput3 = 0.0;
	double totalWinnings = 0.0;
	double avgWinnings = 0.0;
	const int RANDOM_SEED = 42;
	double WINNINGS[8];
	bool select = true;

	srand(RANDOM_SEED);

	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl << endl;

	do {
		cout << "Enter your selection now:" << endl << endl;
		cin >> userInput;

		int i = 0;
		switch (userInput) {
		case 1:
			cout << "*** Drop a single chip ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl << endl;
			cin >> userInput2;
			userInput3 = userInput2;
			if ((userInput2 > -1) && (userInput2 < 9)) {
				SingleChipInsert(userInput3);
			}

			else {
				cout << "Invalid slot." << endl;
				select = true;
			}
			break;
			//Part 3 - multiple chip drop
		/*case 2:
			cout << "*** Drop multiple chips ***" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			cin >> numChips;
			if (numChips < 1) {
				cout << "Invalid number of chips." << endl;
			}
			else {
				cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
				cin >> userInput2;
				userInput3 = userInput2;
				if ((userInput3 < 0) || (userInput3 > 8)) {
					cout << "Invalid slot." << endl;
				}
				else if ((userInput3 >= 0) && (userInput3 <= 8)) {
					for (i = 0; i < numChips; ++i) {
						userInput3 = userInput2;
						for (int j = 1; j < 13; ++j) {
							if (userInput3 == 0) {
								userInput3 = userInput3 + 0.5;
							}
							else if (userInput3 == 8) {
								userInput3 = userInput3 - 0.5;
							}
							else {
								randNum = rand() % 2;
								if (randNum == 0) {
									userInput3 = userInput3 - 0.5;
								}
								else if (randNum == 1) {
									userInput3 = userInput3 + 0.5;
								}
							}
						}
						if ((userInput3 == 0) || (userInput3 == 8)) {
							totalWinnings = totalWinnings + WINNINGS_0_8;
						}
						else if ((userInput3 == 1) || (userInput3 == 7)) {
							totalWinnings = totalWinnings + WINNINGS_1_7;
						}
						else if ((userInput3 == 2) || (userInput3 == 6)) {
							totalWinnings = totalWinnings + WINNINGS_2_6;
						}
						else if ((userInput3 == 3) || (userInput3 == 5)) {
							totalWinnings = totalWinnings + WINNINGS_3_5;
						}
						else if (userInput3 == 4) {
							totalWinnings = totalWinnings + WINNINGS_4;
						}
					}
					cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
					avgWinnings = totalWinnings / numChips;
					cout << "Average winnings per chip: $" << avgWinnings << endl;
					totalWinnings = 0.00;
					avgWinnings = 0.00;
				}
			}
			select = true;
			break; */
		case 3:
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl << endl;
			select = true;
			break;
		case 4:
			select = false;
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Invalid selection. Enter 3 to see options." << endl << endl;
			select = true;
			break;
		}
	} while (select);

	return 0;
}

