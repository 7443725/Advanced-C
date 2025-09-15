/*
 * 
 * Волков Дмитрий Викторович
группа Д01-081

Задача A10-Распаковать порядок
Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float, 
она возвращает порядок который хранится в поле EXP в виде десятичного целого числа. 
Функция должна строго соответствовать прототипу:
int extractExp(float)
Пример №1
Данные на входе:		1.0
Данные на выходе:	127


*/

#include <stdio.h>
#include <stdint.h>

int extractExp(float f) {
    union {
        float f;
        struct 
        {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp;
}

int main()
{
    float N;
    scanf("%f", &N);
    printf("%d", extractExp(N));
    return 0;
}