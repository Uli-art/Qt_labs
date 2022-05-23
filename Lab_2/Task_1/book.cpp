#include "book.h"

Book::Book()
{

}

Book::Book(QString registrationNumber,
               QString author,
               QString title,
               int year,
               QString publisher,
               int pages) : registrationNumber(registrationNumber),author(author),title(title),year(year),publisher(publisher),pages(pages)
{
}

void Book::operator =(Book anotherBook){
    this->registrationNumber = anotherBook.registrationNumber;
    this->author = anotherBook.author;
    this->title = anotherBook.title;
    this->year = anotherBook.year;
    this->publisher = anotherBook.publisher;
    this->pages = anotherBook.pages;
}

QString Book::getRegistrationNumber(){
    return registrationNumber;
}
QString Book::getAuthor(){
    return author;
}
QString Book::getTitle(){
    return title;
}
int Book::getYear(){
    return year;
}
QString Book::getPublisher(){
    return publisher;
}
int Book::getPages(){
    return pages;
}
