
#ifndef Graph_h
#define Graph_h


#include "queue.h"
#include <string>
#include <fstream>
#include <stack>
#include "hashtable.h"
#include "PriorityQueue.h"

const double infinity=1000000000;

class Graph
{
public:
    
    Graph(int size);
    
    void breadthfirstSearch(int s);
    
    void printAdjList();
    
    void getAdjVertices(int AdjVertices[], int& length, int addressindex);
    

    void Construct(ifstream &infile);
    
    void printNameOfCities();
    
    void printDistanceMatrix();
    
    void printCostMatrix();
    
    void GetShortestPath(int source, Hashtable<double> *Hashy);
    
    void ConstructPriorityQueue(ifstream &infile,int size);
    
    void AssignRide(Hashtable<double> *Hashy);
    
    bool BFS(int src, int dest, int pred[], int dist[]);
    
    void print_bfs(int src, int dest);
    
    
    
    void MinimalSpanningTree(int sourceCity);
    
    void printTree();
    
    
private:
    
    List<int> *AdjList;
    int numVertices;
    double **distance;
    double **CostPerPassenger;
    string *NameOfCities;
    double *shortestDistance;
    int *predecessor;
    MaxHeap *priorityQueue;
    int *citylimiter;
    
    
    int MSTsource;
    int *edges;
    double *edgeweights;
    
};

Graph::Graph(int size)
{
    numVertices=size;
    
    AdjList=new List<int>[numVertices];
    
    distance=new double *[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        distance[i]=new double[numVertices];
    }
    
    CostPerPassenger=new double *[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        CostPerPassenger[i]=new double[numVertices];
    }
    
    NameOfCities=new string[numVertices];
    
    shortestDistance=new double[numVertices];
    
    predecessor=new int[numVertices];
    
    priorityQueue=new MaxHeap(100);
    
    citylimiter=new int[numVertices];
    
    edges=new int[numVertices];
    
    edgeweights=new double[numVertices];
    
    for(int i=0;i<numVertices;i++)
    {
        citylimiter[i]=0;
    }
        
    
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            distance[i][j]=infinity;
        }
    }
    
    for(int k=0;k<numVertices;k++)
    {
        for(int l=0;l<numVertices;l++)
        {
            CostPerPassenger[k][l]=infinity;
        }
    }
    
    for(int i=0;i<numVertices;i++)
    {
        predecessor[i]=-1;
    }
    
}

void Graph::Construct(ifstream &infile)
{
    int citycounter=0;
    int cityindex1=0;
    int cityindex2=0;
    double tempCostPerPassenger;
    double tempDistance;
    string city1,city2;
    bool check=false;
    
    infile>>NameOfCities[0];
    citycounter++;
    infile>>NameOfCities[1];
    citycounter++;
    infile>>tempDistance;
    infile>>tempCostPerPassenger;
    distance[0][1]=tempDistance;
    distance[1][0]=tempDistance;
    CostPerPassenger[0][1]=tempCostPerPassenger;
    CostPerPassenger[1][0]=tempCostPerPassenger;
    
    while(infile)
    {
        infile>>city1;
        infile>>city2;
        
        for(int i=0;i<citycounter;i++)
        {
            if(NameOfCities[i]==city1)
            {
                cityindex1=i;
                check=true;
            }
        }
        
        if(check==false)
        {
            NameOfCities[citycounter]=city1;
            cityindex1=citycounter;
            citycounter++;
        }
        
        check=false;
        
        for(int i=0;i<citycounter;i++)
        {
            if(NameOfCities[i]==city2)
            {
                cityindex2=i;
                check=true;
            }
        }
        
        if(check==false)
        {
            NameOfCities[citycounter]=city2;
            cityindex2=citycounter;
            citycounter++;
        }
        
        check=false;
        
        infile>>tempDistance;
        infile>>tempCostPerPassenger;
        
        distance[cityindex1][cityindex2]=tempDistance;
        distance[cityindex2][cityindex1]=tempDistance;
        CostPerPassenger[cityindex1][cityindex2]=tempCostPerPassenger;
        CostPerPassenger[cityindex2][cityindex1]=tempCostPerPassenger;
    }
    
    //making Adjacency list
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            if(distance[i][j]!=infinity && CostPerPassenger[i][j]!=infinity)
            {
                AdjList[i].InsertLast(j);
            }
        }
    }
}

void Graph::printNameOfCities()
{
    for(int i=0;i<numVertices;i++)
    {
        cout<<NameOfCities[i]<<endl;
    }
}


void Graph::printCostMatrix()
{
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            cout<<CostPerPassenger[i][j]<<" | ";
        }
        cout<<endl;
    }
}

