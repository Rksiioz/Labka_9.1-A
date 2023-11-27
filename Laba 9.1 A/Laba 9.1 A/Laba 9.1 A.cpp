#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

enum Spec {
    RI = 1,
    KI,
    VP,
    PZ
};

struct Student {
    int id;
    std::string surname;
    int course;
    Spec spec;
    int physics;
    int math;
    int it;
};


void Create(Student* students, int N) {
    int spec;

    for (int i = 0; i < N; i++) {
        students[i].id = i + 1;

        std::cout << "Прізвище: "; std::cin >> students[i].surname;
        std::cout << "Курс: "; std::cin >> students[i].course;
        std::cout << "Спеціальність (" <<
            "РІ: " << RI << ", " <<
            "КІ: " << KI << ", " <<
            "ВП: " << VP << ", " <<
            "ПЗ: " << PZ << "):" << std::endl;

        std::cin >> spec;
        students[i].spec = (Spec)spec;

        std::cout << "Фізика: "; std::cin >> students[i].physics;
        std::cout << "Математика: "; std::cin >> students[i].math;
        std::cout << "Інформатика: "; std::cin >> students[i].it;
        cout << endl;
    }
}

std::string getSpecStr(Spec s) {
    switch (s) {
    case RI:
        return "РІ";
    case KI:
        return "КІ";
    case VP:
        return "ВП";
    case PZ:
        return "ПЗ";
    default:
        return "Невідома";
    }
}

void PrintHeader() {
    cout << "============================================================================"
        << endl;
    cout << "| №  | Прізвище | Спеціальність | Курс | Фізика | Математика | Інформатика |"
        << endl;
    cout << "============================================================================"
        << endl;
}

void Print(const Student* p, int N) {
    PrintHeader();

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout
            << "| " << setw(8) << right << p[i].surname << " "
            << "| " << setw(15) << left << getSpecStr(p[i].spec)
            << "| " << setw(5) << right << p[i].course
            << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math
            << "| " << setw(11) << right << p[i].it << "|" << endl;
        cout << "----------------------------------------------------------------------------";
        cout << endl;
    }
    cout << endl;
}

double average1(Student& p) {
    return ((double)p.physics + (double)p.it + (double)p.math) / 3.0;
}

double Tusk1(Student* p, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
       if(average1(p[i]) > 4.5) {
           count++;
       }
    }
   return ((double)count / N) * 100;
}

void Tusk2(Student* p, int N) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (p[i].physics == 5 && p[i].math == 5 && p[i].it == 5) {
            cout << "Студенти які вчаться на відмінно: \n" << p[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Відмінників немає" << endl;
    }
}

int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

     int N;
     cout << "Введіть N: "; cin >> N;
     cout << endl;

    Student* a = new Student[N];

    Create(a, N);

    Print(a, N);

    cout << "% студентів у яких середній бал більший за 4.5: " << Tusk1(a, N) << endl;

    Tusk2(a, N);

    delete[] a;
    return 0;

}