#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
    char* data;
    int size;
public:
    MyString();
    MyString(MyString& other);
    ~MyString();

    MyString& operator =(MyString& other);
};

#endif // MYSTRING_H
