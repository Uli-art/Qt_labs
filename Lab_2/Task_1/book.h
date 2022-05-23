#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
private:
    QString registrationNumber;
    QString author;
    QString title;
    int year;
    QString publisher;
    int pages;
public:
    Book();
    Book(QString registrationNumber,
        QString author,
        QString title,
        int year,
        QString publisher,
        int pages
    );
    void operator = (Book anotherBook);
    QString getRegistrationNumber();
    QString getAuthor();
    QString getTitle();
    int getYear();
    QString getPublisher();
    int getPages();
};


#endif // BOOK_H
