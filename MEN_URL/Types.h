#ifndef TYPES_H
#define TYPES_H

#include <qt5/QtGui/QGenericMatrix>

typedef double Real;
typedef QGenericMatrix<5,5,Real> QMatrix5x5;
typedef QGenericMatrix<1,5,Real> QMatrix5x1; // 5 rows, 1 column

#endif // TYPES_H
