#include <sstream>
#include "book.h"
#include "util.h"

using namespace std;
Book::Book(const std::string cateogry, const std::string name, double price, int qty, std::string ISBN, std::string author) : Product("book", name, price, qty)
{
    ISBN_ = ISBN;
    author_ = author;
}

Book::~Book(){

}

std::set<std::string> Book::keywords() const {
    set<string> name_keywords = parseStringToWords(name_);
    set<string> author_keywords = parseStringToWords(author_);

    set<string> all_keywords = setUnion(name_keywords, author_keywords);

    all_keywords.insert(ISBN_);
    return all_keywords;
}

std::string Book::displayString() const{
    stringstream ss;
    ss << name_ << endl;
    ss << "Author: " << author_ << " ISBN: " << ISBN_ << endl;
    ss << price_ << " " << qty_ << " left.";
    
    return ss.str();
}

void Book::dump(std::ostream& os) const{
    os << "book" << '\n' << name_ << '\n' << price_ << '\n' << qty_ << '\n' << ISBN_ << '\n'<< author_ << endl;
}