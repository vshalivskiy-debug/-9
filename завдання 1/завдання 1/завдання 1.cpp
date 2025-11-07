#include <iostream>
#include <cmath>      // sqrt
#include <iomanip>    // setprecision
#include <clocale>    // setlocale

int main()
{
    // Спробуємо налаштувати локаль (для виводу українських повідомлень)
    std::setlocale(LC_ALL, "");

    double S;
    std::cout << "Введіть площу квадрата: ";
    if (!(std::cin >> S)) {
        std::cerr << "Помилка вводу. Введіть числове значення.\n";
        return 1;
    }

    if (S <= 0.0) {
        std::cout << "Площа повинна бути більшою за нуль!\n";
        return 0;
    }

    double a = std::sqrt(S);        // сторона
    double P = 4.0 * a;             // периметр

    std::cout << std::fixed << std::setprecision(4); // точність — 4 знаки, змінюй за потреби
    std::cout << "Сторона квадрата: " << a << '\n';
    std::cout << "Периметр квадрата: " << P << '\n';

    return 0;
}