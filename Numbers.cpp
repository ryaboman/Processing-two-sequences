#include "Numbers.h"

#include <stdio.h>
#include <iostream>
#include "fstream"
#include "string.h"
#include <random>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;


Numbers::Numbers() {

}

Numbers::Numbers(string pathToFile) {
    ReadDataFromFile(pathToFile);
}

Numbers::~Numbers() {
    DeleteElements();
}

void Numbers::DeleteElements() {
    delete []itr_begin;
    countOfElements = 0;
}

void Numbers::ReadDataFromFile(string pathToFile) {

    try {
        ifstream fin(pathToFile);

        if (!fin != 0)
        {
            cerr << "Не могу открыть файл " << "InpData.txt";
            exit(1);
        }

        //fin.gcount
        // пока не конец файла
        while (!fin.eof()) {
            int number;
            fin >> number;
            AddElement(number);
        }

        fin.close();
    }
    catch(...){
        cout << "Возникло исключение при чтении данных из файла" << endl;
    }
}

bool Numbers::WriteDataToFile(string pathToFile) {

    try {

        //создаем  поток для записи
        ofstream fout;

        //открываем(создаем) файл
        fout.open(pathToFile, ios_base::out);

        for (int* itr = itr_begin; itr < itr_end; itr++) {
            fout << *itr << endl;
        }
        
        //закрываем поток 
        fout.close();

        return true;
    }
    catch (...) {
        cout << "Возникло исключение при записи данных в файл" << endl;
    }

    return false;
}

void Numbers::AddElement(int element) {

    countOfElements++;
    int* tempArr = new int[countOfElements];

    if (countOfElements > 1) {
        //копируем данные в новый массив
        copy(itr_begin, itr_end, tempArr);
    }
    
    //delete elementss;
    itr_begin = tempArr;


    tempArr += countOfElements - 1;
    *tempArr = element;
    
    itr_end = tempArr;
    itr_end++;
}

void Numbers::PrintElements() {

    //Вывод элементов массива
    for (int* itr = itr_begin; itr < itr_end; itr++) {
        cout << *itr << "; ";
    }
    cout << endl;

    int* max_element = std::max_element(itr_begin, itr_end);
    cout << "   Максимальное значение в наборе: " << *max_element;
    cout << endl;

    int* min_element = std::min_element(itr_begin, itr_end);   
    cout << "   Минимальное значение в наборе: " << *min_element;
    cout << endl;

    
    int sum = 0;
    for (int* itr = itr_begin; itr < itr_end; itr++) {
        sum += *itr;
    }
    float average_element = sum/countOfElements;

    cout << "   Среднее арифметическое значение в наборе: " << average_element;
    cout << endl;
}

void Numbers::GenerateElements() {

    DeleteElements();
    
    SYSTEMTIME st;
    GetLocalTime(&st);

    srand(st.wMilliseconds);

    for (int index=0; index < 20; index++) {
        int number = -15 + rand()%30;
        AddElement(number);
    }    
}


int* Numbers::GetBegin() {
    return itr_begin;
}

int* Numbers::GetEnd() {
    return itr_end;
}


