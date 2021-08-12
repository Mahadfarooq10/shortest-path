

#ifndef queue_h
#define queue_h


template<class DT>
class Queue
{
private:
    
    DT *list;
    int head;
    int tail;
    int size;
    int count;
    
public:
   
    Queue(int s);
    
    void Put(DT element);
    
    int Get();
    
    bool IsEmpty();
    
    bool IsFull();
    
};
template<class DT>
Queue<DT>::Queue(int s)
{
    head=0;
    size=s;
    tail=size-1;
    count=0;
    
    list = new DT [size];
    
}
template<class DT>
bool Queue<DT>::IsEmpty()
{
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class DT>
bool Queue<DT>::IsFull()
{
    if(count==size)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
template<class DT>
void Queue<DT>::Put(DT element)
{
    if(!IsFull())
    {
        tail=(tail+1)%size;
        count++;
        list[tail]=element;
    }
    else
    {
        cout<<"cant add to a full Queue!"<<endl;
        
    }
}
template<class DT>
int Queue<DT>::Get()
{
    if(!IsEmpty())
    {
        int value;
        value=list[head];
        head=(head+1)%size;
        count--;
        return value;
    }
    else
        return 0;
}

#endif /* queue_h */
