#pragma once
#include <iostream>
#include <exception>
#include <string>

// Instructions for C2dot4:
// Design a class Line that implements a line, which is represented by the formula 
// y = ax + b. Your class should store a and b as double member variables. Write a member
// function intersect(l) that returns the x coordinate at which this line intersects line
// l. If the two lines are parallel, then your function should throw an exception 
// Parallel. Write a C++ program that creates a number of Line objects and tests each 
// pair for intersection. Your program should print an appropriate error message for 
// parallel lines.

namespace C2dot4 {
	class Line {
	public:
		Line();
		Line(double a, double b);
		~Line();
		const double intersect(Line &line) /*throw(Parallel)*/;
		const void Line::printSlopeInterceptForm();

	private:
		double m_a;
		double m_b;
	};

	class ParallelException : public std::runtime_error
	{
	public:
		ParallelException::ParallelException() : std::runtime_error("These two lines are parallel!")
		{
		
		}
	};

	void run();
}