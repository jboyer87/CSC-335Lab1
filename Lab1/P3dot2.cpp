#include "P3dot2.h"
#include <iostream>
#include <iomanip>

namespace P3dot2 {

	Matrix::Matrix()
	{
		m_columns = 3;
		m_rows = 3;

		// Initialize the data
		this->initializeMatrixData();
	}

	Matrix::Matrix(int columns, int rows)
	{
		m_columns = columns;
		m_rows = rows;

		this->initializeMatrixData();
	}

	Matrix::~Matrix()
	{
		if (m_data != nullptr)
		{
			// Delete each sub array
			for (int i = 0; i < m_rows; ++i) 
			{
				delete[] m_data[i];
			}
			
			// Then delete the main data object pointer 
			delete[] m_data;
		}
	}

	void Matrix::initializeMatrixData()
	{
		m_data = new int*[m_rows];

		for (int i = 0; i < m_rows; i++)
		{
			m_data[i] = new int[m_columns];
		}

		for (int rows = 0; rows < m_rows; rows++)
		{
			for (int columns = 0; columns < m_columns; columns++)
			{
				m_data[rows][columns] = 0;
			}
		}
	}

	void Matrix::load()
	{
		std::cout << "Enter the matrix values one by one: ";

		for (int rows = 0; rows < m_rows; rows++)
		{
			for (int columns = 0; columns < m_columns; columns++)
			{
				std::cin >> m_data[rows][columns];
			}
		}
	}

	void Matrix::display()
	{
		for (int i = 0; i <= m_rows - 1; i++)
		{
			for (int j = 0; j <= m_columns - 1; j++)
			{
				if (j == 0)
				{
					std::cout << "[";
				}

				std::cout << std::setw(2) << this->m_data[i][j];

				if (j == m_columns - 1)
				{
					std::cout << "]" << std::endl;
				}
				else
				{
					std::cout << ", ";
				}
			}
		}
	}

	Matrix Matrix::operator+(const Matrix &inputMatrix)
	{
		// Make sure they are the same size and throw an exception if not
		if (m_rows != inputMatrix.m_rows || m_columns != inputMatrix.m_columns)
		{
			throw std::invalid_argument("The number of rows and columns between matrix objects must be equal.");
		}

		Matrix matrixToReturn(this->m_rows, this->m_columns);

		for (int rows = 0; rows < m_rows; rows++)
		{
			for (int columns = 0; columns < m_columns; columns++)
			{
				// Add the two integers and stuff it into the matrix at the correct position
				matrixToReturn.m_data[rows][columns] = (this->m_data[rows][columns] + inputMatrix.m_data[rows][columns]);
			}
		}

		return matrixToReturn;
	}

	Matrix Matrix::operator*(const Matrix &inputMatrix)
	{
		// Make sure they are able to be multiplied and throw an exception if not
		if (m_columns != inputMatrix.m_rows)
		{
			throw std::invalid_argument("The number of columns in the first matrix must match the number of rows in the second matrix.");
		}

		Matrix matrixToReturn(inputMatrix.m_columns, this->m_rows);

		for (int rows = 0; rows < this->m_rows; rows++)
		{
			for (int columns = 0; columns < inputMatrix.m_columns; columns++)
			{
				int sum = 0;

				for (int k = 0; k < inputMatrix.m_rows; k++)
				{
					int value1 = this->m_data[rows][k];
					int value2 = inputMatrix.m_data[k][columns];

					sum += value1 * value2;
				}

				matrixToReturn.m_data[rows][columns] = sum;
			}
		}

		return matrixToReturn;
	}

	void run() 
	{
		Matrix test1 = Matrix();
		Matrix test2 = Matrix(3, 3);

		Matrix test3 = Matrix(4, 5);

		test1.load();

		test2.load();

		Matrix sum = test1 + test2;

		sum.display();
		
		std::cout << std::endl;
		
		Matrix product = test1 * test2;

		product.display();
		
		std::cout << std::endl;
	}
}