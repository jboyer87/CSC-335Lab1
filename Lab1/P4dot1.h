#pragma once

#include <iostream>

// Implement prefixAverages1 and prefixAverages2 from Section 4.2.5, and perform an 
// experimental analysis of their running times. Visualize their running times as a 
// function of the input size with a log-log chart.

namespace P4dot1 {
	
	// Play with n to test the algorithms against different values. I tested 100, 200, 1000, 2000 
	// 100:
	// 1: .00161928
	// 2: 5.3333e-05

	// 200:
	// 1: .0132513
	// 2: .00016779
	
	// 1000:
	// 1: 1.47088
	// 2: .00360616

	// 2000:
	// 1: 11.2878
	// 2: .0145005

	const int n = 2000;

	int *prefixAverages1(int X[n]);

	int *prefixAverages2(int X[n]);

	void run();
}