#include <iostream>
using namespace std;

class Matrix
{
	int** matrixInClass;
public:
	void setMatrix(int rowAmount, int colAmount);
	void changeRowAndColumn(int rowAmount, int colAmount);
};
//==============================================================
void Matrix::setMatrix(int rowAmount, int colAmount) // ���������� ������� �������
{
	matrixInClass = new int* [rowAmount]; // �������� ������ ��� ������� 
	for (int i = 0; i < rowAmount; i++)
	{
		matrixInClass[i] = new int[colAmount];
	}

	for (int i = 0; i < rowAmount; i++) // ���������� �������� � ������
	{
		cout << " | ";
		for (int j = 0; j < colAmount; j++)
		{
			matrixInClass[i][j] = i + j;
			cout << matrixInClass[i][j] << " ";
		}
		cout << " | " << endl;
	}
}
//==============================================================
void Matrix::changeRowAndColumn(int rowAmount, int colAmount)
{
	int** tempMatrix = new int* [colAmount]; // �������� ������ ��� ��������� ������� 
	for (int i = 0; i < colAmount; i++)
	{
		tempMatrix[i] = new int[rowAmount];
	}

	for (int i = 0; i < colAmount; i++) // �������� ������� � ������,  � ������ � �������
	{
		for (int j = 0; j < rowAmount; j++)
		{
			tempMatrix[i][j] = matrixInClass[j][i];
		}
		cout << endl;
	}

	for (int i = 0; i < rowAmount; i++) // ����������� ������ ����� ���������� ����� 
	{
		delete[] matrixInClass[i];
	}
	delete[] matrixInClass;

	matrixInClass = new int* [colAmount]; // �������� ����� ������
	for (int i = 0; i < colAmount; i++)
	{
		matrixInClass[i] = new int[rowAmount];
	}

	for (int i = 0; i < colAmount; i++) // �������� �� ��������� �������
	{
		cout << "|";
		for (int j = 0; j < rowAmount; j++)
		{
			matrixInClass[i][j] = tempMatrix[i][j];
			cout << matrixInClass[i][j] << "  ";
		}
		cout << "|" << endl;
	}

	for (int i = 0; i < colAmount; i++) // ����������� ������ ��������� �������
	{
		delete[] tempMatrix[i];
	}
	delete[] tempMatrix;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int rowAmount;
	int colAmount;
	cout << "������� ���������� ����� ���������� �������: ";
	cin >> rowAmount;
	cout << "������� ���������� �������� ���������� �������: ";
	cin >> colAmount;

	Matrix Object;

	Object.setMatrix(rowAmount, colAmount);

	cout << "\n������ �������� ����� �� �������� ��������: ";
	Object.changeRowAndColumn(rowAmount, colAmount);

	return 0;
}