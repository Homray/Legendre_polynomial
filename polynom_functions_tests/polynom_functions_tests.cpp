#include "pch.h"
#include "CppUnitTest.h"

#include "..\Legendre_polynomial\monom.cpp"
#include "..\Legendre_polynomial\polynom.cpp"

#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template <typename T> std::string ToString(T& pol)
{
	std::stringstream stream;
	stream << pol;

	return std::string(stream.str());
}

int operator != (monom mon1, monom mon2)	// Оператор != для мономов
{
	if (mon1.get_coef() == mon2.get_coef() && mon1.get_deg() == mon2.get_deg()) return false;
	return true;
}

int operator == (polynom pol1, polynom pol2)	// Оператор == для полиномов
{
	if (pol1.get_vect().size() != (pol2.get_vect().size())) return false;	//если размеры полиномов (их векторов мономов) разные
	else {																	//если размеры полиномов (их векторов мономов) одинаковые
		if (!pol1.get_vect().size()) return true;	//пустой ролином
		else {
			for (int i = 0; i < pol1.get_vect().size(); ++i) {
				if (pol1.get_vect()[i] != pol2.get_vect()[i]) return false;	//помономное сравлеие
			}
		}
		return true;
	}
}

namespace polynomfunctionstests
{
	TEST_CLASS(otuput_operator)
	{
	public:
		
		TEST_METHOD(empty)
		{
			std::string exepted = "0";
			polynom pol({});
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

		TEST_METHOD(positive_constant)
		{
			std::string exepted = "4";
			polynom pol({monom(4,0)});
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}
		TEST_METHOD(negative_constant)
		{
			std::string exepted = "- 9";
			polynom pol({ monom(-9 ,0) });
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

		TEST_METHOD(positive_x)
		{
			std::string exepted = "4*x";
			polynom pol({ monom(4,1) });
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

		TEST_METHOD(negative_x)
		{
			std::string exepted = "- 7*x";
			polynom pol({ monom(-7 ,1) });
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

		TEST_METHOD(any1)
		{
			std::string exepted = "2*x^4 - 4*x^2 + 5*x";
			polynom pol({ monom(5 ,1), monom(2, 4), monom(-4 , 2)});
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

		TEST_METHOD(any2)
		{
			std::string exepted = "5*x^-10";
			polynom pol({ monom(0 ,0), monom(5, -10) });
			Assert::IsTrue(ToString<polynom>(pol) == exepted);
		}

	};

	TEST_CLASS(multiplication_by_number_on_the_right)
	{
	public:

		TEST_METHOD(null_number)
		{
			polynom exepted = polynom({});
			polynom pol({monom(1,2), monom(5,7)});
			Assert::IsTrue(pol * 0 == exepted);
		}

		TEST_METHOD(empty_polynom)
		{
			polynom exepted = polynom({});
			polynom pol({});
			Assert::IsTrue(pol*7  == exepted);
		}

		TEST_METHOD(positive_number)
		{
			polynom exepted = polynom({ monom(8,2), monom(-14,1), monom(4,0) });
			polynom pol({monom(4,2), monom(-7,1), monom(2,0)});
			Assert::IsTrue(pol * 2 == exepted);
		}

		TEST_METHOD(negative_number)
		{
			polynom exepted = polynom({ monom(-12,2), monom(21,1), monom(-6,0) });
			polynom pol({ monom(4,2), monom(-7,1), monom(2,0) });
			Assert::IsTrue(pol * -3 == exepted);
		}
	};

	TEST_CLASS(multiplication_by_number_on_the_left)
	{
	public:

		TEST_METHOD(null_number)
		{
			polynom exepted = polynom({});
			polynom pol({ monom(1,2), monom(5,7) });
			Assert::IsTrue(0 * pol == exepted);
		}

		TEST_METHOD(empty_polynom)
		{
			polynom exepted = polynom({});
			polynom pol({});
			Assert::IsTrue(7 * pol == exepted);
		}

		TEST_METHOD(positive_number)
		{
			polynom exepted = polynom({ monom(8,2), monom(-14,1), monom(4,0) });
			polynom pol({ monom(4,2), monom(-7,1), monom(2,0) });
			Assert::IsTrue(2 * pol == exepted);
		}

		TEST_METHOD(negative_number)
		{
			polynom exepted = polynom({ monom(-12,2), monom(21,1), monom(-6,0) });
			polynom pol({ monom(4,2), monom(-7,1), monom(2,0) });
			Assert::IsTrue(-3 * pol == exepted);
		}
	};

	TEST_CLASS(multiplication_by_monom_on_the_right)
	{
	public:
		TEST_METHOD(null_monom)
		{
			polynom exepted = polynom({});
			polynom pol({ monom(4,2), monom(-7,1), monom(2,0) });
			Assert::IsTrue(pol * monom(0,2) == exepted);
		}

		TEST_METHOD(empty_polynom)
		{
			polynom exepted = polynom({});
			polynom pol({});
			Assert::IsTrue(pol * monom(4, 2) == exepted);
		}

		TEST_METHOD(negative_monom)
		{
			polynom exepted = polynom({monom(-20,4), monom(10,2)});
			polynom pol({ monom(4,2), monom(-2,0) });
			Assert::IsTrue(pol * monom(-5, 2) == exepted);
		}

		TEST_METHOD(positive_monom)
		{
			polynom exepted = polynom({ monom(20,4), monom(-10,2) });
			polynom pol({ monom(4,2), monom(-2,0) });
			Assert::IsTrue(pol * monom(5, 2) == exepted);
		}
	};

	TEST_CLASS(multiplication_by_monom_on_the_left)
	{
	public:
		TEST_METHOD(null_monom)
		{
			polynom exepted = polynom({});
			polynom pol({ monom(4,2), monom(-7,1), monom(2,0) });
			Assert::IsTrue(monom(0, 2) * pol == exepted);
		}

		TEST_METHOD(empty_polynom)
		{
			polynom exepted = polynom({});
			polynom pol({});
			Assert::IsTrue(monom(4, 2) * pol == exepted);
		}

		TEST_METHOD(negative_monom)
		{
			polynom exepted = polynom({ monom(-20,4), monom(10,2) });
			polynom pol({ monom(4,2), monom(-2,0) });
			Assert::IsTrue(monom(-5, 2) * pol == exepted);
		}

		TEST_METHOD(positive_monom)
		{
			polynom exepted = polynom({ monom(20,4), monom(-10,2) });
			polynom pol({ monom(4,2), monom(-2,0) });
			Assert::IsTrue(monom(5, 2) * pol == exepted);
		}
	};

	TEST_CLASS(addition_of_polymoms)
	{
	public:
		TEST_METHOD(empty)
		{
			polynom exepted = polynom({ monom(4,2), monom(-2,0) });
			polynom pol1({ monom(4,2), monom(-2,0) });
			polynom pol2({});
			Assert::IsTrue(pol1 + pol2 == exepted);
		}

		TEST_METHOD(result_is_empty)
		{
			polynom exepted = polynom({});
			polynom pol1({ monom(4,2), monom(-2,0) });
			polynom pol2({ monom(-4,2), monom(2,0) });
			Assert::IsTrue(pol1 + pol2 == exepted);
		}

		TEST_METHOD(any1)
		{
			polynom exepted = polynom({ monom(-7,5), monom(9,2), monom(2,1), monom(-2,0)});
			polynom pol1({ monom(4,2), monom(-2,0) });
			polynom pol2({ monom(-7,5), monom(2,1), monom(5,2)});
			Assert::IsTrue(pol1 + pol2 == exepted);
		}
	};

	TEST_CLASS(multiplications_of_polymoms)
	{
	public:
		TEST_METHOD(empty)
		{
			polynom exepted = polynom({});
			polynom pol1({ monom(4,2), monom(-2,0) });
			polynom pol2({});
			Assert::IsTrue(pol1 * pol2 == exepted);
		}

		TEST_METHOD(any)
		{
			polynom exepted = polynom({monom(12,5), monom(2, 3), monom(-4, 1)});
			polynom pol1({ monom(4,2), monom(-2,0) });
			polynom pol2({ monom(3,3), monom(2,1) });
			Assert::IsTrue(pol1 * pol2 == exepted);
		}

		TEST_METHOD(subtraction_OF_SQUERES)
		{
			polynom exepted = polynom({ monom(1,2), monom(-1, 0)});
			polynom pol1({ monom(1,1), monom(-1,0) });
			polynom pol2({ monom(1,1), monom(1,0) });
			Assert::IsTrue(pol1 * pol2 == exepted);
		}
	};
}
