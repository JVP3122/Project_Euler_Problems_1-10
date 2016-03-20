#include<iostream>
#include<math.h>
#include<cmath>
#include<vector>
#include<limits>
#include<algorithm>
#include<time.h>

int P1(int, int, int);
int P2(int);
int P3(long long int);
bool prime(int);
int P4();
bool isPalindrome(int);
long long int P5(int);
void primeFactors(int, std::vector<int>& factorVector);
long long int P6(int);
int P7();

void main() {
	using namespace std;
	cout << "The answer to problem 1 is: " << P1(3, 5, 1000) << endl;
	cout << "The answer to problem 2 is: " << P2(4000000) << endl;
	cout << "The answer to problem 3 is: " << P3(600851475143) << endl;
	cout << "The answer to problem 4 is: " << P4() << endl;
	cout << "The answer to problem 5 is: " << P5(20) << endl;
	cout << "The answer to problem 6 is: " << P6(100) << endl;
	cout << "The answer to problem 7 is: " << P7() << endl;
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

// This function simply checks if integer i is a palindrome as defined in problem 4.
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

// Problem 5 - What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
long long int P5(int endVal) {
	/* The main goal of this exercise is to determine the minimum prime factorization that would account
	for all integers up through and including endVal.  If we're completing this problem for
	endVal = 10, then we would need 3 twos, 2 threes, 1 five, and 1 seven.  All integers up through and
	including 10 can be made up of combinations of at most all of these numbers.  For example, 6 requires
	1 two and 1 three, while 8 requires 3 twos but no other values.*/
	using namespace std;
	vector<int> primeVector;
	long long int multipleVal = 1;
	// Creates vector of all prime numbers up to the input integer.
	for (int i = 1; i <= endVal; i++) {
		if (prime(i) == true)
			primeVector.push_back(i);
	}
	
	vector<int> countVector(primeVector.size()); // Creates vector to keep track of max count of each prime factor

	for (int i = 1; i <= endVal; i++) {
		vector<int> factorVector; // Create blank vector to return prime factorization of integer i
		primeFactors(i, factorVector); // Populate prime factorization vector
		
		// For integer i above, cycle through each prime number up to and including i
		// and check how many times it shows up in the prime factorization (factorVector)
		for (int j = 0; j < primeVector.size(); j++) {
			int iter = 0;
			for (int k = 0; k < factorVector.size(); k++) {
				if (factorVector[k] == primeVector[j]) {
					iter++;
				}
			}
			// Only replace the value in the count vector if the new count is higher than the previous one
			// For example, countVector[0] (corresponding to 2) would be 1 until i=4 in the main loop, when it would
			// become 2, until i=8 in the main loop in which case it would become 3, etc.
			if (countVector[j] < iter)
				countVector[j] = iter;
		}
	}
	for (int i = 0; i < countVector.size(); i++) {
		// Uncomment the line below to get a visual of how the primeVector and countVector vectors work.
		// cout << "The count for prime number " << primeVector[i] << " is " << countVector[i] << endl;
		multipleVal*=pow((int)primeVector[i],(int)countVector[i]); // This line simply raises all prime values to their respective powers.
	}
	return multipleVal;
}

// This function returns the entire prime factorization of integer n.  A blank vector needs to be passed which will be popluated with factors.
void primeFactors(int n, std::vector<int>& factorVector) {
	//std::vector<int> factorVector;
	while (n % 2 == 0) {
		factorVector.push_back(2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			factorVector.push_back(i);
			n = n / i;
		}
	}
	if (n > 2)
		factorVector.push_back(n);
}

// Problem 6 - Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
long long int P6(int endVal) {
	long long int indSquare = 0;
	long long int sumSquare = 0;

	for (int i = 0; i <= endVal; i++) {
		indSquare += pow(i, 2);
		sumSquare += i;
	}
	sumSquare = pow(sumSquare, 2);
	return sumSquare - indSquare;
}

// Problem 7 - What is the 10 001st prime number?
int P7() {
	using namespace std;
	int n = 120000, sum_of_elems = 0, p = 2, primeVal = 10001, returnVal;
	vector<bool> vectorA(n-1);
	vector<int> numVector(n-1);
	for (int i = 0; i < n - 1; i++) {
		vectorA[i] = true;
		numVector[i] = i + 2;
	}
	while (pow(p, 2) <= n) {
		int j = pow(p, 2);
		while (j <= n) {
			vectorA[j-2] = false;
			j += p;
		}
		p += 1;
	}

	for (int i = 0; i < vectorA.size(); i++) {
		sum_of_elems += vectorA[i];
		if (sum_of_elems == primeVal) {
			returnVal = numVector[i];
			break;
		}
	}
	return returnVal;
}