// Task_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*Задача 9. Вчера на уроке математики Саша (возможно Богом данный) узнал 
о том, что иногда полезно использовать вместо десятичной системы 
счисления какую-нибудь другую. Однако, учительница (как иронично) не 
объяснила, почему в системе счисления по основанию b в качестве цифр 
выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно 
выбирать и другие наборы цифр. Например, вместо троичной системы 
счисления можно рассмотреть систему счисления, где вместо обычных цифр 
0, 1, 2 есть цифры 1, 2 и 3. Саша заинтересовался вопросом, а как перевести 
число n в эту систему счисления? Например, число 7 в этой системе 
записывается как 21, так как 7 = 2∙3+1, а число 22 записывается как 211, так 
как 22 = 2 ∙ 9 + 1 ∙ 3 + 1. 
Входные данные натуральное число n, 1 ≤ n ≤ 2•109.
Выходные данные число n записанное в указанной системе счисления*/
/*    if (num % 3 == 0) {
        addNum = "3";
        while (num != convertVariants(addNum)) {
            int length = addNum.length();
            if (length == 1) {
                addNum += '1';
            } else 
                addNum[1] += 1;
            std::string tempNum = addNum;
            if (!IsItFour(addNum)) {
                int count = 0;
                
                for (int i = 0; i < length; ++i) {
                    tempNum = addNum;
                    if (addNum[i] == '4') {
                        addNum[i] -= 3;
                        addNum[i + 1] += 1;
                        if (i == addNum.length() - 1)
                            addNum += '1';
                    }
                }
            }
        }
        
    }
    else {*/
#include <iostream>
#include <cmath>


int Length(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}

std::string Reverse(std::string str) {

    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}


int convertVariants(std::string num) {
    int converted = 0;
    int i = 0;
    for (int i = 0; i < num.length(); ++i) {
        int add = num[i] - 48;
        converted += add * pow(3, i);
    }
    return converted;
}

bool IsItFour(std::string num) {

    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '4') {
            return false;
        }
    }
    return true;
}

//std::string convert(int num, std::string addNum) {
    
//}

std::string erase(int pos, int count, std::string& num) {
    std::string newNum;
    
    for (int i = 0; i < num.length(); ++i) {
        
        if (i >= pos && i < count) {
            
            ++i;
        }
        newNum += num[i];
    }
    return newNum;
}

int find(std::string a, std::string findEl) {
    int pos;
    bool isPos = true;
    for (int i = 0; i < a.length() - findEl.length() + 1; ++i) {
        isPos = true;
        if (a[i] == findEl[0]) {
            for (int j = 0; j < findEl.length(); ++j) {
                if (a[i + j] != findEl[j]) {
                    isPos = false;
                    break;
                }
            }
        }
        else { isPos = false; }
        if (isPos) {
            return i;
        }
    }
    return -1;
}
void replace(int pos, std::string& a, std::string replEl) {
    for (int i = 0; i < replEl.length(); ++i) {
        a[i + pos] = replEl[i];
    }
}
std::string convertIntoNewSystem(int num) {
    std::string addNum;

        int i = 0;
        while (num > 0) {
            int temp = (num % 3);
            addNum += temp + 48;
            num /= 3;
            ++i;
        }
        addNum = Reverse(addNum);
        int pos = find(addNum, "10");
        while (pos + 1) {
            replace(pos, addNum, "03");
            pos = find(addNum, "10");
        }
        int pos1 = find(addNum, "20");
        while (pos1 + 1) {
            replace(pos1, addNum, "13");
            pos1 = find(addNum, "20");
        }
        int pos2 = find(addNum, "30");
        while (pos2 + 1) {
            replace(pos2, addNum, "23");
            pos2 = find(addNum, "30");
        }
        while (addNum[0] == '0')
            addNum = erase(0, 1, addNum);

    
    return addNum;
}
    

// 2064105063
// 2142433642
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
