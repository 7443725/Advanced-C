/*
Волков Дмитрий Викторович
группа Д01-081

 Задача 1-Максимальный блок
Описана структура данных
typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. 
Если список пустой, то функция должна возвращать 0. 
Если есть несколько таких блоков, то вернуть адрес любого из них.
Прототип функции:
uint64_t findMaxBlock(list *head)

    Пример №1
    Данные на входе:	3
	  140525067852320 10
	  140525067852350 30
	  140525067852900 100
    Данные на выходе:	140525067852900
   
 */


#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


uint64_t findMaxBlock(list* head)
{
    size_t mx_size = 0;
    void* address = 0; 
    while (head)
    {
        if (head->size > mx_size)
        {
            mx_size = head->size; 
            address = head->address;
        }
        head = head->next; 
    }
        return (uint64_t)address;
}
