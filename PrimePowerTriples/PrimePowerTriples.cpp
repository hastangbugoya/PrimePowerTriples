// PrimePowerTriples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
*/
#include "pch.h"
#include <iostream>

constexpr auto maxvalue = 1000;
constexpr auto sievesize = 50000;
constexpr auto searchlimit = 30;

int isprime(int n, int *sieve)
{
	int i;
	for (i = 2; n % i != 0 && i <= n / 2; i++);
	if (i > n / 2)
		return 1;
	else
		return 0;
}

long getnextprime(long n, int *sieve)
{
	n++;
	while (n < 49999 && !sieve[n])
		n++;
	return n;
}

int main()
{
	int primes[sievesize];
	int i, j, k;
	long long sum;
	int ctr = 0;

	for (i = 0; i < sievesize - 1; i++)
		primes[i] = 1;

	for (i = 2; i < sievesize - 1; i++)
	{
		if (primes[i])
		{
			for (j = 2; j * i <= sievesize - 1; j++)
				primes[j*i] = 0;
		}
	}

	//7071 square root of 50,000,000
	for(i = 2; i < 10; i = getnextprime(i, primes))
		for (j = 2; j < 10; j = getnextprime(j, primes))
			for (k = 2; k < 10; k = getnextprime(k, primes))
			{
				sum = i * i + j * j * j + k * k * k * k;
				if (sum < 50)
				{
					printf("%d^2 + %d^3 + %d^4 = %d\n", i, j, k, sum);
					ctr++;
				}
					
			}
	printf("%d", ctr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
