#pragma once

#include "monom.h"
#include <vector>
#include <algorithm>

class polynom
{
public:

	polynom(std::vector<monom> pol);	// ����������� � ����������� (������� ������������� �� �������� ��������)

	std::vector<monom> get_vect() { return vect; }	// �������� ������ ������� ��������


	friend std::ostream& operator << (std::ostream& output, polynom pol);	// ����� ��������

	friend polynom operator * (polynom pol, const double num_right);		// ��������� �������� �� ����� ������
	friend polynom operator * (const double num_left, polynom pol);			// ��������� �������� �� ����� �����

	friend polynom operator * (polynom pol, monom mon_right);				// ��������� �������� �� ����� ������
	friend polynom operator * (monom mon_left, polynom pol);				// ��������� �������� �� ����� �����

	friend polynom operator + (polynom pol1, polynom pol2);					// �������� ���������

	friend polynom operator - (polynom pol1, polynom pol2);					// ��������� ���������

	friend polynom operator * (polynom pol1, polynom pol2);					// ��������� �������� �� �������

private:

	std::vector<monom> vect;
};

