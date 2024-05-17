//
// Created by Home on 08.05.2024.
//
#pragma once
#include "Ui.h"
#include<iostream>
#include <vector>
#include <bits/atomic_lockfree_defines.h>
using namespace std;

Ui::Ui(Service service)
{
    this->x = service;
}

Ui::~Ui()
{
}

void Ui::showAllProducts()
{
    map<Product, int> allProducts = this->x.getAllProducts();
    if (allProducts.empty() == true)
    {
        cout << "No products!" << endl;
    }
    else
    {
        for (auto it = allProducts.begin(); it != allProducts.end(); ++it)
        {
            cout << "The product is:" << it->first<<endl;
        }
        cout << "X. Exit" << endl;
    }
}

void Ui::showMenu()
{
    std::cout << "1.Show products" << std::endl;
    std::cout << "2.Buy a product" << std::endl;
    std::cout << "3.Exit" << std::endl;
}


void Ui::console(char& option)
{
    this->showMenu();
    std::cout << "Choose your option: ";
    std::cin >> option;
    std::cout << std::endl;
}

void Ui::buyProduct()
{
    cout << "Enter the sum of money required: ";
    double value;
    cin>>value;
    cout<<"Enter the code of the product:";
    int code;
    cin>>code;
    this->x.atm(code,value);
}

void Ui::run()
{
    bool run = true;
    while (run)
    {
        char option;
        console(option);
        switch (option) {
        case '1':
            {
                this->showAllProducts();
                break;
            }
        case '2':
            {
                this->buyProduct();
            }
        case'3':
            {
                this->
            }
        default:
            std::cout << "Invalid option. Try again!";
            std::cout << std::endl;
        }
    }
}
