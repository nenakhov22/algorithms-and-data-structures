[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7089652&assignment_repo_type=AssignmentRepo)
# Задание 0 для тестирования
Набор положительных чисел a_1, a_2, ..., a_k называется разбиением натурального числа n, если n = a_1 + a_2 + ... + a_k, где a_1 ⩾ a_2 ⩾...⩾ a_k > 0.

Например, существует 5 различных разбиений числа n=4:
* 1+1+1+1
* 2+1+1
* 2+2
* 3+1
* 4

Необходимо для заданных чисел n и k вычислить число разбиений n на k частей.

Числа n и k пользователь вводит с клавиатуры (n,k⩽500). Результатом работы программы является выведенное в консоль число разбиений n на k частей.

### Пример
**Вход:** `4 2`

**Выход:** `2`

Шаблон программы приведен в файле `task.cpp`. В нём необходимо написать реализацию функции `partition`.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7214865&assignment_repo_type=AssignmentRepo)
# Задание 1: Очередь с минимумом
Реализуйте работу очереди. На вход программе подаются строки, содержащие команды. Каждая строка содержит одну команду. 
* Команда «+ X» означает добавление в очередь числа X, по модулю не превышающего 10^9. 
* Команда «−» означает изъятие элемента из очереди. 
* Команда «?» означает поиск минимального элемента в очереди.

**Входной файл.** В первой строке содержится N (1 ≤ N ≤ 10^6) — число команд. В последующих строках содержатся команды, по одной в каждой строке.

**Выходной файл.** Для каждой операции поиска минимума в очереди выведите её результат. Результаты должны быть выведены в том порядке, в котором эти операции встречаются во входном файле. Входные данные гарантируют, что операции извлечения или поиска минимума для пустой очереди не производятся.

## Пример
Вызов программы `queuemin queuemin.in queuemin.out`

queuemin.in
```
7
+ 1
?
+ 10
?
-
?
-
```

queuemin.out
```
1
1
10
```
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7290567&assignment_repo_type=AssignmentRepo)
# Задание 2: Поиск медианы
Во время аккредитации эксперту необходимо провести собеседование с обучающимися по образовательной программе. Но студентов достаточно много и побеседовать со всеми у эксперта нет возможности, поэтому он попросил учебный отдел выбрать троих представителей: студент с самым низким «средним баллом зачетки», студент со средним «средним баллом зачетки» и студент с самым высоким «средним баллом зачётки». Считается, что у студента на образовательной программе средний «средний балл зачетки», если при сортировке студентов по среднему баллу он оказывается ровно посередине списка. Известно, что количество студентов нечетное (3 ≤ n ≤ 99999). 

Известно, что у каждого студента есть уникальный идентификационный номер, значение которого расположено в границах от 1 до n. Информация о среднем балле зачетки хранится в массиве M таким образом, что средний балл студента с идентификационным номером i, содержится в ячейке M[i]. Помогите сотруднику учебного отдела вычислить идентификационные номера студентов, которые будут приглашены на встречу с экспертом.

### Формат входного файла
Первая строка входного файла содержит число студентов n (3 ≤ n ≤ 99999, n нечетно). Вторая строка содержит описание массива M, состоящее из n положительных вещественных чисел, разделенных пробелами. Гарантируется, что все элементы массива M различны, их значения имеют точность не более двух знаков после запятой.

### Выход
Выведите в консоль три целых положительных числа, разделенных пробелами — идентификационные номера самого слабого, среднего и самого сильного студента.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7433808&assignment_repo_type=AssignmentRepo)
# Задание 3: Число инверсий
Инверсией в последовательности чисел Xi, i=1…n называется такая ситуация, когда i < j, а Xi > Xj.

Дан массив целых чисел. Задача — подсчитать число инверсий в нем.

Подсказка: чтобы сделать это быстрее, можно воспользоваться модификацией сортировки слиянием.

## Формат входного файла 
В первой строке входного файла содержится число n (1 ≤ n ≤ 100 000) — число элементов в массиве. Во второй строке находятся n целых чисел, по модулю не превосходящих 10^9.

## Формат выходного файла
В выходной файл надо вывести число инверсий в массиве.

## Пример
Вызов программы `inversions inversions.in inversions.out`

