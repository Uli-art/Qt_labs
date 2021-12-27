// Task_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int FcountOfIntrNum(int number){
    int countOfIntrNum = 0;
    countOfIntrNum = 0;
    countOfIntrNum = number / 10;
    if (number % 10 == 9) {
        ++countOfIntrNum;
    }
    return countOfIntrNum;
}
