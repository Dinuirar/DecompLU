#ifndef MATH_H
#define MATH_H

#include "Types.h"

Real CalcDeterminant(QMatrix5x5 decLU);
Real CalcDeviation(QMatrix5x1 b, QMatrix5x1 c);
QMatrix5x5 InvertLowerMatrix(QMatrix5x5);
QMatrix5x5 InvertUpperMatrix(QMatrix5x5);

#endif // MATH_H
