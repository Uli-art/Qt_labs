// Lab_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 1.
Разработать программу в соответствии с вариантом, реализующую
работу со структурами в консольном приложении.
Использовать динамический массив структур, содержащий поля согласно
варианту индивидуального задания.
Программа должна содержать необходимые комментарии.
Следует ввод/вывод на экран входных и выходных данных. Для
форматированного ввода-вывода использовать scanf и printf, предусмотреть
некорректный ввод. Обрабатываемая структура должна иметь не менее пяти
полей (элементов) двух и более типов (если в задании указано меньше -
добавить). В каждом варианте задания реализовать следующие функции
для работы со структурой:
1. Функцию формирования динамического одномерного массива структур,
значения которых вводятся с клавиатуры. Предусмотреть возможность
заполнения одного поля структуры, используя известные значения других полей
структуры (придумать самим). С массивом структур работать через оператор new.
При вводе структур необходимо реализовать следующие механизмы:
• ввод заранее заданного количества структур; +
• ввод до появления структуры с заданным признаком;
• диалог с пользователем о необходимости продолжать ввод. +
2. Функцию просмотра содержимого динамического массива структур. +
3. Функцию дополнения уже существующего массива структур новыми
структурами. + 
4. Функцию поиска и вывода на экран структуры (структур) с заданным
значением элемента. +
5. Функции удаления и изменения элемента массива структур с заданным
значением элемента.
6. Функцию упорядочения массива структур по одному из полей
(элементов). Поле для сортировки выбрать самим. Способ указан в скобках. + 
Пример выполнения задания. На основе предметной области «Человек»
(фамилия, имя, отчество, пол, возраст) создать динамический массив структур.
Вывести на экран содержимое массива. Сделать выборку в исходном массиве
согласно полу и возрастному диапазону. Отсортировать исходный массив в
алфавитном порядке (достаточно по первой букве), используя алгоритм
сортировки, указанный в скобках.
10. Информация о сотрудниках содержит ФИО, номер отдела, должность,
стаж работы на предприятии. Вывести список сотрудников заданного отдела,
имеющих стаж работы на предприятии более 20 лет (Шейкер сортировка по
возрастанию).
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
/* Размер буфера */
#define CLI_BUFFER_SIZE 30
int idOfEmployee = 0;
int Length(int temp) {
    int count = 0;
    while (temp > 0) {
        temp /= 10;
        ++count;
    }
    return count;
}

int cli_read(int& value)
{
    size_t length = 0;
    bool correct;
    char buf[CLI_BUFFER_SIZE] = "";
    
    /* Чтение в буфер */
    if (!fgets(buf, sizeof(buf), stdin)) {
        return -1;
    }

    /* Удаление символа перевода строки */
    length = strlen(buf);
    if (buf[length - 1] == '\n') {
        buf[--length] = '\0';

        /* Перевод из строки в число */
        value = atoi(buf);
        if (length == Length(value)) {
            correct = true;
        }
        else {
            correct = false;
        }
        /* Обработка ошибок */
        if (length == 0) {
            fprintf(stderr, "Ошибка: введена пустая строка.\n");
            return -1;
        }
        if (!correct) {
            fprintf(stderr, "Ошибка: некорректный символ.\n");
            return -1;
        }
    }
    else {
        /* Строка прочитана не полностью
           Пропустить остаток строки   */
        scanf_s("%*[^\n]");
        scanf_s("%*c");
        fprintf(stderr, "Ошибка: не вводите больше чем %d символа(ов).\n", CLI_BUFFER_SIZE - 2);

        return -1;
    }

    return value;
}

