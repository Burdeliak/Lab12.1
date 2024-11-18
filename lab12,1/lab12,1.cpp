#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>   // Для роботи з файлами
#include <string>    // Для роботи з рядками
#include <cstdio>    // Для видалення тимчасових файлів
#include "../Lab12.1/lab12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab121
{
	TEST_CLASS(lab121)
	{
	public:

		TEST_METHOD(PrintFileTest)
		{
			const char* testFilename = "test_file.txt";

		// Створюємо тестовий файл
		{
			std::ofstream fout(testFilename, std::ios::binary);
			fout << "Sample123\nText!";
			fout.close();
		}

		// Замінимо стандартний потік виведення, щоб перевірити результат
		std::stringstream buffer;
		std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

		// Викликаємо PrintFile
		PrintFile(testFilename);

		// Перевіряємо виведення
		std::string output = buffer.str();
		std::string expectedOutput = "Sample123\nText!\n"; // Включає перенесення рядка
		Assert::AreEqual(expectedOutput, output, L"Printed content mismatch.");

		// Відновлюємо стандартний потік виведення
		std::cout.rdbuf(oldCout);

		// Видаляємо тимчасовий файл
		std::remove(testFilename);
		}
	};
}
