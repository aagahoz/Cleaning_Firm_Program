#ifndef library_hpp
#define library_hpp

#include <iostream>
#include <iomanip>
using namespace std;

void reset_array_to_false_1D(bool *array, int size);
void reset_array_to_false_1D_init_value(int *array, int size, int initValue);
void reset_array_to_false_2D(bool **array, int rows, int cols);

bool **create_2D_array_init_false(int rows, int cols);
int *create_1D_array_init_value(int size, int init_value);
bool *create_1D_bool_array(int size);
int *create_1D_int_array(int size);

void delete_1D_int_array(int *array);
void delete_1D_bool_array(bool *array);
void delete_2D_bool_array(bool **array, int rows);

void print_was_appointed_for_lead_workers(bool **TableArray2D, int numLeadWorkers, int numFirms);
void print_was_appointed_for_workers(bool **TableArray2D, int numWorkers, int numFirms);
void print_all_workers_for_itaretion(int *indexFirmForWorkers, int *indexFirmForLeadWorkers, const int *leadWorkerCountsForFirms, int numFirms, int numWorkers, int numLeadWorkers, const string *firmsName, const string *workersNames, const string *leadWorkersName);

void copy_array_values(const int *arrayOrign, int *newArray, int size);
int get_total_array_values(int *array, int size);

int get_filled_index_count_by_minus1(int* array, int size);

#endif