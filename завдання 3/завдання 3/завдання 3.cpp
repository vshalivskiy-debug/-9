#include <iostream>
#include <cmath>
#include <stdexcept>
#include <windows.h> // для кирилиці в консолі

using namespace std;

int main() {
    // Налаштування консолі для української мови
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        double a, b;

        cout << "Введіть довжину першого катета: ";
        cin >> a;
        if (a <= 0) throw invalid_argument("Довжина катета має бути додатною.");

        cout << "Введіть довжину другого катета: ";
        cin >> b;
        if (b <= 0) throw invalid_argument("Довжина катета має бути додатною.");

        // Перевірка на можливість існування прямокутного трикутника
        if (a <= 0 || b <= 0)
            throw logic_error("Трикутник з такими катетами не існує.");

        // Обчислення гіпотенузи
        double c = sqrt(a * a + b * b);

        // Обчислення периметра
        double perimeter = a + b + c;

        cout << "Периметр прямокутного трикутника = " << perimeter << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    system("pause");
    return 0;
}