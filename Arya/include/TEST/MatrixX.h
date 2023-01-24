
#ifndef MATRIX_H
#define MATRIX_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include"Arya/VectorX.h"
# define ZeroMATRIX createMatrix(0,0)
#include "arya_export.h"



typedef struct {
    int Rows;// Number of Rows
    VectorXf *Mat;
} ARYA_EXPORT MatrixXf;


//Create Matrix Function:
MatrixXf* ARYA_EXPORT createMatrix(int rows, int columns);

//Destroy Matrix and Vector :
void ARYA_EXPORT destroyMat(MatrixXf *MatA);
void ARYA_EXPORT destroyVect(VectorXf *VectA);

//Print Matrix MatA:
void ARYA_EXPORT PrintMat(MatrixXf *MatA);

//Get Functions:
float* ARYA_EXPORT getMatrixElement(MatrixXf *MatA, int row, int column);
VectorXf* ARYA_EXPORT getMatrixRM(MatrixXf *MatA);
VectorXf* ARYA_EXPORT getMatrixCM(MatrixXf *MatA);
VectorXf* ARYA_EXPORT getMatrixRow(MatrixXf *MatA, int Row);
VectorXf* ARYA_EXPORT getMatrixColumn(MatrixXf *MatA, int Column);

//Load Matrix:
MatrixXf* ARYA_EXPORT loadMatrixRM(float *Data, MatrixXf* MatA);
MatrixXf* ARYA_EXPORT loadMatrixCM(float *Data, MatrixXf* MatA);
MatrixXf* ARYA_EXPORT createloadMatrixCM(float* Data, int Rows, int Columns);

MatrixXf* ARYA_EXPORT vectorToMatrixRM(VectorXf* VectA, int Rows, int Columns);
MatrixXf* ARYA_EXPORT vectorToMatrixCM(VectorXf* VectA, int Rows, int Columns);

MatrixXf* ARYA_EXPORT createMatTranspose(MatrixXf *MatA);

MatrixXf* ARYA_EXPORT createMatMultiplication(MatrixXf* MatA, MatrixXf* MatB);
MatrixXf* ARYA_EXPORT MatAmplify(MatrixXf* MatA, float Val);

//Load Identity 2 versions:
MatrixXf* ARYA_EXPORT LoadIdentity(int n);
//Matrix* LoadIdentity(Matrix *MatA );

MatrixXf* ARYA_EXPORT createMatSum(MatrixXf* MatA, MatrixXf* MatB);
MatrixXf* ARYA_EXPORT createMatDiff(MatrixXf* MatA, MatrixXf* MatB);


//Inverse Functions :
void ARYA_EXPORT getCofactor(MatrixXf *MatA, MatrixXf *temp, int p, int q, int n);
float ARYA_EXPORT Determinant(MatrixXf *MatA, int n);
void ARYA_EXPORT adjoint(MatrixXf* MatA, MatrixXf* Adj);
MatrixXf* ARYA_EXPORT createInverse(MatrixXf *MatA);

// Vector x Vector
MatrixXf* ARYA_EXPORT createVectMultiplication(VectorXf* VectA, VectorXf* VectB);

VectorXf* ARYA_EXPORT maxCorrelationVector(MatrixXf* MatA, VectorXf* VectB);
int ARYA_EXPORT MaxCorrIdx(MatrixXf* MatA, VectorXf* VectB);

MatrixXf* ARYA_EXPORT createProjectionMatrix(MatrixXf* Measurement);
MatrixXf* ARYA_EXPORT createProjection(MatrixXf* Measurement, MatrixXf* Output);
MatrixXf* ARYA_EXPORT createResidual(MatrixXf* Measurement, MatrixXf* Output);

#endif

