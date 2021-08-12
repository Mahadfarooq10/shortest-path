#include "linkedlist.h"
#include "Graph.h"
#include <fstream>
#include "hashtable.h"


int main()
{
    int No_of_cities;
    
    ifstream infile;
    ofstream outfile;
    
    infile.open("inputfile.txt");
    
    if(!infile)
    {
        cout<<"Unable to open input file\n";
    }
    
    
    infile>>No_of_cities;
    
    Hashtable<double> *Hashy;
    Hashy=new Hashtable<double>(No_of_cities);

    Graph Uber(No_of_cities);
    Uber.Construct(infile);
    infile.close();
    cout<<"Showing Cities:"<<endl;
    Uber.printNameOfCities();
    cout<<endl;
    

    for(int i=0;i<No_of_cities;i++)
    {
        Uber.GetShortestPath(i,Hashy);
        cout<<"------------------------"<<endl;
    }
    for(int i=0;i<No_of_cities;i++)
    {
        for(int j=0;j<No_of_cities;j++)
        {
            Uber.print_bfs(i, j);
            cout<<endl;
            cout<<endl;
        }
        cout<<"----------------\n";
    }
    
    
    
    infile.open("UserInfo.txt");
    if(!infile)
    {
        cout<<"unable to open to file\n";
        
    }
    cout<<endl;
    
    int no_of_users;
    infile>>no_of_users;
    Uber.ConstructPriorityQueue(infile,no_of_users);
    cout<<"After processing all rides requested"<<endl;
    
    cout<<endl;
    cout<<"---------------------------\n";
    
    for(int i=0;i<no_of_users;i++)
    {
        cout<<"("<<i+1<<")"<<endl;
        Uber.AssignRide(Hashy);
    }

    cout<<endl;
    cout<<endl;
    cout<<"---------------------------\n";
    cout<<"---------------------------\n";
    cout<<"---------------------------\n";
    
    
    
    Uber.MinimalSpanningTree(2);
    Uber.printTree();
    
    
    return 0;
}
