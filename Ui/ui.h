#pragma once
#include "C:/Users/Home/CLionProjects/lab9-10\/Service/service.h"
#include "C:/Users/Home/CLionProjects/lab9-10/Domain/product.h"
class Ui {
private:
    Service* x;
    static double addMoney(const Product& product);
    static void showMenu();
    void console(char& option);
    void showAllProducts();
    void updateProduct();
    void deleteProduct();
    void buyProduct();

public:
    Ui(Service* service);
    ~Ui();
    void run();
};