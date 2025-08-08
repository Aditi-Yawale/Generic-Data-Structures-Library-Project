///////////////////////////////////////////////////////
//
// PROJECT : GENERIC DATA STRUCTURES LIBRARY
// AUTHOR : ADITI YAWALE
//
////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
//
//CODE OF SINGLY LINEAR
//
////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}
///////////////////////////////////////////////////////
//
//CODE OF DOUBLY CIRCULAR
//
///////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}
///////////////////////////////////////////////////////
//
//CODE OF DOUBLY LINEAR
//
///////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;

    cout<<"\nNULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"| <=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;
    newn = new struct nodeDL<T>;
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    iCount++;
    
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;

    newn = new struct nodeDL<T>;  

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        temp = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }   
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * temp = First;
    struct nodeDL<T> * newn = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new struct nodeDL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos-1;i++)
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;

        iCount++;         
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
        First->prev = NULL;
        
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(First->next == NULL)
    {
        delete temp->next;
        First = NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp1 = NULL;
    struct nodeDL<T> * temp2 = NULL;

    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->prev = temp1;
        delete temp2;

        iCount--;         
    }
}


///////////////////////////////////////////////////////
//
//CODE OF SINGLY CIRCULAR
//
///////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class T>
struct nodeCL
{
    T data;
    struct nodeCL *next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeCL<T> * First;
        struct nodeCL<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    do
    {
        cout<<"| "<<First->data<<" |->";
        First = First->next;
    }while(First != Last->next);
    cout<<endl;
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeCL<T> * newn = NULL;
    
    newn = new struct nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
        newn->next = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeCL<T> * newn = NULL;
    
    newn = new struct nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
        newn->next = newn;
    }
    else
    {
        newn->next = Last->next;
        Last->next = newn;
        Last = newn;
    }
    iCount++;
    

}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iRet = 0;

    iRet = Count();
    
    struct nodeCL<T> * temp = NULL;
    struct nodeCL<T> * newn = NULL;


    if((iPos < 1) || (iPos > iRet + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iRet + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        newn = new struct nodeCL<T>;

        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeCL<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp->next->next != First)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last -> next = First; 
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    int iRet = 0;

    struct nodeCL<T> * temp1 = NULL;
    struct nodeCL<T> * temp2 = NULL;

    iRet = Count();

    if((iPos < 1) || (iPos > iRet))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iRet)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1 -> next = temp2->next;
        delete temp2;
    }
    iCount--;

}
///////////////////////////////////////////////////////
//
//CODE OF BINARY SEARCH TREE
//
///////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct nodeBST
{
    T data;
    nodeBST<T>* lchild;
    nodeBST<T>* rchild;
};

template <class T>
class BST
{
private:
    nodeBST<T>* Root;

    void Inorder(nodeBST<T>* node);
    void Preorder(nodeBST<T>* node);
    void Postorder(nodeBST<T>* node);
    bool Search(nodeBST<T>* node, T No);
    int CountLeaf(nodeBST<T>* node);
    int CountParent(nodeBST<T>* node);
    int CountAll(nodeBST<T>* node);

public:
    BST();
    void Insert(T No);

    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();

    bool Search(T No);
    int CountLeaf();
    int CountParent();
    int CountAll();
};

// Constructor
template <class T>
BST<T>::BST()
{
    Root = nullptr;
}

// Insert
template <class T>
void BST<T>::Insert(T No)
{
    nodeBST<T>* newn = new nodeBST<T>{No, nullptr, nullptr};

    if (Root == nullptr)
    {
        Root = newn;
        return;
    }

    nodeBST<T>* temp = Root;

    while (true)
    {
        if (temp->data == No)
        {
            cout << "Unable to insert node as element is already present\n";
            delete newn;
            break;
        }
        else if (No > temp->data)
        {
            if (temp->rchild == nullptr)
            {
                temp->rchild = newn;
                break;
            }
            temp = temp->rchild;
        }
        else
        {
            if (temp->lchild == nullptr)
            {
                temp->lchild = newn;
                break;
            }
            temp = temp->lchild;
        }
    }
}

// Inorder
template <class T>
void BST<T>::Inorder(nodeBST<T>* node)
{
    if (node != nullptr)
    {
        Inorder(node->lchild);
        cout << node->data << "\n";
        Inorder(node->rchild);
    }
}

template <class T>
void BST<T>::DisplayInorder()
{
    Inorder(Root);
}

// Preorder
template <class T>
void BST<T>::Preorder(nodeBST<T>* node)
{
    if (node != nullptr)
    {
        cout << node->data << "\n";
        Preorder(node->lchild);
        Preorder(node->rchild);
    }
}

template <class T>
void BST<T>::DisplayPreorder()
{
    Preorder(Root);
}

// Postorder
template <class T>
void BST<T>::Postorder(nodeBST<T>* node)
{
    if (node != nullptr)
    {
        Postorder(node->lchild);
        Postorder(node->rchild);
        cout << node->data << "\n";
    }
}

template <class T>
void BST<T>::DisplayPostorder()
{
    Postorder(Root);
}

// Search
template <class T>
bool BST<T>::Search(nodeBST<T>* node, T No)
{
    while (node != nullptr)
    {
        if (node->data == No)
            return true;
        else if (No > node->data)
            node = node->rchild;
        else
            node = node->lchild;
    }
    return false;
}

template <class T>
bool BST<T>::Search(T No)
{
    return Search(Root, No);
}

// CountLeaf
template <class T>
int BST<T>::CountLeaf(nodeBST<T>* node)
{
    if (node == nullptr)
        return 0;
    if (node->lchild == nullptr && node->rchild == nullptr)
        return 1;
    return CountLeaf(node->lchild) + CountLeaf(node->rchild);
}

template <class T>
int BST<T>::CountLeaf()
{
    return CountLeaf(Root);
}

// CountParent
template <class T>
int BST<T>::CountParent(nodeBST<T>* node)
{
    if (node == nullptr)
        return 0;
    if (node->lchild != nullptr || node->rchild != nullptr)
        return 1 + CountParent(node->lchild) + CountParent(node->rchild);
    return CountParent(node->lchild) + CountParent(node->rchild);
}

template <class T>
int BST<T>::CountParent()
{
    return CountParent(Root);
}

// CountAll
template <class T>
int BST<T>::CountAll(nodeBST<T>* node)
{
    if (node == nullptr)
        return 0;
    return 1 + CountAll(node->lchild) + CountAll(node->rchild);
}

template <class T>
int BST<T>::CountAll()
{
    return CountAll(Root);
}

///////////////////////////////////////////////////////
//
//CODE OF STACK
//
///////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T> ::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T> ::Count()
{
    return iCount;
}

template <class T>
void Stack<T> ::Push(T No)
{
    struct nodeS<T> * newn = NULL;

    newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack<T> ::Pop()
{
    return 0;
}


///////////////////////////////////////////////////////
//
//CODE OF QUEUE
//
///////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No); 
        int DeQueue();   
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T> ::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T> ::Count()
{
    return iCount;
}

template <class T>
void Queue<T> ::EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new struct nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T> ::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

///////////////////////////////////////////////////////
//
//MAIN FUNCTION
//
///////////////////////////////////////////////////////

int main()
{

    return 0;
}
