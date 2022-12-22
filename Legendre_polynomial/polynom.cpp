#include "polynom.h"


int mon_comp(monom mon1, monom mon2)	// Компаратор для sort() (сортировка вектора мономов)
{
	if (mon1.get_deg() > mon2.get_deg()) return 1;
	//if (mon1.get_deg() == mon2.get_deg())
	return 0;
}


polynom::polynom(std::vector<monom> pol) { 
	this->vect = pol;	//загоняем полученный вектор мономов в поле vect полинома

	if (!this->vect.size()) return;	//если пустой вектор, то выйти

	sort(this->vect.begin(), this->vect.end(), mon_comp);	//сортируем поле вектора мономов по степеням

	int i = 0;
	double val;
	while (i < this->vect.size()-1) {	//удаляем нулевые коэффициенты и собираем мономы с одинаковыми степенями в один моном
		if (this->vect[i].get_coef() == 0) {	//удаляем моном с нулевым коэффициентом
			this->vect.erase(this->vect.begin() + i);
		}

		else if (this->vect[i].get_deg() == this->vect[i + 1].get_deg()) {	//из 2ух соседних мономов одинаковой степени делаем один
			val = this->vect[i + 1].get_coef();	// сохраняем коэфициент 2го монома
			this->vect[i + 1].set_coef(val + this->vect[i].get_coef());	//к коэффициенту 2го монома прибывляем коэффициент 1го
			this->vect.erase(this->vect.begin() + i);	//удаляем 1ый моном
		}
		else ++i;	//если нет нулевого коэффикиента и i-ый и (i+1)-ый мономы разных степеней, то двигаемсядальше
	}
	if (this->vect.size()==1 && this->vect[0].get_coef()==0) this->vect.erase(this->vect.begin());
}

std::ostream& operator << (std::ostream& output, polynom pol)	
{
	if (!pol.vect.size()) {	//если в полиноме нет слагаемых, вывести 0
		output << 0;
		return output;
	}
	output << pol.vect[0];						//выводим первое слагаемое
	for (int i = 1; i < pol.vect.size(); ++i) {	//выводим остальные слагаемые
		if ( pol.vect[i].get_coef() < 0 ) output << " " << pol.vect[i];	//не выводим знак + перед отрицательными коэффициентами
		else output << " + " << pol.vect[i];							//вывести знак + перед положительными коэффициентами
	}

	return output;
}

polynom operator * (polynom pol, const double num_right)
{
	std::vector<monom> v;	//создаем вектор мономов, чтобы вставить в новый полином (результат)
	for (int i = 0; i < pol.vect.size(); ++i) {	//записывает в созданный вектор мономы
		v.push_back(pol.vect[i] * num_right);	
	}
	return polynom(v);	//возвращяем результатом полиномом с созданным вектором
}

polynom operator * (const double num_left, polynom pol)
{
	std::vector<monom> v;	//создаем вектор мономов, чтобы вставить в новый полином (результат)
	for (int i = 0; i < pol.vect.size(); ++i) {	//записывает в созданный вектор мономы
		v.push_back(num_left * pol.vect[i]);
	}
	return polynom(v);	//возвращяем результатом полиномом с созданным вектором
}

polynom operator * (polynom pol, monom mon_right)
{
	std::vector<monom> v;	//создаем вектор мономов, чтобы вставить в новый полином (результат)
	for (int i = 0; i < pol.vect.size(); ++i) {	//записывает в созданный вектор мономы
		v.push_back(pol.vect[i] * mon_right);
	}
	return polynom(v);	//возвращяем результатом полиномом с созданным вектором
}

polynom operator * (monom mon_left, polynom pol)
{
	std::vector<monom> v;	//создаем вектор мономов, чтобы вставить в новый полином (результат)
	for (int i = 0; i < pol.vect.size(); ++i) {	//записывает в созданный вектор мономы
		v.push_back(mon_left * pol.vect[i]);
	}
	return polynom(v);	//возвращяем результатом полиномом с созданным вектором
}


polynom operator + (polynom pol1, polynom pol2)
{
	std::vector<monom> v = pol1.vect;	//создаем вектор мономов, в который копируем вектор мономов 1го полинома 
	v.insert(v.end(), pol2.vect.begin(), pol2.vect.end());	//добавляем вконец созданного вектора вектор мономов 2го полинома 
	return polynom(v); //возвращаем полином, коложив в него созданный вектор (конструктор сам все сделает)
}

polynom operator - (polynom pol1, polynom pol2)
{
	return pol1 + (-1 * pol2);	//используем уже имеющиеся операции сложения полиномов и умножения полинома на число
}

polynom operator * (polynom pol1, polynom pol2)
{
 	polynom product({});	//создаем полином в который будем постепенно класть произведение
	for (int i = 0; i < pol1.vect.size(); ++i) {	//умножаем 2ой полином на мономы 1го полинома и результат добавляем в созданный полином
		product = product + pol1.vect[i] * pol2;
	}

	return product;	//возвращаем созданный полином
}