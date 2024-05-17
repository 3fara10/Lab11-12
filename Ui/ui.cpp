//
// Created by Home on 08.05.2024.
//
#pragma once
#include "Ui.h"
#include<iostream>
#include <map>
#include <vector>
#include <bits/atomic_lockfree_defines.h>
using namespace std;

Ui::Ui(Service* service)
{
    this->x = service;
}

Ui::~Ui()
{
}

void Ui::showAllProducts()
{
    map<Product, int> allProducts = this->x->getAvailableProducts();
    if (allProducts.empty() == true)
    {
        cout << "No products!" << endl;
    }
    else
    {
        for (auto it = allProducts.begin(); it != allProducts.end(); ++it)
        {
            cout << "The product is:" << it->first << endl;
        }
    }
}

void Ui::showMenu()
{
    std::cout << "1.Show products" << std::endl;
    std::cout << "2.Enter the money to buy the products." << std::endl;
    std::cout << "3.Enter the code to update the numbers of the products." << std::endl;
    std::cout << "4.Enter the code to delete the product." << std::endl;
    std::cout << "5.Exit" << std::endl;
}


void Ui::console(char& option)
{
    this->showMenu();
    std::cout << "Choose your option: ";
    std::cin >> option;
    std::cout << std::endl;
}

void Ui::updateProduct()
{
    try
    {
        ProductValidator x;
        int code;
        cout << "Enter the code of the product:";
        cin >> code;
        x.verifyInt(code);
        int noProducts;
        cout << "Enter the new number of the products";
        cin >> noProducts;
        x.verifyInt(noProducts);
        this->x->updateNoProducts(this->x->getProduct(code), noProducts);
    }
    catch (NotFoundException& error)
    {
        cout << error.what();
    }catch (InvalidValueException& error)
    {
        cout << error.what();
    }
}

void Ui::deleteProduct()
{
    try
    {
        ProductValidator x;
        int code;
        cout << "Enter the code of the product:";
        cin >> code;
        x.verifyInt(code);
        this->x->deleteProduct(this->x->getProduct(code));
    }
    catch (NotFoundException& error)
    {
        cout << error.what()<<endl;
    }catch (InvalidValueException& error)
    {
        cout << error.what()<<endl;
    }
}

void Ui::buyProduct()
{
    try
    {
        ProductValidator x;
        int code;
        cout << "Enter the code of the product:";
        cin >> code;
        x.verifyInt(code);
        double value = this->addMoney(this->x->getProduct(code));
        this->x->atm(code, value);
        cout << endl << "The transaction was successful" << endl;
    }
    catch (NotFoundException& error)
    {
        cout << error.what()<<endl;
    }catch (InvalidValueException& error)
    {
        cout << error.what()<<endl;
    }
}

double Ui::addMoney(const Product& product)
{
    cout << "Enter the amount of money required: " << endl;
    double amount = 0;
    do
    {
        cout << "Your credit is: " << amount << endl;
        cout << endl << "Enter the value: ";
        double value;
        cin >> value;
        MoneyValidator x;
        x.validate(value);
        amount += value;
    }
    while (amount < product.getPrice());
    return amount;
}


void Ui::run()
{
    bool run = true;
    while (run)
    {
        char option;
        console(option);
        switch (option)
        {
        case '1':
            {
                this->showAllProducts();
                break;
            }
        case '2':
            {
                this->buyProduct();
                break;
            }
        case '3':
            {
                this->updateProduct();
                break;
            }
        case '4':
            {
                this->deleteProduct();
                break;
            }
        case'5':
            {
                run = false;
                break;
            }
        default:
            std::cout << "Invalid option. Try again!";
            std::cout << std::endl;
        }
    }
}
