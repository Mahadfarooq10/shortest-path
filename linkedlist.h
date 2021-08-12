

#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node *next ;
};

template<typename T>
class List
{
public:
    
    List();
    
    void InsertLast(const T& newitem);
    
    void Delete(const T& deleteItem);
    
    T getFront();
    
    void printList();
    
    void ReversePrint();
    
    void Swap(Node<T> *N1, Node<T> *N2);
    
    int length();
    
    Node<T>* returnFirst()
    {
        return first;
    };
    
    bool IsEmpty()
    {
        if(first==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    };
    
private:
    Node<T> *first ;
    
};

////////IMPLEMENTATION/////////////////////////

template<typename T>
List<T>::List()
{
    first=NULL;
}

template<typename T>
void List<T>::InsertLast(const T& newitem)
{
    Node<T> *Newnode;
    Node<T> *current;
    Newnode=new Node<T>;
    
    Newnode->next=NULL;
    Newnode->data=newitem;
    
    if(first==NULL)
    {
        first=Newnode;
        
    }
    else
    {
        current=first;
        
        while(current->next!=NULL)
        {
            current=current->next;
        }
        
        current->next=Newnode;
        
    }
}

template<typename T>
void List<T>::Delete(const T& deleteItem)
{
    Node<T> *current=NULL;
    Node<T> *trailcurrent=NULL;
    bool found =false;
    
    if(first == NULL)
    {
        cout<<"cant delete from empty list"<<endl;
        
    }
    
    else
        if(first->data==deleteItem)
        {
            current=first;
            first=first->next;
            delete current;
        }
    
        else
        {
            trailcurrent=current;
            current=first->next;
            
            while (current != NULL && !found)
            {
                if(current->data!=deleteItem)
                {
                    trailcurrent=current;
                    current=current->next;
                }
                else
                {
                    found=true;
                }
            }
            
            if(found)
            {
                trailcurrent->next=current->next;
                delete current;
                
            }
            else
            {
                cout<<"Item to be deleted not found"<<endl;
            }
        }
    
}

template<typename T>
void List<T>::printList()
{
    Node<T>* p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

template<typename T>
void List<T>::ReversePrint()
{
    reverseprint(first);
    
    
}

template<typename T>
void reverseprint(Node<T> *first)
{
    if(first!=NULL)
    {
        reverseprint(first->next);
        cout<<first->data<<" ";
    }
}

template<typename T>
void List<T>::Swap(Node<T> *N1, Node<T> *N2)
{
    if (N1->next==N2 || N2->next==N1)
    {
        if(N1==first)
        {
            N1->next=N2->next;
            N2->next=first;
            first=N2;
            
        }
        else
        {
            bool found=false;
            Node<T> *p,*pbefore;
            pbefore=first;
            p=first->next;
            while(p!=NULL && !found)
            {
                if(p!=N1)
                {
                    pbefore=p;
                    p=p->next;
                }
                else
                {
                    found=true;
                }
            }
            pbefore->next=p->next;
            p->next=N2->next;
            N2->next=N1;
            
        }
    }
    else
    {
        Node<T>* n1prev,*n2prev = nullptr,*m = nullptr,*x = nullptr;
        bool found1=false;
        bool found2=false;
        bool found3=false;
        if(N1==first)
        {
            n2prev=first;
            m=first->next;
            while(N2!=NULL && !found1)
            {
                if(m!=N2)
                {
                    n2prev=m;
                    m=m->next;
                }
                else
                {
                    found1=true;
                }
                
            }
            first->next=n2prev->next;
            n2prev->next=N1;
            N1->next=N2->next;
            N2->next=n2prev;
            
        }
        
        else
        {
            n1prev=first;
            m=first->next;
            while(N1!=NULL && !found2)
            {
                if(m!=N1)
                {
                    n1prev=m;
                    m=m->next;
                }
                else
                {
                    found2=true;
                }
                
            }
            
            while(N2!=NULL && !found3)
            {
                n2prev=first;
                x=first->next;
                if(x!=N2)
                {
                    n2prev=x;
                    x=x->next;
                }
                else
                {
                    found3=true;
                }
                
            }
            n1prev->next=n2prev->next;
            n2prev->next=N1;
            N1->next=N2->next;
            N2->next=n2prev;
            
        }
    }
    
}

template<typename T>
int List<T>::length()
{
    Node<T> *current;
    
    int counter=0;
    current=first;
    
    while (current!=NULL)
    {
        current=current->next;
        counter++;
    }
    
    return counter;
}

template <typename T>
T List<T>::getFront()
{
    Node<T> *current;
    
    current=first;
    first=first->next;
    
    return current->data;
    
}

#endif /* linkedlist_h */
