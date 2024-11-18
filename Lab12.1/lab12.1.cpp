#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для створення файлу з символами, які вводить користувач
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary); // Відкриваємо файл для запису
    char ch; // Відповідь користувача про продовження введення
    string input; // Введений рядок
    do {
        cout << "Vvedit riadok: ";
        cin.ignore();
        getline(cin, input); // Зчитуємо рядок
        for (char c : input) {
            fout.write(reinterpret_cast<const char*>(&c), sizeof(c)); // Записуємо символи у файл
        }
        cout << "Prodovgutu? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

// Функція для виведення вмісту файлу на екран
void PrintFile(const char* filename) {
    ifstream fin(filename, ios::binary); // Відкриваємо файл для читання
    char c;
    while (fin.read(reinterpret_cast<char*>(&c), sizeof(c))) { // Зчитуємо символи
        cout << c;
    }
    cout << endl;
    fin.close();
}

// Функція для копіювання символів латинського алфавіту у новий файл
void CopyLatinCharacters(const char* srcFilename, const char* destFilename) {
    ifstream fin(srcFilename, ios::binary); // Відкриваємо вхідний файл
    ofstream fout(destFilename, ios::binary); // Відкриваємо вихідний файл
    char c;
    while (fin.read(reinterpret_cast<char*>(&c), sizeof(c))) { // Зчитуємо символи
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // Перевірка на латинські букви
            fout.write(reinterpret_cast<const char*>(&c), sizeof(c)); // Записуємо в інший файл
        }
    }
    fin.close();
    fout.close();
}

int main() {
    char srcFilename[100]; // Ім'я початкового файлу
    char destFilename[100]; // Ім'я файлу для латинських символів

    cout << "Enter the name of the first file: ";
    cin >> srcFilename;
    CreateFile(srcFilename); // Створюємо файл з введених символів

    cout << "the contents of the first file:" << endl;
    PrintFile(srcFilename); // Виводимо вміст початкового файлу

    cout << "Enter a name for the file with Latin characters: ";
    cin >> destFilename;
    CopyLatinCharacters(srcFilename, destFilename); // Копіюємо латинські символи

    cout << "The contents of the file with Latin characters:" << endl;
    PrintFile(destFilename); // Виводимо вміст нового файлу

    return 0;
}
