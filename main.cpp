#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

struct Vertex
{
    int X;
    int Y;
};

class DA
{
    int n;  //number of vertexes in the graph
    double distance[100][100];  //distance between two vertex
    Vertex v[100];
    bool selected[100];     // this is used for what vertex is selected
    int edge[100][100];     // :|
public:
    DA();   // initial vertexes by random number
    void Euclidean_Distance();      // finding distance between vertexes
    void Selected_Vertexse();       // Using prime algorithm to find the nearest path in graph
};

DA::DA()
{
    srand (time(NULL));
    int option;

    //*******************************************************
    bool check = true;
    while (check)
    {
        cout << "How do you want to input number: \n";
        cout << "1. Manual\n2. Random automatic\n";
        cout << "Your option: ";
        cin >> option;
        cout << "--------------------------------\n";
        if (option == 1 || option == 2)
            check = false;
    }
    //*******************************************************


    //*******************************************************
    if (option == 1)
    {
        cout << "\nEnter the number of dots: ";
        cin >> n;
        cout << endl;
        for (int i=0; i<n; i++)
        {
            cout << "Enter X[" << i+1 << "]: ";
            cin >> v[i].X;
            cout << "Enter Y[" << i+1 << "]: ";
            cin >> v[i].Y;
            cout << "-----------------\n";
        }

        cout << "\n\n\n*** the dots you entered ***\n";
        cout << "-------------------------------\n";
        cout << "X: ";
        for (int i=0; i<n; i++)
        {
            cout << v[i].X << " ";
        }

        cout << "\nY: ";
        for (int i=0; i<n; i++)
        {
            cout << v[i].Y << " ";
        }
        cout << "\n\n\n";
    }
    //*******************************************************


    //*******************************************************
    else
    {
        cout << "\nEnter the number of dots: ";
        cin >> n;

        bool flag = true;
        while (flag)
        {
            for (int i=0; i<n; i++)
            {
                v[i].X = rand() % n;                v[i].Y = rand() % n;
            }

            //  if we have two same dots, produce them again
            for (int i=0; i<n; i++)
            {
                for (int j=i+1; j<n; j++)
                {
                    if (v[i].X == v[j].X && v[i].Y == v[j].Y)
                    {
                        for (int k=0; k<n; k++)
                        {
                            v[k].X = 0;
                            v[k].Y = 0;
                        }
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }
        }

        // Print vertexes produced by random function
        cout << "\n\n\n*** Dots made by random function ***\n";
        cout << "------------------------------------\n";
        cout << "X: ";
        for (int i=0; i<n; i++)
        {
            cout << v[i].X << " ";
        }

        cout << "\nY: ";
        for (int i=0; i<n; i++)
        {
            cout << v[i].Y << " ";
        }
        cout << "\n\n\n";
    }
    //*******************************************************
}


void DA::Euclidean_Distance()
{
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            distance[i][j] = sqrt( (pow(v[i].X - v[j].X,2)) + (pow(v[i].Y - v[j].Y,2)) );
            distance[j][i] = distance[i][j];
        }
    }

    cout << "\n*** All distance between vertexes ***\n";
    cout << "-------------------------------------\n\t";
    for (int i=0; i<n; i++)
        cout << i+1 << "\t";
    cout << "\n\t";
    for (int i=0; i<n; i++)
        cout << "________";
    cout << endl;

    for (int i=0; i<n; i++)
    {
        cout << i+1 << "|\t";
        for (int j=0; j<n; j++)
            cout << distance[i][j] << "\t";
        cout << "\n\n";
    }
    cout << "\n\n\n";
}


void DA::Selected_Vertexse()
{
    cout << "** Vertexes & weight of edge between them **\n";
    cout << "--------------------------------------------\n";

    int V = 0, v1, v2;
    selected[0] = true;

    //  prime algorithm begin
    while (V < n-1)
    {
        float min_Distance = 10000;
        v1 = 0;
        v2 = 0;

        for (int i=0; i<n; i++)
        {
            if (selected[i])
            {
                for (int j=0; j<n; j++)
                {
                    if (!selected[j])
                    {
                        if (distance[i][j] < min_Distance)
                        {
                            min_Distance = distance[i][j];
                            v1 = i;
                            v2 = j;
                        }
                    }
                }
            }
        }
        cout << v1+1 << "-" << v2+1 << " : " << distance[v1][v2] << endl;
        selected[v2] = true;
        V++;
    }
}


int main()
{
    DA test;
    test.Euclidean_Distance();
    test.Selected_Vertexse();
    cout << "\n\n  -----------------------\n";
    cout << " | Student: Erfan Riahi  |\n | Student ID: 971490031 |\n | Year: 2020            |\n";
    cout << "  -----------------------";
}
