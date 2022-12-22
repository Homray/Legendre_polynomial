#include "pch.h"
#include "CppUnitTest.h"

#include "..\Legendre_polynomial\monom.cpp"

#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template <typename T> std::string ToString(T& mon)
{
	std::stringstream stream;
	stream << mon;

	return std::string(stream.str());
}

int operator == (monom mon1, monom mon2)	// Оператор == для мономов
{
	if (mon1.get_coef() == mon2.get_coef() && mon1.get_deg() == mon2.get_deg()) return true;
	return false;
}

//namespace Microsoft {
//	namespace VisualStudio {
//		namespace CppUnitTestFramework {
//			template <> static std::wstring ToString(const monom& q) {
//				std::wstringstream s;
//				;
//				return s.str();
//			}
//		}
//	}
//}



namespace monomfunctionstests
{
	TEST_CLASS(output_operator)
	{
	public:
		
		TEST_METHOD(null_coef)
		{
			monom t(0, 7);
			std::string exepted = "0";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(constant)
		{
			monom t(6, 0);
			std::string exepted = "6";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(negative_constant)
		{
			monom t(-8, 0);
			std::string exepted = "- 8";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(coef_equals_one)
		{
			monom t(1, 7);
			std::string exepted = "x^7";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(coef_equals_negative_one)
		{
			monom t(-1, 3);
			std::string exepted = "- x^3";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD( x )
		{
			monom t(1, 1);
			std::string exepted = "x";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(negstive_x)
		{
			monom t(-1, 1);
			std::string exepted = "- x";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(any)
		{
			monom t(5, 12);
			std::string exepted = "5*x^12";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}

		TEST_METHOD(negative_any)
		{
			monom t(-8, 2);
			std::string exepted = "- 8*x^2";
			Assert::IsTrue(ToString<monom>(t) == exepted);
		}
	};


	TEST_CLASS(multiplication_by_the_number_on_the_right)
	{
	public:
		TEST_METHOD(null_number)
		{
			monom mon(2,3);
			monom exepted(0,3);
			Assert::IsTrue(mon * 0 == exepted);
		}

		TEST_METHOD(null_coef_of_monomial)
		{
			monom mon(0, 3);
			monom exepted(0, 3);
			Assert::IsTrue(mon * 3 == exepted);
		}

		TEST_METHOD(positive_number_positive_coef)
		{
			monom mon(2, 3);
			monom exepted(4, 3);
			Assert::IsTrue(mon * 2 == exepted);
		}

		TEST_METHOD(negative_number_positive_coef)
		{
			monom mon(2, 3);
			monom exepted(-4, 3);
			Assert::IsTrue(mon * -2 == exepted);
		}

		TEST_METHOD(positive_number_negative_coef)
		{
			monom mon(-2, 3);
			monom exepted(-12, 3);
			Assert::IsTrue(mon * 6 == exepted);
		}

		TEST_METHOD(negative_number_negative_coef)
		{
			monom mon(-2, 3);
			monom exepted(8, 3);
			Assert::IsTrue(mon * -4 == exepted);
		}
	};

	TEST_CLASS(multiplication_by_the_number_on_the_left)
	{
	public:
		TEST_METHOD(null_number)
		{
			monom mon(2, 3);
			monom exepted(0, 3);
			Assert::IsTrue(0 * mon == exepted);
		}

		TEST_METHOD(null_coef_of_monomial)
		{
			monom mon(0, 3);
			monom exepted(0, 3);
			Assert::IsTrue(3 * mon == exepted);
		}

		TEST_METHOD(positive_number_positive_coef)
		{
			monom mon(2, 3);
			monom exepted(4, 3);
			Assert::IsTrue(2 * mon == exepted);
		}

		TEST_METHOD(negative_number_positive_coef)
		{
			monom mon(2, 3);
			monom exepted(-4, 3);
			Assert::IsTrue(-2 * mon == exepted);
		}

		TEST_METHOD(positive_number_negative_coef)
		{
			monom mon(-2, 3);
			monom exepted(-12, 3);
			Assert::IsTrue(6 * mon == exepted);
		}

		TEST_METHOD(negative_number_negative_coef)
		{
			monom mon(-2, 3);
			monom exepted(8, 3);
			Assert::IsTrue(-4 * mon == exepted);
		}
	};

	TEST_CLASS(multiplication_of_monomials)
	{
	public:
		TEST_METHOD(null_coef_of_one_monom)
		{
			monom mon1(0, 3);
			monom mon2(2, 4);
			monom exepted(0, 7);
			Assert::IsTrue(mon1 * mon2 == exepted);
		}

		TEST_METHOD(positive_and_positive_coefs)
		{
			monom mon1(6, 1);
			monom mon2(2, 3);
			monom exepted(12, 4);
			Assert::IsTrue(mon1 * mon2 == exepted);
		}

		TEST_METHOD(positive_and_negative_coefs)
		{
			monom mon1(5, 0);
			monom mon2(-7, 6);
			monom exepted(-35, 6);
			Assert::IsTrue(mon1 * mon2 == exepted);
		}

		TEST_METHOD(negative_and_negative_coefs)
		{
			monom mon1(-3, 5);
			monom mon2(-9, 2);
			monom exepted(27, 7);
			Assert::IsTrue(mon1 * mon2 == exepted);
		}
	};
}
