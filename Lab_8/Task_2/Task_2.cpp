// Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 2. Вариант 10
Разработать программу в соответствии с вариантом,
реализующую работу с файлами в консольном приложении.
Информация, обрабатываемая программой, должна храниться
в файле, результат работы занести в другой файл и отобразить на экране.
Использовать динамический массив структур, содержащий поля согласно
варианту индивидуального задания. Выделение памяти реализовать через
calloc.
Программа должна содержать необходимые комментарии.
Следует предусмотреть простейший вывод на экран входных и выходных
данных. В каждом варианте задания реализовать следующие функции
для работы со структурой: инициализации данных, добавления,
удаления, корректировки и просмотра записей файла.

10. Информация об участниках спортивных соревнований
содержит: наименование страны, название команды, Ф.И.О. игрока, игровой
номер, возраст, рост, вес. Вывести информацию о самой молодой команде.

*/

#include <iostream>
#include <fstream>
#define CLI_BUFFER_SIZE 100
int IdOfParticipant = 0;

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

struct Participant {
    int id;
    std::string country = "None";
    std::string nameOfteam = "None";
    std::string FIO = "None";
    int gameNumber = 0;
    int age = 0;
    int heigth = 0;
    int weigth = 0;
};

Participant* Participanti(Participant* arrayOfParticipant, int& size, int id, std::string country, std::string nameOfteam, std::string FIO, int gameNumber, int age, int heigth, int weigth) {
    Participant* NewarrayOfParticipant = (Participant*)calloc(size + 1, sizeof(Participant));
    new (NewarrayOfParticipant) Participant[size + 1]();
    for (int i = 0; i < size; ++i) {
        NewarrayOfParticipant[i] = arrayOfParticipant[i];
    }
    Participant temp = {id, country, nameOfteam, FIO, gameNumber, age, heigth, weigth};
    NewarrayOfParticipant[size] = temp;
    size += 1;
    return NewarrayOfParticipant;
}

void PrintStruct(Participant Participant) {
    std::ofstream fout;
    fout.open("cppstudio.txt", std::ios_base::app);
    fout << "Participant: " << Participant.id << "\n";
    fout << "Country: " << Participant.country << "\n";
    fout << "Team: " << Participant.nameOfteam << "\n";
    fout << "FIO: " << Participant.FIO << "\n";
    fout << "Number: " << Participant.gameNumber << "\n";
    fout << "Age: " << Participant.age << "\n";
    fout << "Heigth: " << Participant.heigth << "\n";
    fout << "Weigth: " << Participant.weigth << "\n";
    fout.close();

}

Participant Initialize(Participant &Participant) {
    Participant.id = ++IdOfParticipant;
    std::cout << "Enter country: ";
    Participant.country = stringInitialization();
    std::cout << std::endl;
    std::cout << "Enter name of team: ";
    Participant.nameOfteam = stringInitialization();
    std::cout << std::endl;
    std::cout << "Enter FIO: ";
    Participant.FIO = stringInitialization();
    std::cout << std::endl;
    std::cout << "Enter game Number: ";
    Participant.gameNumber = intInitialization();
    std::cout << std::endl;
    std::cout << "Enter age: ";
    Participant.age = intInitialization();
    std::cout << std::endl;
    std::cout << "Enter heigth: ";
    Participant.heigth = intInitialization();
    std::cout << std::endl;
    std::cout << "Enter weigth: ";
    Participant.weigth = intInitialization();
    std::cout << std::endl;
    PrintStruct(Participant);
    return Participant;
}

Participant* Add(Participant* arrayOfParticipant, int& size, int countOfNewEl) {
    Participant* NewarrayOfParticipant = (Participant*)calloc(size + countOfNewEl, sizeof(Participant));
    new (NewarrayOfParticipant) Participant[size + countOfNewEl]();
    for (int i = 0; i < size; ++i) {
        NewarrayOfParticipant[i] = arrayOfParticipant[i];
    }
    for (int i = size; i < size + countOfNewEl; ++i) {
        NewarrayOfParticipant[i] = Initialize(NewarrayOfParticipant[i]);
        
    }
    size += countOfNewEl;
    
    return NewarrayOfParticipant;
}