void Graph::printDistanceMatrix()
{
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            cout<<distance[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void Graph::GetShortestPath(int source, Hashtable<double> *Hashy)
{
    int v=0;
    double minDistance;
    bool distanceFound[numVertices];
    
    for(int i=0;i<numVertices;i++)
    {
        shortestDistance[i]=distance[source][i];
    }
    
    for(int i=0;i<numVertices;i++)
    {
        distanceFound[i]=false;
    }
    
    distanceFound[source]=true;
    shortestDistance[source]=0;
    
    for(int i=0;i<numVertices;i++)
    {
        minDistance=infinity;
        
        for(int j=0;j<numVertices;j++)
        {
            if(distanceFound[j]==false)
            {
                if(shortestDistance[j]<minDistance)
                {
                    v=j;
                    minDistance=shortestDistance[v];
                }
                
            }
        }
        distanceFound[v]=true;
        
        for(int j=0;j<numVertices;j++)
        {
            if(distanceFound[j]==false)
            {
                if(minDistance+distance[v][j]<shortestDistance[j])
                {
                    shortestDistance[j]=minDistance+distance[v][j];
                    predecessor[j]=v;
                }
            }
        }
            
    }
    
    cout<<"Shortest distance from "<<NameOfCities[source]<<" to all other cities:"<<endl;
    for(int i=0;i<numVertices;i++)
    {
        cout<<NameOfCities[i]<<" "<<shortestDistance[i]<<endl;
    }
    
    cout<<endl;
    
    
    ///////////////Printing path//////////////////
    bool check=false;
    int temp;
    cout<<"Path followed for shortest distance:"<<endl;
    
    for(int i=0;i<numVertices;i++)
    {
        if(predecessor[i]==-1)
        {
            cout<<NameOfCities[source]<<"-->"<<NameOfCities[i]<<endl;
        }
        
        else
        {
            temp=predecessor[i];
            stack<int> St;
            while(check!=true)
            {
                if(temp==-1)
                {
                    check=true;
                }
                else
                {
                    
                    St.push(temp);
                    temp=predecessor[temp];
                }
            }
            check=false;
            cout<<NameOfCities[source]<<"-->";
            while(!St.empty())
            {
                temp=St.top();
                St.pop();
                cout<<NameOfCities[temp]<<"-->";
            }
            cout<<NameOfCities[i]<<endl;
        }
    }
    cout<<endl;
    
    for(int i=0;i<numVertices;i++)
    {
        Hashy->HashFunction(source, i, shortestDistance, predecessor);
    }
    for(int i=0;i<numVertices;i++)
    {
        predecessor[i]=-1;
    }
}

void Graph::ConstructPriorityQueue(ifstream &infile, int size)
{
    int ID;
    string source,end,user;
    
    UserType *Users;
    Users=new UserType[size];
    bool found=false;
    
    for(int i=0;i<size;i++)
    {
    
        int j=0,k=0;
        infile>>ID;
        infile>>source;
        infile>>end;
        getline(infile,user,'\n');
        
        while(!found)
        {
            if(NameOfCities[j]==source)
            {
                found=true;
            }
            j++;
        }
        
        found=false;
        
        while(!found)
        {
            if(NameOfCities[k]==end)
            {
                found=true;
            }
            k++;
        }
       
        found=false;
        
        Users[i].setID(ID);
        Users[i].setSource(j-1);
        Users[i].setEnd(k-1);
        Users[i].setUserAndPreference(user);
        
    }
    
    for(int i=0;i<size;i++)
    {
        priorityQueue->insert(Users[i]);
    }
    
}

void Graph::AssignRide(Hashtable<double> *Hashy)
{
    UserType ride;
    int source,end,ID,temp,usertype;
    double shortestpath=0,fare=0;
    
    ride=priorityQueue->Delete();
    usertype=ride.returnPreference();
    source=ride.getsource();
    citylimiter[source]++;
    end=ride.returnEnd();
    ID=ride.getID();
    shortestpath=Hashy->getShortestDistance(source, end);
    
    if(usertype==13)
    {
        fare=10*shortestpath;
    }
    else
    {
        fare=15*shortestpath;
    }
    
    if(citylimiter[source]>=5)
    {
        cout<<"City car limit reached, No Car Available to be assigned to user"<<ID<<endl;
        
    }
    else
    {
        cout<<"Car Assigned successfully to user "<<ID<<" "<<ride.returnUserType()<<endl;
        cout<<"From:"<<NameOfCities[source]<<"-->"<<NameOfCities[end]<<endl;
        cout<<"Shortest Distance:"<<shortestpath<<"Km"<<endl;
        cout<<"Fare: "<<fare<<"Rs"<<endl;
        cout<<"Path followed to reach Destination\n";
        bool check=false;
        
        
        if(Hashy->getPredecessor(source, end)==-1)
        {
            cout<<NameOfCities[source]<<">>"<<NameOfCities[end]<<endl;
        }
        
        else
        {
            temp=Hashy->getPredecessor(source, end);
            stack<int> St;
            while(check!=true)
            {
                if(temp==-1)
                {
                    check=true;
                }
                else
                {
                    
                    St.push(temp);
                    temp=Hashy->getPredecessor(source, temp);
                }
            }
            check=false;
            cout<<NameOfCities[source]<<">>";
            while(!St.empty())
            {
                temp=St.top();
                St.pop();
                cout<<NameOfCities[temp]<<">>";
            }
            cout<<NameOfCities[end]<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
}

void Graph::MinimalSpanningTree(int sourceCity)
{
    int i,j,k;
    int startcity=0,endcity=0;
    double minweight;
    
    MSTsource=sourceCity;
    
    bool mst[numVertices];
    
    for(j=0;j<numVertices;j++)
    {
        mst[j]=false;
        edges[j]=sourceCity;
        edgeweights[j]=CostPerPassenger[sourceCity][j];
    
    }
    mst[sourceCity]=true;
    edgeweights[sourceCity]=0;
    
    for(i=0;i<numVertices-1;i++)
    {
        minweight=infinity;
        for(j=0;j<numVertices;j++)
        {
            if(mst[j])
            {
                for(k=0;k<numVertices;k++)
                {
                    if(!mst[k] && CostPerPassenger[j][k]<minweight)
                    {
                        endcity=k;
                        startcity=j;
                        minweight=CostPerPassenger[j][k];
                    }
                }
            }
        }
        mst[endcity]=true;
        edges[endcity]=startcity;
        edgeweights[endcity]=minweight;
    }

}

void Graph::printTree()
{
    double treeweight=0;
    
    cout<<"Source City "<<NameOfCities[MSTsource]<<endl;
    cout<<"Route-----Cost/Passenger "<<endl;
    
    for(int i=0;i<numVertices;i++)
    {
        treeweight=treeweight+edgeweights[i];
        cout<<"("<<NameOfCities[edges[i]]<<","<<NameOfCities[i]<<")----"<<edgeweights[i]<<endl;
    }
    cout<<endl;
    cout<<"Total Minimal Operational Cost: "<<treeweight<<endl;
}





void Graph::printAdjList()
{
    for(int i=0;i<numVertices;i++)
    {
        cout<<i<<" :";
        AdjList[i].printList();
        cout<<endl;
    }
}

void Graph::getAdjVertices(int *AdjVertices, int &length,int addressindex)
{
    Node<int> *current;
    
    length= 0;
    current=AdjList[addressindex].returnFirst();
    
    while(current!=NULL)
    {
        AdjVertices[length++]=current->data;
        current=current->next;
    }
    
}

bool Graph::BFS(int src, int dest, int pred[], int dist[])
{
    Queue<int> Q(100);
    int u;
    bool *visited;
    visited = new bool[numVertices];
    int *adjVertices;
    int adjVerticesLength = 0;
    adjVertices = new int[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
        dist[i] = infinity;
        pred[i] = -1;
    }
    
    visited[src] = true;
    dist[src] = 0;
    Q.Put(src);
    
    while (!Q.IsEmpty())
    {
        u = Q.Get();
        getAdjVertices(adjVertices, adjVerticesLength, u);
        
        for (int w = 0; w < adjVerticesLength; w++)
        {
            if (!visited[adjVertices[w]])
            {
                Q.Put(adjVertices[w]);
                visited[adjVertices[w]] = true;
                dist[adjVertices[w]] = dist[u] + 1;
                pred[adjVertices[w]] = u;
                Q.Put(adjVertices[w]);
                if (adjVertices[w] == dest)
                {
                    return true;
                }
            }
        }
    }
    return true;
}



void Graph::print_bfs(int src, int dest)
{
    int pred[numVertices], dist[numVertices];
    
    if (BFS(src, dest, pred, dist) == false)
    {
        cout << "Given source and destination are not connected" << endl;
        return;
    }
    
    // stack path stores the shortest path
    stack<int> path;
    int crawl = dest;
    path.push(crawl);
    while (pred[crawl] != -1)
    {
        path.push(pred[crawl]);
        crawl = pred[crawl];
    }
    
    cout<<"Source City:"<<NameOfCities[src]<<endl;
    // distance from source is in distance array
    cout << "Minimum number of hops are : " << dist[dest];
    
    // printing path from source to destination
    cout << "\n Path to be followed is::\n";
    while (!path.empty())
    {
        cout << NameOfCities[path.top()] << "-";
        path.pop();
    }
}

#endif /* Graph_h */
