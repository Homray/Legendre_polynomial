
#include "monom.h"
#include "polynom.h"

std::vector<polynom> legendre_polynomials(int n)
{
    std::vector<polynom> LPs;   //������ ��� ������ ����������� ��������

    LPs.push_back(polynom({ monom(1,0) })); //������ ������� ��������� ��������
    LPs.push_back(polynom({ monom(1,1) })); //������ ������ ��������� ��������

    for (int i = 2; i <= n; ++i) {  //��������� ��������� ���������� �������� �� �������: Pn+1(x)=(2n+1)x/(n+1)Pn(x)-n/(n+1)Pn-1(x)
        LPs.push_back((2 * (i - 1) + 1) / (double)i * monom(1, 1) * LPs[i - 1] - (i - 1) / (double)i * LPs[i - 2]);
    }

    return LPs; //���������� ������ ����������� ��������
}

int main()
{
    int n = 10;
    std::vector<polynom> LPs = legendre_polynomials(n);    //������� ������ ������ 10 ����������� ��������

    //int num;
    //setlocale(LC_ALL, "ru"); //������� ���������
    /*std::cout << "����� ��������� �������� ������� (�� " << 10 << "): ";
    std::cin >> num;
    std::cout <<std::endl<< "P_" << n << "(x) = ";
    std::cout << LPs[num] << std::endl;*/

    for (int i = 0; i <= 10; ++i) {
        std::cout << "P_" << i << "(x) = " << LPs[i] << std::endl;
    }

 

}