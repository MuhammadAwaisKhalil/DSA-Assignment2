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
void countingSortByDigit(vector<T>& arr, T exp) {
    int n = static_cast<int>(arr.size());
    vector<T> output(n, 0);
    vector<int> count(10, 0);

    for (T num : arr) {
        int digit = static_cast<int>((num / exp) % 10);
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = static_cast<int>((arr[i] / exp) % 10);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

template <typename T>
void radixSort(vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    T maxVal = *max_element(arr.begin(), arr.end());

    for (T exp = 1; maxVal / exp > 0; ) {
        countingSortByDigit(arr, exp);
        if (exp > maxVal / 10) {
            break;
        }
        exp *= 10;
    }
}


