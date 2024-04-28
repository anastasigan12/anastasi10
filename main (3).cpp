#include <iostream>

using namespace std;

// Оголошення структури TTime
struct TTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Функція для зменшення часу на 1 секунду
void PrevSec(TTime &t) {
    if (t.second > 0) {
        --t.second;
    } else if (t.minute > 0) {
        --t.minute;
        t.second = 59;
    } else if (t.hour > 0) {
        --t.hour;
        t.minute = 59;
        t.second = 59;
    } else {
        // Нічого не робимо, якщо час невідомий (00:00:00)
    }
}

// Функція для розрахунку площі кільця на основі радіусів колів
void calculateRingArea() {
    const double PI = 3.14;
    double R1, R2;

    cout << "Введіть радіус більшого кола: ";
    cin >> R1;

    cout << "Введіть радіус меншого кола: ";
    cin >> R2;

    if (R1 <= R2) {
        cout << "Неправильні значення радіусів!" << endl;
        return;
    }

    double S1 = PI * R1 * R1; // Площа більшого кола
    double S2 = PI * R2 * R2; // Площа меншого кола
    double S3 = S1 - S2;      // Площа кільця

    cout << "Площа більшого кола: " << S1 << endl;
    cout << "Площа меншого кола: " << S2 << endl;
    cout << "Площа кільця: " << S3 << endl;
}

// Функція для перевірки, чи всі цифри числа унікальні
bool isUnique(int num) {
    int digit1 = num % 10;        // Отримати одиницю
    int digit2 = (num % 100) / 10; // Отримати десяток
    int digit3 = num / 100;        // Отримати сотню

    if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
        return false;
    } else {
        return true;
    }
}

// Основна функція
int main() {
    // Приклад використання функції PrevSec
    TTime times[] = {
        {2024, 4, 28, 17, 58, 30},
        {2024, 4, 28, 17, 58, 0},
        {2024, 4, 28, 17, 57, 59},
        {2024, 4, 28, 17, 57, 0},
        {2024, 4, 27, 0, 0, 0}
    };

    for (TTime& t : times) {
        cout << "Before: " << t.year << "-" << t.month << "-" << t.day << " "
             << t.hour << ":" << t.minute << ":" << t.second << endl;
        PrevSec(t);
        cout << "After:  " << t.year << "-" << t.month << "-" << t.day << " "
             << t.hour << ":" << t.minute << ":" << t.second << endl;
    }

    // Виклик функції для обчислення площі кільця
    calculateRingArea();

    // Виклик функції для перевірки унікальності цифр у числі
    int num;
    cout << "Введіть тризначне число: ";
    cin >> num;

    if (num < 100 || num >= 1000) {
        cout << "Неправильне значення числа!" << endl;
        return 1;
    }

    bool unique = isUnique(num);

    if (unique) {
        cout << "Всі цифри числа різні" << endl;
    } else {
        cout << "Всі цифри числа НЕ різні" << endl;
    }

    return 0;
}