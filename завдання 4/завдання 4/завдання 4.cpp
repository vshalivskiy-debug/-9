#include <iostream>
#include <stdexcept>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main() {
    // Встановлення кодування UTF-16 для консолі
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    try {
        int number;
        wcout << L"Введіть двоцифрове число: ";
        wcin >> number;

        if (wcin.fail()) {
            throw runtime_error("Некоректне введення! Введіть число.");
        }

        if (number < 10 || number > 99) {
            throw out_of_range("Число повинно бути двоцифровим!");
        }

        int tens = number / 10;
        int units = number % 10;
        int sum = tens + units;
        int product = tens * units;

        wcout << L"Кількість десятків = " << tens << endl;
        wcout << L"Кількість одиниць = " << units << endl;
        wcout << L"Сума цифр = " << sum << endl;
        wcout << L"Добуток цифр = " << product << endl;
    }
    catch (const exception& e) {
        wcout << L"Помилка: " << e.what() << endl;
    }

    system("pause");
    return 0;
}