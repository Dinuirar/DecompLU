#include "Messages.h"
#include <iostream>
#include <iomanip>

void DefaultModeMessage(){
    std::cout << "rozwiazany zostanie uklad Ax = b: \n"
                 "A = \n"
            "\t| 2q*e-4\t 1\t 6\t 9\t 10 \t|\n"
            "\t| 2e-4\t\t 1\t 6\t 9\t 10 \t|\n"
            "\t| 1\t\t 6\t 6\t 8\t 6 \t| \n"
            "\t| 5\t\t 9\t 10\t 7\t 10 \t|\n"
            "\t| 3\t\t 4\t 9\t 7\t 9 \t|\n\n"
                 "b = \n"
                 "\t| 10\t|\n"
                 "\t| 2\t|\n"
                 "\t| 9\t|\n"
                 "\t| 9\t|\n"
                 "\t| 3\t|\n";
}

void WelcomingMessage() {
    std::cout << "Program rozwiazujacy uklad rownan liniowych\n"
             "postaci Ax = b, metoda rozkladu LU\n"
            "Czy chcesz rozwiazac uklad domyslny z parametrem? [T/N]\n";
}

void DispMatrix(QMatrix5x5 A) {
    int tsizeRow = 5, tsizeCol = 5;
    for (int i = 0; i < tsizeRow; i++) {
        for (int j=0; j<tsizeCol; j++) {
            std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j) << "\t";
        }
        std::cout<<"\n";
    }
}

void DispMatrix(QMatrix5x1 A) {
    int tsizeRow = 5, tsizeCol = 1;
    for (int i = 0; i < tsizeRow; i++) {
        for (int j=0; j<tsizeCol; j++) {
            std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j) << "\t";
        }
        std::cout<<"\n";
    }
}

void DispMatrixForLatex(QMatrix5x5 A, std::string MatrixName, const int HowManyDecimal) {
    int tsizeRow = 5, tsizeCol = 5;
    std::cout << "\n" << MatrixName << "\n"
              << "\\left[\n"
              << "\\begin{array}{";
    for( int i = 0; i < tsizeCol; i++ ) std::cout<<"c";
    std::cout << "}\n";
    for ( int i = 0; i < tsizeRow; i++ ) {
        for ( int j = 0; j < tsizeCol; j++ ) {
            if(j == 0)
                std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j);
            else std::cout<< std::setprecision(0) << A(i, j);
            if( j != tsizeCol-1 ) std::cout << "&";
        }
        if( i != tsizeRow-1 ) std::cout<<"\\\\ \n";
    }
    std::cout<<"\n\\end{array}\n"
               "\\right]\n\n";
}

void DispMatrixForLatex(QMatrix5x1 A, std::string MatrixName, const int HowManyDecimal) {
    int tsizeRow = 5, tsizeCol = 1;
    std::cout << "\n" << MatrixName << "\n$$\n"
              << "\\left[\n"
              << "\\begin{array}{";
    for( int i = 0; i < tsizeCol; i++ ) std::cout<<"c";
    std::cout << "}\n";
    for ( int i = 0; i < tsizeRow; i++ ) {
        for ( int j = 0; j < tsizeCol; j++ ) {
            std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j);
            if( j != tsizeCol-1 ) std::cout << "&";
        }
        if( i != tsizeRow-1 ) std::cout<<"\\\\ \n";
    }
    std::cout<<"\n\\end{array}\n"
               "\\right]\n$$\n";
}

void DispMatrixForLatex(QMatrix5x1 A, const int HowManyDecimal) {
    int tsizeRow = 5, tsizeCol = 1;
    std::cout << "\\left[\n"
        "\\begin{array}{";
    for( int i = 0; i < tsizeCol; i++ ) std::cout<<"c";
    std::cout << "}\n";
    for ( int i = 0; i < tsizeRow; i++ ) {
        for ( int j = 0; j < tsizeCol; j++ ) {
            std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j);
            if( j != tsizeCol-1 ) std::cout << "&";
        }
        if( i != tsizeRow-1 ) std::cout<<"\\\\ \n";
    }
    std::cout<<"\n\\end{array}\n"
               "\\right]\n";
}

void DispMatrixForLatex(QMatrix5x5 A, const int HowManyDecimal) {
    int tsizeRow = 5, tsizeCol = 5;
    std::cout << "\\left[\n"
        "\\begin{array}{";
    for( int i = 0; i < tsizeCol; i++ ) std::cout<<"c";
    std::cout << "}\n";
    for ( int i = 0; i < tsizeRow; i++ ) {
        for ( int j = 0; j < tsizeCol; j++ ) {
            if(j == 0) std::cout << std::setiosflags (std::ios::fixed) << std::setprecision(HowManyDecimal) << A(i, j);
            else std::cout<< std::setprecision(0) << A(i, j);
            if( j != tsizeCol-1 ) std::cout << "&";
        }
        if( i != tsizeRow-1 ) std::cout<<"\\\\ \n";
    }
    std::cout<<"\n\\end{array}\n"
               "\\right]\n";
}
