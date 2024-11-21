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
        cerr << "������� �������� �����!" << endl;
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

    outFile << "ʳ������ ����� �����: " << uniqueBrands << endl;

    inFile.close();
    outFile.close();
    cout << "������� ���������. ���������� ������� � ���� " << outputFileName << endl;
}

void menu() {
    string inputFileName, outputFileName;
    cout << "������ ��'� �������� �����: ";
    cin >> inputFileName;
    cout << "������ ��'� ��������� �����: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int choice;
        cout << "\n--- ���� ---\n";
        cout << "1. �������� �����\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        if (choice == 1) {
            menu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "������� ����. ��������� �� ���.\n";
        }
    }
    return 0;
}
