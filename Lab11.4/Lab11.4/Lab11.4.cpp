#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;

struct Car {
    string brand;
    double price;
    double mileage;
};

double calculateAverageMileage(ifstream& inFile) {
    double totalMileage = 0;
    int count = 0;
    Car car;
    while (inFile >> car.brand >> car.price >> car.mileage) {
        totalMileage += car.mileage;
        count++;
    }
    return count == 0 ? 0 : totalMileage / count;
}

int countUniqueBrands(ifstream& inFile) {
    string currentBrand, previousBrand = "";
    int uniqueCount = 0;
    Car car;
    while (inFile >> car.brand >> car.price >> car.mileage) {
        if (car.brand != previousBrand) {
            uniqueCount++;
            previousBrand = car.brand;
        }
    }
    return uniqueCount;
}

void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile || !outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    double averageMileage = calculateAverageMileage(inFile);
    inFile.clear();
    inFile.seekg(0);
    string lines[100];
    int lineCount = 0;
    while (getline(inFile, lines[lineCount])) {  //1)//
        lineCount++;
    }
    sort(lines, lines + lineCount);

    for (int i = 0; i < lineCount; i++) {
        outFile << lines[i] << " " << averageMileage << endl;
    }

    inFile.clear();
    inFile.seekg(0);
    int uniqueBrands = countUniqueBrands(inFile);

    outFile << "Кількість різних марок: " << uniqueBrands << endl;

    inFile.close();
    outFile.close();
    cout << "Обробка завершена. Результати записані у файл " << outputFileName << endl;
}

void menu() {
    string inputFileName, outputFileName;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFileName;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int choice;
        cout << "\n--- Меню ---\n";
        cout << "1. Обробити файли\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            menu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
    return 0;
}
