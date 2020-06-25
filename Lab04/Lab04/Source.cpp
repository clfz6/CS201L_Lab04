#include<iostream>
#include<vector>

using namespace std;

int num_rows, num_columns; 
vector<vector<int>> matrix1, matrix2, c;

void createMatrix(vector<vector<int>>& matrix)
{
	cout << "Enter the number of rows in this matrix >>> ";
	cin >> num_rows;
	cout << endl << endl << "Enter the number of columns in this matrix >>> ";
	cin >> num_columns;

	matrix.resize(num_rows);
	for (int i = 0; i < num_rows; i++)
	{
		matrix.at(i).resize(num_columns);

	}
	cout << endl << endl << "Please enter the values in this matrix, you can enter each row at one, each cell or all of them separated by spaces." << endl;

	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void displayMatrix(vector<vector<int>>& matrix, int g)
{
	cout << endl << endl << "You entered the grid g" << g << " as:" << endl;

	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void addMatrices(vector<vector<int>> a, vector<vector<int>> b)
{
	if (a.size() == b.size() && a[0].size() == b[0].size())
	{
		c.resize(num_rows);
		for (int i = 0; i < num_rows; i++)
		{
			c.at(i).resize(num_columns);
		}

		cout << "g1 + g2 is:" << endl;
		for (int i = 0; i < num_rows; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Cannot add 2 grids of this size together, the # of rows and columsn in each must be the same" << endl;
	}
}

void multiplyMatrices(vector<vector<int>> a, vector<vector<int>> b)
{
	if (a[0].size() == b.size())
	{
		c.resize(a.size());
		for (int i = 0; i < a.size(); i++)
		{
			c.at(i).resize(b[0].size());
		}

		cout << "g1 * g2 is:" << endl;
		for (int i = 0; i < num_rows; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				c[i][j] = a[i][j] * b[j][i];
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Cannot add 2 grids of this size together, the # of rows and columsn in each must be the same" << endl;
	}
}

int main()
{
	char input, upperInput;

	do
	{
		createMatrix(matrix1);
		displayMatrix(matrix1, 1);
		createMatrix(matrix2);
		displayMatrix(matrix2, 2);
		addMatrices(matrix1, matrix2);
		multiplyMatrices(matrix1, matrix2);
		cout << "Press Q to quit, any other key to do another grid" << endl;
		cin >> input;
		upperInput = toupper(input);

	} while (upperInput != 'Q');
	
	return 0;
}