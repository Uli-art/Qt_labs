// Task_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
������� 4.
1 ������ 20?? ���� ����� ��������� ������� ����������� �����,
����������� ��������� ��� �������� ������������ � �����������
�����������. ��-������, �� �������� ������ ������ ����� 
C, Q, W � X (������������ ���������� ������ ��� ����� �������, ���������� ���������
Word, eXcel � ������).
C:
������ C ����� ������� e, i, y ����� ����� ������ ����� s, � � ��������� ������� � ����� k. 
Q:
������ ����� q ����� ����� ������ ����� k,
������ ��������� qu � kv,
X:
������ x � ks,
W:
������ w � v. 
��-������, 
��������� ���� ph ����� ������������ ��� f, 
you � oo � ��� u,
ee � ��� i,
th � ��� z.
����� ����, ��� ������� ��������� (������� �������������� ����� �����)
������� ������
�� ������� ����� ���������� ����� �� ���������� �����, ���
��������� ����. ����� ����� �� ��������� 100 ��������.
�������� ������
� �������� ���� ������� ��� �� �����, �� ��� ���������������
�������. ���� ������ ����� ����������� ��������� ���� ���� ���������,
�� ������ ����� ������ ������ ���� ����� ���������. ������ ����� �
������� x?ks, qu?kv ������ ���� ������ ��������.
������� ������
Too swift for Theex, too quick for Gallow,
Too strong for young Prince Joseph to follow.
�������� ������
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
