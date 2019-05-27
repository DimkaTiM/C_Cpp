Тут хранятся всякие работы, а также мои пометки для Си и С++

"С" Разная индексация для работы с переменной массива
```C
int a[] = {1, 2, 3};    // инициализация массива
printf("%d", *(a + 2)); // 
printf("%d", 2[a] );    // равноценное обращение к элементу с индексом "2"
printf("%d", a<:2:> );  //
```


"С++" реализация Spread
```C++

double stddev(int count, ...) 
{
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        sum += num;
    }
    va_end(args);
    return sum;
}

int main()
{
    std::cout << stddev(4, 20, 25, 30, 35) << '\n'; // 110
}
```
