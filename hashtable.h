
#ifndef hashtable_h
#define hashtable_h

#include <iostream>
using namespace std;

template<class DT>
class Hashtable
{
public:
    Hashtable(int size);
    void HashFunction(int source, int end, double shortestdistance[], int predecessor[]);
    double getShortestDistance(int source, int end);
    int getPredecessor(int source, int end);
    void printHashtable();
    
private:
    int Size;
    DT **array;
};

template<class DT>
Hashtable<DT>::Hashtable(int size)
{
    Size=size;
    array=new DT *[Size*Size*Size];
    
    for(int i=0;i<Size*Size*Size;i++)
    {
        array[i]=new DT[2];
    }
    
    for(int i=0;i<(Size*Size*Size);i++)
    {
        for(int j=0;j<2;j++)
        {
            array[i][j]=-100;
        }
    }
}

template<class DT>
void Hashtable<DT>::HashFunction(int source, int end, double *shortestdistance, int *predecessor)
{
    int index;
    index=(Size+end+(source*Size))%(Size*Size*Size);
    
    array[index][0]=shortestdistance[end];
    array[index][1]=predecessor[end];
    
}

template<class DT>
double Hashtable<DT>::getShortestDistance(int source, int end)
{
    int index,Sdistance;
    index=(Size+end+(source*Size))%(Size*Size*Size);
    Sdistance=array[index][0];
    return Sdistance;
}

template<class DT>
int Hashtable<DT>::getPredecessor(int source, int end)
{
    int index,P;
    index=(Size+end+(source*Size))%(Size*Size*Size);
    P=array[index][1];
    return P;
}

template<class DT>
void Hashtable<DT>::printHashtable()
{
    for(int i=0;i<(Size*Size*Size);i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
        
    }
}

#endif /* hashtable_h */
