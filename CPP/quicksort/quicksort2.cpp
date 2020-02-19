#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int getRandomNumber(){
  int randomNumber = 0;
  randomNumber = (rand() % 65535)+1;
  return randomNumber;
}

void randomArrayFill(int* arrayFill, int size){
  for (int i = 0; i < size; i++){
    arrayFill[i] = getRandomNumber();
  }
}

void printArray(int* array, int size){
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int partition(int* a, int l, int h){
  int v, i, j, temp;
  v = a[l];
  i = l;
  j = h+1;

  do{
    do
      i++;
    while(a[i] < v && i <= h);
    do
      j--;
    while(v < a[j]);
    if(i < j){
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }while(i < j);
  a[l] = a[j];
  a[j] = v;
  return(j);
}

void quickSort(int* a, int l, int h){
  int j;
  if(l < h){
    j = partition(a, l, h);
    quickSort(a, l, j - 1);
    quickSort(a, j + 1, h);
  }
}

int main(){
  std::ofstream log_quick;
  int size = 1000000000;
  int* array;
  array = (int *) malloc(size * sizeof(int));
  srand(time(0));
  log_quick.open("time_records_quick.txt", std::ios::app);

  try{
    if (log_quick.is_open()){

      for (size_t i = 1; i <= 50; i++){
        //Generating the array
        randomArrayFill(array, size);
        //Applying Quick Sort
        //cout << "Array de Entrada \n";
        //printArray(array, size);

        printf("Aplicando Quick Sort para %d elementos... \n", size);
        auto start_quick = std::chrono::high_resolution_clock::now();
        quickSort(array, 0, size - 1);
        auto finish_quick = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_quick = finish_quick - start_quick;
        std::cout << "Tempo de execução: " << elapsed_quick.count() << " s\n";
        log_quick << "Quick Sort - Execução nº " << i << " \n";
        log_quick << size << " elementos. \n";
        log_quick << "Tempo de execução: " << elapsed_quick.count() << " s\n\n";
        //cout << "Array de Saída \n";
        //printArray(array, size);
        cout << " ----------- \n";
      }

      log_quick.close();

      }
    }catch(...){
      std::cout << "Incapaz de abrir o arquivo." << '\n';
    }
}
