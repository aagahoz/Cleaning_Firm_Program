#include "library.hpp"

void reset_array_to_false_1D(bool *array, int size)
{
  for (int i = 0; i < size; i++) // lead_worker_is_appointed reset to false
    array[i] = false;
}

void reset_array_to_false_1D_init_value(int *array, int size, int initValue)
{
  for (int i = 0; i < size; i++) // lead_worker_is_appointed reset to false
    array[i] = initValue;
}

void reset_array_to_false_2D(bool **array, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      array[i][j] = false;
}

bool **create_2D_array_init_false(int rows, int cols)
{
  bool **array = new bool *[rows];

  for (int i = 0; i < rows; i++)
    array[i] = new bool[cols];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      array[i][j] = false;

  return array;
}

int *create_1D_array_init_value(int size, int init_value)
{
  int *array = new int[size];

  for (int i = 0; i < size; i++)
    array[i] = init_value;

  return array;
}

bool *create_1D_bool_array(int size)
{
  bool *array = new bool[size];

  return array;
}

int *create_1D_int_array(int size)
{
  int *array = new int[size];

  return array;
}

void delete_1D_int_array(int *array)
{
  delete[] array;
}

void delete_1D_bool_array(bool *array)
{
  delete[] array;
}

void delete_2D_bool_array(bool **array, int rows)
{
  for (int i = 0; i < rows; i++)
    delete[] array[i];

  delete[] array;
}

void print_was_appointed_for_lead_workers(bool **TableArray2D, int numLeadWorkers, int numFirms)
{
  cout << "Lead Workers All Appointments Table" << endl;
  for (int i = 0; i < numLeadWorkers; i++)
  {
    for (int j = 0; j < numFirms; j++)
    {
      cout << TableArray2D[i][j] << "  ";
    }
    cout << endl;
  }
}

void print_was_appointed_for_workers(bool **TableArray2D, int numWorkers, int numFirms)
{
  cout << "Workers All Appointments Table" << endl;
  for (int i = 0; i < numWorkers; i++)
  {
    for (int j = 0; j < numFirms; j++)
    {
      cout << TableArray2D[i][j] << "  ";
    }
    cout << endl;
  }
}

void print_all_workers_for_itaretion(int *indexFirmForWorkers, int *indexFirmForLeadWorkers, const int *leadWorkerCountsForFirms, int numFirms, int numWorkers, int numLeadWorkers, const string *firmsName, const string *workersNames, const string *leadWorkersName)
{
  cout << endl;
  cout << " **   Appointed Workers List   **" << endl;
  for (int i = 0; i < numFirms; i++)
  {
    cout << firmsName[i] << ": " << setw(2);
    for (int j = 0; j < numLeadWorkers; j++)
    {
      if (indexFirmForLeadWorkers[j] == i)
      {
        cout << leadWorkersName[j] << " ";
      }
    }
    cout << setw((4 - leadWorkerCountsForFirms[i]) * 5);

    for (int j = 0; j < numWorkers; j++)
    {
      if (indexFirmForWorkers[j] == i)
      {
        cout << workersNames[j] << "  ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void copy_array_values(const int *arrayOrign, int *newArray, int size)
{
  for (int i = 0; i < size; i++)
  {
    newArray[i] = arrayOrign[i];
  }
}

int get_total_array_values(int *array, int size)
{
  int total = 0;
  for (int i = 0; i < size; i++)
  {
    total += array[i];
  }
  return total;
}

int get_filled_index_count_by_minus1(int *array, int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] != -1)
    {
      count++;
    }
  }
  return count;
}