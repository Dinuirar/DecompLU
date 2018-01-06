#include "General.h"
#include <iostream>
#include <iomanip>

#include "Messages.h"
#include "Math.h"

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
    for (int i = 1; i < N; i++) {
        y(i, 0) = (b(i,0) - L(i, i-1)*y(i-1, 0)) / L(i,i);
    }
    x(N-1, 0) = y(N-1, 0) / U(N-1, N-1);
    for(int i = N-2; i >= 0; i--) {
        x(i, 0) = (y(i, 0) - U(i, i+1) * x(i+1, 0))/ U(i, i);
    }
    return x;
}

QMatrix5x1 CalculateResultInv(QMatrix5x5 L, QMatrix5x5 U, QMatrix5x1 b) {
    return InvertUpperMatrix(U) * (InvertLowerMatrix(L) * b); // x = invU * y; y = invL * b; x = invU * invL * b
}

QMatrix5x5 MergeLandU(QMatrix5x5 L, QMatrix5x5 U) {
    return L + U - QMatrix5x5();
}

QMatrix5x1 CalcExactResult(Real q) {
    QMatrix5x1 c;
    c(0,0) = 4000/(q-1);
    c(1,0) = (219*q - 1720219) / (160*q - 160);
    c(2,0) = (-199*q - 5479161)/(320*q - 320);
    c(3,0) = (117*q+3639883)/(160*q - 160);
    c(4,0) = (-71*q - 2920569)/(320*q-320);
    return c;
}
