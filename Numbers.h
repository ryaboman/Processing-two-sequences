#pragma once

#include <iostream>
#include <vector>

using namespace std;



class Numbers final {

    int countOfElements = 0;

    int* itr_begin;
    int* itr_end;

public:

    Numbers();

    Numbers(string pathToFile);

    ~Numbers();

    bool WriteDataToFile(string pathToFile);

    void AddElement(int element);
    void PrintElements();
    void GenerateElements();
    int* GetBegin();
    int* GetEnd();

private:
    void ReadDataFromFile(string pathToFile);
    void DeleteElements();

};



