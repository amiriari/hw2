#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include "mydatastore.h"
#include "product.h"

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
    for (unsigned int i = 0; i < products_.size(); i++)
        delete products_[i];

    for(std::map<std::string, User*>::iterator it = user_map_.begin(); it != user_map_.end(); it++)
        delete it->second;
}

void MyDataStore::addProduct(Product* p){
    set<string> keywords = p->keywords();
    for (std::set<string>::iterator it = keywords.begin(); it != keywords.end(); it++){
        if(product_map_.find(*it) != product_map_.end())
            product_map_[*it].insert(p);
        
        else{
            set<Product*> null;
            product_map_[*it] = null;
            product_map_[*it].insert(p);
        }
    }
    products_.push_back(p);
}

void MyDataStore::addUser(User* u){
    user_map_[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::set<Product*> temp;
    vector<Product*> empty;

    vector<Product*> result;
    if (type == 0){
        for (unsigned int i = 0; i < terms.size(); i++){
            if (i == 0)
                temp = product_map_[terms[0]];
                
            if(product_map_.find(terms[i]) != product_map_.end())
                temp = setIntersection(temp,product_map_[terms[i]]);
            
            else 
                return empty;
        }    
    }
    if (type == 1){
        for (unsigned int i = 0; i < terms.size(); i++){
            if(product_map_.find(terms[i]) != product_map_.end()){
                if (temp.empty())
                    temp = product_map_[terms[i]];

                temp = setUnion(temp,product_map_[terms[i]]);
            }        
        }
    }

    
    for (std::set<Product*>::iterator it = temp.begin(); it != temp.end(); ++it)
        result.push_back(*it);
    
    return result;

}

void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << endl;
    for(unsigned int i=0; i<products_.size(); i++)
        products_[i] -> dump(ofile);

    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    
    for(std::map<std::string, User*>::iterator it = user_map_.begin(); it != user_map_.end(); it++)
       (it->second) -> dump(ofile);
    
    ofile << "</users>" << endl;
}

void MyDataStore::addToCart(std::string username, Product* target){
    if(user_map_.find(username) == user_map_.end()){
        cout << "Invalid request" << endl;
    }
    else{
        if (cart_.find(username) != cart_.end())
            cart_[username].push_back(target);
        else{
            vector<Product*> user_products;
            user_products.push_back(target);
            cart_[username] = user_products;
        }
    }

}


void MyDataStore::viewCart(std::string username){
    if(user_map_.find(username) == user_map_.end()){
        cout << "Invalid username" << endl;
    }
    else{
        vector<Product*> cart = cart_[username];
        for(unsigned int i=0; i<cart.size(); i++){
            cout << "Item " << i+1 << endl;
            cout << cart[i] -> displayString() << endl;
        }
    }
}

void MyDataStore::buyCart(std::string username){
    if(user_map_.find(username) == user_map_.end())
        cout << "Invalid username" << endl;
    
    else{
        vector<Product*> cart = cart_[username];
        vector<Product*> update;
        User* curr_user = user_map_[username];

        for(unsigned int i=0; i<cart.size(); i++){
            if(curr_user->getBalance() >= cart[i]->getPrice() && cart[i]->getQty()>0){
                cart[i]->subtractQty(1);
                curr_user->deductAmount(cart[i]->getPrice());
            }
            else
                update.push_back(cart[i]);
        }
        cart_[username] = update;
    }
}