Participant* DeleteElement(Participant* arrayOfParticipant, int& size, int id) {
    
    Participant* NewarrayOfParticipant = (Participant*)calloc(size - 1, sizeof(Participant));
    new (NewarrayOfParticipant) Participant[size - 1]();
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arrayOfParticipant[i].id != id) {
            NewarrayOfParticipant[count] = arrayOfParticipant[i];
            NewarrayOfParticipant[count].id = count + 1;
            ++count;
        }
    }
    size -= 1;
    std::ofstream ofs;
    ofs.open("cppstudio.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    for(int i = 0; i < size; ++i){
        PrintStruct(NewarrayOfParticipant[i]);
    }
    return NewarrayOfParticipant;
}

Participant* Change(Participant* arrayOfParticipant, int& size, int id) {
    for (int i = 0; i < size; ++i) {
        if (arrayOfParticipant[i].id == id) {
            int answer;
            std::cout << "What field you want to change?(1 - country, 2 - nameOfteam, 3 - FIO, 4 - gameNumber, 5 - age, 6 - heigth, 7 - weigth)";
            answer = intInitialization();
            switch (answer)
            {
            case 1:
                arrayOfParticipant[i].country = stringInitialization();
                break;
            case 2:
                arrayOfParticipant[i].nameOfteam = stringInitialization();
                break;
            case 3:
                arrayOfParticipant[i].FIO = stringInitialization();
                break;
            case 4:
                arrayOfParticipant[i].gameNumber = intInitialization();
                break;
            case 5:
                arrayOfParticipant[i].age = intInitialization();
                break;
            case 6:
                arrayOfParticipant[i].heigth = intInitialization();
                break;
            case 7:
                arrayOfParticipant[i].weigth = intInitialization();
                break;
            default:
                break;
            }
            std::ofstream ofs;
            ofs.open("cppstudio.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            for (int i = 0; i < size; ++i) {
                PrintStruct(arrayOfParticipant[i]);
            }
        }
    }
    return arrayOfParticipant;
}

double Avg(double sum, int count) {
    return sum / count;
}

std::string find(Participant* arrayOfParticipant, int size ) {
    std::string name;
    std::string nameOfteam;
    double sum = 0;
    int count = 0;
    double min = 300;
    for (int i = 0; i < size; ++i) {
        nameOfteam = arrayOfParticipant[i].nameOfteam;
        sum = 0;
        count = 0;
        for (int j = 0; j < size; ++j) {
            if (nameOfteam.compare(arrayOfParticipant[j].nameOfteam) == 0) {
                sum += arrayOfParticipant[j].age;
                ++count;
            }
        }
        sum = Avg(sum, count);
        if (sum < min) {
            min = sum;
            name = nameOfteam;
        }
    }
    return name;
}

void PrintRez(Participant Participant) {
    std::ofstream fout;
    fout.open("Rez.txt", std::ios_base::app);
    fout << "Participant: " << Participant.id << "\n";
    fout << "Country: " << Participant.country << "\n";
    fout << "Team: " << Participant.nameOfteam << "\n";
    fout << "FIO: " << Participant.FIO << "\n";
    fout << "Number: " << Participant.gameNumber << "\n";
    fout << "Age: " << Participant.age << "\n";
    fout << "Heigth: " << Participant.heigth << "\n";
    fout << "Weigth: " << Participant.weigth << "\n";
    fout.close();
}

