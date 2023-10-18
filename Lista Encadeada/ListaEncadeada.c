//#include "tadEncadeada.h"
#include "tadEncadeada.h"



int main()
{
    Linked *list = createList();
    Data data;

    data.value = 10;
    prepend(list, data);

    data.value = 20;
    append(list, data);

    data.value = 30;
    insert(list, data, -50);

    data.value = 40;
    insert(list, data, 1);

    data.value = 50;
    insert(list, data, 0);

    data.value = 60;
    insert(list, data, -50);

    showList(list);

    removeEnd(list);
    removeFront(list);
    removePosition(list, 2);

    showList(list);

    printf("List size: %d\n", listSize(list));
    data.value = 40;
    printf("Position: %d\n", findElement(list, data));

    destroyList(list);
    return  0;
}