
#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <iostream>
#include <string>
using namespace std;

class UserType
{
    friend ostream& operator<<(ostream& out, const UserType& object)
    {
        out<<"ID:"<<object.ID<<endl;
        out<<object.source<<"->"<<object.end<<endl;
        
        return out;
        
    };
    
public:
    
    void setID(int identification)
    {
        ID=identification;
    };
    void setSource(int start)
    {
        source=start;
    };
    void setEnd(int dest)
    {
        end=dest;
    };
    void setUserAndPreference(string UserType)
    {
        user=UserType;
        preference=UserType.length();
    };
    
    int getID()
    {
        return ID;
    };
    
    int getsource()
    {
        return source;
    };
    
    int returnEnd()
    {
        return end;
        
    };
    
    string returnUserType()
    {
        return user;
    };
    
    int returnPreference()
    {
        return preference;
    };
    
    bool operator>(const UserType &other) const
    {
      if(preference>other.preference)
      {
          return true;
      }
      else
      {
            return false;
      }
    };
    
    const UserType& operator = (const UserType& other);
    
private:
    int ID;
    int source;
    int end;
    string user;
    int preference;
};

const UserType& UserType::operator=(const UserType &other)
{
    
            ID=other.ID;
            source=other.source;
            end=other.end;
            user=other.user;
            preference=other.preference;
    
        return *this;
}

class MaxHeap
{
public:

    MaxHeap(int maxsize);
    
    void swap(UserType &a,UserType &b);

    void insert(const UserType data)
    {
        arr[no_of_elements]=data;
        no_of_elements++;
        heapify();
    };
    void heapify();
    
    void Heapify(int i);

    UserType Delete()
    {
        UserType deleteditem;
        swap(arr[0],arr[no_of_elements-1]);
        deleteditem=arr[no_of_elements-1];
        no_of_elements--;
        
        heapify();
        
        return deleteditem;
    };

    void printContents()
    {
        for(int i=0;i<no_of_elements;i++)
        {
            cout<<arr[i]<<" ";
        }
    };

    ~MaxHeap()
    {
        delete arr;
    };
    
    
private:
    UserType *arr;
    int no_of_elements;
    int max_size;
    
};

MaxHeap::MaxHeap(int maxsize)
{
    arr=new UserType[maxsize];
    no_of_elements=0;
}

void MaxHeap::swap(UserType &a, UserType &b)
{
    UserType temp;
    
    temp=a;
    a=b;
    b=temp;
    
    
}

void MaxHeap::heapify()
{
    for(int i=no_of_elements-1;i>0;i--)
    {
        Heapify(i);
        
    }
}

void MaxHeap::Heapify(int i)
{
    int left,right,parent;
    while (i!=no_of_elements)
    {
        if(i%2==1)
        {
            left=i;
            right=i+1;
            parent=i/2;
            
            
            if(arr[left]>arr[parent])
            {
                swap(arr[left], arr[parent]);
            }
            i=i+1;
            
        }
        else
        {
            
            left=i-1;
            right=i;
            parent=i/2;
            
            if(arr[right]>arr[parent] && arr[left]>arr[parent])
            {
                if(arr[left]>arr[right])
                {
                    swap(arr[left], arr[parent]);
                }
                else
                {
                    swap(arr[right], arr[parent]);
                }
            }
            else
            {
                if(arr[right]>arr[parent])
                {
                    swap(arr[right], arr[parent]);
                }
            }
            i=i+1;
        }
        
    }
    
}

#endif /* PriorityQueue_h */
