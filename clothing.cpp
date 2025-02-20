#include <sstream>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string cateogry, const std::string name, double price, int qty, std::string size, std::string brand) : Product("clothing", name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing(){

}

std::set<std::string> Clothing::keywords() const {
    set<string> name_keywords = parseStringToWords(name_);
    set<string> brand_keywords = parseStringToWords(brand_);

    set<string> all_keywords = setUnion(name_keywords, brand_keywords);




    return all_keywords;
}

std::string Clothing::displayString() const{

    stringstream s;
    s << name_ << endl;
    s << "Size: " << size_ << " Brand: " << brand_ << endl;
    s << price_ << " " << qty_ << " left.";

    return s.str();
}
//fix this
void Clothing::dump(std::ostream& os) const{
    os << "clothing" << '\n' << name_ << '\n' << price_ << '\n' << qty_ << '\n' << size_ << '\n' << brand_ << endl;
}

