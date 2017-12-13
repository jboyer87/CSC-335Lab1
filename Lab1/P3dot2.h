#pragma once

// Write a C++ program for a matrix class that can add and multiply arbitrary 
// two-dimensional arrays of integers. Do this by overloading the addition ("+") and 
// multiplication("*") operators.

namespace P3dot2 {
	class Matrix {
	public:
		Matrix();
		Matrix(int columns, int rows);
		virtual ~Matrix();
		Matrix(const Matrix &right);
		Matrix operator+(const Matrix &matrix);
		Matrix operator*(const Matrix &matrix);

		void load();

		void const display();

	private:
		int** m_data;
		int m_columns = 0;
		int m_rows = 0;
		void initializeMatrixData();
	};

	void run();
}