#include"tests.h"
#include<cassert>
#include<cstring>

#include "file_repository.h"
#include"money.h"
#include"product.h"
#include"repository.h"
#include"service.h"
void testProduct() {
    //-----------------------------------------------------------------TEST CONSTRUCTORS
    // Test default constructor
    Product product1;
    assert(product1.getCode() == 0);
    assert(product1.getPrice() == 0);

    // Test parameterized constructor
    Product product2(1, "Croissant", 2);
    assert(product2.getCode() == 1);
    assert(strcmp(product2.getName(), "Croissant") == 0);
    assert(product2.getPrice() == 2);

    // Test copy constructor
    Product product3(product2);
    assert(product3.getCode() == 1);
    assert(strcmp(product3.getName(), "Croissant") == 0);
    assert(product3.getPrice() == 2);


    //-----------------------------------------------------------------TEST GETTERS
    Product product(1, "Croissant", 2);
    // Test getters
    assert(product.getCode() == 1);
    assert(strcmp(product.getName(), "Croissant") == 0);
    assert(product.getPrice() == 2);

    // Test setters
    product.setCode(2);
    assert(product.getCode() == 2);

    product.setPrice(3);
    assert(product.getPrice() == 3);

    product.setName("Chocolate");
    assert(strcmp(product.getName(), "Chocolate") == 0);

    // Test setter for nullptr name
    product.setName(nullptr);
    assert(product.getName() == nullptr);

    Product product10(1, "Croissant", 2);
    //Test the assignment operator
    product2 = product10;

    // Check if the values are correctly assigned
    assert(product2.getCode() == 1);
    assert(strcmp(product2.getName(), "Croissant") == 0);
    assert(product2.getPrice() == 2);

    // Modify product1
    product10.setCode(2);
    product10.setName("Chocolate");
    product10.setPrice(3);

    // Check if product2 remains unchanged
    assert(product2.getCode() == 1);
    assert(strcmp(product2.getName(), "Croissant") == 0);
    assert(product2.getPrice() == 2);

    // Test self-assignment
    product10 = product10;
    assert(product10.getCode() == 2);
    assert(strcmp(product10.getName(), "Chocolate") == 0);
    assert(product10.getPrice() == 3);

    // Test assignment to nullptr name
    product10.setName(nullptr);
    Product product5 = product10;
    assert(product5.getName() == nullptr);
}

void testMoney() {
    //-----------------------------------------------------------------TEST CONSTRUCTORS
    // Test default constructor
    Money money1;
    assert(money1.getValue() == 0);

    // Test parameterized constructor
    Money money2(10);
    assert(money2.getValue() == 10);

    //-----------------------------------------------------------------TEST GETTERS
    // Test setValue
    money1.setValue(5);
    assert(money1.getValue() == 5);

    money2.setValue(20);
    assert(money2.getValue() == 20);

    //-------------------------------------------------------------------TEST OPERATORS
    // Test comparison operator
    Money money3(5);
    assert(money1 < money2);
    assert(!(money2 < money1));
    assert(!(money1 < money3));
}

void testRepository()
{
    //----------------------------------------------------------------TEST CONSTRUCTORS
    // Test default constructor
    Repository<Product> repo;
    // Test addElement
    Product p1(32323,"banana",3.0); // Create a product
    repo.addElement(p1, 5); // Add 5 of p1
    repo.addElement(Product(5564,"baanana",5.2), 7);

    //--------------------------------------------------------------TEST GETTERS
    // Test getAll
    map<Product, int> allElements = repo.getAll();
    assert(allElements.size() == 2); // Ensure correct number of elements

    //Test GetNoElements
    assert(repo.getNoElement(p1)==5);

    // Test deleteElement
    repo.deleteElement(p1); // Delete p1 from repository
    assert(repo.getNoElement(p1) == -1); // Ensure p1 is deleted

    // Test updateElement
    repo.updateElement(Product(5564,"baanana",5.2), 8); // Update the quantity of Product 2 to 8
    assert(repo.getNoElement(Product(5564,"baanana",5.2)) == 8); // Ensure quantity is updated

    // Test assignment operator
    Repository<Product> repo2;
    repo2 = repo;

    // Test that assignment worked correctly
    map<Product, int> allElements2 = repo2.getAll();
    assert(allElements2.size() == 1); // Ensure correct number of elements in repo2
    assert(allElements2.begin()->second == 8); // Ensure quantity of Product 2 is correct in repo2
    cout<<repo2;
}
void testFileRepository()
{
    FileRepository<Product> product("C:/Users/Home/CLionProjects/lab9-10/teste.txt");
    assert(product.getNoElement(Product(1,"pepsi", 3))==56);
}
void testService()
{
    // Create repositories
    Repository<Product>productRepository;
    Repository<Money> moneyRepository;
    moneyRepository.addElement(0.10,0);
    moneyRepository.addElement(0.50,0);
    moneyRepository.addElement(1,0);
    moneyRepository.addElement(5,0);
    moneyRepository.addElement(10,0);
    moneyRepository.addElement(20,0);
    moneyRepository.addElement(50,0);
    moneyRepository.addElement(100,0);
    moneyRepository.addElement(200,0);
    moneyRepository.addElement(500,0);
    // Create service
    Service service(productRepository, moneyRepository);

    // Test addProduct method
    Product p1(1, "Croissant", 2.5);
    service.addProduct(p1, 10);

    // Retrieve the added product from the repository
    Product retrievedProduct = service.getProduct(1);

    // Assert statements to check if the retrieved product matches the expected details
    assert(retrievedProduct.getCode() == 1);
    assert(strcmp(retrievedProduct.getName(),"Croissant")==0);
    assert(retrievedProduct.getPrice() == 2.5);

    // Test addNoMoney method
    Money m1(20);
    service.addNoMoney(m1, 20);

    // Test updateNoProducts method
    service.updateNoProducts(p1, 15);
    assert(service.getProductKey(p1.getCode()) == 15);

    // Test updateNoMoney method
    service.updateNoMoney(m1, 25);
    assert(service.getMoneyKey(m1) == 25);

    // Test deleteNoProducts method
    service.deleteNoProducts(p1, 5);
    assert(service.getProductKey(p1.getCode()) == 10);

    // Test deleteNoMoney method
    service.deleteNoMoney(m1, 10);
    assert(service.getMoneyKey(m1) == 15);

    //test atm
    service.addNoMoney(5,2);
    Product p2(12, "Croisssant", 5);
    service.addProduct(p2, 10);

    // Test with sufficient money
    service.atm(12, 5.0); // Purchase a Croissant with 5 lei
    assert(service.getMoneyKey(5) == 3);

    service.deleteProduct(p2);
    service.deleteProduct(p1);
    service.deleteNoMoney(5,3);
    service.deleteNoMoney(20,20);

    service.addNoMoney(Money(10), 10);
    service.addProduct(Product(98, "Suc", 40.0),3);
    service.atm(98,50.0);
    assert(service.getMoneyKey(Money(10.0)) == 9);

    service.atm(98,700);
    //RESTUL DE TESTE CU EXCEPTII
}
void tests() {
	testProduct();
	testMoney();
   testRepository();
   testService();
   testFileRepository();
}
