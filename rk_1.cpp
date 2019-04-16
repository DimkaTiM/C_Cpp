#include <iostream>

struct list
{
    int data; // поле данных
    struct list *next; // указатель на следующий элемент
};




//инициализация списка
struct list * init(int a) // а- значение первого узла
{
    struct list *lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->data = a;
    lst->next = NULL; // это последний узел списка
    return(lst);
}




// вывод всего списка
void listprint(list *lst)
{
    struct list *p;
    p = lst;
    do {
        printf("%d ", p->data); // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != NULL);
}

// добавить число
struct list * addnumber(list *lst, int number)
{
    struct list *temp, *p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->data = number; // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий элемент
    return(temp);
}



void sort(list *start) //параметр - указатель на начало списка.
{
    list *p_list; // указатель для внешнего цыкла for
    list *pp_list; // для внутреннего
    for (p_list = start->next; p_list != NULL; p_list = p_list->next) //пробегаемся по всех узлах списка
        for (pp_list = start->next; pp_list->next != NULL; pp_list = pp_list->next) //а здесь только до узла, next которого указывает на NULL
//обычный обмен значениями
            if (pp_list->data > pp_list->next->data)
            {
                int tmp;
                tmp = pp_list->data; //
                pp_list->data = pp_list->next->data;
                pp_list->next->data = tmp;
            }

}

void dell(list *start, int el) //указатель на начало списка, и значение которое мы будем искать в списке, если найдем значит нужно удалить.
{
    list *p_list = start->next; //рабочий указатель, который будем использовать для пробега по списку.
    list *prev = start; //указатель, который всегда будет указывать на элемент предыдущий до p_list.
    while (p_list != NULL) //пробегаемся по всему списку
    {

        if (p_list->data == el) //проверка - нужно ли удаление
        {

            list *tmp = new list; // временней узел, в который будем записывать значение того узла который нужно удалить.
            *tmp = *p_list;

            prev->next = p_list->next; //теперь нужно сделать так, чтоб элемент next предыдущего узла указывал на узел, который идет после p_list,то есть на p_list->next
            delete tmp;
        }
        prev = p_list; // перемещаем указатель prev на один элемент
        p_list = p_list->next; //так же перемещаем next.
    }
}




//вставлять элемент в отсортированный список. В этой функции есть два нюанса: надо проверять, нужно вставить элемент в начало списка или в конец.
void insert (list *start, int el){                              //указатель на начало списка, число которое нужно вставить в список.
    list *p_list;                                               //рабочий указатель.
    p_list = start->next;                                       //в начале он ссылается на второй узел списка.
    while (p_list->next != NULL) {
        if (p_list == start->next && p_list->data>el) {         //эта проверка нужна для того, чтоб проверить не надо ли вставить елемент в начало списка.
            list *temp = new list;                             //временная переменная, в которую будем записывать узел, на который ссылается
            *temp = * p_list;                            //запоминаем *p_list в *tmp. Здесь мы запоминаем не адрес, а именно значение
            p_list->data = el;                                 //теперь в item записываем елемент который нужно было вставить в список.
            p_list->next = temp;                               //и в next записываем адрес tmp
            break;
        }
        if (p_list->data <= el && p_list->next->data >= el) {   //Если элемент надо вставить не на начало и не в конец списка.
            list *tmp = new list;                               //Выделяем память для нового узла
            tmp->data = el;
            tmp->next = p_list->next;
            p_list->next = tmp;                                 //Вставляем узел после узла, на который указывает p_list
            break;
        }
        p_list = p_list->next;                                  //передвигаем указатель на следующий элемент.
        if (p_list->next == NULL && el>=p_list->data) {         //Проверяем не нужно вставить узел в конец списка.

            list *tmp = new list;
            tmp->data = el;
            tmp->next = NULL;                                   //Так как вставляем узел в конец списка то его элемент next должен ссылаться на NULL
            p_list->next = tmp;                                 //вставляем узел в список.
            break;
        }

    }
}


int main() {
    struct list *A = init(1);


    int N;
    std::cout << "Сколько числе будет в списке?";
    std::cin >> N;

    int k;
    for(int v = 0; v < N; v++){
        std::cin >> k;
        addnumber(A, k);
    }

    std::cout << "Ваш список: ";
    listprint(A);
    printf("\n\n\n");



    std::cout << "Сортировка: ";
    listprint(A);
    printf("\n\n\n");



    std::cout << "Какое число хотите вставить в отсортированный массив? ";
    int d;
    std::cin >> d;
    insert(A, d);
    std::cout << "Ваш отсортиванный массив со вставкой";
    listprint(A);
    printf("\n\n\n");





    
    listprint(A);

    printf("\n\n\n");
    sort(A);
    listprint(A);
    insert(A, 2);
    printf("\n");
    listprint(A);


}

