#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;
using namespace chrono;

void insertion_sort(vector<int>);
void bubble_sort(vector<int>);
void bubble_sort_opt(vector<int>);
void selection_sort(vector<int>);

void print_array(vector<int>);
double time_algorithm(vector<int>, void (*Func)(vector<int>));
string time_algorithms(int arr_length, int iterations);


int main() {
    
    ofstream outputFile("Times.txt");

    srand(time(NULL));

    for(int i=0; i<1001; i+=10){
        
        outputFile << time_algorithms(i, 10);
    }

    outputFile.close();

}

string time_algorithms(int len, int n){
    
    vector<int> numbers(len);
    double a,b,c,d;

    for(int i=0;i<n;++i){
        
        for (int j = 0; j < numbers.size(); ++j) {
            numbers[j] = rand();
        }

        a += time_algorithm(numbers,&insertion_sort);
        b += time_algorithm(numbers,&bubble_sort);
        c += time_algorithm(numbers,&bubble_sort_opt);
        d += time_algorithm(numbers,&selection_sort);
    }

    ostringstream times;
    times << numbers.size() << " " << a/n << " " << b/n << " " << c/n << " " << d/n << endl;
    cout << times.str();
    
    return times.str();
}

double time_algorithm(vector<int> arr, void (*Func)(vector<int>)) {
    auto start = high_resolution_clock::now();
    Func(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void insertion_sort(vector<int> arr) {
    
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = temp;
    }

    //print_array(arr);

}

void bubble_sort(vector<int> arr) {
    
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    //print_array(arr);

}

void bubble_sort_opt(vector<int> arr) {
    
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {

        bool Flag = true;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                Flag = false;
            }
        }
        
        if(Flag) {break;}
    }

    //print_array(arr);

}

void selection_sort(vector<int> arr) {
    
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
    
        int minLoc = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minLoc]) {
                minLoc = j;
            }
        }
        swap(arr[i], arr[minLoc]);
    }
    //print_array(arr);

}
 
void print_array(vector<int> arr) {
    for (int i:arr) {
        cout << i << " ";
    }
    cout << endl;
}