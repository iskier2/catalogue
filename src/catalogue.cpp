//
// Created by Iskra on 05.04.2024.
//
#include <sstream>
#include "catalogue.hpp"
std::string to_string(const Product& p){
    std::ostringstream stream;
    stream << p.get_name() << " [" << p.get_id() << "] : $" << p.get_price();
    return stream.str();
}

std::vector<Product> Catalogue::get_products_with_appropriate_price( std::function<bool(double)> priceValidation) {
    std::vector<Product> res;
    for(const auto& product : inventory_)
        if(priceValidation(product.second.get_price()))
            res.push_back(product.second);
    return res;
}
