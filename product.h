#pragma once
#include <ostream>
#include <istream>

class Product {
private:
	//The code of the product.
	int code;
	//The name of the product.
	char* name;
	//The price of the product.
	double price;
public:
	//The default constructor.
	Product();
	//The parameterized constructor.
	Product(int newCode, const char* newName, double newPrice);
	//Copy constructor
	Product(const Product& newProduct);
	//Deconstructor
	~Product();

	//-----------------------Getters and Setters
	int getCode()const ;
	const char* getName()const;
	double getPrice()const ;

	void setCode(int newCode);
	void setName(const char* newName);
	void setPrice(double newPrice);

	Product& operator=(const Product& newProduct);
	bool operator <(const Product& product) const;
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
	friend std::istream& operator>>(std::istream& is, Product& product);
};