inversions.in
```
10
1 8 2 1 4 7 3 2 3 6
```

inversions.out
```
17 
```
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7418159&assignment_repo_type=AssignmentRepo)
# Задание 4: K-ая порядковая статистика

Элементы массива получаются по рекуррентной формуле: x_{i} = A·x_{i-2} + B·x_{i-1} + C, i=3,4… 

В массиве из n элементов нужно найти k1-ое, (k1 + 1)-ое, …, k2-ое в порядке возрастания в этом массиве.

## Формат входного файла
В первой строке входного файла содержатся три числа: n — размер массива, а также границы интервала k1 и k2 (2 ≤ n ≤ 4·10^7, 1 ≤ k1 ≤ k2 ≤ n, k2 − k1 < 200). 

Во второй строке находятся числа A, B, C, x_1, x_2 по модулю не превосходящие 10^9. 

Вычисления элементов массива по формуле должны производится в 32-битном знаковом типе, переполнения должны игнорироваться.

## Формат выходного файла
В единственной строке выходного файла выведите k1-е, (k1 + 1)-ое, …, k2-е в порядке возрастания числа в массиве. Числа разделяйте одним пробелом.

Имена входного и выходного файла задаются в командной строке.

## Примеры
input1.txt
```
5 3 4
2 3 5 1 2
```
output1.txt
```
13 48
```

input2.txt
```
5 3 4
200000 300000 5 1 2
```
output1.txt
```
2 800005
```
Во втором примере элементы массива a равны: `(1, 2, 800005, −516268571, 1331571109)`.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7582704&assignment_repo_type=AssignmentRepo)
# Задание 5: LSD-сортировка
В первой строке входного файла содержится число N — число строк, число M — их длина и число K – число фаз цифровой сортировки (1 ≤ N ≤ 10^6, 1 ≤ K ≤ M ≤ 10^6). 

Далее, начиная со второй строки, по вертикали записаны строки, то есть вторая строка файла состоит из первых символов N строк, третья строка файла состоит из вторых символов N строк и т.д.

Необходимо вывести номера строк в порядке после K фаз цифровой сортировки по младшему разряду (LCD-сортировка, Least Significant Digit radix sort).

Имена входного и выходного файла заданы аргументами командной строки.

В примерах даны три строки:
* «abbb», имеющая индекс 1;
* «aaba», имеющая индекс 2;
* «bbaa», имеющая индекс 3.

## Пример 1
input.txt
```
3 4 1
aab
bab
bba
baa
```
output.txt
```
2 3 1
```
*Примечание.* Первая фаза цифровой сортировки отсортирует строки по последнему символу, таким образом, первой строкой окажется «aaba» (индекс 2), затем «bbaa» (индекс 3), затем «abbb» (индекс 1). Таким образом, ответ равен «2 3 1».

## Пример 2
input.txt
```
3 4 2
aab
bab
bba
baa
```
output.txt
```
3 2 1
```

## Пример 3
input.txt
```
3 4 3
aab
bab
bba
baa
```
output.txt
```
2 3 1
```

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7583749&assignment_repo_type=AssignmentRepo)
# Задание 6: Самобалансирующееся дерево

Реализовать контейнер множество с помощью самобалансирующегося AVL-дерева.

На вход программе подаются строки, содержащие команды. Каждая строка содержит одну команду. 
* Команда «+ X» означает добавление в множество числа X, по модулю не превышающего 10^9. 
* Команда «− X» означает изъятие элемента из множества. 
* Команда «? X» означает проверку наличия числа X в множестве.

## Входной файл
В первой строке содержится N (1 ≤ N ≤ 10^6) — число команд. В последующих строках содержатся команды, по одной в каждой строке.

## Выходной файл
* Для каждой операции «+ X» или «– X» вывести баланс корня дерева после выполнения операции. Если дерево пустое (в нем нет вершин), вывести 0. 
* Для каждой операции «? X» вывести её результат: true, если ключ есть в множестве, false – иначе. 
* Результаты должны быть выведены в том порядке, в котором эти операции встречаются во входном файле. 
* Вывод для каждой операции должен содержаться в отдельной строке.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7813043&assignment_repo_type=AssignmentRepo)
# Задание 7: B-tree
Реализовать контейнер множество с помощью B-tree.

