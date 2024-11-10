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
            cerr << "�� ���� ������� ���� " << "InpData.txt";
            exit(1);
        }

        //fin.gcount
        // ���� �� ����� �����
        while (!fin.eof()) {
            int number;
            fin >> number;
            AddElement(number);
        }

        fin.close();
    }
    catch(...){
        cout << "�������� ���������� ��� ������ ������ �� �����" << endl;
    }
}

bool Numbers::WriteDataToFile(string pathToFile) {

    try {

        //�������  ����� ��� ������
        ofstream fout;

        //���������(�������) ����
        fout.open(pathToFile, ios_base::out);

        for (int* itr = itr_begin; itr < itr_end; itr++) {
            fout << *itr << endl;
        }
        
        //��������� ����� 
        fout.close();

        return true;
    }
    catch (...) {
        cout << "�������� ���������� ��� ������ ������ � ����" << endl;
    }

    return false;
}

void Numbers::AddElement(int element) {

    countOfElements++;
    int* tempArr = new int[countOfElements];

    if (countOfElements > 1) {
        //�������� ������ � ����� ������
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

    //����� ��������� �������
    for (int* itr = itr_begin; itr < itr_end; itr++) {
        cout << *itr << "; ";
    }
    cout << endl;

    int* max_element = std::max_element(itr_begin, itr_end);
    cout << "   ������������ �������� � ������: " << *max_element;
    cout << endl;

    int* min_element = std::min_element(itr_begin, itr_end);   
    cout << "   ����������� �������� � ������: " << *min_element;
    cout << endl;

    
    int sum = 0;
    for (int* itr = itr_begin; itr < itr_end; itr++) {
        sum += *itr;
    }
    float average_element = sum/countOfElements;

    cout << "   ������� �������������� �������� � ������: " << average_element;
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


