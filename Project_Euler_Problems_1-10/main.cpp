#include<iostream>
//#include<vector>

int P1(int, int, int);

void main() {
	using namespace std;
	cout << P1(3, 5, 1000) << endl;
}


// Problem 1 - Find the sum of all multiples of 3 or 5 below 1000
int P1(int valOne, int valTwo, int maxVal) {
	int sumVal = 0, iterCount = 0;
	do {
		if ((iterCount % valOne == 0) || (iterCount % valTwo == 0)){
			sumVal = sumVal + iterCount;
		}
		iterCount++;
	} while (iterCount < maxVal);
	return sumVal;
}