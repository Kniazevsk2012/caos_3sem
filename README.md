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
