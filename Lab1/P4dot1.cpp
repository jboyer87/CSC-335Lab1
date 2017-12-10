#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>   

#include "P4dot1.h"

namespace P4dot1 {
	int* prefixAverages1(int X[n])
	{
		int A[n];

		for (int i = 0; i <= n - 1; i++)
		{
			int a = 0;
			for (int j = 0; j <= i; j++)
			{
				a = a + X[j];
			}
			A[i] = a / (i + 1);
		}

		return A;
	}

	int* prefixAverages2(int X[n])
	{
		int A[n];
		int s = 0;

		for (int i = 0; i <= n - 1; i++)
		{
			s = s + X[i];
			A[i] = s / (i + 1);
		}

		return A;
	}

	void run() {
		std::vector<double> measurements;
		std::vector<double> measurements2;

		std::chrono::time_point<std::chrono::high_resolution_clock> finish;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;

		// Declare an array
		int X[n];

		// Fill the array
		for (int i = 0; i <= n - 1; i++)
		{
			X[i] = i;
		}

		double totalTime1 = 0.0;
		double totalTime2 = 0.0;

		std::cout << "Testing prefixAverages1" << std::endl;

		for (int i = 0; i < n; i++)
		{
			start = std::chrono::high_resolution_clock::now();

			int *p;

			p = prefixAverages1(X);

			//std::cout << "\tRun #" << i+1 << "..." << std::endl;

			finish = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double> elapsed = finish - start;
			measurements.push_back(elapsed.count());
			
			totalTime1 += measurements[i];
		}

		std::cout << "\t That took " << totalTime1 << std::endl;

		std::cout << std::endl;

		std::cout << "Testing prefixAverages2" << std::endl;

		for (int i = 0; i < n; i++)
		{
			start = std::chrono::high_resolution_clock::now();

			int *p2;

			p2 = prefixAverages2(X);

			//std::cout << "\tRun #" << i+1 << "..." << std::endl;

			finish = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double> elapsed = finish - start;
			measurements2.push_back(elapsed.count());

			totalTime2 += measurements2[i];
		}

		std::cout << "\t That took " << totalTime2 << std::endl;

	}
}