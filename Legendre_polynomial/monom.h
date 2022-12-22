#pragma once

#include <iostream>

class monom
{
public:
	monom(double coef, int deg) : coef(coef), deg(deg) {}	// ����������� � �����������

	virtual ~monom() {};	// ����������

	const double get_coef() { return coef; }		// �������� ����������� ������
	void set_coef(double val) { coef = val; }		// ���������� ����������� ������
	int get_deg() { return deg; }					// �������� ������� ������
	void set_deg(int val) { deg = val; }			// ���������� ������� ������


	friend std::ostream& operator << (std::ostream& output, monom mon);		//	����� ������


	monom operator * (const double num_right);								//	��������� ����� �� ����� ������
	friend monom operator * (const double num_left ,const monom a);			//	��������� ����� �� ����� �����
	/*monom operator * (const double num, const monom a)
	{
		return monom(num * a.coef, a.deg);
	}*/

	friend monom operator * (const monom mon1, const monom mon2);			//��������� ������ �� �����


private:
	double coef = 0;
	int deg = 0;
};

