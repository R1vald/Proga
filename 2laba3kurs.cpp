#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

typedef unsigned long ul;
typedef unsigned int ui;

ul CalcDayNumFromDate(ui d, ui m, ui y)  // принимает дату в формате yy/mm/dd
{
    m = (m + 9) % 12;
    y -= m / 10;
    ul dn = 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);

    return dn;
}


string CalcDayOfWeek(ul d, ul m, int y)
{
    string day[] = {
      "Среда",
      "Четверг",
      "Пятница",
      "Суббота",
      "Воскресенье",
      "Понедельник",
      "Вторник"
    };

    ul dn = CalcDayNumFromDate(d, m, y);

    return day[dn % 7];
}

int main()
{
    setlocale(LC_ALL, "rus");
    ui d = 0, m = 0, y = 0;
    int z;
    bool flag = true;
    system("cls");
    while (flag)
    {
        cout << "Выберите команду:\n";
        cout << "1) Вызвать функцию 2) Выход" << endl;
        int a; cin >> a;
        switch(a)
        {
        case 1: //Вызов функции
        {
            cout << "Введите произвольную дату в формате (день/месяц/год)" << endl;
            cin >> d >> m >> y;
            std::string dow = CalcDayOfWeek(d, m, y);
            
            cout << d << "/";
            cout << m << "/";
            cout << y << ": ";
            cout << dow << std::endl;
            
        }
        break;
        case 2: //Выход из цикла
        {
            flag = false;
        }
        }
       
    }
    system("pause");
    return 0;
};

//cout << "Введите произвольную дату в формате (день/месяц/год)" << endl;
//cin >> d >> m >> y;
//std::string dow = CalcDayOfWeek(d, m, y);
//
//cout << d << "/";
//cout << m << "/";
//cout << y << ": ";
//cout << dow << std::endl;
//Sleep(5000);

