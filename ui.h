#pragma once
#include "Service.h"
class Ui {
private:
    Service x;
public:
    Ui(Service service);
    ~Ui();

    void showAllProducts();
    void showMenu();
    void console(char& option);
    void buyProduct();
    void run();
};