#include<iostream>
#include<math.h>
#include<vector>
#include<limits>

int P1(int, int, int);
int P2(int);
int P3(long long int);
bool prime(int);

void main() {
	using namespace std;
	cout << "The answer to problem 1 is: " << P1(3, 5, 1000) << endl;
	cout << "The answer to problem 2 is: " << P2(4000000) << endl;
	cout << "The answer to problem 3 is: " << P3(600851475143) << endl;
}

// Problem 1 - Find the sum of all multiples of 3 or 5 below 1000
int P1(int valOne, int valTwo, int maxVal) {
	int sumVal = 0, iterCount = 0;
	do {
		if ((iterCount % valOne == 0) || (iterCount % valTwo == 0)) {
			sumVal = sumVal + iterCount;
		}
		iterCount++;
	} while (iterCount < maxVal);
	return sumVal;
}

// Problem 2 - By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
int P2(int maxVal) {
	int fibFirst = 1, fibSecond = 1, fibTemp = 0, sumVal = 0;
	while (fibSecond < maxVal) {
		if (fibSecond % 2 == 0) {
			sumVal = sumVal + fibSecond;
		}
		fibTemp = fibFirst + fibSecond;
		fibFirst = fibSecond;
		fibSecond = fibTemp;
	}
	return sumVal;
}

// Problem 3 - What is the largest prime factor of the number 600851475143 ?
int P3(long long int maxVal) {
	int tempVal = 1, iterCount = 0;
	std::vector<int> resultsVector;
	while (tempVal < sqrt(maxVal)) {
		if ((maxVal % tempVal == 0) && prime(tempVal) == true)
			resultsVector.push_back (tempVal);
		tempVal++;
	}
	return resultsVector[resultsVector.size()-1];

/*	This section was used to make sure that all prime factors were being properly calculated*/
/*	for (unsigned int i = 0; i < resultsVector.size(); i++) {
		if (i < resultsVector.size() - 1) {
			std::cout << resultsVector[i] << ", ";
		}
		else {
			std::cout << resultsVector[i] << std::endl;
		}
	} */
}

// Function to determine if a number is a prime.  I don't yet know how to put this into its own source file and create a separate header file so it is left here.
bool prime(int inputVal) {
	using namespace std;
	if (inputVal <= 1)
		return false;
	else if ((inputVal == 2) || (inputVal % 2 == 0))
		return false;
	else {
		bool primeVal = true;
		int divisor = 3;
		while (divisor < inputVal) {
			if (inputVal % divisor == 0) {
				primeVal = false;
				break;
			}
			divisor += 2;
//			cout << divisor << "\t" << primeVal << "\t" << inputVal << endl;
		}
		return primeVal;
	}
}