#include <iostream>
#include <cmath>
#include <stdexcept>
#include <io.h>
#include <fcntl.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class Ring {
private:
    double outerRadius;
    double innerRadius;

public:
    Ring(double R, double r) {
        if (R <= 0 || r <= 0)
            throw invalid_argument("Радіуси повинні бути додатними числами!");
        if (r >= R)
            throw invalid_argument("Внутрішній радіус не може бути більший або рівний зовнішньому!");
        outerRadius = R;
        innerRadius = r;
    }

    double area() const {
        return M_PI * (outerRadius * outerRadius - innerRadius * innerRadius);
    }
};

int main() {
    // Підтримка української в консолі
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    double R, r;
    wcout << L"Введіть зовнішній радіус кільця: ";
    wcin >> R;
    wcout << L"Введіть внутрішній радіус кільця: ";
    wcin >> r;

    try {
        Ring ring(R, r);
        wcout << L"Площа кільця = " << ring.area() << endl;
    }
    catch (const exception& e) {
        wcout << L"Помилка: " << e.what() << endl;
    }

    system("pause");
    return 0;
}