std::string correctString(std::string& value) {
    size_t length = 0;
    bool correct;
    char buf[CLI_BUFFER_SIZE] = "";
    std::cin >> correct;
    /* Чтение в буфер */
    if (!fgets(buf, sizeof(buf), stdin)) {
        return "1";
    }

    /* Удаление символа перевода строки */
    length = strlen(buf);
    if (buf[length - 1] == '\n') {
        buf[--length] = '\0';

        for (int i = 0; i < length; ++i) {
            if (buf[i] < 'A' || buf[i] > 'z') {
                fprintf(stderr, "Ошибка: некорректный символ.\n");
                return "1";
            }
            else if (buf[i] > 'Z' && buf[i] < 'a') {
                fprintf(stderr, "Ошибка: некорректный символ.\n");
                return "1";
            }
        }
        /* Обработка ошибок */
        if (length == 0) {
            fprintf(stderr, "Ошибка: введена пустая строка.\n");
            return "1";
        }
    }
    else {
        /* Строка прочитана не полностью
           Пропустить остаток строки      */
        scanf_s("%*[^\n]");
        scanf_s("%*c");
        fprintf(stderr, "Ошибка: не вводите больше чем %d символа(ов).\n", CLI_BUFFER_SIZE - 2);

        return "1";
    }

    return buf;
}
int intInitialization() {
    int value = 0;
    do {
        value = cli_read(value);
        if (value == -1) {
            printf("Пожалуйста, попробуйте еще раз.\n");
        }
    } while (value == -1);
    return value;
}

std::string stringInitialization() {
    std::string value;
    do {
        value = correctString(value);
        if (value == "1") {
            printf("Пожалуйста, попробуйте еще раз.\n");
        }
    } while (value == "1");
    return value;
}

struct Employee {
    int id;
    std::string Name = "None";
    std::string Surname = "None";
    std::string Patronymic = "None";
    int numberOffice = 0;
    std::string Post = "None";
    int Experience = 0;
};

void Initialization(Employee& employee) {
    employee.id = ++idOfEmployee;

    std::cout << "How many fields do you want to fill(press 0 - 1 field, press 1 - all fields): \n";
    int answer;
    scanf_s("%d", &answer);
    std::cin.clear();
    if (answer !=  0) {
        
        std::cout << "Enter name: ";
        employee.Name = stringInitialization();
        
        std::cout << "Enter surname: \n";
        employee.Surname = stringInitialization();

        std::cout << "Enter patronymic: \n";
        employee.Patronymic = stringInitialization();

        std::cout << "Enter number of office: \n";
        employee.numberOffice = intInitialization();

        std::cout << "Enter post: \n";
        employee.Post = stringInitialization();

        std::cout << "Enter Experience: \n";
        employee.Experience = intInitialization();

    }
    else {
        std::cout << "Which field you want to fill in (all other fields will be filled with default value) 1 - Name, 2 - Surname, 3 - Patronymic, 4 - numberOffice, 5 - Post, 6 - Experience  \n";
        int numberOfField;
        scanf_s("%d", &numberOfField);
        switch (numberOfField)
        {
        case 1:
            std::cout << "Enter name: \n";
            employee.Name = stringInitialization();
            break;
        case 2:
            std::cout << "Enter surname: \n";
            employee.Surname = stringInitialization();
            break;
        case 3:
            std::cout << "Enter patronymic: \n";
            employee.Patronymic = stringInitialization();
            break;
        case 4:
            std::cout << "Enter number of office: \n";
            employee.numberOffice = intInitialization();
            break;
        case 5:
            std::cout << "Enter post: \n";
            employee.Post = stringInitialization();
            break;
        case 6:
            std::cout << "Enter Experience: \n";
            employee.Experience = intInitialization();
            break;
        default:
            std::cout << "Incorrect input \n";
            break;
        }
    }
}

void print(Employee* arrayOfEmployee, int size) {

    for (int i = 0; i < size; ++i) {
        printf("Employee number : % d\n Name : % s\n Surname : % s\n Patronymic : % s\n numberOffice : % d\n Post : % s\n Experience : % d\n", arrayOfEmployee[i].id, arrayOfEmployee[i].Name.c_str(), arrayOfEmployee[i].Surname.c_str(), arrayOfEmployee[i].Patronymic.c_str(), arrayOfEmployee[i].numberOffice, arrayOfEmployee[i].Post.c_str(), arrayOfEmployee[i].Experience);
       // std::cout << arrayOfEmployee[i].Surname;
    }
}

