#include "Math.h"
#include <cmath>

Real CalcDeterminant(QMatrix5x5 decLU) {
    const int N = 5;
    Real determinant = 1;
    for (int i = 0; i < N; i++)
        determinant *= decLU(i, i);
    return determinant;
}

QMatrix5x5 InvertLowerMatrix(QMatrix5x5 L) {
    const int N = 5;
    QMatrix5x5 L_;
    Real sum;
    for (int i = 0; i < N; i ++) {
        L_(i,i) = 1 / L(i,i);
        for (int j = 0; j <= i-1; j++) {
            sum = 0;
            for (int k = 0; k <= i-1; k++) {
                sum += L(i,k) * L_(k,j);
            }
            L_(i, j) = -L_(i,i) * sum;
        }
    }
    return L_;
}

QMatrix5x5 InvertUpperMatrix(QMatrix5x5 U) {
    const int N = 5;
    QMatrix5x5 U_;
    Real sum;
    for (int i = 0; i < N; i ++) {
        U_(i,i) = 1 / U(i,i);
        for (int j = 0; j <= i-1; j++) {
            sum = 0;
            for (int k = 0; k <= i-1; k++) {
                sum += U(k,i) * U_(j,k);
            }
            U_(j, i) = -U_(i,i) * sum;
        }
    }
    return U_;
}

Real CalcDeviation(QMatrix5x1 b, QMatrix5x1 c) {
    int N = 5;
    Real sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (c(i, 0) - b(i, 0)) * (c(i, 0) - b(i, 0));
    }
    return 0.2 * sqrt(sum);
}
