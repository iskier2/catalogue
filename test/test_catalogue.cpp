//
// Created by Iskra on 05.04.2024.
//
#include "gtest/gtest.h"
#include "catalogue.hpp"

TEST(CatalogueTest, containsKeyIsNotPresent){
    Catalogue c({});
    EXPECT_EQ(c.contains("p1"), false);
}
TEST(CatalogueTest, containsKeyIsPresent){
    Product p1("p1", "prod1", 0);
    std::map<std::string, Product> m;
    m.emplace("p1", p1);
    Catalogue c(m);
    Product p2("p2", "prod2", 2);
    c.add_product(p2);
    EXPECT_EQ(c.contains("p1"), true);
    EXPECT_EQ(c.contains("p2"), true);
}
TEST(CatalogueTest, getProductsWithAppropriatePrice) {
    Product p1("X1", "Toy X1", 10.3);
    Product p2("X2", "Toy X2", 8.3);

    Catalogue catalogue(Catalogue::inventory_t{
            {p1.get_id(), p1},
            {p2.get_id(), p2},
    });

    std::function<bool (double)> predicate = [](double price) {
        return (price < 10.0);
    };
    auto filtered_products = catalogue.get_products_with_appropriate_price(predicate);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].get_id(), p2.get_id());
}