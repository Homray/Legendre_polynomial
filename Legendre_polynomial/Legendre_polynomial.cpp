
#include "monom.h"
#include "polynom.h"

std::vector<polynom> legendre_polynomials(int n)
{
    std::vector<polynom> LPs;   //вектор для списка многочленов Лежандра

    LPs.push_back(polynom({ monom(1,0) })); //задали нулевой многочлен Лежандра
    LPs.push_back(polynom({ monom(1,1) })); //задали первый многочлен Лежандра

    for (int i = 2; i <= n; ++i) {  //вычисляем остальный многочлены Лежандра по формуле: Pn+1(x)=(2n+1)x/(n+1)Pn(x)-n/(n+1)Pn-1(x)
        LPs.push_back((2 * (i - 1) + 1) / (double)i * monom(1, 1) * LPs[i - 1] - (i - 1) / (double)i * LPs[i - 2]);
    }

    return LPs; //возвращаем список многочленов Лежандра
}

int main()
{
    int n = 10;
    std::vector<polynom> LPs = legendre_polynomials(n);    //создали список первых 10 многочленов Лежандра

    //int num;
    //setlocale(LC_ALL, "ru"); //русская раскладка
    /*std::cout << "Какой многочлен Лажандра вывести (до " << 10 << "): ";
    std::cin >> num;
    std::cout <<std::endl<< "P_" << n << "(x) = ";
    std::cout << LPs[num] << std::endl;*/

    for (int i = 0; i <= 10; ++i) {
        std::cout << "P_" << i << "(x) = " << LPs[i] << std::endl;
    }

 

}