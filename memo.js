alert("Hello World!"); // Всплывающее окно до показа страницы

function testComment(a, b) { // Функция
    var x;
    x = a * b;    
    return x;
 }
 
/* 
Регистр важен - x, X - разные переменные
Переменная начинается с буквы, $, _ (далее включаются только цифры)
Переменная не называется ключевыми словами: break, delete, function, return, typeof, case, do, if, switch, var, catch, else, in, this, void, 
                                            continue, false, instanceof, throw, while, debugger, finally, new, true, with, default, for, null, try
                                            (class, const, enum, export, extends, import, super) [зарезервированные, не часть языка]
                                            (implements, let, private, public, yield, interface, package, protected, static) [просто низя]

Инициализация:
    let studentName = "Vasiliy"; [видна только внутри блока {...}, только после объявления, на каждой итерации цикла независимые переменные]
    var x = 1; [переменная видна и до объявления, переживёт цикл]
    x = 1;
Присвоение:
    studentName = "Vasiliy";
 */ 