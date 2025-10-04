#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <set>
#include <string>

class Movie : public Product {
public:
    Movie(std::string name, double price, int qty, std::string genre, std::string rating);
    ~Movie() override; 
    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

private:



    std::string genre_;
    std::string rating_;
};

#endif