Employee* add(Employee* arrayOfEmployee, int& size, int countOfNewEl) {
    Employee* NewarrayOfEmployee = new Employee[size + countOfNewEl];
    for (int i = 0; i < size; ++i) {
        NewarrayOfEmployee[i] = arrayOfEmployee[i];
    }
    for (int i = size; i < size + countOfNewEl; ++i) {
        Initialization(NewarrayOfEmployee[i]);
        if (i != size - 1) {
            std::cout << "Do you wamt to continue? (1 - yes, 0 - no): \n";
            int answer ;
            scanf_s("%d", &answer) ;
            if (!answer)
                break;
           
        }
    }
    delete[] arrayOfEmployee;
    size += countOfNewEl;
    return NewarrayOfEmployee;
}

Employee* find(Employee* arrayOfEmployee,int size ,int numberOffice,int Experience, int& count) {
    count = 0;
    Employee* NewarrayOfEmployee = new Employee[size];
    for (int i = 0; i < size; ++i) {
        if (arrayOfEmployee[i].numberOffice == numberOffice && arrayOfEmployee[i].Experience > Experience) {
            NewarrayOfEmployee[count] = arrayOfEmployee[i];
            ++count;
        }
    }
    if (count != size - 1) {
        Employee* ShortNewarrayOfEmployee = new Employee[count + 1];
        for (int i = 0; i <= count; ++i) {
            ShortNewarrayOfEmployee[i] = NewarrayOfEmployee[i];
        }
        delete[] NewarrayOfEmployee;
        return ShortNewarrayOfEmployee;
    }
    return NewarrayOfEmployee;
}

void swap(Employee* &arrayOfEmployee,int i, int j) {
    Employee temp = arrayOfEmployee[i];
    arrayOfEmployee[i] = arrayOfEmployee[j];
    arrayOfEmployee[j] = temp;
}

void sort(Employee* arrayOfEmployee, int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (arrayOfEmployee[i].Name[0] > arrayOfEmployee[i + 1].Name[0]) {
                swap(arrayOfEmployee, i, i + 1);
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arrayOfEmployee[i].Name[0] < arrayOfEmployee[i - 1].Name[0]) {
                swap(arrayOfEmployee, i, i - 1);
            }
        }
        left++;
    }
}

Employee* deleteValue(Employee* arrayOfEmployee, int& size,int numderOfElement ,int countOfDelEl) {
    if (numderOfElement + countOfDelEl >= size) {
        std::cout << "Incorrect input \n";
        return arrayOfEmployee;
    }
    Employee* NewarrayOfEmployee = new Employee[size - countOfDelEl];
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (i < numderOfElement || i >= numderOfElement + countOfDelEl) {
            
            NewarrayOfEmployee[count] = arrayOfEmployee[i];
            NewarrayOfEmployee[count].id = count + 1;
            ++count;
        }
    }
    delete[] arrayOfEmployee;
    size -= countOfDelEl;
    return NewarrayOfEmployee;
}

Employee* deleteWith(Employee* arrayOfEmployee, int& size, int id) {

       // Employee* NewarrayOfEmployee;
       // NewarrayOfEmployee = find(arrayOfEmployee, size, numberOffice, Experience, count);
        int numberOfDelEl = 0;
        for (int i = 0; i < size; ++i) {
            if (arrayOfEmployee[i].id == id) {
                arrayOfEmployee = deleteValue(arrayOfEmployee, size, i, 1);
            }
        }
        --idOfEmployee;
        return arrayOfEmployee;
}

