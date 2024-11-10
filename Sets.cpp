#include "Sets.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <windows.h>


Sets::Sets() {

}

Sets::~Sets() {
	for (auto set : inputSets) {
		set->~Numbers();
	}
	for (auto set : outputSets) {
		set->~Numbers();
	}
}


void Sets::AddSetFromFile(string pathToFile) {
	
	Numbers* setNumbers = new Numbers(pathToFile);

	inputSets.push_back(setNumbers);
}

list<Numbers*>::iterator operator + (list<Numbers*>::iterator it, int index) {
	for (int counter = 0; counter < index; counter++, it++);
	return it;
};

void Sets::DeleteSet(int removeIndex) {
	//inputSets.remove(removeSet);
	

	list<Numbers*>::iterator itResult = inputSets.begin();
	itResult = itResult + removeIndex;
	
	inputSets.erase(itResult);

}

void Sets::Clear() {

	inputSets.clear();
	outputSets.clear();

}

//Выборка элементов из наборов согласно условию задачи
bool Sets::SelectElements(Numbers* firstSetNumbers, Numbers* secondSetNumbers) {

	if ((firstSetNumbers == NULL) || (secondSetNumbers == NULL)) {
		return false;
	}

	int* itResult;
	int* itrBegin = secondSetNumbers->GetBegin();
	int* itrEnd = secondSetNumbers->GetEnd();

	int* itrBegin1 = firstSetNumbers->GetBegin();
	int* itrEnd1 = firstSetNumbers->GetEnd();

	queue<int> queueNumbers;
	stack<int> stackNumbers;

	Numbers* thirdSetNumbers = new Numbers();

	for (auto ptrAtElement = itrBegin1; ptrAtElement < itrEnd1; ptrAtElement++) {
		
		auto element = *ptrAtElement;

		itResult = find(itrBegin, itrEnd, element);

		if ((element >= 0) && (itResult == itrEnd)) {
			//прямой порядок. Записываем в очередь
			queueNumbers.push(element);
		}

		if ((element < 0) && (itResult != itrEnd)) {
			//обратный порядок. Записываем в стек
			stackNumbers.push(element);
		}
	}

	while (!queueNumbers.empty()) {
		int element = queueNumbers.front();
		queueNumbers.pop();
		thirdSetNumbers->AddElement(element);
	}

	while (!stackNumbers.empty()) {
		int element = stackNumbers.top();
		stackNumbers.pop();
		thirdSetNumbers->AddElement(element);
	}

	outputSets.push_back(thirdSetNumbers);

	return true;
}

void Sets::GenerateSet(int amountOfSets) {
	
	for (int index=0; index < amountOfSets; index++) {
		Numbers* setNumbers = new Numbers();
		setNumbers->GenerateElements();

		inputSets.push_back(setNumbers);
		
		//Задержка нужна чтобы массивы не были одинаковы
		Sleep(10);
	}
	
}

void Sets::PrintInputSets() {
	int index = 1;
	for (auto setNumbers : inputSets) {
		cout << "Входной набор элементов №" << index << ": ";
		setNumbers->PrintElements();
		index++;
	}
}

void Sets::PrintOutputSets() {
	int index = 1;
	for (auto setNumbers : outputSets) {
		cout << "Выходной набор элементов №" << index << ": ";
		setNumbers->PrintElements();
		index++;
	}
}

void Sets::PrintSets() {
	PrintInputSets();
	PrintOutputSets();
}

void Sets::WriteSetsToFile(string pathToFolder) {
	
	int indexInputSet = 1;
	string pathToFileInputSet = pathToFolder + "\\InputSet№";
	for (auto setNumbers : inputSets) {		
		setNumbers->WriteDataToFile( pathToFileInputSet + to_string(indexInputSet) + ".txt");
		indexInputSet++;
	}

	int indexOutputSet = 1;
	string pathToFileOutputSet = pathToFolder + "\\OutputSet№";
	for (auto setNumbers : outputSets) {
		setNumbers->WriteDataToFile( pathToFileOutputSet + to_string(indexOutputSet) + ".txt");
		indexOutputSet++;
	}
}