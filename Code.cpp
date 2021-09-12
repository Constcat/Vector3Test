#include <iostream>
#include <string>
#include "Vector3.h"
#define test 5

using namespace std;


int Vector3dot(int veca[], int vecb[]) {
	int product = 0;
	for (int i = 0; i < test; i++)
		product = product + veca[i] * vecb[i];
	return product;
}

void Vector3cross(int veca[], int vecb[], int temp[]) {
	temp[0] = veca[1] * vecb[2] - veca[2] * vecb[1];
	temp[1] = veca[0] * vecb[2] - veca[2] * vecb[0];
	temp[2] = veca[0] * vecb[1] - veca[1] * vecb[0];
}

int main() {
	int veca[] = { 4, 2, -1 };
	int vecb[] = { 5, 7, 1 };
	int temp[test];

	cout << Vector3dot(veca, vecb) << endl;
	Vector3cross(veca, vecb, temp);

	for (int i = 0; i < test; i++)
		cout << temp[i] << " ";
	return 0;
}
