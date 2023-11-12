#include "taskmanager.h"
#include <ctime>
#include <QVector>

TaskManager::TaskManager()
{

}

TaskManager *TaskManager::getInstance()
{
    if (!p_instance)
        p_instance = new TaskManager();
    return p_instance;
}

QString TaskManager::create_task(int taskNumber)
{
    std::srand(std::time(nullptr));
    int taskKey = 1+rand()%10000;
    QString taskText = "123";

    switch (taskNumber) {
    case 1:
        return create_task1(taskKey);
        break;
    case 2:
        return create_task2(taskKey);
        break;
    default:
        return QString("error");
        break;
    }
}

bool TaskManager::check_task(int taskNumber, int taskKey, QString answer)
{
    switch (taskNumber) {
    case 1:
        return check_task1(taskKey,answer);
    case 2:
        return check_task2(taskKey,answer);
    default:
        return false;
    }
}

bool TaskManager::check_task1(int taskKey, QString answer)
{
    srand(taskKey);
    QVector<QVector<int>> matrix(3,QVector<int>(3,0));
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = rand()%199-99;
        }
    }
    // Вычисление определителя по методу Лапласа
    int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
          - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
          + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    if (det == answer.toInt()) {
        return true;
    } else {
        return false;
    }
}

bool TaskManager::check_task2(int taskKey, QString answer)
{
    srand(taskKey);
    QVector<int> vector;
    for(int i = 0; i < 8; i++) {
        vector.push_back(rand()%2);
    }
    int vars = 3;
    int truth_table[8][3] = {{0,0,0}, {0,0,1}, {0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    const char LETTER[] = "ABC";
    const int MAX = 8;
    int trinagle[64][64];
    QString s;
    for (int i = 0; i < MAX; i++) {
        trinagle[0][i] = vector[i];
    }
    printf("\n");

    int trin_max = MAX - 1;

    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < trin_max; j++) {
            trinagle[i][j] = trinagle[i - 1][j] ^
                             trinagle[i - 1][j + 1];
        }
        trin_max--;
    }
    if (trinagle[0][0]) s += "1";
    for (int i = 0; i < MAX; i++) {
        if (trinagle[i][0]) {
            for (int j = 0; j < vars; j++) {
                if (truth_table[i][j]) {
                    s += LETTER[j];
                }
            }
            if (i != MAX) s += "+";
        }
    }
    if (s[s.size()-1]=='+'){
        s.chop(1);
    }
    QStringList answer1 = answer.split("+");
    QStringList corrAns = s.split("+");
    answer1.sort();
    corrAns.sort();
    if (answer1.size() != corrAns.size()) {
        return false;
    } else {
        for (int i = 0; i < answer1.size(); i++) {
            if (answer1[i] != corrAns[i]) return false;
        }
        return true;
    }
}

QString TaskManager::create_task1(int taskKey)
{
    srand(taskKey);
    QString data;
    for(int i = 0; i < 9; i++) {
        data.append(QString::number(rand()%199-99) + " ");
    }
    QString taskText = "Дана квадратная матрица размера 3х3. Найти её определитель.";
    return QString("1") + QString("$") + QString::number(taskKey) + QString("$") + taskText + QString("$") + data;
}

QString TaskManager::create_task2(int taskKey)
{
    srand(taskKey);
    QString data;
    for(int i = 0; i < 8; i++) {
        data.append(QString::number(rand()%2) + " ");
    }
    QString taskText = "Дана функция трёх переменных A,B,C; заданная значением строк матрицы истинности. Построить полином жегалкина.";
    return QString("2") + QString("$") + QString::number(taskKey) + QString("$") + taskText + QString("$") + data;
}
