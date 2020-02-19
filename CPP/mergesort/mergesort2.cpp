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

void randomArrayFill(long* arrayFill, int size){
  for (int i = 0; i < size; i++){
    arrayFill[i] = getRandomNumber();
  }
}

void merge(long* array,long low,long mid,long high){
    long n1 = mid-low+1;
    long n2 = high - mid;
    long *L= new long [n1+1];
    long *R=new long [n2+1];
    for (int i=0;i<=n1;i++){
        L[i] = array[low+i];

    }
    for (int j=0;j<=n2;j++){
        R[j] = array[mid+j+1];
    }
    L[n1]=INT_MAX ;
    R[n2]=INT_MAX;
    long i=0;
    long j=0;
    for (long k=low;k<=high;k++){
        if (L[i] <= R[j] ){
            array[k]=L[i];
            i=i+1;
        }
        else{
            array[k]=R[j];
            j=j+1;
        }
    }

    delete[] L;
    delete[] R;
}

void mergeSort(long* array,long low,long high){
    if (low<high){
      int mid =(low+high)/2;
      mergeSort(array,low,mid);
      mergeSort(array,mid+1,high);
      merge(array,low,mid,high);
    }
}

void printArray(int* array, int size){
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main(){
  std::ofstream log_merge, log_quick, log_insertion;
  int size = 100000000;
  long* array = new long[size];
  srand(time(0));
  log_merge.open("time_records_merge.txt", std::ios::app);

  try{
    if (log_merge.is_open()){

      for (size_t i = 1; i <= 50; i++){
        //Generating the array
        randomArrayFill(array, size);
        //Applying Merge Sort
        printf("Aplicando Merge Sort para %d elementos... \n", size);
        auto start_merge = std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, size-1);
        auto finish_merge = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_merge = finish_merge - start_merge;
        std::cout << "Tempo de execução: " << elapsed_merge.count() << " s\n";
        log_merge << "Merge Sort - Execução nº " << i << " \n";
        log_merge << size << " elementos. \n";
        log_merge << "Tempo de execução: " << elapsed_merge.count() << " s\n\n";
        cout << " ----------- \n";
      }

      log_merge.close();

      }
    }catch(...){
      std::cout << "Incapaz de abrir o arquivo." << '\n';
    }
}
