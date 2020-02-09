# CAOS 3 semester


## inf01


### inf01-0

На стандартном потоке ввода подается последовательно вещественное число x и целое число в 16-ричной записи y.

Единственным аргументов программы является целое число z в 27-ричной системе исчисления.

Необходимо вывести вычислить значение x+y+z и вывести его на стандартный поток вывода с точностью до 3-го знака после точки.

### inf01-1 

Реализуйте функцию с прототипом:

typedef enum {
    PlusZero      = 0x00,
    MinusZero     = 0x01,
    PlusInf       = 0xF0,
    MinusInf      = 0xF1,
    PlusRegular   = 0x10,
    MinusRegular  = 0x11,
    PlusDenormal  = 0x20,
    MinusDenormal = 0x21,
    SignalingNaN  = 0x30,
    QuietNaN      = 0x31
} float_class_t;

extern float_class_t
classify(double *value_ptr);
      
которая классифицирует специальные значения вещественного числа,
на которое указывает value_ptr, в соответствии со стандартом IEEE 754.
При решении допускается использовать только побитовые операции, включая сдвиги.

### inf01-2

Реализовать функцию с прототипом:

uint16_t satsum(uint16_t x, uint16_t y);
которая выполняет сложение с насыщением, то есть
в случае целочисленного переполнения возвращает максимально возможное целое число для данного типа данных.

В коде программы запрещено использовать константы, отличные от 0 и 1.
Запрещено использовать платформо-зависимые или компиляторо-зависимые функции,
типы данных с повышенной разрядностью или вещественные типы данных.

### inf01-3

В аргументах командной строки задаются целые неотрицательные числа
в шестнадцатеричной системе исчисления в синтаксисе языка Си.

Для каждого числа определить минимально необходимое количество байт,
которое требуется для того, чтобы можно было хранить эти числа.

### inf01-4

Реализуйте калькулятор выражений над множествами в обратной польской записи.

На стандартном потоке ввода задается последовательность, состоящая из символов-значений, и символов-операций.

Значениями являются цифры от 0 до 9, и буквы английского алфавита (заглавные и строчные).
Последовательности значений кодируют множества из 62 элементов.

Операциями являются:

& - пересечение множеств;
| - объединение множеств;
^ - симметрическая разность;
~ - дополнение текущего результата до полного множества.
В начальный момент времени, множество-результат является пустым.
При чтении символов со стандартного потока ввода, когда встречается символ операции,
то эта операция применяется к множеству-результату и последнему прочитанному множеству (как в обратной польской записи).

Вывести на экран полученное итоговое значение множества в нормализованной форме:
сначала цифры, затем заглавные буквы, потом - строчные (упорядоченные по алфавиту).

Для хранения множеств использовать, суммарно, не более 16 байт памяти.

### inf01-5

На стандартном потоке ввода подается последовательность символов в кодировке UTF-8.

Посчитать количество символов, которые могут быть представлены в кодирове ASCII, и количество символов, которые не могут быть представлены в этой кодировке.

На стандартный поток вывода вывести последовательно два эти числа.

В случае ошибки декодирования потока данных, необходимо вывести результаты подсчёта, полученные на момент обнаружения ошибки, и завершить работу программы с кодом ошибки 1.

Запрещается использовать какие-либо функции стандартной библиотеки, за исключением функций ввода. Используйте только битовые операции.

Не забывайте о том, что символ перевода строки \n является легальным ASCII-символом.


## inf02


### inf02-0

Реализуйте функцию с меткой f, которая вычисляет значение выражения y=Ax2+Bx+C

Значения A, B, C и x хранятся, соответсвенно, в регистрах r0, r1, r2 и r3.

Результат вычисления выражения сохраните в регистре r0.

Все аргументы и значение выражения представимы 32-разрядными знаковыми целыми числами.

Использовать оперативную память запрещено, - можно использовать только регистры.

### inf02-1

Реализуйте на языке ассемблера ARM функцию с сигнатурой:

int summ(int x0, int N, int *X)
Функция должна вычислять значение x0+∑xi, где 0<e;i<N

### inf02-2

Реализуйте функцию solve с прототипом
int solve(int A, int B, int C, int D);
которая находит минимальное значение x ∈[0,254], которое является одним из корней уравнения: Ax3+Bx2+Cx+D=0.

Все аргументы и значение выражения представимы 32-разрядными знаковыми целыми числами.
Не забывайте про сохраняемые регистры; можно использовать для этого память на стеке.
Гарантируется, что на тестовых данных существует целочисленное решение.


## inf03


### inf03-0

Реализуйте программу, которая вычисляет сумму двух целых десятичных чисел. Размер типа равен размеру машинного слова.

Можно использовать функции стандартной библиотеки языка Си scanf и printf.
В качестве точки входа можно считать функцию main.

### inf03-1

Напишите программу, которая читает со стандартного потока ввода последовательность символов, и выводит только те из них, которые являются десятичными цифрами от 0 до 9.

Можно использовать функции стандартной библиотеки языка Си: fgetc и fputc.
В качестве точки входа можно считать функцию main.

### inf03-2

Реализуйте программу, которая считывает символы со стандартного потока ввода, а затем выводит их в обратном порядке.

Можно использовать функции стандартной библиотеки языка Си: fgetc, fputc, realloc и free.
В качестве точки входа можно считать функцию main.


## inf04


### inf04-0

Реализуйте две функции на языке ассемблера x86 (IA-32) или x86-64 с сигнатурами:

