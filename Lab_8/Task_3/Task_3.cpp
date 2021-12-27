// Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 3. Реализовать любой из 30 вариантов (кроме уже реализованных вами)
заданий используя классы. Реализовать корректировку записей внутри файла без
полной перезаписи файла. Все методы класса должны иметь модификатор public,
а остальные поля – private;
Вариант 2
В радиоателье хранятся квитанции о сданной в ремонт
радиоаппаратуре. Каждая квитанция содержит следующую информацию:
наименование группы изделий(телевизор, радиоприемник и т. п.),марку
изделия, дату приемки в ремонт, состояние готовности заказа (выполнен, не
выполнен). Вывести информацию о состоянии заказов на текущие сутки по
группам изделий.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
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

class radio {
private:
	std::string name;
	std::string brand;
	std::string date;
	int price;
	bool ready;
public:
    radio(std::string name, std::string brand, std::string date, int price, bool ready) {
        this->name = name;
        this->brand = brand;
        this->date = date;
        this->price = price;
        this->ready = ready;

    }
    radio() {
        this->name = "None";
        this->brand = "None";
        this->date = "None";
        this->price = 0;
        this->ready = 0;
    }
    void EnterClass(radio*& radio, int count) {
        std::string path = "file.txt";
        std::ofstream fout;
        fout.open(path, std::ios_base::app);
  
            
            printf_s("%s", "\nEnter the name: ");
            std::cin >> radio[count - 1].name;
            fout << radio[count - 1].name.c_str() << "\n";
            printf_s("%s", "Enter the brand: ");
            std::cin >> radio[count - 1].brand;
            fout << radio[count - 1].brand << "\n";
            printf_s("%s", "Enter the delivery date: ");
            std::cin >> radio[count - 1].date;
            fout << radio[count - 1].date << "\n";
            printf_s("%s", "Enter price: ");
            std::cin >> radio[count - 1].price;
            fout << radio[count - 1].price << "\n";
            printf_s("%s", "Is it ready?(0 - no/1 - yes): ");
            std::cin >> radio[count - 1].ready;
            fout << radio[count - 1].ready << "\n";
            
        
    }

    radio* Add(radio*& arrayOfradio, int& size, int countOfNewEl) {
        radio* NewarrayOfradio = new radio[size + countOfNewEl];
        for (int i = 0; i < size; ++i) {
            NewarrayOfradio[i] = arrayOfradio[i];
        }
        for (int i = size; i < size + countOfNewEl; ++i) {
            NewarrayOfradio[i].EnterClass(NewarrayOfradio, i);

        }
        size += countOfNewEl;
        arrayOfradio = new radio[size];
        for (int i = 0; i < size; ++i) {
            arrayOfradio[i] = NewarrayOfradio[i];
        }
        return NewarrayOfradio;
    }

