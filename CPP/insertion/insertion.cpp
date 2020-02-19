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

void insertionSort(int* array, int size){
    int key, j;
    for(int i = 1; i < size; i++){
      j = i;
      while(j > 0 && array[j - 1] > array[j]){
        key = array[j];
        array[j] = array[j - 1];
        array[j - 1] = key;
        j--;
      }
    }
}

void printArray(int* array, int size){
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main(){
  std::ofstream log_insertion;
  int size = 1000000;
  int* array;
  array = (int *) malloc(size * sizeof(int));
  srand(time(0));
  log_insertion.open("time_records_insertion.txt", std::ios::app);

  try{
    if (log_insertion.is_open()){

      for (size_t rep = 1; rep <= 50; rep++){
        //Generating the array
        randomArrayFill(array, size);
        //Applying Insertion Sort
        //printArray(array, size);
        printf("Aplicando Insertion Sort para %d elementos... \n", size);
        auto start_insertion = std::chrono::high_resolution_clock::now();
        insertionSort(array, size);
        auto finish_insertion = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_insertion = finish_insertion - start_insertion;
        std::cout << "Tempo de execução: " << elapsed_insertion.count() << " s\n";
        log_insertion << "Insertion Sort - Execução nº " << rep << " \n";
        log_insertion << size << " elementos. \n";
        log_insertion << "Tempo de execução: " << elapsed_insertion.count() << " s\n\n";
      }

      log_insertion.close();

      }
    }catch(...){
      std::cout << "Incapaz de abrir o arquivo." << '\n';
    }
}
