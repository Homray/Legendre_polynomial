#include "polynom.h"


int mon_comp(monom mon1, monom mon2)	// ���������� ��� sort() (���������� ������� �������)
{
	if (mon1.get_deg() > mon2.get_deg()) return 1;
	//if (mon1.get_deg() == mon2.get_deg())
	return 0;
}


polynom::polynom(std::vector<monom> pol) { 
	this->vect = pol;	//�������� ���������� ������ ������� � ���� vect ��������

	if (!this->vect.size()) return;	//���� ������ ������, �� �����

	sort(this->vect.begin(), this->vect.end(), mon_comp);	//��������� ���� ������� ������� �� ��������

	int i = 0;
	double val;
	while (i < this->vect.size()-1) {	//������� ������� ������������ � �������� ������ � ����������� ��������� � ���� �����
		if (this->vect[i].get_coef() == 0) {	//������� ����� � ������� �������������
			this->vect.erase(this->vect.begin() + i);
		}

		else if (this->vect[i].get_deg() == this->vect[i + 1].get_deg()) {	//�� 2�� �������� ������� ���������� ������� ������ ����
			val = this->vect[i + 1].get_coef();	// ��������� ���������� 2�� ������
			this->vect[i + 1].set_coef(val + this->vect[i].get_coef());	//� ������������ 2�� ������ ���������� ����������� 1��
			this->vect.erase(this->vect.begin() + i);	//������� 1�� �����
		}
		else ++i;	//���� ��� �������� ������������ � i-�� � (i+1)-�� ������ ������ ��������, �� ���������������
	}
	if (this->vect.size()==1 && this->vect[0].get_coef()==0) this->vect.erase(this->vect.begin());
}

std::ostream& operator << (std::ostream& output, polynom pol)	
{
	if (!pol.vect.size()) {	//���� � �������� ��� ���������, ������� 0
		output << 0;
		return output;
	}
	output << pol.vect[0];						//������� ������ ���������
	for (int i = 1; i < pol.vect.size(); ++i) {	//������� ��������� ���������
		if ( pol.vect[i].get_coef() < 0 ) output << " " << pol.vect[i];	//�� ������� ���� + ����� �������������� ��������������
		else output << " + " << pol.vect[i];							//������� ���� + ����� �������������� ��������������
	}

	return output;
}

polynom operator * (polynom pol, const double num_right)
{
	std::vector<monom> v;	//������� ������ �������, ����� �������� � ����� ������� (���������)
	for (int i = 0; i < pol.vect.size(); ++i) {	//���������� � ��������� ������ ������
		v.push_back(pol.vect[i] * num_right);	
	}
	return polynom(v);	//���������� ����������� ��������� � ��������� ��������
}

polynom operator * (const double num_left, polynom pol)
{
	std::vector<monom> v;	//������� ������ �������, ����� �������� � ����� ������� (���������)
	for (int i = 0; i < pol.vect.size(); ++i) {	//���������� � ��������� ������ ������
		v.push_back(num_left * pol.vect[i]);
	}
	return polynom(v);	//���������� ����������� ��������� � ��������� ��������
}

polynom operator * (polynom pol, monom mon_right)
{
	std::vector<monom> v;	//������� ������ �������, ����� �������� � ����� ������� (���������)
	for (int i = 0; i < pol.vect.size(); ++i) {	//���������� � ��������� ������ ������
		v.push_back(pol.vect[i] * mon_right);
	}
	return polynom(v);	//���������� ����������� ��������� � ��������� ��������
}

polynom operator * (monom mon_left, polynom pol)
{
	std::vector<monom> v;	//������� ������ �������, ����� �������� � ����� ������� (���������)
	for (int i = 0; i < pol.vect.size(); ++i) {	//���������� � ��������� ������ ������
		v.push_back(mon_left * pol.vect[i]);
	}
	return polynom(v);	//���������� ����������� ��������� � ��������� ��������
}


polynom operator + (polynom pol1, polynom pol2)
{
	std::vector<monom> v = pol1.vect;	//������� ������ �������, � ������� �������� ������ ������� 1�� �������� 
	v.insert(v.end(), pol2.vect.begin(), pol2.vect.end());	//��������� ������ ���������� ������� ������ ������� 2�� �������� 
	return polynom(v); //���������� �������, ������� � ���� ��������� ������ (����������� ��� ��� �������)
}

polynom operator - (polynom pol1, polynom pol2)
{
	return pol1 + (-1 * pol2);	//���������� ��� ��������� �������� �������� ��������� � ��������� �������� �� �����
}

polynom operator * (polynom pol1, polynom pol2)
{
 	polynom product({});	//������� ������� � ������� ����� ���������� ������ ������������
	for (int i = 0; i < pol1.vect.size(); ++i) {	//�������� 2�� ������� �� ������ 1�� �������� � ��������� ��������� � ��������� �������
		product = product + pol1.vect[i] * pol2;
	}

	return product;	//���������� ��������� �������
}