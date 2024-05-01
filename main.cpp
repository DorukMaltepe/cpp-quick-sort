#include <iostream>
#include "vector"

// Pivot always last index
void quickSort(std::vector<int> &arr, int start, int end){
    if(end <= start){
        return;
    }

    int pivot = end;
    int i = start-1 , j = start;
    int temp = 0;

    while(j != pivot){

        if(arr[j] >= arr[pivot]){
            j++;
        } else if (arr[j] < arr[pivot]){
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    i++;
    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;


    quickSort(arr, start,i-1);
    quickSort(arr, i+1, arr.size()-1);

}

int main() {
    std::vector<int> arr = {8,2,4,7,1,3,9,6,5};
    int arr_size = arr.size();

    std::cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    quickSort(arr, 0, arr.size()-1);

    std::cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
