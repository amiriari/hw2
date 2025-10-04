#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <map>
#include "datastore.h"
#include "util.h"

class MyDataStore : public DataStore{
    public:
        MyDataStore();

        ~MyDataStore();

        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);

        void addToCart(std::string username, Product* target);

        void viewCart(std::string username);

        void buyCart(std::string username);
    
    private:
        std::map<std::string, User*> user_map_;
        std::map<std::string, std::set<Product*>> product_map_;
        std::map<std::string,std::vector<Product*>> cart_;
        std::vector<Product*> products_;

};
#endif