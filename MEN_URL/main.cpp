#include "Messages.h"
#include "General.h"
#include "Types.h"
#include "InputSet.h"
#include "Math.h"

#include <vector>
#include <fstream>

#include <iostream>
#include <qt5/QtGui/QGenericMatrix>

using namespace std;

int main() {
    Real q;
    QMatrix5x5 A;
    QMatrix5x1 b;

    WelcomingMessage();
    DefaultModeMessage();
    //q = GetParameter();
    q = 2; // do testow wartosc zafixowana
    if (q == 0) {
        SetMatrixACrout(q, A);
    }
    SetMatrixA(q, A);
    SetMatrixb(b);

    if ( q == 1 ) {
        cout << "Dla q = 1 uklad nie ma rozwiazan.\n";
        return 0;
    }

    QMatrix5x5 LA, UA;
    LUDecomposition (A, LA, UA);

    QMatrix5x1 x = CalculateResultInv(LA, UA, b);

    QMatrix5x1 c = A*x;
    Real E = CalcDeviation(c, b);

    bool simEq = 0,
            simDet = 1;
    //////////////////////////E(q)///////////////////////////////////
    if(simEq) {
        vector<Real> qis, Es;
        Real step = 0.1;
        QMatrix5x5 tmpA, tmpL, tmpU;
        QMatrix5x1 tmpx;
        for (Real qi = 0.2; qi <= 5; qi += step) {
            SetMatrixA(qi, tmpA);
            LUDecomposition(tmpA, tmpL, tmpU);
            tmpx = CalculateResultInv(tmpL, tmpU, b);
            Es.push_back( CalcDeviation( b, tmpA*tmpx ) );
            qis.push_back( qi );
        }
        ofstream file;
        file.open("dataEq.txt");
        for (int i = 0; i < qis.size(); i++) {
            //        file << qis[i] << "," << Es[i] << endl;
        }
        file.close();
    }
    /////////////////////////////////////////////////////////////////
    if(simDet) {
        vector<Real> qis, dets;
        Real step = 0.1;
        QMatrix5x5 tmpA, tmpL, tmpU, tmpdecLU;
        for (Real qi = 0.2; qi <= 5; qi += step) {
            SetMatrixA(qi, tmpA);
            LUDecomposition(tmpA, tmpL, tmpU);
            tmpdecLU = MergeLandU(tmpL, tmpU);
            dets.push_back( CalcDeterminant(tmpdecLU) );
            qis.push_back( qi );
        }
        ofstream file;
        file.open("dataDetq.txt");
        for (int i = 0; i < qis.size(); i++) {
                    file << qis[i] << "," << dets[i] << endl;
        }
        file.close();
    }
    /////////////////////////////////////////////////////////////////
    QMatrix5x5 invA = InvertUpperMatrix(UA) * InvertLowerMatrix(LA);
    cout << "\ninvA = invU * invL: \n";
    DispMatrix( invA );
    cout << "\nA * invA = \n";
    DispMatrix( A * invA);
    /////////////////////////////////////////////////////////////////
    QMatrix5x5 B, LB, UB;
    SetMatrixB(B);
    LUDecomposition(B, LB, UB);
    QMatrix5x5 invB = InvertUpperMatrix(UB) * InvertLowerMatrix(LB);
    cout << "\ninvB = invU * invL\n";
    DispMatrix( invB );
    cout << "\nB * invB = \n";
    DispMatrix( B * invB );

//    cout << "E(q) dla q = " << q << " wynosi " << E << "\n";

//    cout << "\ndekompozycja LU macierzy A: \n";
//    QMatrix5x5 decLU = MergeLandU(L, U);
//    DispMatrix( decLU );

//    cout <<"\ndetA = ";
//    cout << CalcDeterminant(decLU) << "\n";

//    cout << "\nmacierz rozwiazan x: \n";
//    DispMatrix( x );


//    cout << "\ndekompozycja LU:\n";
//    DispMatrix(decLU);

//    cout << "\nL:\n";
//    DispMatrix(L);

//    cout << "\nU:\n";
//    DispMatrix(U);

    return 0;
}
