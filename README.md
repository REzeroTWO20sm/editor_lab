#  Лабораторная работа по созданию простого консольного editor
## При создании использовался паттерн кОмманд

### Введение

Паттерн Command — это поведенческий паттерн, инкапсулирующий запрос в виде объекта. Это позволяет гибко управлять выполнением операций.

### Компоненты

* Интерфейс Command (Command): Определяет метод `execute()`, выполняющий конкретную операцию.
* Конкретные команды (Commands): Реализуют интерфейс Command и содержат логику выполнения определенной операции.
* Получатель (Editor): Класс, содержащий методы, которые фактически выполняют операции.
* Вызывающий (Invoker): Класс, вызывающий команду, активируя метод `execute()`.

### Преимущества

* Разделение ответственности: Логика вызова операции отделена от ее выполнения.
* Отмена/Повтор: Легко реализовать стек команд для отмены и повтора действий.
* Макрокоманды: Можно создавать составные команды из нескольких простых.
* Очередь команд: Команды можно ставить в очередь для асинхронного выполнения.

### Применение в C++

* Графические интерфейсы: Обработка событий пользователя.
* Обработка транзакций: Группировка операций в атомарные единицы.
* Многопоточность: Постановка задач в очередь для выполнения в разных потоках.

### Заключение

Паттерн Command — мощный инструмент для создания гибких и расширяемых приложений на C++. Он помогает отделить логику вызова операций от их выполнения, улучшает поддержку отмены/повтора и способствует модульности кода.

![Govno](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExODk0ZDZhZWVtMWczOTAzaHpqYm11ZWplcHVrdTc2Nmk0M25lOGxvZCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/3o7bug2wkdhpf7kbFS/giphy.gif)