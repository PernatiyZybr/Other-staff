alert("Hello World!"); // Всплывающее окно до показа страницы

function testComment(a, b) { // Функция
    var x;
    x = a * b;    
    return x;
 }
 
/* ПЕРЕМЕННЫЕ
Регистр важен - x, X - разные переменные
Переменная начинается с буквы, $, _ (далее включаются только цифры)
Переменная не называется ключевыми словами: break, delete, function, return, typeof, case, do, if, switch, var, catch, else, in, this, void, 
                                            continue, false, instanceof, throw, while, debugger, finally, new, true, with, default, for, null, try
                                            (class, const, enum, export, extends, import, super) [зарезервированные, не часть языка]
                                            (implements, let, private, public, yield, interface, package, protected, static) [просто низя]

Инициализация:
    var x = 1; [переменная видна и до объявления, переживёт цикл][локальная переменная]
    x = 1; [глобальная переменная, если до этого не было с таким же именем]
Присвоение:
    let studentName = "Vasiliy"; [видна только внутри блока {...}, только после объявления, на каждой итерации цикла независимые переменные]
    studentName = "Vasiliy";
Локальные переменные уничтожаются при выходе из функции
Глобальнаые переменные уничтожаются при выходе со страницы [var]

Типы данных:
 - Числа (number)
 - Строки (string)
 - Логические (boolean): true, false
 - Неопределенные (undefined) [создали, но не присвоили]
 - Объект (object)
 - Пустой (null)
alert (typeof myName); - проверка типа переменной

Правила:
string + number = string

 */ 