Employee* Change(Employee* arrayOfEmployee, int& size, int id) {
    for (int i = 0; i < size; ++i) {
        if (arrayOfEmployee[i].id == id) {
            int answer = 1;
            while (answer) {
                std::cout << "Which field you want to change 1 - Name, 2 - Surname, 3 - Patronymic, 4 - numberOffice, 5 - Post, 6 - Experience  \n";
                int numberOfField;
                scanf_s("%d", &numberOfField);
                switch (numberOfField)
                {
                case 1:
                    std::cout << "Enter name: \n";
                    arrayOfEmployee[i].Name = stringInitialization();
                    break;
                case 2:
                    std::cout << "Enter surname: \n";
                    arrayOfEmployee[i].Surname = stringInitialization();
                    break;
                case 3:
                    std::cout << "Enter patronymic: \n";
                    arrayOfEmployee[i].Patronymic = stringInitialization();
                    break;
                case 4:
                    std::cout << "Enter number of office: \n";
                    arrayOfEmployee[i].numberOffice = intInitialization();
                    break;
                case 5:
                    std::cout << "Enter post: \n";
                    arrayOfEmployee[i].Post = stringInitialization();
                    break;
                case 6:
                    std::cout << "Enter Experience: \n";
                    arrayOfEmployee[i].Experience = intInitialization();
                    break;
                default:
                    std::cout << "Incorrect input \n";
                    break;
                }
                printf("Do you want to continue change this element?(1 - yes, 0 - no)");
                scanf_s("%d", &answer);
            }
            return arrayOfEmployee;
        }
    }
    
}

int main()
{
   setlocale(0,"");
  /*  int size;
    std::cout << " Enter count of employee:  ";
    std::cin >> size;

    Employee* arrayOfEmployee = new Employee[size];
    for (int i = 0; i < size; ++i) {
        Initialization(arrayOfEmployee[i]);
        if (i != size - 1) {
        std::cout << "Do you wamt to continue? (1 - yes, 0 - no): ";
            int answer;
            scanf_s("%d", &answer);
            if (!answer)
                break;
        }
    }
    print(arrayOfEmployee, size);
   arrayOfEmployee = deleteValue(arrayOfEmployee, size, 2, 2);
     print(arrayOfEmployee, size);
   
   // Employee* NewarrayOfEmployee = find(arrayOfEmployee, size, 45,20, sizeOfNewArr);
    //sort(arrayOfEmployee, size);
    print(arrayOfEmployee,size);*/
   int size;
   std::cout << " Enter count of employee:  ";
   std::cin >> size;

   Employee* arrayOfEmployee = new Employee[size];
   for (int i = 0; i < size; ++i) {
       Initialization(arrayOfEmployee[i]);
       if (i != size - 1) {
           std::cout << "Do you wamt to continue? (1 - yes, 0 - no): ";
           int answer;
           scanf_s("%d", &answer);
           if (!answer)
               break;
       }
   }
   Employee* NewarrayOfEmployee;
   int countOfNew = 0;
   int numberOfOffice = 0;
   int sizeOfNewArr;
   int idOfEmpl = 0;
   int id = 0;
    int answer = 0;
    while (answer != 7) {
        printf_s("What do you want to do? \n \t Add new employee(1) \n\t Print all employees(2) \n\t Find employees with similar number of office and experience > 20(3) \n\t Delete employee(4) \n\t Change employee(5)\n\t Sort(6) \n\t  End all operation(7)\n");
        scanf_s("%d", &answer);
        switch (answer)
        {
        case 1: 
            countOfNew = 0;
            printf("Enter count of new elements: ");
            scanf_s("%d", &countOfNew);
            arrayOfEmployee = add(arrayOfEmployee, size, countOfNew);
            break;
        case 2:
            print(arrayOfEmployee, size);
            break;
        case 3:
            numberOfOffice = 0;
            sizeOfNewArr;
            printf("Enter numder of office: ");
            scanf_s("%d", &numberOfOffice);
            NewarrayOfEmployee = find(arrayOfEmployee, size, numberOfOffice, 20, sizeOfNewArr);
            print(NewarrayOfEmployee, sizeOfNewArr);
            break;
        case 4:
            idOfEmpl = 0;
            printf("Enter id of employee: ");
            scanf_s("%d", &idOfEmpl);
            arrayOfEmployee = deleteWith(arrayOfEmployee, size, idOfEmpl);
            break;
        case 5:
            id = 0;
            printf("Enter id of employee: ");
            scanf_s("%d", &id);
            arrayOfEmployee = Change(arrayOfEmployee, size, id);
            break;
        case 6:
            sort(arrayOfEmployee, size);
            break;

        default:
            answer = 7;
            break;
        }
    }
}

/*
    std::cout << "What you want to do?(0 - delete this element, 1 - change this element)";
    int answer;
    scanf_s("%d", answer);
    if (answer > 0) {

    }
    else {
*/