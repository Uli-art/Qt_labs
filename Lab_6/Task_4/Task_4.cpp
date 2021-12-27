// Task_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 4.
1 апреля 20?? года будет проведена реформа английского языка,
позволяющая облегчить его освоение иностранцами и английскими
школьниками. Во-первых, из алфавита уберут четыре буквы 
C, Q, W и X (наклавиатуре компьютера вместо них будут клавиши, вызывающие программы
Word, eXcel и другие).
C:
Вместо C перед буквами e, i, y нужно будет писать букву s, а в остальных случаях – букву k. 
Q:
Вместо буквы q нужно будет писать букву k,
вместо сочетания qu – kv,
X:
вместо x – ks,
W:
вместо w – v. 
Во-вторых, 
сочетание букв ph будет записываться как f, 
you и oo – как u,
ee – как i,
th – как z.
Кроме того, все двойные согласные (включая образовавшиеся после замен)
Входные данные
Во входном файле содержится текст на английском языке, без
переносов слов. Длина строк не превышает 100 символов.
Выходные данные
В выходной файл вывести тот же текст, но уже соответствующий
реформе. Если первая буква заменяемого сочетания букв была прописной,
то первая буква замены должна быть также прописной. Вторая буква в
заменах x?ks, qu?kv должна быть всегда строчной.
Входные данные
Too swift for Theex, too quick for Gallow,
Too strong for young Prince Joseph to follow.
Выходные данные
Tu svift for Ziks, tu kvik for Galov,
Tu strong for ung Prinse Josef to folov.y
*/

#include <iostream>
#include <string>



bool RecurringEl(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == str[i + 1]) {
            return true;
        }
    }
    return false;
}

void DeleteRecurringEl(std::string& str) {
    while (RecurringEl(str)) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == str[i + 1]) {
                str.erase(i, 1);
            }
        }
    }
}

void Replace(std::string& str) {
    for (int i = 0; i < str.length(); ++i) {

        if (str[i] == 'c' || str[i] == 'C') {
            if (str[i + 1] == 'e' || str[i + 1] == 'i') {
                if (str[i] == 'C') {
                    str[i] = 'S';
                }
                else {
                    str[i] = 's';
                }
            }
            else {
                if (str[i] == 'C') {
                    str[i] = 'K';
                }
                else {
                    str[i] = 'k';
                }
            }
        }

        if (str[i] == 'q' || str[i] == 'Q') {
            if (str[i] == 'Q') {
                str[i] = 'K';
            }
            else {
                str[i] = 'k';
            }
            if (str[i + 1] == 'u') {
                str[i + 1] = 'v';
            }
        }

        if (str[i] == 'x' || str[i] == 'X') {
            if (str[i] == 'X') {
                str.replace(i, 1, "Ks");
            }
            else {
                str.replace(i, 1, "ks");
            }

        }

        if (str[i] == 'w' || str[i] == 'W') {
            if (str[i] == 'W') {
                str[i] = 'V';
            }
            else {
                str[i] = 'v';
            }
        }

        if (str[i] == 'p' || str[i] == 'P') {
            if (str[i + 1] == 'h') {

                if (str[i] == 'P') {
                    str.replace(i, 2, "F");
                }
                else {
                    str.replace(i, 2, "f");
                }
            }
        }

        if (str[i] == 'y' || str[i] == 'Y') {
            if (str[i + 1] == 'o') {
                if (str[i + 2] == 'u') {
                    if (str[i] == 'Y') {
                        str.replace(i, 3, "U");
                    }
                    else {
                        str.replace(i, 3, "u");
                    }
                }

            }
        }

        if (str[i] == 'o' || str[i] == 'O') {
            if (str[i + 1] == 'o') {
                if (str[i] == 'O') {
                    str.replace(i, 2, "u");
                }
                else {
                    str.replace(i, 2, "u");
                }

            }
        }

        if (str[i] == 'e' || str[i] == 'E') {
            if (str[i + 1] == 'e') {
                if (str[i] == 'E') {
                    str.replace(i, 2, "I");
                }
                else {
                    str.replace(i, 2, "i");
                }

            }
        }

        if (str[i] == 't' || str[i] == 'T') {
            if (str[i + 1] == 'h') {
                if (str[i] == 'T') {
                    str.replace(i, 2, "Z");
                }
                else {
                    str.replace(i, 2, "z");
                }

            }
        }
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
