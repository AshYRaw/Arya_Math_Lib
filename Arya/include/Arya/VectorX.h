#ifndef VECTORX_H
#define VECTORX_H
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#define ZERO 0.0000
#define ZeroVector createVector(true,0)
#define ZeroVectorX createVectorX(true,0)

#include "arya_export.h"
void ARYA_EXPORT hello();

typedef struct{
    bool Row;
    int Capacity;
    float *Vect;
}ARYA_EXPORT VectorXf;
float* ZeroARRAY;


VectorXf* ARYA_EXPORT createVector(bool Row, int Capacity);
VectorXf ARYA_EXPORT createVectorX(bool Row, int Capacity);
void ARYA_EXPORT PrintVect(VectorXf *VectA);

VectorXf* ARYA_EXPORT createVectTranspose(VectorXf* VectA);

float* ARYA_EXPORT getVector(VectorXf* VectA);
float* ARYA_EXPORT getVectorElement(VectorXf *VectA, int index);
VectorXf* ARYA_EXPORT loadVector(float* Data, VectorXf* VectA);

float ARYA_EXPORT distance(VectorXf* VectA, VectorXf* VectB);
float ARYA_EXPORT Norm(VectorXf* VectA, float N);
float ARYA_EXPORT Correlation(VectorXf* VectA, VectorXf* VectB);


VectorXf* createVectSum(VectorXf* VectA, VectorXf* VectB){
    if(VectA->Capacity == VectB->Capacity && VectA->Row == VectB->Row){
        VectorXf* VectSum = createVector(VectA->Row, VectA->Capacity);
        for (int i = 0; i < VectA->Capacity; i++) {
            VectSum->Vect[i] = VectA->Vect[i] + VectB->Vect[i];
		}
		return VectSum;
    }
    else {
        printf("Vector Dimension Mismatch\n");
        return VectA;
    }
}

VectorXf* createVectDiff(VectorXf* VectA, VectorXf* VectB){
    if(VectA->Capacity == VectB->Capacity && VectA->Row == VectB->Row){
        VectorXf* VectDiff = createVector(VectA->Row, VectA->Capacity);
        for (int i = 0; i < VectA->Capacity; i++) {
            VectDiff->Vect[i] = VectA->Vect[i] - VectB->Vect[i];
		}
		return VectDiff;
    }
    else {
        printf("Vector Dimension Mismatch\n");
        return VectA;
    }
}


float DotProduct(VectorXf* VectA, VectorXf* VectB){
    if(VectA->Capacity == VectB->Capacity){

        float Product=0;
        for(int i=0; i<VectA->Capacity; i++){
            Product += VectA->Vect[i] * VectB->Vect[i];
        }
        return Product;
    }
    else{
       return ZERO;
    }
}


VectorXf* VectAmplify(VectorXf* VectA, float Val){
        for (int i = 0; i < VectA->Capacity; i++) {
			    VectA->Vect[i] = Val*(VectA->Vect[i]);
		}
		return VectA;
}

VectorXf* createVectNormalized(VectorXf* VectA){
    if(VectA->Capacity > 0){
        VectorXf* VectNormalized = createVector(VectA->Row, VectA->Capacity);
        float VectLength = 0;
        for(int i=0; i<VectA->Capacity; i++){
            VectLength+=(VectA->Vect[i] * VectA->Vect[i]);
        }
        VectLength = sqrt(VectLength);
        //printf("\nVectLen:%f\n",VectLength);
        for(int i=0; i<VectA->Capacity; i++){
            VectNormalized->Vect[i] = (VectA->Vect[i])/VectLength;
        }
        return VectNormalized;
    }
    else{
        return ZeroVector;
    }
}


#endif
