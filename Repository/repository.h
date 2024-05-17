//
// Created by Home on 08.05.2024.
//
#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <sstream>

#endif //REPOSITORY_H
#include<map>
using namespace  std;

template<typename T> class Repository
{
private:
    map<T,int>x;
public:
    //The default constructor
    Repository();
    //Deconstructor
    ~Repository();

    //Add an element in the dictionary
    void addElement(const T& element,int noElements);
    //Remove an element in the dictionary
    void deleteElement(const T& element);
    //Update an element in the dictionary
    void updateElement(const T& element, int noElements);

    //Return the dictionary
    map<T,int> getAll() const;
    //Return the number of elements of a specifed element(the value).
    int getNoElement(const T& element);
    bool findElement(const T& element);
    //The assignment operator
    Repository<T>&operator=(const Repository<T> &newRepo);
};
template <typename T>
Repository<T>::Repository()
{
}

template <typename T>
Repository<T>::~Repository()
{
}

template <typename T>
void Repository<T>::addElement(const T& element, int noElements)
{
    //to verify if it s unique,if it's not to update the element
    this->x.insert(pair<T, int>(element, noElements));
}

template <typename T>
void Repository<T>::deleteElement(const T& element)
{
    auto it = x.find(element);
    if (it != x.end())
    {
        x.erase(it);
    }//throw exception
}

template <typename T>
void Repository<T>::updateElement(const T& element, int noElements)
{
    auto it = x.find(element);
    if (it != x.end())
    {
        it->second=noElements;
    }//throw exception
}

template <typename T>
map<T, int> Repository<T>::getAll() const
{
    return this->x;
}

template <typename T>
int Repository<T>::getNoElement(const T& element)
{
    auto it = x.find(element);
    if (it != x.end())
    {
        return it->second;
    }else
    {
        return -1;
    }
}

template <typename T>
bool Repository<T>::findElement(const T& element)
{
    return this->getNoElement(element)!= -1 ? true : false;
}

template <typename T>
Repository<T>& Repository<T>::operator=(const Repository<T>& newRepo)
{
    if (this != &newRepo) {
        this->x = newRepo.x;
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Repository<T>& repo)
{
    for (const auto& pair :repo.getAll()) {
        os << pair.first << " " << pair.second << "\n";
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Repository<T>& repo){
    std::string line;
    while (std::getline(is, line)) {
        std::istringstream iss(line);
        T element;
        int noElements;
        if (iss >> element >> noElements) {
            repo.addElement(element, noElements);
        }
    }
    return is;
}
