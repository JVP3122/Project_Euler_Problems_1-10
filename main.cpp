#include<iostream>
#include<math.h>
#include<vector>
#include<limits>
#include<algorithm>

int P1(int, int, int);
int P2(int);
int P3(long long int);
bool prime(int);
int P4();
bool isPalindrome(int);
long long int P5(int);
void primeFactors(int);

void main() {
	using namespace std;
//	cout << "The answer to problem 1 is: " << P1(3, 5, 1000) << endl;
//	cout << "The answer to problem 2 is: " << P2(4000000) << endl;
//	cout << "The answer to problem 3 is: " << P3(600851475143) << endl;
//	cout << "The answer to problem 4 is: " << P4() << endl;
//	cout << "The answer to problem 5 is: " << P5(20) << endl;
	primeFactors(64);
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
	else if (inputVal == 2)
		return true;
	else if (inputVal % 2 == 0)
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

// Problem 4 - Find the largest palindrome made from the product of two 3-digit numbers.
int P4() {
	int testVal, finalVal = 0;

	for (int i = 999; i > 99; i--) {
		for (int j = i; j > 99; j--) {
			testVal = i*j;
			if ((isPalindrome(testVal) == true) && (testVal > finalVal)) {
				finalVal = testVal;
			}
			if ((double)testVal / (double)finalVal < 0.75)
				break;
		}
	}
	return finalVal;
}

bool isPalindrome(int i) {
	std::vector<int> myVector1;
	std::vector<int> myVector2;
	bool palindrome = true;
	while (i) {
		myVector1.push_back(i % 10);
		myVector2.push_back(i % 10);
		i /= 10;
	}
	std::reverse(myVector1.begin(), myVector1.end());
	for (int j = 0; j < myVector1.size(); j++) {
		if (myVector1[j] != myVector2[j]) {
			palindrome = false;
		}
	}
	return palindrome;
}

long long int P5(int endVal) {
	using namespace std;
	vector<int> factorVector;
	vector<int> primeVector;
	long long int multipleVal = 1;
	for (int i = 1; i <= endVal; i++) {
		if (prime(i) == true)
			primeVector.push_back(i);
	}
	for (int i = 0; i < primeVector.size(); i++) {
		cout << primeVector[i] << " ";
	}

	return 0;
}

void primeFactors(int n) {
	while (n % 2 == 0) {
		printf("%d ", 2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			printf("%d ", i);
			n = n / i;
		}
	}
	if (n > 2)
		printf("%d ", n);
}