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


MatrixXf* createMatrix(int rows, int columns) {
    MatrixXf* MatA = (MatrixXf*)malloc(sizeof(MatrixXf));
    MatA->Rows = rows;

    MatA->Mat = (VectorXf*)malloc(rows*columns*sizeof(VectorXf*));
    for(int i=0;i<MatA->Rows;i++){
        //MatA->Mat[] = (Vector*)malloc((rows-i)*sizeof(Vector*));
        MatA->Mat[i] = createVectorX(true,columns);
    }
    // set values to 0.
    for(int i=0; i<MatA->Rows; i++){
        for(int j=0; j<MatA->Mat[i].Capacity; j++){
            MatA->Mat[i].Vect[j] = ZERO;
        }
    }
    return MatA;
}

float* getMatrixElement(MatrixXf *MatA, int row, int column){
    if(MatA->Rows>=row&&MatA->Mat->Capacity>=column){
        printf("%f",(MatA->Mat[row].Vect[column]));
        return(&(MatA->Mat[row].Vect[column]));
    }
    else {
        printf("Index out of bounds");
        return (&(MatA->Mat[MatA->Rows].Vect[MatA->Mat->Capacity]));
    }
}

VectorXf* getMatrixRM(MatrixXf *MatA){
    if(MatA->Rows> 0 && MatA->Mat->Capacity > 0){
        VectorXf *VectA = createVector(true,(MatA->Rows)*(MatA->Mat->Capacity));
        int idx =0;
        for(int i=0; i<MatA->Rows;i++){
            for(int j=0; j<MatA->Mat[i].Capacity; j++){
                VectA->Vect[idx++]= MatA->Mat[i].Vect[j];
            }
        }
        return (VectA);
    }
    else{
        printf("Matrix Does not Exist");
        return ZeroVector;
    }
}

VectorXf* getMatrixCM(MatrixXf *MatA){
    if(MatA->Rows> 0 && MatA->Mat->Capacity > 0){
        VectorXf *VectA = createVector(true,(MatA->Rows)*(MatA->Mat->Capacity));
        int idx =0;
        for(int j=0; j<MatA->Mat[j].Capacity; j++){
           for(int i=0; i<MatA->Rows;i++) {
                VectA->Vect[idx++]= MatA->Mat[i].Vect[j];
            }
        }
        return (VectA);
    }
    else{
        // return vector NULL : define this .3
        printf("Matrix Does not Exist");
        return ZeroVector;
    }
}

VectorXf* getMatrixRow(MatrixXf *MatA, int Row){
    if(MatA->Rows> 0 && MatA->Mat->Capacity > 0){

        VectorXf *VectA = createVector(true,(MatA->Mat[Row].Capacity));
        for(int i=0; i<MatA->Mat[Row].Capacity; i++){
            VectA->Vect[i]= MatA->Mat[Row].Vect[i];
        }
        return (VectA);
    }
    else{
        // return vector NULL : define this
        printf("Matrix Does not Exist");
        return ZeroVector;
    }
}

VectorXf* getMatrixColumn(MatrixXf *MatA, int Column){
    if(MatA->Rows> 0 && MatA->Mat->Capacity > 0){
        //printf("getTest");
        VectorXf *VectA = createVector(false,MatA->Rows);
        for(int i=0; i<MatA->Rows; i++){
            VectA->Vect[i]= MatA->Mat[i].Vect[Column];
            //printf("%f",VectA->Vect[i]);
        }
        return (VectA);
    }
    else{
        printf("Matrix Does not Exist");
        return ZeroVector;
    }
}

/*
Matrix* getMatrixColumnMat(Matrix *MatA, int Column){
    if(MatA->Rows> 0 && MatA->Mat->Capacity > 0){
        printf("getTestXYZ");
        Matrix *MatX = createMatrix(MatA->Rows,1);
        for(int i=0; i<MatA->Rows; i++){
            MatX->Mat[i].Vect[0]= MatA->Mat[i].Vect[Column];
        }
        return (MatX);
    }
    else{
        printf("Matrix Does not Exist");
        return ZeroMATRIX;
    }
}
*/

MatrixXf* loadMatrixRM(float *Data, MatrixXf* MatA){
    for(int i=0; i<MatA->Rows; i++){
        for(int j=0; j<MatA->Mat[i].Capacity; j++){
            MatA->Mat[i].Vect[j] = *Data++;
        }
    }
    return MatA;
}

MatrixXf* loadMatrixCM(float* Data, MatrixXf* MatA){

    for(int j=0; j<MatA->Mat[j].Capacity; j++){
        for(int i=0; i<MatA->Rows; i++){
            MatA->Mat[i].Vect[j] = *Data++;
        }
    }
    return MatA;
}

MatrixXf* createloadMatrixCM(float Data[], int Rows, int Columns){

    MatrixXf* MatA = createMatrix(Rows,Columns);
    for(int j=0; j<MatA->Mat[j].Capacity; j++){
        for(int i=0; i<MatA->Rows; i++){
            MatA->Mat[i].Vect[j] = Data[i+j]++;
        }
    }
    return MatA;
}

