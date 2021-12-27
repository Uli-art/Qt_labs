// Task_10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*Задача 10. Патриций решил устроить праздник и для этого приготовил 240 
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал 
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба 
неизвестна. Про яд известно, что человек, который его выпил, умирает в 
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У 
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в 
какой именно бочке яд. Каким образом можно это узнать*/

#include <iostream>

std::string ConvertToThurd(int num) {
    std::string converted ;
    int i = 0;
    while(num > 0){
        converted += (num % 3) + 48;
        ++i;
        num /= 3;
    }
    return converted;
}
void Сheck2(bool slaves[], std::string numOfBarrel, std::string& answer) {
    for (int i = 0; i < 5; ++i) {
        if (slaves[i]) {
            if (numOfBarrel[i] == '2') {
                answer[ i] = '2';
                slaves[i] = false;
            }
        }
    }
}

void Сheck1(bool slaves[], std::string numOfBarrel,std::string& answer) {
    for (int i = 0; i < 5; ++i) {
        if (slaves[i]) {
            if (numOfBarrel[i] == '1') {
                answer[i] = '1';
                slaves[i] = false;
            }
        }
    }
}

void maincalc(int numOfBarrel) {
    std::string converted = ConvertToThurd(numOfBarrel);
    for (int i = converted.length(); i < 5; ++i) {
        converted += '0';
    }
    std::cout << converted << std::endl;
    std::string answer = "000000";
   // bool slaves[5] = { true,true,true,true,true }; 
    bool* slaves = new bool[5];
    for (int i = 0; i < 5; ++i) {
        slaves[i] = true;
    }
    //slaves = { true, true, true, true, true };
    Сheck2(slaves, converted, answer);
    Сheck1(slaves, converted, answer);
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (!slaves[i]) {
            ++count;
        }
    }
    std::cout << "Dead slaves: " << count << " " << "Count of the days: 2";
}
int main()
{
    int numOfBarrel;
    std::cin >> numOfBarrel;
    maincalc(numOfBarrel);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
