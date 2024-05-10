#include "gtest/gtest.h"
#include "catalogue.hpp"

//
// Created by Iskra on 05.04.2024.
//
TEST(ProductTest, create){
    Product p("id", "name", 0);
    EXPECT_EQ(p.get_price(), 0);
    EXPECT_EQ(p.get_id(), "id");
    EXPECT_EQ(p.get_name(), "name");
}
TEST(ProductTest, toString){
    Product p("id2", "name2", 2);
    EXPECT_EQ(to_string(p), "name2 [id2] : $2");
}