extern int N;
extern int *A;
extern int *B;
extern int *R;
extern void summ();
extern void everyday795(int X, int Y);
      
Первая функция вычисляет значения Ri=Ai+Bi для всех i от 0 до N.

Вторая функция:
вводит с клавиатуры знаковое целое число;
умножает его на X;
прибавляет к нему Y;
выводит результат на экран.

### inf04-1

Реализуйте функцию на языке ассемблера x86 (IA-32) или x86-64 с сигнатурой:
extern void summ(int N, const int *A, const int *B, int *R);
      
Функция вычисляет значения Ri=Ai+Bi для всех i от 0 до N.
Память для хранения массива-результата уже выделена.


## inf05


### inf05-0

Реализуйте на языке ассемблера x86 (IA-32) или x86-64 две функции с сигнатурами:

extern double
calc(double A, double B, double C, int D);

extern void
vector_sum(int N, const float *A, const float *B, float *R);
Первая функция вычисляет значение выражения (A+B)/(C+D) и возвращает результат. Можно использовать как вычисления с помощью i387 FPU (только x86), так и с помощью инструкций SSE (x86 и x86-64).

Вторая функция вычисляет поэлементную сумму R[i]=A[i]+B[i]. Гарантируется, что число N больше нуля и кратно 4, а адреса массивов выровнены в памяти по границе 32 байта. Используйте векторные инструкции для вычисления.

### inf05-1

Реализуйте на языке ассемблера x86 (IA-32) или x86-64 функцию с сигнатурой:

extern double my_sin(double x)
которая вычисляет значение sin(x).

Запрещено использовать встроенные тригонометрические инструкции.

Для вычислений используйте известный вам из курса Математического анализа способ разложения функции в ряд. Точность результата должна быть маскимально возможной для типа данных double.


## inf06

### inf06-0

Реализуйте на языке ассемблера x86 или x86_64 программу, которая выводит "Hello, World!".

Использование стандартной библиотеки Си запрещено.
Точка входа в программу - функция _start.

### inf06-1

Реализуйте на языке ассемблера x86 или x86_64 программу, которая копирует содержимое со стандартного потока ввода на стандартный поток вывода.

Использование стандартной библиотеки Си запрещено.
Точка входа в программу - функция _start.


## inf07


### inf07-0

Программе в аргументах командной строки передаются три имени файла. Первый аргумент - входной файл, два остальных - выходные.

Реализуйте программу, которая читает символы из первого файла, во второй файл записывает только цифры, а в третий - всё остальное.

Разрешается использовать только низкоуровневый ввод-вывод POSIX.

Если входной файл не существует, то нужно завершить работу с кодом 1.
Если не возможно создать один из выходных файлов, то завершить работу с кодом 2.
При возникновении других ошибок ввода-вывода - завершить работу с кодом 3.

### inf07-1

Программе в аргументе командной строки передается имя файла с бинарными данными в Little-Endian.

Файл хранит внутри себя односвязный список элементов:

struct Item {
  int value;
  uint32_t next_pointer;
};
Поле value храние значение элемента списка, поле next_pointer - позицию в файле (в байтах), указывающую на следующий элемент. Признаком последнего элемента является значение next_pointer, равное 0.
Расположение первого элемента списка (если он существует) - строго в нулевой позиции в файле, расположение остальных - случайным образом.

Выведите на экран значения элементов в списке в текстовом представлении.
Для работы с файлом использовать только низкоуровневый ввод-вывод POSIX.

### inf07-1-winapi

Программе в аргументе командной строки передается имя файла с бинарными данными в Little-Endian.

Файл хранит внутри себя односвязный список элементов:

struct Item
{
  int value;
  uint32_t next_pointer;
};
Поле value храние значение элемента списка, поле next_pointer - позицию в файле (в байтах), указывающую на следующий элемент. Признаком последнего элемента является значение next_pointer, равное 0.
Расположение первого элемента списка (если он существует) - строго в нулевой позиции в файле, расположение остальных - случайным образом.

Выведите на экран значения элементов в списке в текстовом представлении.
Для работы с файлом использовать только низкоуровневый ввод-вывод WinAPI.

### inf07-2

Программе на стандартном потоке ввода передаётся список имён файлов.
Необходимо посчитать суммарный размер в байтах всех файлов, которые являются регулярными.

### inf07-4

Программе на стандартном потоке ввода передаётся список имён файлов.

Если файл является символической ссылкой, то нужно вывести абсолютное имя того файла, на который эта ссылка указывает.
Если файл является регулярным, то необходимо создать символическую ссылку в текущем каталоге, приписав в названии файла префикс link_to_.


## inf08


### inf08-0

Программе передаются два аргумента: имя файла, и строка для поиска.
Необходимо найти все вхождения строки в текстовом файле, используя отображение на память с помощью системного вызова mmap.

На стандартный поток вывода вывести список всех позиций (с нуля) в файле, где втречаются строка.

### inf08-1

Программе в аргументе командной строки передается имя файла с бинарными данными в Little-Endian.

Файл хранит внутри себя односвязный список элементов:

struct Item {
  int value;
  uint32_t next_pointer;
};
Поле value храние значение элемента списка, поле next_pointer - позицию в файле (в байтах), указывающую на следующий элемент. Признаком последнего элемента является значение next_pointer, равное 0.

Расположение первого элемента списка (если он существует) - строго в нулевой позиции в файле, расположение остальных - случайным образом.

Выведите на экран значения элементов в списке в текстовом представлении.
Используйте отображение содержимого файла на память.
