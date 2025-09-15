/*
 * 
 * Волков Дмитрий Викторович
группа Д01-081

Задача A8-Весы
В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна) и гири массами 1г, 3г, 9г, 27г, и т.д.
 по одной штуке каждой массы. Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно, сколько гирь придется положить на весы (на любую чашку). 
Надо помочь ему. 
Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000). Формат выходных данных: единственное целое число – общее количество гирь или число –1 если данный товар взвесить невозможно.
Пример №1
Данные на входе:		8
Данные на выходе:	2

*/


#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t left_ch : 1;
    uint8_t right_ch : 1;
    uint32_t mass_left;
    uint32_t mass_right;
    uint32_t count;
}mass;

int func_mass(mass * d)
{
    if(!d->left_ch)//
        for (;d->mass_left < 1000000000; d->mass_left *=3)
        {
            if (d->mass_left == d->mass_right)
                return ++d->count;
            if (d->mass_left > d->mass_right)
            {
                d->left_ch = 1;
                d->count++;
                break;
            }
        }
    if (!d->right_ch)//
        for (uint32_t i = 1; i < 1000000000; i *= 3)
        {
            if(d->mass_left == (d->mass_right +i))
                return ++d->count;
            if (d->mass_left < (d->mass_right + i))
            {
                if (i > 1)
                {
                    d->mass_right += (i / 3);
                    d->count++;
                    func_mass(d);
                    break;
                }
                else
                {
                    return -1;
                }
            }
        }
}


int main()
{
    mass N = {0,0,1,0,0}, * p;
    p = &N;
    scanf("%u", &N.mass_right);
    printf("%d", func_mass(p));
    return 0;
}
