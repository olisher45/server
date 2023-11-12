#ifndef SERVER_H
#define SERVER_H

#include <QByteArray>

/**
 * @brief Класс Server представляет собой синглтон для управления сервером.
 *
 * Этот класс обеспечивает авторизацию, регистрацию, отправку заданий, проверку заданий,
 * управление подключениями и другие функции, связанные с обработкой запросов от клиентов.
 */
class Server
{
private:
    Server();
    Server(const Server& );
    Server& operator = (Server &);
    static inline Server *p_instance = nullptr;

private:
    /**
     * @brief wrong_user_message вызывается при неверных сообщениях от пользователя.
     * @return QByteArray с ответом сервера.
     */
    QByteArray wrong_user_message();

    /**
     * @brief auth авторизует подключение пользователя.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @return QByteArray с ответом сервера.
     */
    QByteArray auth(QString login, QString password);

    /**
     * @brief reg регистрирует пользователя (добавляет информацию о нём в базу данных).
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @param userType Тип пользователя.
     * @param loginTeacher Логин преподавателя (если применимо).
     * @return QByteArray с ответом сервера.
     */
    QByteArray reg(QString login, QString password, int userType, QString loginTeacher);

    /**
     * @brief check_auth проверяет, авторизировано ли данное устройство.
     * @param userKey Уникальный ключ пользователя.
     * @return true, если устройство авторизовано, false в противном случае.
     */
    bool check_auth(int userKey);

    /**
     * @brief task_is_done отдаёт задание на проверку и возвращает ответ.
     * @param userKey Уникальный ключ пользователя.
     * @param taskNumber Номер задания.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return QByteArray с ответом сервера.
     */
    QByteArray task_is_done(int userKey, int taskNumber, int taskKey, QString answer);

    /**
     * @brief reset_connections сбрасывает подключения для зарегистрированных пользователей.
     * @return QByteArray с ответом сервера.
     */
    QByteArray reset_connections();

    /**
     * @brief get_task генерирует задание и передает клиенту условие задания и его уникальный номер.
     * @param taskNumber Номер задания.
     * @return QByteArray с ответом сервера.
     */
    QByteArray get_task(int taskNumber);

    /**
     * @brief check_task проверяет задание, генерируя условие задания по номеру задания и его уникальному ключу.
     * @param taskNumber Номер задания.
     * @param taskKey Уникальный ключ задания.
     * @param answer Ответ пользователя.
     * @return true, если задание выполнено верно, false в противном случае.
     */
    bool check_task(int taskNumber, int taskKey, QString answer);

    /**
     * @brief user_logout удаляет подключения для пользователя с данными логином и паролем.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @return QByteArray с ответом сервера.
     */
    QByteArray user_logout(QString login, QString password);

    /**
     * @brief del_group удаляет группу заданного преподавателя.
     * @param userKey Уникальный ключ пользователя (преподавателя).
     * @return QByteArray с ответом сервера.
     */
    QByteArray del_group(int userKey);

    /**
     * @brief is_it_a_teacher проверяет, является ли пользователь преподавателем.
     * @param userKey Уникальный ключ пользователя.
     * @return true, если пользователь - преподаватель, false в противном случае.
     */
    bool is_it_a_teacher(int userKey);

    /**
     * @brief get_students_list если запрос идет от преподавателя, возвращает список логинов его студентов.
     * @param userKey Уникальный ключ пользователя (преподавателя).
     * @return QByteArray с ответом сервера.
     */
    QByteArray get_students_list(int userKey);

    /**
     * @brief get_statistics если запрос идет от преподавателя, возвращает статистику по заданию ученика.
     * @param userKey Уникальный ключ пользователя (преподавателя).
     * @param studentLogin Логин ученика.
     * @param taskNumber Номер задания.
     * @return QByteArray с ответом сервера.
     */
    QByteArray get_statistics(int userKey, QString studentLogin, int taskNumber);

public:
    /**
     * @brief getInstance возвращает экземпляр синглтона Server.
     * @return Указатель на экземпляр Server.
     */
    static Server* getInstance();

    /**
     * @brief parse принимает сообщение пользователя и возвращает ответ подходящей функции.
     * @param userMessage Сообщение пользователя.
     * @return QByteArray с ответом сервера.
     */
    QByteArray parse(QString userMessage);
};

#endif // SERVER_H
