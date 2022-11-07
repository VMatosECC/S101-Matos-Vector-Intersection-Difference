// S101-Matos-Vector-Intersection-Difference.cpp 
// Author:  V. Matos
// Goal:    Create a vector v3 that contains the data items 
//          common to vectors v1 nd v2
// --------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// Prototypes ---------------------------------------------------------------
int  countOccurrence(int item, vector<int> v);
void calculateIntersection(vector<int> v1, vector<int> v2, vector<int>& v3);
void calculateDifference(vector<int> v1, vector<int> v2, vector<int>& v3);
void showVector(vector<int> v, string caption = "Vector");

int main()
{
    vector<int> v1{ 10, 11, 15, 17 };
    vector<int> v2{ 8, 11, 12, 14, 17, 20 };
    vector<int> v3;

    showVector(v1, "This is v1");
    showVector(v2, "This is v2");
    calculateIntersection(v1, v2, v3);
    showVector(v3, "This is the intersection of v1 and v2");

    calculateDifference(v1, v2, v3);
    showVector(v3, "This is the difference of v1 and v2");

    calculateDifference(v2, v1, v3);
    showVector(v3, "This is the difference of v2 and v1");
}

// User-Defined methods
void showVector(vector<int> v, string caption )
{
    cout << endl << caption << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int  countOccurrence(int item, vector<int> v)
{
    int counter = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == item) counter++;
    }
    return counter;
}

void calculateIntersection(vector<int> v1, vector<int> v2, vector<int>& v3)
{
    v3.clear();
    for (int i = 0; i < v1.size(); i++)
    {
        if (countOccurrence(v1[i], v2) > 0)
        {
            v3.push_back(v1[i]);
        }
    }
}

void calculateDifference(vector<int> v1, vector<int> v2, vector<int>& v3)
{
    v3.clear();
    for (int i = 0; i < v1.size(); i++)
    {
        if (countOccurrence(v1[i], v2) == 0)
        {
            v3.push_back(v1[i]);
        }
    }
}