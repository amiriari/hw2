#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product {
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author);
        ~Book();
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    private:
        std::string ISBN_;
        std::string author_;
};

#endif
