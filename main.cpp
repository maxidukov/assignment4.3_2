#include <iostream>

void quick_sort(int*, int);

int main() {
  int aa[3][18] = {
     {3,43,38,29,18,72,57,61,2,33},
     {88,91,87,59,53,49,29,16,4,27,28,89,2,25,74},
     {24,66,20,79,30,16,19,62,94,59,0,7,59,90,84,60,95,62},
  };  //CLUMSY, MAKESHIFT C-STYLE JAGGED 2D ARRAY
  int asizes[3] = {10,15,18};
  //int a[] = {3,2,1};
  for(int j{};j<3;j++){
     std::cout<<"Исходный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n";
     quick_sort(aa[j],asizes[j]);
     std::cout<<"Отсортированный массив: ";
     for(int i{};i<asizes[j];i++){
        std::cout<<aa[j][i]<<" ";
     }
     std::cout << "\n\n";
  }
}

int pivoting(int P, int* a, int size){
  int left = 0;
  int right = size-1;
  int pivot = a[P];
  while(true){
     while(a[left] < pivot){
        left += 1;
     }
     while(a[right] > pivot){
        right -= 1;
     }
     if(left >= right){
        return left;
     }
     std::swap(a[left], a[right]);
     left += 1;
     right -= 1;
  }
}

void quick_sort(int* a, int size){
   if(size>1){
     int border = pivoting(size/2,a,size);
     quick_sort(a,border);
     quick_sort(a+border,size-border);
   }
}

