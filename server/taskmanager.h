#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QString>

/**
 * @brief Класс TaskManager представляет собой синглтон для управления заданиями.
 *
 * Этот класс предоставляет функциональность для генерации и проверки заданий.
 */
class TaskManager
{
private:
    TaskManager();
    TaskManager(const TaskManager& ) = delete;
    TaskManager& operator = (TaskManager &) = delete;
    static inline TaskManager *p_instance = nullptr;
    ~TaskManager();

public:
    /**
     * @brief getInstance возвращает экземпляр синглтона TaskManager.
     * @return Указатель на экземпляр TaskManager.
     */
    static TaskManager* getInstance();

    /**
     * @brief create_task генерирует одно из пяти заданий.
     * @param taskNumber Номер задания.
     * @return Строка с условием задания.
     */
    QString create_task(int taskNumber);

    /**
     * @brief check_task проверяет задание.
     * @param taskNumber Номер задания.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task(int taskNumber, int taskKey, QString answer);

private:
    /**
     * @brief check_task1 проверяет выполнение задания 1.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task1(int taskKey, QString answer);

    /**
     * @brief check_task2 проверяет выполнение задания 2.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task2(int taskKey, QString answer);

    /**
     * @brief check_task3 проверяет выполнение задания 3.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task3(int taskKey, QString answer);

    /**
     * @brief check_task4 проверяет выполнение задания 4.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task4(int taskKey, QString answer);

    /**
     * @brief check_task5 проверяет выполнение задания 5.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task5(int taskKey, QString answer);

    /**
     * @brief create_task1 генерирует условие задания 1.
     * @param taskKey Уникальный ключ задания.
     * @return Строка с условием задания.
     */
    QString create_task1(int taskKey = 0);

    /**
     * @brief create_task2 генерирует условие задания 2.
     * @param taskKey Уникальный ключ задания.
     * @return Строка с условием задания.
     */
    QString create_task2(int taskKey = 0);

    /**
     * @brief create_task3 генерирует условие задания 3.
     * @param taskKey Уникальный ключ задания.
     * @return Строка с условием задания.
     */
    QString create_task3(int taskKey = 0);

    /**
     * @brief create_task4 генерирует условие задания 4.
     * @param taskKey Уникальный ключ задания.
     * @return Строка с условием задания.
     */
    QString create_task4(int taskKey = 0);

    /**
     * @brief create_task5 генерирует условие задания 5.
     * @param taskKey Уникальный ключ задания.
     * @return Строка с условием задания.
     */
    QString create_task5(int taskKey = 0);
};

#endif // TASKMANAGER_H
