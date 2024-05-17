#pragma once
#include"C:\Users\Home\CLionProjects\lab9-10\Tests\tests.h"
#include"C:\Users\Home\CLionProjects\lab9-10\Repository\file_repository.h"
#include "C:\Users\Home\CLionProjects\lab9-10\Ui\ui.h"
#include"C:\Users\Home\CLionProjects\lab9-10\Domain\product.h"
#include "C:\Users\Home\CLionProjects\lab9-10\Domain\money.h"
#include "C:\Users\Home\CLionProjects\lab9-10\Service\service.h"
#include"C:\Users\Home\CLionProjects\lab9-10\Repository\file_repository.h"

int main()
{
    //tests();
    Repository<Money>* money = new Repository<Money>();
    Repository<Product>* product = new Repository<Product>();
    FileRepository<Product>* fproduct = new FileRepository<Product>("C:/Users/Home/CLionProjects/lab9-10/Domain/product.txt");
    FileRepository<Money>* fmoney = new FileRepository<Money>("C:/Users/Home/CLionProjects/lab9-10/Domain/money.txt");
    Service * service = new Service(fproduct, fmoney);
    Ui y(service);
    y.run();

    delete money;
    delete product;
    delete fproduct;
    delete fmoney;
}
