#pragma once

#include <iostream>

class monom
{
public:
	monom(double coef, int deg) : coef(coef), deg(deg) {}	// Конструктор с параметрами

	virtual ~monom() {};	// Деструктор

	const double get_coef() { return coef; }		// Получить коэффициент монома
	void set_coef(double val) { coef = val; }		// Установить коэффициент монома
	int get_deg() { return deg; }					// Получить степень монома
	void set_deg(int val) { deg = val; }			// Установить степень монома


	friend std::ostream& operator << (std::ostream& output, monom mon);		//	Вывод монома


	monom operator * (const double num_right);								//	Умножение мнома на число справа
	friend monom operator * (const double num_left ,const monom a);			//	Умножение мнома на число слева
	/*monom operator * (const double num, const monom a)
	{
		return monom(num * a.coef, a.deg);
	}*/

	friend monom operator * (const monom mon1, const monom mon2);			//Умножение монома на моном


private:
	double coef = 0;
	int deg = 0;
};

