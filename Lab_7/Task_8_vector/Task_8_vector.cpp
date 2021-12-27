// Task_8_vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int Length(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power & 1) { 
            result = (result * base);
        }
        base = (base * base) ;
        power >>= 1;
    }
    return result;
}

int Division(std::vector<int>& findNum) {
    int carry = 0;
    for (int i = (int)findNum.size() - 1; i >= 0; --i) {
        long long cur = findNum[i] + carry * 1000000000;
        findNum[i] = int(cur / 2);
        carry = int(cur % 2);
    }
    while (findNum.size() > 1 && findNum.back() == 0)
        findNum.pop_back();
    return carry;
}

bool convertNew(std::vector<int> willBeConverted, std::vector<int> findNum) {
    int len = findNum.size();
    for (int i = len - 1; i >= 0; --i) {
        int lenfindNum = Length(findNum[i]);
        int temp = findNum[i];
        for (int j = 0; j < lenfindNum; ++j) {
            if (temp % 10 != Division(willBeConverted))
                return false;
            temp /= 10;
        }
    }
    return true;
}

void Plus(std::vector<int>& findNum) {
    std::uint64_t temp = 1;
    int count = 0;
    int len = findNum.size();
    for (int i = len - 1; i >= 0; --i) {
        int lenfindNum = Length(findNum[i]);
        count = 0;
        while (findNum[i] & temp && lenfindNum != count) {
            findNum[i] -= fast_power(10, count);
            temp = temp << 1;
            ++count;
        }
        if (lenfindNum != count || lenfindNum != 9) {
            findNum[i] += fast_power(10, count);
            break;
        }
        if (i == 0) {
            findNum.push_back(1);
        }
    }
}

std::vector<int> Decimal(int num) {
    int count = 0;
    std::vector<int> findNum;
    findNum.push_back(1);
    //findNum[0] = 1;
    if (num == 1) {
        return findNum;
    }
    bool negative = false;
    while ((count) != num) {
        if (convertNew(findNum, findNum)) {
            count += 1;
        }
        else {
            negative = true;
        }
        if (count != num) {
            Plus(findNum);
            if (negative) {
                Plus(findNum);
                negative = false;
            }
        }
    }
    return findNum;
}

int main()
{
    int count;
    std::cin >> count;
    //std::cout << Decimal(count);
    //std::string num;
  //  std::cin >> num;
    std::vector<int> DevidedNum = Decimal(count);

   /* for (int i = num.length(); i > 0; i -= 9) {
        if (i < 9) {
            DevidedNum.push_back(atoi(num.substr(0, i).c_str()));
        }
        else {
            DevidedNum.push_back(atoi(num.substr(i - 9, 9).c_str()));
        }
    }*/
    for (int i = (int)DevidedNum.size() - 1; i >= 0; --i){
        std::cout << DevidedNum[i];
        //printf("%09d", DevidedNum[i]);
    }
}
/*
#include <iostream>
#include <bitset>
#include <limits>
#include <algorithm>
#include <vector> 
std::string BinaryAdd(std::string First, std::string Second)
{
    int Carry = 0;
    std::string Result;

    while (Second.size() > First.size())
        First.insert(0, "0");

    while (First.size() > Second.size())
        Second.insert(0, "0");

    for (int I = First.size() - 1; I >= 0; --I)
    {
        int FirstBit = First[I] - 0x30;
        int SecondBit = Second[I] - 0x30;
        Result += static_cast<char>((FirstBit ^ SecondBit ^ Carry) + 0x30);
        Carry = (FirstBit & SecondBit) | (SecondBit & Carry) | (FirstBit & Carry);
    }

    if (Carry)
        Result += 0x31;

    std::reverse(Result.begin(), Result.end());
    return Result;
}

std::string BinaryMulDec(std::string value, int amount)
{
    if (amount == 0)
    {
        for (auto& s : value)
        {
            s = 0x30;
        }
        return value;
    }

    std::string result = value;
    for (int I = 0; I < amount - 1; ++I)
        result = BinaryAdd(result, value);

    return result;
}

std::int64_t CalcPowers(std::int64_t value)
{
    std::int64_t t = 1;
    while (t < value)
        t *= 10;

    return t;
}

std::string ToBinary(const std::string& value)
{
    std::vector<std::string> sets;
    std::vector<int> multipliers;

    int Len = 0;
    int Rem = value.size() % 4;

    for (auto it = value.end(), jt = value.end(); it != value.begin() - 1; --it)
    {
        if (Len++ == 4)
        {
            std::string t = std::string(it, jt);
            sets.push_back(std::bitset<16>(std::stoull(t)).to_string());
            multipliers.push_back(CalcPowers(std::stoull(t)));
            jt = it;
            Len = 1;
        }
    }

    if (Rem != 0 && Rem != value.size())
    {
        sets.push_back(std::bitset<16>(std::stoull(std::string(value.begin(), value.begin() + Rem))).to_string());
    }

    auto formula = [](std::string a, std::string b, int mul) -> std::string
    {
        return BinaryAdd(BinaryMulDec(a, mul), b);
    };

    std::reverse(sets.begin(), sets.end());
    std::reverse(multipliers.begin(), multipliers.end());
    std::string result = sets[0];

    for (std::size_t i = 1; i < sets.size(); ++i)
    {
        result = formula(result, sets[i], multipliers[i]);
    }

    return result;
}

void ConcatenateDecimals(std::int64_t* arr, int size)
{
    auto formula = [](std::int64_t a, std::int64_t b) -> std::int64_t
    {
        return (a * CalcPowers(b)) + b;
    };

    std::int64_t val = arr[0];

    for (int i = 1; i < size; ++i)
    {
        val = formula(val, arr[i]);
    }

    std::cout << val;
}

int main()
{
    std::string decimal = "64497387062899840145";
    //6449738706289984014 = 0101100110000010000100110010111001100010100000001000001000001110

    
    std::int64_t arr[] = {644, 9738, 7062, 8998, 4014};
    ConcatenateDecimals(arr, 5);

    std::cout << ToBinary(decimal);

    return 0;
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
