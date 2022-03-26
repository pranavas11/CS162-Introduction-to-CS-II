#include <iostream>
using namespace std;

struct book {          // member variables are public by default
      string title;
      string author;
      int pages;
};

void print_book_info(book* bk) {
      cout << "\nTitle is: " << (*bk).title << endl;
      cout << "It has " << bk->pages << " pages" << endl;
      cout << "The author is: " << bk->author << endl;
}

class Book {
  public:
      // class member variables
      string title;
      string author;
      int pages;
      
      // class member function
      void print_info();
};

void Book::print_info() {
      cout << "\nTitle: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "Number of pages: " << pages << endl << endl << endl;
}

int main() {
      // uses struct info
      book b1;
      b1.title = "Goodnight Moon";
      b1.author = "Margaret Wise Brown";
      b1.pages = 33;
      print_book_info(&b1);
      
      // uses class info
      Book b2;
      b2.title = "The Great Gatsby";
      b2.author = "F. Scott Fitzgerald";
      b2.pages = 200;
      b2.print_info();
      
      return 0;
}