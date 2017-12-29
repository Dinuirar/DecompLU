#ifndef GENERAL_H
#define GENERAL_H

#include <qt5/QtGui/QGenericMatrix>
#include "Types.h"

QMatrix5x5 LUDecomposition(QMatrix5x5);
void LUDecomposition(QMatrix5x5 A, QMatrix5x5& L, QMatrix5x5& U);
QMatrix5x1 CalculateResult(QMatrix5x5, QMatrix5x5, QMatrix5x1);
QMatrix5x1 CalculateResultInv(QMatrix5x5 L, QMatrix5x5 U, QMatrix5x1 b);
QMatrix5x5 MergeLandU(QMatrix5x5 L, QMatrix5x5 U);

#endif // FUNCTIONS_H
