#include <sstream>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, std::string genre, std::string rating)
    : Product("movie", name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}


Movie::~Movie(){

}

std::set<std::string> Movie::keywords() const {
    set<string> name_keywords = parseStringToWords(name_);
    set<string> genre_keywords = parseStringToWords(genre_);

    set<string> all_keywords = setUnion(name_keywords, genre_keywords);
    return all_keywords;
}

std::string Movie::displayString() const{
    stringstream s;
    s << name_ << endl;
    s << "Genre: " << genre_ << " Rating: " << rating_ << endl;
    s << price_ << " " << qty_ << " left.";

    return s.str();
}
//debug this
void Movie::dump(std::ostream& os) const{
    os << "movie" << '\n' << name_ << '\n' << price_ << '\n' << qty_ << '\n' << genre_ << '\n' << rating_ << endl;
}