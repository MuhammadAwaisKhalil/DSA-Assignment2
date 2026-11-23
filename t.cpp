#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<cstdint>
#include<cstring>

using namespace std;

// This function simply prints the numbers or strings stored in a vector.
template <typename T>
void showArray(const vector<T>& data)
{
    if (data.empty())
    {
        cout << "(empty)" << endl;
        return;
    }
    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSort(vector<T> data, bool ascending = true)
{
    // Selection sort finds the smallest or largest value for each position.
    int n = static_cast<int>(data.size());

    cout << "\n--- Selection Sort ---" << endl;
    cout << "Initial Array: ";
    showArray(data);

    if (n <= 1)
    {
        cout << "Sorted Array: ";
        showArray(data);
        cout << "Time Complexity of Selection Sort -> Best: O(n^2), Average: O(n^2), Worst: O(n^2)" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // At first, assume the current position contains the required value.
        int currentSmall = i;

        for (int j = i + 1; j < n; j++)
        {
            if (ascending)
            {
                if (data[currentSmall] > data[j])
                {
                    currentSmall = j;
                }
            }
            else
            {
                if (data[currentSmall] < data[j])
                {
                    currentSmall = j;
                }
            }
        }

        if (currentSmall != i)
        {
            T temp = data[currentSmall];
            data[currentSmall] = data[i];
            data[i] = temp;
        }
    }

    cout << "Sorted Array: ";
    showArray(data);
    cout << "Time Complexity of Selection Sort -> Best: O(n^2), Average: O(n^2), Worst: O(n^2)" << endl;
}

template <typename T>
int partition(vector<T>& data, int low, int high, bool ascending)
{
    // The last element is used as the pivot in this quick sort implementation.
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
        // Divide the array around the pivot, then sort both smaller parts.
        int pivotIndex = partition(data, low, high, ascending);
        quickSortHelper(data, low, pivotIndex - 1, ascending);
        quickSortHelper(data, pivotIndex + 1, high, ascending);
    }
}

template <typename T>
void quickSort(vector<T> data, bool ascending = true)
{
    int n = static_cast<int>(data.size());

    cout << "\n--- Quick Sort ---" << endl;
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
        cout << "Sorted Array: ";
        showArray(data);
        cout << "Time Complexity of Quick Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n^2)" << endl;
        return;
    }

    quickSortHelper(data, 0, n - 1, ascending);

    cout << "Sorted Array: ";
    showArray(data);
    cout << "Time Complexity of Quick Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n^2)" << endl;
}

template <typename T>
void merge(vector<T>& o, vector<T>& left, vector<T>& right, bool ascending)
{
    // Compare the front values of both halves and copy the smaller/larger one.
    size_t xl = 0;
    size_t xr = 0;
    for (size_t oIndex = 0; oIndex < o.size(); oIndex++)
    {
        if (xl >= left.size())
            o[oIndex] = right[xr++];
        else if (xr >= right.size())
            o[oIndex] = left[xl++];
        else if (ascending ? (left[xl] <= right[xr]) : (left[xl] >= right[xr]))
            o[oIndex] = left[xl++];
        else
            o[oIndex] = right[xr++];
    }
}

template <typename T>
void mergeSortHelper(vector<T>& p, int size, bool ascending)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        // Split the array into two halves and sort each half separately.
        int mid = size / 2;
        vector<T> left(p.begin(), p.begin() + mid);
        vector<T> right(p.begin() + mid, p.end());
        mergeSortHelper(left, mid, ascending);
        mergeSortHelper(right, size - mid, ascending);
        merge(p, left, right, ascending);
    }
}

template <typename T>
void mergeSort(vector<T> p, bool ascending = true)
{
    int n = static_cast<int>(p.size());

    cout << "\n--- Merge Sort ---" << endl;
    cout << "Initial Array: ";
    showArray(p);

    if (n <= 1)
    {
        cout << "Sorted Array: ";
        showArray(p);
        cout << "Time Complexity of Merge Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n log n)" << endl;
        return;
    }

    mergeSortHelper(p, n, ascending);

    cout << "Sorted Array: ";
    showArray(p);
    cout << "Time Complexity of Merge Sort -> Best: O(n log n), Average: O(n log n), Worst: O(n log n)" << endl;
}

