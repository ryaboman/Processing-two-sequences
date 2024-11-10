#include <iostream>
#include "Sets.h"

#include <windows.h>
#include <string>
#include <filesystem>
#include <stack>

using namespace std;

static string menu[] =
{
  " 1 > загрузить входные наборы из файлов InputSet№1.txt, InputSet№2.txt;\n",
  " 2 > генерировать входные наборы;\n",
  " 3 > рассчитать выходной набор;\n",
  " 4 > записать наборы в файл;\n",
  " 0 > выход;\n",
  " ? > "
};

int main(void){

    setlocale(LC_ALL, "Russian");

    Sets* proc = new Sets();    

    int selected_item = 10;

    bool statusOfRepeat = true;
   
    while (statusOfRepeat) {

        //Распечатка меню
        cout << endl;                
        for (auto item_menu : menu) {
            cout << item_menu;
        }        

        //очистим входной поток
        

        //cin >> selected_item;
        fflush(stdin);
        scanf_s("%d", &selected_item);

        cout << endl;

        //Выполнения выбранного действия пользователя
        switch (selected_item){

            case 1:{
                string pathToFile_1 = "files\\InputSet№1.txt";
                string pathToFile_2 = "files\\InputSet№2.txt";

                proc->AddSetFromFile(pathToFile_1);
                proc->AddSetFromFile(pathToFile_2);

                proc->PrintSets();                

                break;
            }
                

            case 2:{
                //удалим имеющиеся наборы
                proc->Clear();

                //сгенерируем два входных набора
                proc->GenerateSet(2);
                proc->PrintSets();
                break;
            }
                
            
            case 3:{
                //OpSelectElementsFromSets
                if (proc->inputSets.size() >= 2) {
                    proc->SelectElements(proc->inputSets.front(), proc->inputSets.back());
                    proc->PrintSets();
                }
                else {
                    cout << "Не достаточно элементов в наборе!" << endl;
                }
                
                break;
            }

            case 4:{
                proc->WriteSetsToFile("files");
                //cout << "Данные записаны";
                break;
            }
                
            case 0:{
                statusOfRepeat = false;
                break;
            }
                
            default:{
                break;
            }
                
        }

    }

    proc->~Sets();
}
