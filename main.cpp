#pragma once
#include"tests.h"
#include"file_repository.h"
#include"ui.h"
#include"product.h"
int main()
{
    //tests();
    FileRepository<Product> product("C:/Users/Home/CLionProjects/lab9-10/product.txt");
    FileRepository<Money>money("C:/Users/Home/CLionProjects/lab9-10/money.txt");
    Service service(product,money);
    Ui y(service);
    y.run();

}