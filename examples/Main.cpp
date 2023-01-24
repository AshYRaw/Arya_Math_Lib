#include <Arya/VectorX.h>
#include <Arya/MatrixX.h>
#include<stdio.h>
int main()
{
	hello();
	//VectorXf* testvector = createVector(true, 3);
	VectorXf* TestVector = createVector(true, 3);
	printf("\n\n");
	PrintVect(TestVector);
	printf("\n\n");

	MatrixXf* TestMatrix = createMatrix(3,3);
	PrintMat(TestMatrix);
	return 0;
}