MatrixXf* vectorToMatrixRM(VectorXf* VectA, int Rows, int Columns){

    MatrixXf* MatA = createMatrix(Rows, Columns);
    float* Data = getVector(VectA);
    loadMatrixRM(Data,MatA) ;
    return MatA;
}

MatrixXf* vectorToMatrixCM(VectorXf* VectA, int Rows, int Columns){

    MatrixXf* MatA = createMatrix(Rows, Columns);
    float* Data = getVector(VectA);
    loadMatrixCM(Data,MatA);
    return MatA;
}


//set element Matrix : matrix, each val and index.
// Get Element : Matrix, index -> return value.
//Get matrix in a single array. - row major
// Get matrix row, column.
//Load matrix : array, row major order

// typedef float and double
// excel files use : double.

void PrintMat(MatrixXf* MatA){

    for(int i=0; i<MatA->Rows; i++){
        for(int j=0; j<MatA->Mat[i].Capacity; j++){
            printf("%f ", MatA->Mat[i].Vect[j]);
        }
        printf("\n");
    }
}

void destroyVect(VectorXf *VectA){
    //free(VectA->Vect);
    //memset(VectA,0,sizeof(Vector));
    float* currentVal;
    for(int i=0; i< VectA->Capacity; i++){
         currentVal =  &(VectA->Vect[i]);
        free(currentVal);
    }
    //free(VectA->Vect);
    //int* C = &(VectA->Capacity);
    //free(C);
    //free(VectA->Row);
}

void destroyMat(MatrixXf* MatA){
    //free(MatA->Mat);
    //Matrix* CurrentMat = *MatA;
    //free(CurrentMat->Mat->Vect);
    for(int i=0; i< MatA->Rows; i++){
        VectorXf* currentVect =  &(MatA->Mat[i]);
        destroyVect(currentVect);
    }
    //free(MatA->Mat->Vect);

    //memset(MatA,0,sizeof(Matrix));
    int* R = &(MatA->Rows);
    free(R);
}


/*MatrixXf* LoadIdentity(MatrixXf *MatA ){
    if(MatA->Rows == MatA->Mat->Capacity){
        int n = MatA->Rows;
        struct Matrix* Identity = createMatrix(n,n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    Identity->Mat[i].Vect[j]= 1;
                }
                else{
                    Identity->Mat[i].Vect[j]= 0;
                }
            }
        }
        return Identity;
    }
    else {
        printf("Dimension Error");
        return MatA;
    }
}*/

MatrixXf* LoadIdentity(int n){
    MatrixXf* Identity = createMatrix(n,n);
    Identity->Rows = n;
    Identity->Mat->Capacity = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                Identity->Mat[i].Vect[j]= 1;
            }
            else{
                Identity->Mat[i].Vect[j]= 0;
            }
        }
    }
    return Identity;
}

MatrixXf* createMatSum(MatrixXf* MatA, MatrixXf* MatB){
    if(MatA->Rows == MatB->Rows && MatA->Mat->Capacity == MatB->Mat->Capacity){
        MatrixXf* MatSum = createMatrix(MatA->Rows, MatA->Mat->Capacity);
        for (int i = 0; i < MatA->Rows; i++) {
			for (int j = 0; j < MatA->Mat->Capacity; j++) {
				MatSum->Mat[i].Vect[j] = MatA->Mat[i].Vect[j] + MatB->Mat[i].Vect[j];
			}
		}
		return MatSum;
    }
    else {
        printf("Matrix Dimension Error\n");
        return MatA;
    }
}

MatrixXf* createMatDiff(MatrixXf* MatA, MatrixXf* MatB){
    if(MatA->Rows == MatB->Rows && MatA->Mat->Capacity == MatB->Mat->Capacity){
        MatrixXf* MatDiff = createMatrix(MatA->Rows, MatA->Mat->Capacity);
        for (int i = 0; i < MatA->Rows; i++) {
			for (int j = 0; j < MatA->Mat->Capacity; j++) {
				MatDiff->Mat[i].Vect[j] = MatA->Mat[i].Vect[j] - MatB->Mat[i].Vect[j];
			}
		}
		return MatDiff;
    }
    else {
        printf("Matrix Dimension Error\n");
        return MatA;
    }
}


MatrixXf* createVectMultiplication(VectorXf* VectA, VectorXf* VectB){
    if(VectA->Capacity == VectB->Capacity && VectA->Row == true && VectB->Row == false){
        MatrixXf* VectProduct = createMatrix(1,1);//singleton
        for (int i = 0; i < VectA->Capacity; i++) {
            VectProduct->Mat->Vect[0] += VectA->Vect[i]*VectB->Vect[i];
		}
		return VectProduct;
    }
    else if(VectA->Row == false && VectB->Row == true) {
        MatrixXf* VectProduct = createMatrix(VectA->Capacity,VectB->Capacity);
        for(int i=0; i< VectA->Capacity; i++){
            for(int j=0; j< VectB->Capacity; j++){
                VectProduct->Mat[i].Vect[j] = VectA->Vect[i] * VectB->Vect[j];
            }
        }
        return VectProduct;
    }
    else{
        printf("Matrix Dimension Error\n");
        return ZeroMATRIX;
    }
}



#endif

