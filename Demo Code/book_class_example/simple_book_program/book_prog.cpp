#include <iostream>
using namespace std;

struct book{
    string title;
    string author;
    int pages;
};

void print_book_info(book* bk) {
	cout << "Title is: " << (*bk).title << endl;
	cout << "It has " << bk->pages << " pages" << endl;
	cout << "The author is: " << bk->author << endl;
    cout << endl;
}

class Book{
public:
    string title;
    string author;
    int pages;

    void print_info();

};


void Book::print_info(){
    cout << title << endl;
    cout << author << endl;
    cout << pages << endl;
}

int main(){

    book b1;
    b1.title = "Goodnight Moon";
    Book b2;
    b2.title = "7 Ways to Learn a Foreign Language";
    print_book_info(&b1);
    b2.print_info();

    return 0;
}