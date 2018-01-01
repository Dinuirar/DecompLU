#include "General.h"
#include <iostream>
#include <iomanip>

#include "Messages.h"
#include "Math.h"

void errorHandler(QMatrix5x5 A) {
    A.setToIdentity();
}

void LUDecomposition(QMatrix5x5 A, QMatrix5x5& L, QMatrix5x5& U) {
    const int N = 5;
    Real sum;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum = 0;
            for (int k = 0; k <= i-1; k++) {
                sum += ( L(i, k) * U(k, j) );
            }
            U(i, j) = A(i,j) - sum;
        }
        for (int j = i; j < N; j++) {
            sum = 0;
            for (int k = 0; k <= i-1; k++) {
                sum += ( L(j, k) * U(k, i) );
            }
            L(j, i) = (A(j, i) - sum)/U(i, i);
        }
    }
    return;
}

QMatrix5x1 CalculateResult(QMatrix5x5 L, QMatrix5x5 U, QMatrix5x1 b) {
    const int N = 5;
    QMatrix5x1 x;

    QMatrix5x1 y;
    y(0, 0) = L(0,0)/b(0,0);
    // podstawienia "do przodu"
    for (int i = 1; i < N; i++) {
        y(i, 0) = (b(i,0) - L(i, i-1)*y(i-1, 0)) / L(i,i);
    }

    x(N-1, 0) = y(N-1, 0) / U(N-1, N-1);
    // podstawienia "do tylu"
    for(int i = N-2; i >= 0; i--) {
        x(i, 0) = (y(i, 0) - U(i, i+1) * x(i+1, 0))/ U(i, i);
    }

    return x;
}

QMatrix5x1 CalculateResultInv(QMatrix5x5 L, QMatrix5x5 U, QMatrix5x1 b) {
    return InvertUpperMatrix(U) * (InvertLowerMatrix(L) * b); // x = invU * y; y = invL * b; x = invU * invL * b
}

QMatrix5x5 MergeLandU(QMatrix5x5 L, QMatrix5x5 U) {
    return L + U; // - QMatrix() // decLU = L + U - I?
}
