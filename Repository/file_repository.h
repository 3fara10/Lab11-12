//
// Created by Home on 08.05.2024.
//
#pragma once
#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H
#include "repository.h"

#endif

#include <map>
#include <fstream>

using namespace std;

template <typename T>
class FileRepository : public Repository<T>
{
private:
    char* fileName;
    void loadFromFile();
    void saveToFile();

public:
    FileRepository(const char* file);
    ~FileRepository();

    void addElement(T element, int noElements);
    void deleteElement(const T& element);
    void updateElement(const T& element, int noElements);

    int getNoElement(const T& element);
    map<T, int> getAll() const;
    bool findElement(const T& element);

    Repository<T>&operator=(const Repository<T> &newRepo);
};

template <typename T>
void FileRepository<T>::loadFromFile()
{
    ifstream f(this->fileName);
    T element;
    int noElements;
    while (!f.eof())
    {
        f >> element;
        f>> noElements;
        Repository<T>::addElement(element, noElements);
    }
    f.close();
}

template <typename T>
void FileRepository<T>::saveToFile()
{
    ofstream f(this->fileName);
    map<T, int> repository = this->getAll();
    for (auto itr = repository.begin(); itr != repository.end(); ++itr)
        f << itr->first << ' ' << itr->second<<' ';
    f.close();
}


template <typename T>
FileRepository<T>::FileRepository(const char* file):Repository<T>()
{
    this->fileName = (char*)file;
    loadFromFile();
}

template <typename T>
FileRepository<T>::~FileRepository()
{
    saveToFile();
}

template <typename T>
void FileRepository<T>::addElement(T element, int noElements)
{
    Repository<T>::addElement(element, noElements);
    this->saveToFile();
}

template <typename T>
void FileRepository<T>::deleteElement(const T& element)
{
    Repository<T>::deleteElement(element);
    this->saveToFile();
}

template <typename T>
void FileRepository<T>::updateElement(const T& element, int noElements)
{
    Repository<T>::updateElement(element, noElements);
    this->saveToFile();
}

template <typename T>
int FileRepository<T>::getNoElement(const T& element)
{
    return Repository<T>::getNoElement(element);
}

template <typename T>
map<T, int> FileRepository<T>::getAll() const
{
    return Repository<T>::getAll();
}

template <typename T>
bool FileRepository<T>::findElement(const T& element)
{
    return Repository<T>::findElement(element);
}

template <typename T>
Repository<T>& FileRepository<T>::operator=(const Repository<T>& newRepo)
{
    if (this != &newRepo) {
        this->x = newRepo.x;
    }
    return *this;
}
