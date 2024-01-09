#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Массив данных для 1-й задачи в расписании
struct task {
    // День недели, чч:мм:сс - время начала работы, продолжительность работы в часах
    int day=10, h, m, s, time_h;
    // Имя работника, название цеха
    string name_employee, name_workwhop;
};

// Объявление лобальных переменных
string SHEDULE_PATH = "shedule.txt";
int N_TASKS;
struct task TASKS[100];

// Объявление функций
void upload_shedule();
void menu();
void show_shedule();
void add_to_shedule();
void sort_shedule();
void delete_task_in_shedule();


// Сортировка расписания по дням недели, по времени началу работы
bool fucntion_compare(task &a, task &b) {
    return ((a.day*86400 + a.h*3600 + a.m*60 + a.s) < (b.day*86400 + b.h*3600 + b.m*60 + b.s)); 
}
void sort_shedule() {
    sort(TASKS, TASKS + N_TASKS, fucntion_compare);
}

// Функция загрузки расписания из файла
void upload_shedule() {
    fstream shedule;
    shedule.open(SHEDULE_PATH);
    N_TASKS = -1;
    cout << "Подгрузка началась..." << endl;

    while (!shedule.eof()) {
        N_TASKS++;
        shedule >> TASKS[N_TASKS].day;
        shedule.eof();
        shedule >> TASKS[N_TASKS].name_employee;
        shedule.eof();
        shedule >> TASKS[N_TASKS].name_workwhop;
        shedule.eof();
        shedule >> TASKS[N_TASKS].h;
        shedule.eof();
        shedule >> TASKS[N_TASKS].m;
        shedule.eof();
        shedule >> TASKS[N_TASKS].s;
        shedule.eof();
        shedule >> TASKS[N_TASKS].time_h;
    }
    shedule.close();
    cout << "Подгрузка закончилась..." << endl;
    sort_shedule();
    cout << "Расписание отсортировано." << endl;
    menu();
}


void menu() {
    setlocale(LC_ALL, "rus");
    int a;
    cout << " 1) Просмотр расписания на неделю " << endl
         << " 2) Добавление рабочих часов " << endl
         << " 3) Удаление из расписания " << endl
         << " 4) Выход из программы " << endl;
    cin >> a;

    switch (a) {
    case 1:
        show_shedule();
        menu();
        break;
    case 2:
        add_to_shedule();
        break;
    case 3:
        delete_task_in_shedule();
        break;
    case 4:
        cout << "Завершение работы..." << endl;
        break;
    default:
        cout << "Неправильное значение. Попробуйте ещё раз!" << endl;
        menu();
        break;
    }    
}

// Просмотр расписания на неделю
void show_shedule() {
    setlocale(LC_ALL, "rus");
    string week[] = {"понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресение"};

    for (int i = 0; i < N_TASKS; i++) {   
        cout << "Задание " << i << " | День: " << week[TASKS[i].day - 1] << ", Рабочий: " << TASKS[i].name_employee << ", Цех «" << TASKS[i].name_workwhop;
        printf("», Время начала работы: %d:%d:%d, Время работы: %d час(а/ов). \n", TASKS[i].h, TASKS[i].m, TASKS[i].s, TASKS[i].time_h);
    }
}

// Добавить в конце файла запись в расписании
void add_to_shedule() {
    setlocale(LC_ALL, "rus");
    int day, h, m, s, time_h;
    string person, workshop;
    cout << "Создание записи в расписании\nВведите день (1-понедельник, 7-воскресение): ";
    cin >> day;
    if (int(day) > 7 && int(day) < 1) {
        cout << "День недели должен быть числом в диапозоне [1, 7]!" << endl;
        add_to_shedule();
    }
    cout << "Введите имя работника и название цеха:" << endl;
    cin >> person;
    cin >> workshop;
    cout << "Введите время началы работы в формате [чч мм сс] и время работы в часах:" << endl;
    cin >> h;
    cin >> m;
    cin >> s;
    cin >> time_h;

    fstream shedule;
    shedule.open(SHEDULE_PATH, ios::app);
    shedule << "\n" << day << " " << person << " " << workshop << " " << h << " " << m << " " << s << " " << time_h;
    shedule.close();
    N_TASKS++;
    cout << "Задача добавлена в расписание!" << endl;
    upload_shedule();
}

void delete_task_in_shedule() {
    setlocale(LC_ALL, "rus");
    int n;
    show_shedule();
    printf("Вот список заданий на неделю. Какое задание удалить? Выберите число в диапазоне [0, %d]: ", N_TASKS-1);
    cin >> n;
    if (n < 0 && n >= N_TASKS) {
        cout << "Неправильный номер задания!" << endl;
        menu();
    }
    else {
        for (int i = n; i < N_TASKS; ++i) {
            TASKS[i] = TASKS[i + 1];
        }
        N_TASKS--;
        fstream shedule;
        shedule.open(SHEDULE_PATH, std::ios::out);
        // shedule.clear();
        for (int i = 0; i < N_TASKS; ++i) {
            cout << TASKS[i].name_employee  << TASKS[i].day << endl;
            shedule << '\n' << TASKS[i].day << " " << TASKS[i].name_employee << " " << TASKS[i].name_workwhop << " " << TASKS[i].h << " " << TASKS[i].m << " " << TASKS[i].s << " " << TASKS[i].time_h;
        }
        shedule.close();
        upload_shedule();
    };
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Система планирования часов работы сотрудников на производстве." << endl;
    upload_shedule();
}
