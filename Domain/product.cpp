#include "C:/Users/Home/CLionProjects/lab9-10/Domain/product.h"
#include <cstring>
//---------------------------------------------------------------CONSTRUCTORS
Product::Product()
{
	this->code = 0;
	this->name = new char[20];
	this->price = 0.0;
}


Product::Product(int newCode, const char* newName, double newPrice)
{
	this->code = newCode;

	this->name = new char[strlen(newName)+1];
	strcpy(this->name, newName);

	this->price = newPrice;
}


Product::Product(const Product& newProduct)
{
	this->code = newProduct.code;
	this->price = newProduct.price;

	if(newProduct.getName()!=nullptr){
		this->name = new char[strlen(newProduct.getName()) + 1];
		strcpy(this->name, newProduct.getName());
	}else
	{
		this->name=nullptr;
	}
}


Product::~Product()
{
	if (this->name != nullptr) {
		delete[] this->name;
	}
}


//---------------------------------------------------------------SETTERS AND GETTERS
int Product::getCode() const
{
	return this->code;
}


const char* Product::getName() const
{
	return this->name;
}


double Product::getPrice() const
{
	return this->price;
}


void Product::setCode(int newCode)
{
	this->code = newCode;
}

void Product::setName(const char* newName)
{

	if (newName != nullptr) {
		char* copy = new char[strlen(newName) + 1];
		strcpy(copy, newName);
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, copy);
		delete[]copy;
	}
	else {
		this->name = nullptr;
	}
}

void Product::setPrice(double newPrice)
{
	this->price = newPrice;
}

Product& Product::operator=(const Product& newProduct)
{
	this->setCode(newProduct.code);
	this->setPrice(newProduct.price);
	this->setName(newProduct.name);
	return *this;
}

bool Product::operator<(const Product& product) const
{
	return this->code < product.code;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	os << product.code << ' ' << product.name << ' ' << product.price;
	return os;
}

std::istream& operator>>(std::istream& is, Product& product)
{
	is >> product.code >> product.name >> product.price;
	return is;
}
