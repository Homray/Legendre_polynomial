#include "monom.h"
#include<iomanip>	//��� std::setprecision()


std::ostream& operator << (std::ostream& output, monom mon)
{
	output << std::setprecision(5);//�� ������ �������� double �� 3 ������ ����� �������

	if (!mon.get_coef()) output << 0;	//������� �����������	

	else {								//��������� �����������
		if (!mon.get_deg()) {				//������� ��������
			if (mon.get_coef() > 0) output << mon.get_coef();	//������������� ��������� ����
			else output << "- " << abs(mon.get_coef());			//������������� ��������� ����
		}

		else {								//��������� �������
			if (mon.get_coef() == 1) output << "x";			//����������� = 1	

			else if (mon.get_coef() == -1) output << "- x";	//����������� = -1	

			else {											//��������� ������������
				if (mon.get_coef() < 0) output << "- " << abs(mon.get_coef()) << "*x";	//�������������

				else output << mon.get_coef() << "*x";									//�������������
			}
			if (mon.get_deg() != 1) output << "^" << mon.get_deg();	//������� �������, ���� ��� �� ����� 1
		}
	}
	return output;
}

monom monom::operator * (const double num_right)
{
	return monom (this->coef * num_right, this->deg);
}

monom operator * (const double num_left, const monom a)
{
	return monom(a.coef * num_left, a.deg);
}

monom operator * (const monom mon1, const monom mon2)
{
	return monom(mon1.coef * mon2.coef, mon1.deg + mon2.deg);
}