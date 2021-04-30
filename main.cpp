#include <iostream>

using namespace std;

struct node
{
    int value = 0;
    node* prev = this;
    node* next = this;
};

node* findAt(node* listHolder, int index)
{
    node* T = listHolder;
    if(index<=0)
        return nullptr;

    for(int i = 0; i < index; ++i)
        if(T->next != listHolder)
            T = T->next;
        else
            return nullptr;
    return T;
}

void pushBack(node* listHolder, int value)
{
    node* T = new node;

    T->value = value;
    T->prev = listHolder->prev;
    T->next = listHolder;

    listHolder->prev->next = T;
    listHolder->prev = T;
}

void pushFront(node* listHolder, int value)
{
    node* T = new node;

    T->value = value;
    T->prev = listHolder;
    T->next = listHolder->next;

    listHolder->next->prev = T;
    listHolder->next = T;
}

void popBack(node* listHolder)
{
    node* T = listHolder->prev;
    if (T==listHolder)
        return;

    T->prev->next = listHolder;
    listHolder->prev = T->prev;

    delete T;
}

void popFront(node* listHolder)
{
    node* T = listHolder->next;
    if (T==listHolder)
        return;

    T->next->prev = listHolder;
    listHolder->next = T->next;

    delete T;
}

void pushMiddleBack(node* listHolder, int index, int value)
{
    node* K = findAt(listHolder, index-1);

    if(K!=nullptr)
        pushFront(K, value);
}

void pushMiddleFront(node* listHolder, int index, int value)
{
    node* K = findAt(listHolder, index);

    if(K!=nullptr)
        pushBack(K, value);
}

void popMiddle(node* listHolder, int index)
{
    node* K = findAt(listHolder, index);

    if(K!=nullptr)
        popFront(K->prev);
}

node* sd(node const* listHolderA, node const* listHolderB)
{
    node* listHolderC = new node;

    for(node const* T = listHolderA->next; T != listHolderA; T = T->next )
        if(listHolderB->next == listHolderB)
            pushBack(listHolderC,T->value);
        else
            for(node const* P = listHolderB->next; P != listHolderB; P = P->next )
                if(T->value == P->value)
                    break;
                else if (P->next == listHolderB)
                    pushBack(listHolderC, T->value);

    for(node const* T = listHolderB->next; T != listHolderB; T = T->next )
        if(listHolderA->next == listHolderA)
            pushBack(listHolderC,T->value);
        else
            for(node const* P = listHolderA->next; P != listHolderA; P = P->next )
                if(T->value == P->value)
                    break;
                else if (P->next == listHolderA)
                    pushBack(listHolderC, T->value);

    return listHolderC;
}

int main()
{
    node* listHolder = new node;
    for(int i = 1; i < 5; i++)
        pushBack(listHolder,i);

    cout << "Menu\n"
            "1-pushFront\n"
            "2-pushMiddleFront\n"
            "3-pushMiddleBack\n"
            "4-pushBack\n"
            "5-popFront\n"
            "6-popBack\n"
            "7-popMiddle\n"
            "8-symmetric difference\n"
            "9-printing\n";

    int n;
    cin >> n;

    if (n == 1)
    {
        int value;
        cin >> value;
        pushFront(listHolder, value);
    }
    else if (n==2)
    {
        int value, index;
        cin >> index >> value;
        pushMiddleFront(listHolder, index, value);
    }
    else if (n == 3)
    {
        int value, index;
        cin >> index >> value;
        pushMiddleBack(listHolder, index, value);
    }
    else if (n == 4)
    {
        int value;
        cin >> value;
        pushBack(listHolder, value);
    }
    else if (n == 5)
    {
        popFront(listHolder);
    }
    else if (n == 6)
    {
        popBack(listHolder);
    }
    else if (n == 7)
    {
        int index;
        cin >> index;
        popMiddle(listHolder, index);
    }
    else if (n == 8)
    {
        node* listHolderA = new node;
        for(int i = 1; i < 5; i++)
            pushBack(listHolderA,i);

        node* listHolderB = new node;
        for(int i = 1; i < 6; i++)
            pushBack(listHolderB,i);

        listHolder = sd(listHolderA, listHolderB);
    }
    else if (n == 9)
    {
        node* T;
        for (T = listHolder->next; T != listHolder; T = T->next)
            if(T != nullptr)
                cout<< T->value << endl;
    }

    node* T;
    for (T = listHolder->next; T != listHolder; T = T->next)
        if(T != nullptr)
            cout<< T->value << endl;

    return 0;
}
