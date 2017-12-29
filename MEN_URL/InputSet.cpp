#include "InputSet.h"
#include <iostream>

char Initialize() {
    char choose_mode;
    do {
        std::cin >> choose_mode;
    }
    while(choose_mode != 'T' && choose_mode != 'N' && choose_mode != 't' && choose_mode != 'n');
    return choose_mode;
}

Real GetParameter() {
    Real parameter;
    std::cout<<"podaj wartosc parametru q: ";
    std::cin >> parameter;
    return parameter;
}

void SetMatrixA(Real q, QMatrix5x5& A) {
    const int N = 5;
    Real t[N][N] = {
        { 2*q/10000, 1, 6, 9, 10 },
        { 0.0002, 1, 6, 9, 10 },
        { 1, 6, 6, 8, 6 },
        { 5, 9, 10, 7, 10 },
        { 3, 4, 9, 7, 9 }
    };
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            A(i, j) = t[i][j];
        }
    }
}

// specjalna wersja SetMatrixA() -> na diagonali ustawic element ktory w danej kolumnie jest najwiekszy
void SetMatrixACrout(Real parameter, QMatrix5x5& A) {

    // hardcode

    std::cout << "not implemented\n";
}

void SetMatrixB(QMatrix5x5& B) {
    const int tsizeRow = 5, tsizeCol = 5;
    Real t[tsizeRow][tsizeCol] = {
        { 1, 1, 1, 1, 1 },
        { 0.0002, 1, 6, 9, 10 },
        { 1, 6, 6, 8, 6 },
        { 5, 9, 10, 7, 10 },
        { 3, 4, 9, 7, 9 }
    };
    for (int i=0; i<tsizeRow; i++) {
        for (int j=0; j<tsizeCol; j++) {
            B(i, j) = t[i][j];
        }
    }
}

void SetMatrixb(QMatrix5x1& b) {
    Real t[] = { 10, 2, 9, 9, 3 };
    int tsize = 5;
    for (int i=0; i<tsize; i++) {
        b(i, 0) = t[i];
    }
}

