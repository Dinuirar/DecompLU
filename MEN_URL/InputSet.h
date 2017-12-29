#ifndef INPUTSET_H
#define INPUTSET_H

#include "Types.h"

char Initialize();
Real GetParameter();
void SetMatrixA(Real parameter, QMatrix5x5&);
void SetMatrixACrout(Real parameter, QMatrix5x5&);
void SetMatrixb(QMatrix5x1&);
void SetMatrixB(QMatrix5x5&);

#endif // INPUTSET_H
