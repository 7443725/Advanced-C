/*
 * 
 * Волков Дмитрий Викторович
группа Д01-081

Задача A9-Упаковать массив
В программе реализована структура данных:
struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
}
Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
Функция должна строго соответствовать прототипу:
void array2struct(int [], struct pack_array *)
Пример №1
Данные на входе:		1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Данные на выходе:	4294901760 16 16


*/

#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};
void array2struct(int ar[], struct pack_array*p)
{
    for (uint8_t i = 0,ii = 31; i < 32; i++,ii--)
    {
        if (ar[i] == 1)
        {
            p->array |= (1 << ii);
            p->count1++;
        }
        else
        {
            p->array |= (0 << ii);
            p->count0++;
        }
    }
}

int main()
{
    int rt[32] ;
    uint32_t N;
    for(uint8_t i = 0; i <32;i++)
    {
        scanf("%u", &N);
        rt[i] = N;
    }
    struct pack_array d = {0,0,0};
    array2struct(rt, &d);
    printf("%u %u %u", d.array, d.count0, d.count1);
    return 0;
}