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
template <typename T>
int partition(vector<T>& data, int low, int high, bool ascending)
{
    T pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        bool shouldSwap = ascending ? (data[j] <= pivot) : (data[j] >= pivot);
        if (shouldSwap)
        {
            i++;
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    T temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;

    return i + 1;
}

template <typename T>
void quickSortHelper(vector<T>& data, int low, int high, bool ascending)
{
    if (low < high)
    {
        int pivotIndex = partition(data, low, high, ascending);
        quickSortHelper(data, low, pivotIndex - 1, ascending);
        quickSortHelper(data, pivotIndex + 1, high, ascending);
    }
}

template <typename T>
void quickSort(vector<T> data, bool ascending = true)
{
    int n = data.size();

    cout << "Initial Array: ";
    showArray(data);

    if (n == 0)
    {
        cout << "Empty array (nothing to sort)" << endl;
        cout << "Time Complexity of Quick Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n^2)" << endl;
        return;
    }

    if (n == 1)
    {
        cout << "Single element array already sorted" << endl;
        cout << "Time Complexity of Quick Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n^2)" << endl;
        return;
    }

    quickSortHelper(data, 0, n - 1, ascending);

    cout << "Sorted Array: ";
    showArray(data);
    cout << "Time Complexity of Quick Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n^2)" << endl;
}

template <typename T>
void merge(vector<T>& o, vector<T>& left, vector<T>& right)
{
    int xl = 0;
    int xr = 0;
    for (int oIndex = 0; oIndex < o.size(); oIndex++)
    {
        if (xl >= left.size())
            o[oIndex] = right[xr++];
        else if (xr >= right.size())
            o[oIndex] = left[xl++];
        else if (left[xl] < right[xr])
            o[oIndex] = left[xl++];
        else if (left[xl] > right[xr])
            o[oIndex] = right[xr++];

    }
}

template <typename T>
void mergeSort(vector<T>& p, T size)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        int mid = size / 2;
        vector<T> left(p.begin(), p.begin() + mid);
        vector<T> right(p.begin() + mid, p.end());
        mergeSort(left, mid);
        mergeSort(right, size - mid);
        merge(p, left, right);
    }



}

