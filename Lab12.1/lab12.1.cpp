#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ������� ��� ��������� ����� � ���������, �� ������� ����������
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary); // ³�������� ���� ��� ������
    char ch; // ³������ ����������� ��� ����������� ��������
    string input; // �������� �����
    do {
        cout << "Vvedit riadok: ";
        cin.ignore();
        getline(cin, input); // ������� �����
        for (char c : input) {
            fout.write(reinterpret_cast<const char*>(&c), sizeof(c)); // �������� ������� � ����
        }
        cout << "Prodovgutu? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

// ������� ��� ��������� ����� ����� �� �����
void PrintFile(const char* filename) {
    ifstream fin(filename, ios::binary); // ³�������� ���� ��� �������
    char c;
    while (fin.read(reinterpret_cast<char*>(&c), sizeof(c))) { // ������� �������
        cout << c;
    }
    cout << endl;
    fin.close();
}

// ������� ��� ��������� ������� ����������� ������� � ����� ����
void CopyLatinCharacters(const char* srcFilename, const char* destFilename) {
    ifstream fin(srcFilename, ios::binary); // ³�������� ������� ����
    ofstream fout(destFilename, ios::binary); // ³�������� �������� ����
    char c;
    while (fin.read(reinterpret_cast<char*>(&c), sizeof(c))) { // ������� �������
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // �������� �� �������� �����
            fout.write(reinterpret_cast<const char*>(&c), sizeof(c)); // �������� � ����� ����
        }
    }
    fin.close();
    fout.close();
}

int main() {
    char srcFilename[100]; // ��'� ����������� �����
    char destFilename[100]; // ��'� ����� ��� ���������� �������

    cout << "Enter the name of the first file: ";
    cin >> srcFilename;
    CreateFile(srcFilename); // ��������� ���� � �������� �������

    cout << "the contents of the first file:" << endl;
    PrintFile(srcFilename); // �������� ���� ����������� �����

    cout << "Enter a name for the file with Latin characters: ";
    cin >> destFilename;
    CopyLatinCharacters(srcFilename, destFilename); // ������� �������� �������

    cout << "The contents of the file with Latin characters:" << endl;
    PrintFile(destFilename); // �������� ���� ������ �����

    return 0;
}
