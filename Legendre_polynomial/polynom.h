#pragma once

#include "monom.h"
#include <vector>
#include <algorithm>

class polynom
{
public:

	polynom(std::vector<monom> pol);	// Конструктор с параметрами (полином отсортировани по убыванию степеней)

	std::vector<monom> get_vect() { return vect; }	// Получить вектор мономов полинома


	friend std::ostream& operator << (std::ostream& output, polynom pol);	// Вывод полинома

	friend polynom operator * (polynom pol, const double num_right);		// Умножение полинома на число справа
	friend polynom operator * (const double num_left, polynom pol);			// Умножение полинома на число слева

	friend polynom operator * (polynom pol, monom mon_right);				// Умножение полинома на моном справа
	friend polynom operator * (monom mon_left, polynom pol);				// Умножение полинома на моном слева

	friend polynom operator + (polynom pol1, polynom pol2);					// Сложение полиномов

	friend polynom operator - (polynom pol1, polynom pol2);					// Вычитвние полиномов

	friend polynom operator * (polynom pol1, polynom pol2);					// Умножение полинома на полином

private:

	std::vector<monom> vect;
};

