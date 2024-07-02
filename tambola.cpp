#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 9;
const int TOTAL_NUMBERS = 90;

void getColumnRange(int col, int* range, int& size) {
    int start = col * 10 + 1;
    int end = (col + 1) * 10;
    if (col == 8) end = 90; // Last column goes from 80 to 90
    size = 0;
    for (int i = start; i <= end; ++i) {
        range[size++] = i;
    }
}

void generateTambolaTicket(int ticket[ROWS][COLS]) {
    int colRange[10]; // Maximum 10 numbers in any column range
    int rangeSize;

    for (int col = 0; col < COLS; ++col) {
        getColumnRange(col, colRange, rangeSize);
        random_shuffle(colRange, colRange + rangeSize);
        for (int row = 0; row < ROWS; ++row) {
            ticket[row][col] = colRange[row];
        }
    }

    for (int row = 0; row < ROWS; ++row) {
        int zeroCount = 0;
        while (zeroCount < 4) {
            int pos = rand() % COLS;
            if (ticket[row][pos] != 0) {
                ticket[row][pos] = 0;
                zeroCount++;
            }
        }
    }
}

void printTicket(int ticket[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (ticket[row][col] == 0) {
                cout << "   ";
            } else {
                cout << ticket[row][col] << " ";
            }
        }
        cout << endl;
    }
}

void generateNumberPool(int pool[TOTAL_NUMBERS]) {
    for (int i = 0; i < TOTAL_NUMBERS; ++i) {
        pool[i] = i + 1;
    }
}

int callNumber(int pool[TOTAL_NUMBERS], int& poolSize) {
    if (poolSize == 0) return -1;
    int index = rand() % poolSize;
    int number = pool[index];
    pool[index] = pool[--poolSize];
    return number;
}

void markNumber(int ticket[ROWS][COLS], int number) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (ticket[row][col] == number) {
                ticket[row][col] = 0;
            }
        }
    }
}

bool checkFullHouse(int ticket[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (ticket[row][col] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0));
    int ticket[ROWS][COLS] = {0};
    int numberPool[TOTAL_NUMBERS];
    int poolSize = TOTAL_NUMBERS;

    generateTambolaTicket(ticket);
    printTicket(ticket);

    generateNumberPool(numberPool);

    while (poolSize > 0) {
        int calledNumber = callNumber(numberPool, poolSize);
        cout << "Number called: " << calledNumber << endl;
        markNumber(ticket, calledNumber);
        if (checkFullHouse(ticket)) {
            cout << "Full House!" << endl;
            break;
        }
    }

    return 0;
}
