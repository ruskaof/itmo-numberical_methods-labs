
# Лабораторная работа 1. Системы линейных алгебраических уравнений
## Вариант: метод Гаусса
В лабораторной работе Вам предлагается реализовать один из методов, который бы
позволял находить столбец неизвестных для системы линейных алгебраических уравнений.
Необходимо сделать следующие методы ввода данных в программу:
* Пользовательский ввод;
* Ввод данных из файла;
* Генерация случайных матриц.

Для прямых методов (метод Гаусса и метод Гаусса с выбором главных элементы) должно быть
реализовано:
* Вычисление определителя;
* Вывод треугольной матрицы (включая преобразованный столбец В);
* Столбец неизвестных;
* Столбец невязок.

Время работы программы на матрице размера 1500x1501: ~5300мс на Release версии программы.
## `CMake` build types:

Debug (`std=c++17 -Wall -Werror -g`)

Sanitized (`fsanitize=address,undefined,leak`)

Release (`std=c++17 -Wall -Werror -g -O3`)