    int SumByte(radio*& radio, int i) {
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += radio[j].name.size();
            sum += radio[j].brand.size();
            sum += radio[j].date.size();
            sum += sizeof(radio[j].price);
            sum += sizeof(radio[j].ready);
            sum += 10;
        }
        return sum;
    }

    radio* DeleteElement(radio* arrayOfradio, int& size, int id) {
        std::ofstream fout;
        fout.open("file.txt", std::ios::in | std::ios::out | std::ios::binary);
        
        int byte = SumByte(arrayOfradio, id);
        std::filesystem::resize_file("file.txt", byte);
        fout.seekp(byte, std::ios_base::cur);
        for (size_t i = id; i < size - 1; ++i) {
            
                fout << arrayOfradio[i].name << '\n';
                fout << arrayOfradio[i].brand << '\n';
                fout << arrayOfradio[i].date << '\n';
                fout << arrayOfradio[i].price << '\n';
                fout << arrayOfradio[i].ready << '\n';
            
        }
        radio* NewarrayOfradio = new radio[size - 1];
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (i != id) {
                NewarrayOfradio[count] = arrayOfradio[i];
                ++count;
            }
        }
        size -= 1;
        return NewarrayOfradio;
    }

    void Change(radio* arrayOfradio, int& size, int id) {
        std::string path = "file.txt";
        std::ofstream fout;
        fout.open(path, std::ios::in | std::ios::out | std::ios::binary);
        int byte;
        byte = SumByte(arrayOfradio, id);
        for (int i = 0; i < size; ++i) {
            if (i == id) {
                 
                int answer;
                std::cout << "What field you want to change?(1 - name, 2 - brand, 3 - date, 4 - price, 5 - ready)";
                answer = intInitialization();
                switch (answer)
                {
                case 1:
                    arrayOfradio[i].name = stringInitialization();
                    break;
                case 2:
                    arrayOfradio[i].brand = stringInitialization();
                    break;
                case 3:
                    arrayOfradio[i].date = intInitialization();
                    break;
                case 4:
                    arrayOfradio[i].price = intInitialization();
                    break;
                case 5:
                    arrayOfradio[i].ready = intInitialization();
                    break;
                default:
                    break;
                }
                
            }
        }
       
       // std::filesystem::resize_file("file.txt", byte);
        fout.seekp(byte, std::ios_base::beg);
        for (size_t i = id; i < size; ++i)
        {
            fout << arrayOfradio[i].name << '\n';
            fout << arrayOfradio[i].brand << '\n';
            fout << arrayOfradio[i].date << '\n';
            fout << arrayOfradio[i].price << '\n';
            fout << arrayOfradio[i].ready << '\n';
        }
    }

    radio* radios(radio* printarrayOfradio,int& size, std::string name, std::string brand, std::string date, int price, bool ready) {
        radio* newprintarrayOfradio = new radio[size + 1];
        for (int i = 0; i < size; ++i) {
            newprintarrayOfradio[i] = printarrayOfradio[i];
        }
        radio temp = { name, brand, date, price, ready};
        newprintarrayOfradio[size] = temp;
        size += 1;
        return newprintarrayOfradio;
    }
    void PrintInfoFromFile() {
        int size = 0;
        radio* printarrayOfradio = new radio[size];
        std::string add;
        std::string name; std::string brand; std::string date, price, ready;
        std::ifstream in;
        in.open("file.txt");
        if (in.is_open())
        {
            while (in >> name >> brand >> date >> price >> ready )
            {
                printarrayOfradio = radios(printarrayOfradio, size, name, brand, date, atoi(price.c_str()), atoi(ready.c_str()));
            }
        }
        in.close();
        for (int i = 0; i < size; ++i) {
            std::cout << "Name: " << printarrayOfradio[i].name << "\n";
            std::cout << "Brand: " << printarrayOfradio[i].brand << "\n";
            std::cout << "Date: " << printarrayOfradio[i].date << "\n";
            std::cout << "Price: " << printarrayOfradio[i].price << "\n";
            std::cout << "Ready: " << printarrayOfradio[i].ready << "\n";
            
        }
    }
};

int main()
{
    setlocale(0, "");
    int size = 1;
    radio* arrayOfradio = new radio[size];
    /*std::string name; std::string brand; std::string date, price, ready;
    std::ifstream in;
    in.open("file.txt");
    if (in.is_open())
    {
        while (in >> name >> brand >> date >> price >> ready)
        {
            arrayOfradio = radios(arrayOfradio, size, name, brand, date, atoi(price.c_str()), atoi(ready.c_str()));
        }
    }
    in.close();*/
    if (size == 1) {
        arrayOfradio[0].EnterClass(arrayOfradio, 1);
    }
    int answer = 0;
    while (answer <= 4) {
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
            arrayOfradio[0].Add(arrayOfradio, size, newEl);
            break;
        case 2:
            std::cout << "Enter id to delete participant: ";
            scanf_s("%d", &deleteId);
            arrayOfradio[0].DeleteElement(arrayOfradio, size, deleteId);
            break;
        case 3:
            std::cout << "Enter id to change participant: ";
            scanf_s("%d", &changeId);
            arrayOfradio[0].Change(arrayOfradio, size, changeId);
            break;
        case 4:
            arrayOfradio[0].PrintInfoFromFile();
            break;
        default:
            answer = 5;
            break;
        }
    }

    system("pause");
    return 0;;
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
