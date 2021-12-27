//Лабораторная работа 3, выполнила Сидорова У.Ю.
/*
Задание 9
Вычислить a0 - 2a1 + 4a2 + ..
*/

#include <iostream>
#include <ctime>
int main()
{
    std::cout << "Enter number of addendum: "<< std::endl;
    int n;
    std::cin >> n;
    if (n <= 0) {
        std::cout << 0;
        return 0;
    }
    srand(time(NULL));
    int sum = 0 , powTwo = 1, a;
    for (int i = 0; i < n; i++) {
        
        a = 1 ;
        if (i % 2 != 0)
            sum -= powTwo * a;
        else
            sum += powTwo * a;
        powTwo *= 2;

    }
    std::cout << "Sum of " << n << " addendums " << sum;
}

