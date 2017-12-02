#include "C2dot4.h"
#include <iostream>
#include <string>

namespace C2dot4 {
	Line::Line()
	{
		m_a = 0.0;
		m_b = 0.0;
	}

	Line::Line(double a, double b)
	{
		m_a = a;
		m_b = b;
	}

	Line::~Line()
	{

	}

	const double Line::intersect(Line &line)
	{
		// Check for identical slopes (a = a)
		if (this->m_a == line.m_a)
		{
			// Throw an exception, these are parallel lines
			// This also avoids a divide by zero error that could occur if we continue!
			throw ParallelException();
		}

		// Formula to find x intercept
		double xIntersect = (line.m_b - this->m_b) / (line.m_a - this->m_a);

		// If it's 0, omit the negative symbol
		if (xIntersect == 0)
		{
			return xIntersect;
		}

		return -xIntersect;
	}

	const void Line::printSlopeInterceptForm()
	{
		std::cout << "y=" << m_a << "x" << "+" << m_b;
	};


	void run()
	{
		// Define a couple of lines
		Line line1 = Line(10.5, 3.8);

		Line line2 = Line(2.0, 4.0);

		Line line3 = Line(4.0, 2.0);

		Line line4 = Line(5.0, 2.0);

		try 
		{
			// Show the lines in slope intercept form
			std::cout << "Trying line 1 (";
				line1.printSlopeInterceptForm();
			std::cout << ") and line 2:";
				line2.printSlopeInterceptForm();
			std::cout << std::endl;

			// Check to find their intersects, catch if they are parallel
			std::cout << "X Intercept at " << line1.intersect(line2) << std::endl << std::endl;
		}
		catch (ParallelException &parallelException)
		{
			std::cout << parallelException.what() << std::endl << std::endl;
		}

		try
		{
			// Show the lines in slope intercept form
			std::cout << "Trying line 2 (";
			line2.printSlopeInterceptForm();
			std::cout << ") and line 1:";
			line1.printSlopeInterceptForm();
			std::cout << std::endl;

			// Check to find their intersects, catch if they are parallel
			std::cout << "X Intercept at " << line2.intersect(line1) << std::endl << std::endl;
		}
		catch (ParallelException &parallelException)
		{
			std::cout << parallelException.what() << std::endl << std::endl;
		}

		try
		{
			// Show the lines in slope intercept form
			std::cout << "Trying line 3 (";
			line3.printSlopeInterceptForm();
			std::cout << ") and line 3:";
			line3.printSlopeInterceptForm();
			std::cout << std::endl;

			// Check to find their intersects, catch if they are parallel
			std::cout << "X Intercept at " << line3.intersect(line3) << std::endl << std::endl;
		}
		catch (ParallelException &parallelException)
		{
			std::cout << parallelException.what() << std::endl << std::endl;
		}

		try
		{
			// Show the lines in slope intercept form
			std::cout << "Trying line 3 (";
			line3.printSlopeInterceptForm();
			std::cout << ") and line 4:";
			line4.printSlopeInterceptForm();
			std::cout << std::endl;

			// Check to find their intersects, catch if they are parallel
			std::cout << "X Intercept at " << line3.intersect(line4) << std::endl << std::endl;
		}
		catch (ParallelException &parallelException)
		{
			std::cout << parallelException.what() << std::endl << std::endl;
		}
	};
}