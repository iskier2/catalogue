//
// Created by Iskra on 05.04.2024.
//

#ifndef CATALOGUE_1_CATALOGUE_HPP
#define CATALOGUE_1_CATALOGUE_HPP

#include <string>
#include <map>
#include <vector>
#include <functional>

class Product {
private:
    std::string id_;
    std::string name_;
    double price_;
public:
    Product(const std::string& id, const std::string& name, const double& price) : id_(id), name_(name), price_(price){};
    std::string get_id() const {return id_;};
    std::string get_name() const {return name_;};
    double get_price() const {return price_;};

};

std::string to_string(const Product& p);

class Catalogue{
public:
    using inventory_t = std::map<std::string, Product>;
    Catalogue(inventory_t inventory) : inventory_(inventory){};
    void add_product(Product p){inventory_.emplace(p.get_id(), p);};
    bool contains(const std::string& id){return inventory_.count(id);};
    std::vector<Product> get_products_with_appropriate_price( std::function<bool(double)> price);
private:
    inventory_t inventory_;
};
#endif //CATALOGUE_1_CATALOGUE_HPP
