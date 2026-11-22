#include<iostream>
#include<vector>
#include<string>

using namespace std;

// helper function to display array
template <typename T>
void showArray(vector<T>& data)
{
    for(int i = 0; i < data.size(); i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void selectionSort(vector<T> data, bool ascending=true)
{
    int n = data.size();

    cout<<"Initial Array: ";
    showArray(data);
    
    if(n<=1)
    {
        cout<<"Single element array already sorted\nTime Complexity: O(1)";
        return;
    }
    

    for(int i = 0; i < n; i++)
    {
        int currentSmall = i;

        for(int j = i + 1; j < n; j++)
        {
            if(ascending)
            {
                if(data[currentSmall] > data[j])
                {
                    currentSmall = j;
                }
            }
            else
            {
                if(data[currentSmall] < data[j])
                {
                    currentSmall = j;
                }
            }
        }

        if(currentSmall!=i)
        {
            T temp = data[currentSmall];
            data[currentSmall] = data[i];
            data[i] = temp;
        }
    }

    cout<<"Sorted Array: ";
    showArray(data);
    cout<<endl;
    cout<<"Time Complexity of Selection Sort:  O(n^2)"<<endl;

    
}
