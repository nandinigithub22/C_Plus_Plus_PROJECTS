#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int CARD_ROWS = 3;
const int CARD_COLS = 9;
const int NUMBERS_PER_ROW = 5;
const int MAX_NUMBER = 90;

struct Card {
    int numbers[CARD_ROWS][CARD_COLS] = {0};
    bool marked[CARD_ROWS][CARD_COLS] = {false};
};

void generateCard(Card &card) {
    srand(time(0));
    vector<int> numbers(MAX_NUMBER);
    for (int i = 0; i < MAX_NUMBER; ++i) {
        numbers[i] = i + 1;
    }
    random_shuffle(numbers.begin(), numbers.end());

    int index = 0;
    for (int row = 0; row < CARD_ROWS; ++row) {
        int count = 0;
        while (count < NUMBERS_PER_ROW) {
            int col = rand() % CARD_COLS;
            if (card.numbers[row][col] == 0) {
                card.numbers[row][col] = numbers[index++];
                ++count;
            }
        }
    }
}

void printCard(const Card &card) {
    for (int row = 0; row < CARD_ROWS; ++row) {
        for (int col = 0; col < CARD_COLS; ++col) {
            if (card.numbers[row][col] != 0) {
                cout << card.numbers[row][col] << "\t";
            } else {
                cout << " \t";
            }
        }
        cout << "\n";
    }
}

bool markNumber(Card &card, int number) {
    for (int row = 0; row < CARD_ROWS; ++row) {
        for (int col = 0; col < CARD_COLS; ++col) {
            if (card.numbers[row][col] == number) {
                card.marked[row][col] = true;
                return true;
            }
        }
    }
    return false;
}

bool checkWin(const Card &card) {
    for (int row = 0; row < CARD_ROWS; ++row) {
        int markedCount = 0;
        for (int col = 0; col < CARD_COLS; ++col) {
            if (card.marked[row][col]) {
                ++markedCount;
            }
        }
        if (markedCount == NUMBERS_PER_ROW) {
            return true;
        }
    }
    return false;
}

int main() {
    Card playerCard;
    generateCard(playerCard);

    cout << "Your Tambola Card:\n";
    printCard(playerCard);

    vector<int> drawnNumbers(MAX_NUMBER);
    for (int i = 0; i < MAX_NUMBER; ++i) {
        drawnNumbers[i] = i + 1;
    }
    random_shuffle(drawnNumbers.begin(), drawnNumbers.end());

    int turn = 0;
    while (true) {
        int number = drawnNumbers[turn++];
        cout << "\nNumber Drawn: " << number << "\n";
        if (markNumber(playerCard, number)) {
            cout << "Marked on your card.\n";
        } else {
            cout << "Not on your card.\n";
        }

        if (checkWin(playerCard)) {
            cout << "Congratulations! You have won the game.\n";
            break;
        }

        char choice;
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}
