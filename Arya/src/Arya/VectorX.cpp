#include "Arya/VectorX.h"
#include "Arya/MatrixX.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <stdbool.h>

VectorXf* createVector(bool Row, int Capacity){
    VectorXf* VectA = (VectorXf*)malloc(sizeof(VectorXf*));
    VectA->Capacity = Capacity;
    VectA->Row = Row;
    VectA->Vect = (float*)malloc(Capacity*sizeof(float));
    for(int i=0; i< Capacity; i++){
        VectA->Vect[i] = ZERO;
    }
    return VectA;
}

VectorXf createVectorX(bool Row, int Capacity){
    VectorXf* VectA = (VectorXf*)malloc(sizeof(VectorXf));
    VectA->Capacity = Capacity;
    VectA->Row = Row;
    VectA->Vect = (float*)malloc(Capacity*sizeof(float));
    for(int i=0; i< Capacity; i++){
        VectA->Vect[i] = ZERO;
    }
    return *VectA;
}

void PrintVect(VectorXf *VectA){
    if(VectA->Capacity > 0){
        if(VectA->Row==true){
            for(int i=0; i<VectA->Capacity; i++){
                printf("%f ", VectA->Vect[i]);
            }
        }
        else{
            for(int i=0; i<VectA->Capacity; i++){
                printf("%f\n", VectA->Vect[i]);
            }
        }
    }
    else{
        printf("%f",ZERO);
    }
}

VectorXf* createVectTranspose(VectorXf* VectA){
    if(VectA->Capacity > 0){
        VectorXf* VectTranspose = createVector(!VectA->Row, VectA->Capacity);
        for(int i=0; i<VectA->Capacity; i++){
            VectTranspose->Vect[i]=VectA->Vect[i];
        }
        return VectTranspose;
    }
    else{
        return ZeroVector;
    }
}


float* getVector(VectorXf* VectA){
    if(VectA->Capacity > 0){
        float* Data = (float*)malloc(sizeof(float*));
        for(int i=0; i< VectA->Capacity; i++){
            Data[i]=VectA->Vect[i];
        }
        return Data;
    }
    else{
        exit(EXIT_FAILURE);
    }
}


float* getVectorElement(VectorXf *VectA, int index){
    if(VectA->Capacity > 0){
        printf("%f", VectA->Vect[index]) ;
        return(&VectA->Vect[index]);
    }
    else{
        exit(EXIT_FAILURE);
    }
}


VectorXf *loadVector(float* Data, VectorXf* VectA){
    if(VectA->Capacity > 0){
        for(int i=0; i< VectA->Capacity; i++){
            VectA->Vect[i]=Data[i];
        }
        return VectA;
    }
    else{
        return ZeroVector;
    }
}
void hello()
{
	std::cout << "Hello World!" << std::endl;
}