На вход программе подаются строки, содержащие команды. Каждая строка содержит одну команду. 
* Команда «+ X» означает добавление в множество числа X, по модулю не превышающего 10^9. 
* Команда «− X» означает изъятие элемента из множества. 
* Команда «? X» означает проверку наличия числа X в множестве.

## Входной файл
В первой строке содержится два числа t и N — параметр дерева и число команд, 2 ≤ t ≤ 1000, 1 ≤ N ≤ 10^6. В последующих строках содержатся команды, по одной в каждой строке.

## Выходной файл
* Для каждой операции «+ X» или «– X» вывести информацию о корне дерева: количество элементов в корне и далее сами элементы через пробел. 
* Для каждой операции «? X» вывести её результат: true, если ключ есть в множестве, false – иначе. 
* Результаты должны быть выведены в том порядке, в котором эти операции встречаются во входном файле. 
* Вывод для каждой операции должен содержаться в отдельной строке.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7813054&assignment_repo_type=AssignmentRepo)
# Задание 8: Хэш-таблица
Реализовать контейнер множество с помощью хэш-таблицы, поддерживающий операции «добавление ключа», «удаление ключа», «проверка существования ключа».

На вход программе подаются строки, содержащие команды. Каждая строка содержит одну команду. 
* Команда «+ X» означает добавление в множество числа X, по модулю не превышающего 10^9. 
* Команда «− X» означает изъятие элемента из множества. 
* Команда «? X» означает проверку наличия ключа X в множестве.

## Входной файл
В первой строке содержится N (1 ≤ N ≤ 10^6) — число команд. В последующих строках содержатся команды, по одной в каждой строке.

## Выходной файл
* Для каждой операции «? Х» вывести её результат: true, если ключ есть в множестве, false – иначе. 
* Результаты должны быть выведены в том порядке, в котором эти операции встречаются во входном файле. 
* Вывод для каждой операции должен содержаться в отдельной строке.

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7858415&assignment_repo_type=AssignmentRepo)
# Задание 9: Очередь с приоритетами
Реализуйте очередь с приоритетами. Очередь должна поддерживать следующие операции: 
* добавить элемент, 
* извлечь минимальный элемент, 
* уменьшить элемент, добавленный во время одной из операций.

Все операции нумеруются по порядку, начиная с единицы. Гарантируется, что число команд, а также и размер очереди в процессе выполнения команд, не превысит 10^5.

## Формат входного файла
Входной файл содержит описание операций с очередью. Операции могут быть следующими:
* `push x` — требуется добавить элемент x в очередь;
* `extract-min` — требуется удалить из очереди минимальный элемент и вывести его в выходной файл. Если очередь пуста, в выходной файл требуется вывести звездочку «∗»;
* `decrease-key x y` — требуется заменить значение элемента, добавленного в очередь операцией push в строке входного файла номер `x`, на `y`. Гарантируется, что на строке `x` действительно находится операция `push`, что этот элемент не был ранее удален операцией `extract-min`, и что `y` меньше, чем предыдущее значение этого элемента.

В очередь помещаются и извлекаются только целые числа, не превышающие по модулю 10^9 .

## Формат выходного файла
Выведите последовательно результат выполнения всех операций `extract-min`, по одному в каждой строке выходного файла. Если перед очередной операцией `extract-min` очередь пуста, выведите вместо числа звездочку «∗».

## Пример
**input.txt**
```
push 3
push 4
push 2
extract-min
decrease-key 2 1
extract-min
extract-min
extract-min
```

**output.txt**
```
2
1
3
*
```

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7933072&assignment_repo_type=AssignmentRepo)
# Задание 10: Быстрый поиск
Даны строки X и Y. Требуется найти все вхождения строки X в строку Y в качестве подстроки.

Использование сторонних библиотек возбраняется.

## Формат входного файла
Первая строка входного файла содержит X, вторая — Y (1 ≤|X|,|Y|≤ 10^6). 

## Формат выходного файла
В первой строке выведите количество вхождений строки X в строку Y. Во второй строке выведите в возрастающем порядке номера символов строки Y, с которых начинаются вхождения X. Символы нумеруются с единицы.

## Пример
**input.txt**
```
aba
abaCaba
```

**output.txt**
```
2
1 5
```
