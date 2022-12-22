#include "monom.h"
#include<iomanip>	//для std::setprecision()


std::ostream& operator << (std::ostream& output, monom mon)
{
	output << std::setprecision(5);//на выводе обрезает double до 3 знаков после запятой

	if (!mon.get_coef()) output << 0;	//нулевой коэффициент	

	else {								//ненулевой коэффициент
		if (!mon.get_deg()) {				//нулевая степпень
			if (mon.get_coef() > 0) output << mon.get_coef();	//отрицательный свободный член
			else output << "- " << abs(mon.get_coef());			//положительный свободный член
		}

		else {								//ненулевая степень
			if (mon.get_coef() == 1) output << "x";			//коэффициент = 1	

			else if (mon.get_coef() == -1) output << "- x";	//коэффициент = -1	

			else {											//остальные коэффициенты
				if (mon.get_coef() < 0) output << "- " << abs(mon.get_coef()) << "*x";	//отрицательные

				else output << mon.get_coef() << "*x";									//положительные
			}
			if (mon.get_deg() != 1) output << "^" << mon.get_deg();	//вывести степень, если она не равна 1
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