#ifndef DEFAULTMESSAGES_H
#define DEFAULTMESSAGES_H

#include "Types.h"

const int HowManyDecimal = 0;

void DefaultModeMessage();
void WelcomingMessage();
void CustomModeMessage();
void DispMatrix(QMatrix5x5);
void DispMatrix(QMatrix5x1);
void DispMatrixForLatex(QMatrix5x5, const int = HowManyDecimal);
void DispMatrixForLatex(QMatrix5x1, const int = HowManyDecimal);
void DispMatrixForLatex(QMatrix5x5, std::string MatrixName, const int = HowManyDecimal);
void DispMatrixForLatex(QMatrix5x1, std::string MatrixName, const int HowManyDecimal);

#endif // DEFAULTMESSAGES_H
