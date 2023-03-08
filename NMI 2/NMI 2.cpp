#include <iostream>


using namespace std;

int main()
{
	float strKoeficient{ 0 },
		x1{ 0 },
		x2{ 0 },
		x3{ 0 };
	float matrix[3][4] = {
		{	2,	1,	-1,	4 },
		{	1,	3,	2,	7},
		{	9,	2,	-4,	4}
	};
	float matrix1[3][4];

		//copy
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			matrix1[i][j] = matrix[i][j];

		//present
	cout << "Default Matrix: \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			cout << "  " << matrix[i][j] << " \t";
		cout << endl;
	}
	cout << "............................................\n";

	if (matrix[1][0] != 0) {
		strKoeficient = -matrix[0][0] / matrix[1][0];	//base elem/curr elem
		
		for (int elInd = 0; elInd < 4; elInd++) 
			matrix[1][elInd] = matrix[1][elInd] * strKoeficient + matrix[0][elInd];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << "  " << matrix[i][j] << " \t";
			cout << endl;
		}
		cout << "............................................\n";
	}

	if (matrix[2][0] != 0) {
		strKoeficient = - matrix1[0][0] / matrix1[2][0];

		for (int elInd = 0; elInd < 4; elInd++)
			matrix[2][elInd] = matrix[2][elInd] * strKoeficient + matrix[0][elInd];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << "  " << matrix[i][j] << " \t";
			cout << endl;
		}
		cout << "............................................\n";
	}
	
	if (matrix[2][1] != 0) {
		strKoeficient = - matrix[1][1] / matrix[2][1];

		for (int elInd = 1; elInd < 4; elInd++)
			matrix[2][elInd] = matrix[2][elInd] * strKoeficient + matrix[1][elInd];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << "  " << matrix[i][j] << " \t";
			cout << endl;
		}
		cout << "............................................\n";
	}

			//find Result
	//b3/a33
	x3 = matrix[2][3] / matrix[2][2];

	//(b2-a23x3)/a22
	x2 = (matrix[1][3] - matrix[1][2] * x3) / matrix[1][1];
	
	//(b1-a13x3-a12x2)/a11
	x1 = (matrix[0][3] - matrix[0][2] * x3 - matrix[0][1] * x2) / matrix[0][0];

	printf("Result: x1: %g,\n\tx2: %g,\n\tx3: %g.\n ", x1, x2, x3);
};
