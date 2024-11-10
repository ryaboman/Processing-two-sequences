#pragma once

#include "Numbers.h"
#include <list>

using namespace std;

#ifndef ACTION_H 
#define ACTION_H 


class Sets{

    

public:

    list<Numbers*> inputSets;
    list<Numbers*> outputSets;

    Sets();

    ~Sets();

    void AddSetFromFile(string pathToFile);

    void GenerateSet(int amountOfSets);    
    
    //Выбор элементов по условию
    bool SelectElements(Numbers* firstSetNumbers, Numbers* secondSetNumbers);

    void PrintSets();

    void WriteSetsToFile(string pathToFolder);

    void DeleteSet(int removeIndex);

    void Clear();

private:
        
    void PrintInputSets();

    void PrintOutputSets();

};

#endif