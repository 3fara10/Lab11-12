//
// Created by Home on 08.05.2024.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>

#endif //SERVICE_H
#include "money.h"
#include "repository.h"
//
// Created by Home on 08.05.2024.
//
class Service
{
private:
    Repository<Product> productRepository;
    Repository<Money> moneyRepository;

public:
    //Constructors
    Service();
    Service(Repository<Product> productRepository, Repository<Money> moneyRepository);
    ~Service();

    //add methods
    void addProduct(const Product& product, int noProducts);
    void addNoMoney(const Money& money, int noMoney);

    //update methods
    void updateNoProducts(const Product& product, int noProducts);
    void updateNoMoney(const Money& money, int noMoney);

    //delete methods
    void deleteProduct(const Product& product);

    void deleteNoProducts(const Product& product, int noProducts);
    void deleteNoMoney(const Money& money, int noMoney);

    void moneyUpdate(double money);
    void atm(int codeProduct, double money);
    void giveChange(double change);

    Product getProduct(int codeProduct);
    int getProductKey(int codeProduct);
    int getMoneyKey(const Money& money);

    map<Product, int> getAllProducts();
    map<Money, int> getAllMoney();
};

inline Service::Service()
{

}

inline Service::Service(Repository<Product> productRepository, Repository<Money> moneyRepository)
{
    this->moneyRepository = moneyRepository;
    this->productRepository = productRepository;
}

inline Service::~Service()
{
}

inline void Service::addProduct(const Product& product, int noProducts)
{
    if (this->productRepository.findElement(product) == true)
    {
        int currentNoProducts = productRepository.getNoElement(product);
        productRepository.updateElement(product, currentNoProducts + noProducts);
    }
    else
    {
        productRepository.addElement(product, noProducts);
    }
}

inline void Service::addNoMoney(const Money& money, int noMoney)
{
    if (this->moneyRepository.findElement(money) == true)
    {
        int currentNoMoney = this->moneyRepository.getNoElement(money);
        this->moneyRepository.updateElement(money, currentNoMoney + noMoney);
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::updateNoProducts(const Product& product, int noProducts)
{
    if (this->productRepository.findElement(product))
    {
        // If the product exists, update the number of products
        productRepository.updateElement(product, noProducts);
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::updateNoMoney(const Money& money, int noMoney)
{
    // Check if the money exists in the repository
    if (this->moneyRepository.findElement(money))
    {
        // If the money exists, update the number of money units
        moneyRepository.updateElement(money, noMoney);
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::deleteProduct(const Product& product)
{
    if (this->productRepository.findElement(product))
    {
        productRepository.deleteElement(product);
    } else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::deleteNoProducts(const Product& product, int noProducts)
{
    if (this->productRepository.findElement(product))
    {
        int currentNoProducts = productRepository.getNoElement(product);
        int newNoProducts = currentNoProducts - noProducts;
        if (newNoProducts >= 0)
        {
            this->productRepository.updateElement(product, newNoProducts);
        }
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::deleteNoMoney(const Money& money, int noMoney)
{
    if (this->moneyRepository.findElement(money))
    {
        int currentNoMoney = this->moneyRepository.getNoElement(money);
        int newNoMoney = currentNoMoney - noMoney;
        if (newNoMoney >= 0)
        {
            this->moneyRepository.updateElement(money, newNoMoney);
        }
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline void Service::moneyUpdate(double money)
{
    //parcurg de la sfarsit la inceput
    auto moneyMap = this->moneyRepository.getAll();
    for (auto it = moneyMap.rbegin(); it != moneyMap.rend(); ++it)
    {
        //iau fiecare bancnota/moneda in parte
        Money bancnota = it->first;
        //daca suma e mai mare decat bancnota curenta
        while (money >= bancnota.getValue())
        {
            //scadem valoarea bancnotei din suma
            money -= bancnota.getValue();
            //crestem numarul sau de apartitii
            it->second++;
            this->moneyRepository.updateElement(bancnota,it->second);
        }
    }
}

inline void Service::atm(int codeProduct, double money)
{
    //gasim produsul
    Product product = this->getProduct(codeProduct);
    //daca avem bani suficienti
    if (money >= product.getPrice())
    {
        //schimb dupa pe exceptii si afisare in ui
        std::cout << "Restul dumneavoastra este: ";
        double change = money - product.getPrice();
        if (change > 0)
        {
            //daca avem de dat rest
            this->giveChange(change);
        }
        else if (change == 0)
        {
            std::cout<<"0";
            //daca e suma exacta doar punem banii in bancomat
            this->moneyUpdate(money);
            this->deleteNoProducts(product,1);
        }
    }
    else
    {
        std::cout << "ATM ul nu are suficiente fonduri";
    }
}

inline void Service::giveChange(double change)
{
    //facem o copie la toti banii
    std::map<Money, int> copy = this->moneyRepository.getAll();
    std::map<Money, int> copy2 = this->moneyRepository.getAll();
    //copie la rest
    double change_copy = change;
    for (auto it = copy.rbegin(); it != copy.rend(); ++it)
    {
        //parcurgem banii si luam fiecare bancnota in parte
        Money money = it->first;
        //daca suma e mai mare decat bancnota curenta si exista acel tip de bancnota
        while (change >= money.getValue() && it->second > 0)
        {
            //scadem din rest
            change -= money.getValue();
            //scadem din numarul de aparitii
            it->second--;
        }
        if (change == 0)
        {
            break;
        }
    }

    if (change > 0)
    {
        std::cout << "ATM UL NU POATE RETURNA RESTUL.";
    }
    else if (change == 0)
    {
        std::cout << "ATM-ul A PUTUT FURNIZA RESTUL." << std::endl;
        std::cout << "RESTUL DUMNEAVOASTRA ESTE: " << change_copy;
        auto it = copy.rbegin();
        auto it2 = copy2.rbegin();
        while (it != copy.rend() && it2 != copy2.rend())
        {
            if (it->second != it2->second)
            {
                this->moneyRepository.updateElement(it2->first, it->second);
            }
            ++it;
            ++it2;
        }
    }
}


inline Product Service::getProduct(int codeProduct)
{
    std::map<Product, int> allElements = this->productRepository.getAll();
    std::map<Product, int>::iterator it = allElements.begin();
    while (it->first.getCode() != codeProduct && it != allElements.end())
    {
        ++it;
    }
    if (it != allElements.end())
    {
        Product y(it->first.getCode(), it->first.getName(), it->first.getPrice());
        return y;
    }else
    {
        std::cout<<"ENTITATEA NU EXISTA";
    }
}

inline int Service::getProductKey(int codeProduct)
{
    return this->productRepository.getNoElement(this->getProduct(codeProduct));
}

inline int Service::getMoneyKey(const Money& money)
{
    return this->moneyRepository.getNoElement(money);
}

inline map<Money, int> Service::getAllMoney()
{
    return this->moneyRepository.getAll();
}

inline map<Product, int> Service::getAllProducts()
{
    return this->productRepository.getAll();
}