void countingSortByDigit(vector<unsigned long long>& arr, unsigned long long exp, bool ascending) {
    int n = static_cast<int>(arr.size());
    vector<unsigned long long> output(n, 0);
    vector<int> count(10, 0);

    // Find the digit at the current place value, such as ones or tens.
    for (unsigned long long num : arr) {
        int digit = static_cast<int>((num / exp) % 10);
        count[digit]++;
    }

    if (ascending) {
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    }
    else {
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = static_cast<int>((arr[i] / exp) % 10);
        // Place the element in the temporary array while keeping order stable.
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSortUnsigned(vector<unsigned long long>& arr, bool ascending) {
    if (arr.size() <= 1) {
        return;
    }

    unsigned long long maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    for (unsigned long long exp = 1; maxVal / exp > 0; ) {
        // Sort once for each place value, from the rightmost digit to the left.
        countingSortByDigit(arr, exp, ascending);
        if (exp > maxVal / 10) {
            break;
        }
        exp *= 10;
    }
}

void radixSort(vector<long> arr, bool ascending = true) {
    cout << "\n--- Radix Sort ---" << endl;
    cout << "Initial Array: ";
    showArray(arr);

    if (arr.size() <= 1) {
        cout << "Sorted Array: ";
        showArray(arr);
        cout << "Time Complexity of Radix Sort -> Best: O(d*n), Average: O(d*n), Worst: O(d*n)" << endl;
        return;
    }

    vector<unsigned long long> negatives;
    vector<unsigned long long> nonNegatives;

    // Radix sort works easily with positive values, so negatives are handled separately.
    for (long val : arr) {
        if (val < 0) {
            unsigned long long absVal = static_cast<unsigned long long>(-(val + 1)) + 1ULL;
            negatives.push_back(absVal);
        }
        else {
            nonNegatives.push_back(static_cast<unsigned long long>(val));
        }
    }

    radixSortUnsigned(negatives, !ascending);
    radixSortUnsigned(nonNegatives, ascending);

    size_t idx = 0;
    if (ascending) {
        for (unsigned long long val : negatives) {
            arr[idx++] = -static_cast<long>(val - 1ULL) - 1L;
        }
        for (unsigned long long val : nonNegatives) {
            arr[idx++] = static_cast<long>(val);
        }
    }
    else {
        for (unsigned long long val : nonNegatives) {
            arr[idx++] = static_cast<long>(val);
        }
        for (unsigned long long val : negatives) {
            arr[idx++] = -static_cast<long>(val - 1ULL) - 1L;
        }
    }

    cout << "Sorted Array: ";
    showArray(arr);
    cout << "Time Complexity of Radix Sort -> Best: O(d*n), Average: O(d*n), Worst: O(d*n)" << endl;
}

void radixSort(vector<float> arr, bool ascending = true) {
    cout << "\n--- Radix Sort ---" << endl;
    cout << "Initial Array: ";
    showArray(arr);

    if (arr.size() <= 1) {
        cout << "Sorted Array: ";
        showArray(arr);
        cout << "Time Complexity of Radix Sort -> Best: O(d*n), Average: O(d*n), Worst: O(d*n)" << endl;
        return;
    }

    vector<unsigned long long> mapped(arr.size());
    for (size_t i = 0; i < arr.size(); i++) {
        uint32_t bits = 0;
        if (arr[i] == 0.0f) arr[i] = 0.0f;
        // Copy the float's bit pattern so negative and positive values can be ordered.
        memcpy(&bits, &arr[i], sizeof(uint32_t));
        if (bits & 0x80000000U) {
            bits = ~bits;
        }
        else {
            bits |= 0x80000000U;
        }
        mapped[i] = static_cast<unsigned long long>(bits);
    }

    radixSortUnsigned(mapped, ascending);

    // Convert the sorted bit patterns back into normal float values.
    for (size_t i = 0; i < arr.size(); i++) {
        uint32_t bits = static_cast<uint32_t>(mapped[i]);
        if (bits & 0x80000000U) {
            bits &= ~0x80000000U;
        }
        else {
            bits = ~bits;
        }
        memcpy(&arr[i], &bits, sizeof(float));
    }

    cout << "Sorted Array: ";
    showArray(arr);
    cout << "Time Complexity of Radix Sort -> Best: O(d*n), Average: O(d*n), Worst: O(d*n)" << endl;
}

void countingSortByChar(vector<string>& arr, int pos, bool ascending) {
    int n = static_cast<int>(arr.size());
    vector<string> output(n);
    vector<int> count(257, 0);

    // Use character + 1 so that a missing character can be represented by 0.
    for (int i = 0; i < n; i++) {
        int charCode = (pos < static_cast<int>(arr[i].size())) ? (static_cast<unsigned char>(arr[i][pos]) + 1) : 0;
        count[charCode]++;
    }

    if (ascending) {
        for (int i = 1; i < 257; i++) {
            count[i] += count[i - 1];
        }
    }
    else {
        for (int i = 255; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int charCode = (pos < static_cast<int>(arr[i].size())) ? (static_cast<unsigned char>(arr[i][pos]) + 1) : 0;
        output[count[charCode] - 1] = arr[i];
        count[charCode]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<string> arr, bool ascending = true) {
    cout << "\n--- Radix Sort ---" << endl;
    cout << "Initial Array: ";
    showArray(arr);
    if (arr.size() <= 1) {
        cout << "Sorted Array: ";
        showArray(arr);
        cout << "Time Complexity of Radix Sort -> Best: O(dn), Average: O(dn), Worst: O(d*n)" << endl;
        return;
    }
    int maxLen = 0;
    for (const string& s : arr) {
        if (static_cast<int>(s.size()) > maxLen) {
            maxLen = static_cast<int>(s.size());
        }
    }
    // Strings are sorted from their last character backwards to the first character.
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        countingSortByChar(arr, pos, ascending);
    }
    cout << "Sorted Array: ";
    showArray(arr);
    cout << "Time Complexity of Radix Sort -> Best: O(dn), Average: O(dn), Worst: O(d*n)" << endl;
}
template <typename T>
bool parseToken(const string& token, T& outVal)
{
    // Try to convert one word into the required data type.
    stringstream ss(token);
    ss >> outVal;
    return !ss.fail() && ss.eof();
}
template <typename T>
bool parseToken(const string& token, string& outVal)
{
    // Strings do not need conversion, but empty entries are rejected.
    outVal = token;
    return !token.empty();
}
template <typename T>
vector<T> getInputData(const string& typeName)
{
    vector<T> data;
    cout << "\nEnter up to 100 " << typeName << " items separated by spaces (press Enter to finish):" << endl;
    while (true)
    {
        string line;
        if (!getline(cin, line)) break;
        if (line.empty()) break;
        // A line is divided into separate words for processing.
        stringstream ss(line);
        string token;
        bool limitReached = false;
        while (ss >> token)
        {
            
            if (data.size() >= 100)
            {
                cout << "Maximum limit of 100 items reached. Extra items ignored." << endl;
                limitReached = true;
                break;
            }
            T val;
            if (parseToken(token, val))
            {
                data.push_back(val);
            }
            else
            {
                cout << "Invalid " << typeName << " entry rejected: '" << token << "'" << endl;
            }
        }
        if (limitReached || data.size() >= 100) break;
        cout << "Current count: " << data.size() << "/100. Enter more or press Enter to finish:" << endl;
    }
    return data;
}
template <typename T>
void runSelectedAlgorithms(const vector<T>& originalData, const vector<int>& algos, bool ascending)
{
    // Run every algorithm chosen by the user on the original data.
    for (int algo : algos)
    {
        if (algo == 1)
            quickSort(originalData, ascending);
        else if (algo == 2)
            mergeSort(originalData, ascending);
        else if (algo == 3)
            radixSort(originalData, ascending);
        else if (algo == 4)
            selectionSort(originalData, ascending);
    }
}
int getValidIntChoice(int minVal, int maxVal)
{
    // Keep asking until the user enters a number within the allowed range.
    while (true)
    {
        string line;
        if (!getline(cin, line)) return minVal;
        stringstream ss(line);
        int choice;
        if ((ss >> choice) && ss.eof() && choice >= minVal && choice <= maxVal)
        {
            return choice;
        }
        cout << "Invalid choice. Please enter a number between " << minVal << " and " << maxVal << ": ";
    }
}

vector<int> getAlgorithmChoices()
{
    while (true)
    {
        cout << "\nSelect Sorting Algorithm(s):" << endl;
        cout << "1. Quick Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Radix Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. All Algorithms" << endl;
        cout << "Enter choices separated by spaces (e.g., 1 3 or 5): ";
        string line;
        if (!getline(cin, line)) return { 5 };
        stringstream ss(line);
        string token;
        vector<int> choices;
        bool valid = true;
        bool selectAll = false;
        while (ss >> token)
        {
            if (token == "all" || token == "ALL" || token == "5")
            {
                selectAll = true;
            }
            else if (token == "1" || token == "2" || token == "3" || token == "4")
            {
                int c = token[0] - '0';
                bool exists = false;
                for (int existing : choices)
                {
                    if (existing == c) exists = true;
                }
                if (!exists) choices.push_back(c);
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (valid && selectAll)
        {
            return { 1, 2, 3, 4 };
        }
        if (valid && !choices.empty())
        {
            return choices;
        }
        cout << "Invalid selection. Try again." << endl;
    }
}
int main()
{
    // The menu stays open until the user chooses option 4 to exit.
    while (true)
    {
        cout << endl << endl;
        cout << "SORTING SYSTEM MENU" << endl;
        cout << "Select Data Type:" << endl;
        cout << "1. long" << endl;
        cout << "2. float" << endl;
        cout << "3. string" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice (1-4): ";
        int typeChoice = getValidIntChoice(1, 4);
        if (typeChoice == 4)
        {
            cout << "Exiting program." << endl;
            break;
        }
        vector <int> algos = getAlgorithmChoices();
        cout << "\nSelect Sort Order:" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        cout << "Enter choice (1-2): ";
        int orderChoice = getValidIntChoice(1, 2);
        bool ascending = (orderChoice == 1);
        if (typeChoice == 1)
        {
            vector<long> data = getInputData<long>("long");
            runSelectedAlgorithms(data, algos, ascending);
        }
        else if (typeChoice == 2)
        {
            vector<float> data = getInputData<float>("float");
            runSelectedAlgorithms(data, algos, ascending);
        }
        else if (typeChoice == 3)
        {
            vector<string> data = getInputData<string>("string");
            runSelectedAlgorithms(data, algos, ascending);
        }
    }
    return 0;
}