void printRezOdFind(Participant* arrayOfParticipant, int size) {
    std::ofstream ofs;
    ofs.open("Rez.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    std::string name = find(arrayOfParticipant, size);
    for (int i = 0; i < size; ++i) {
        if(name.compare(arrayOfParticipant[i].nameOfteam) == 0){
            PrintRez(arrayOfParticipant[i]);
        }
    }
}

void PrintInfoFromFile() {
    int size = 0;
    Participant* printarrayOfParticipant = (Participant*)calloc(size, sizeof(Participant));
    new (printarrayOfParticipant) Participant[size]();
    std::string add;
    int id; std::string country; std::string nameOfteam; std::string FIO; std::string gameNumber, age, heigth, weigth;
    std::ifstream in;
    in.open("cppstudio.txt");
    if (in.is_open())
    {
        while (in >> add >> id >> add >> country >> add >> nameOfteam >> add >> FIO >> add >> gameNumber >> add >> age >> add >> heigth >> add >> weigth)
        {
            printarrayOfParticipant = Participanti(printarrayOfParticipant, size, id, country, nameOfteam, FIO, atoi(gameNumber.c_str()), atoi(age.c_str()), atoi(heigth.c_str()), atoi(weigth.c_str()));
        }
    }
    in.close();
    for (int i = 0; i < size; ++i) {
        std::cout << "Participant: " << printarrayOfParticipant[i].id << "\n";
        std::cout << "Country: " << printarrayOfParticipant[i].country << "\n";
        std::cout << "Team: " << printarrayOfParticipant[i].nameOfteam << "\n";
        std::cout << "FIO: " << printarrayOfParticipant[i].FIO << "\n";
        std::cout << "Number: " << printarrayOfParticipant[i].gameNumber << "\n";
        std::cout << "Age: " << printarrayOfParticipant[i].age << "\n";
        std::cout << "Heigth: " << printarrayOfParticipant[i].heigth << "\n";
        std::cout << "Weigth: " << printarrayOfParticipant[i].weigth << "\n";
    }
}

int main(int argc, char* argv[])
{
    int size = 0;
    Participant* arrayOfParticipant = (Participant*)calloc(size, sizeof(Participant));
    new (arrayOfParticipant) Participant[size]();
    std::string add;
    int id; std::string country; std::string nameOfteam; std::string FIO; std::string gameNumber, age, heigth, weigth;
    std::ifstream in;
    in.open("cppstudio.txt");
    if (in.is_open())
    {
        while (in >> add >> id >> add >> country >> add >> nameOfteam >> add >> FIO >> add >> gameNumber >> add >> age >> add >> heigth >> add >> weigth)
        {
            arrayOfParticipant = Participanti(arrayOfParticipant, size, id, country, nameOfteam, FIO, atoi(gameNumber.c_str()), atoi(age.c_str()), atoi(heigth.c_str()), atoi(weigth.c_str()));
        }
    }
    in.close();
    IdOfParticipant = arrayOfParticipant[size - 1].id;
    
    if (size == 0) {
        int newEl;
        std::cout << " Enter count of Participant:  ";
        std::cin >> newEl;
        arrayOfParticipant = Add(arrayOfParticipant, size, newEl);
    }
    int answer = 0;
    while (answer < 4) {
        int newEl = 0;
        int deleteId = 0;
        int changeId = 0;
        std::cout << "What do you want to do?(1 - add, 2 - delete, 3 - change, 4 - show info)";
        scanf_s("%d", &answer);
        switch (answer)
        {
        case 1:
            std::cout << " Enter count of Participant:  ";
            std::cin >> newEl;
            arrayOfParticipant = Add(arrayOfParticipant, size, newEl);
            break;
        case 2:
            std::cout << "Enter id to delete participant: ";
            scanf_s("%d", &deleteId);
            arrayOfParticipant = DeleteElement(arrayOfParticipant, size, deleteId);
            break;
        case 3:
            std::cout << "Enter id to change participant: ";
            scanf_s("%d", &changeId);
            arrayOfParticipant = Change(arrayOfParticipant, size, changeId);
            break;
        case 4:
            PrintInfoFromFile();
            break;
        default:
            answer = 5;
            break;
        }
    }

    system("pause");
    return 0;
}
/*
std::ifstream in("D:\\operations.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (in >> sum >> rate)
        {
            new_operations.push_back(Operation(sum, rate));
        }
    }
    in.close();
*/

/*for (int i = 0; i < size; ++i) {

        PrintStruct(arrayOfParticipant[i]);
   }
    std::fstream inOut;
    inOut.open("file.txt", std::ios::out);
    inOut << (char*)&arrayOfParticipant[1] << std::endl;
    inOut.seekp(8, std::ios::beg);
    inOut << "еще строчка текста";
    inOut.close();*/
    //printRezOdFind(arrayOfParticipant, size);
 // std::cout << " Enter count of Participant:  ";
    //std::cin >> size;
   // for (int i = 0; i < size; ++i) {
     //   Initialize(arrayOfParticipant[i]);
//  std::ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
   // fout << "cf"; // запись строки в файл
   // fout.close(); // закрываем файл
/*
Participant: 1  
Country: gb
Team: jyh
FIO: myntbg
Number: 54
Age: 56
Heigth: 356
Weigth: 63
Participant: 2
Country: cf
Team: jhg
FIO: cyhg
Number: 7
Age: 435
Heigth: 56
Weigth: 43
Participant: 3
Country: fytu
Team: vbgf
FIO: hbuy
Number: 87
Age: 68
Heigth: 4
Weigth: 7
*/