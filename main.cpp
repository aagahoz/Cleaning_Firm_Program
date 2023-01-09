#include <iostream>
#include <cstdlib>
#include <ctime>
#include "library.hpp"

using namespace std;

int main()
{
  const int NUM_FIRMS = 9;
  const int NUM_WORKERS = 47;
  const int NUM_LEAD_WORKERS = 10;
  const int NaN_Firm_Index = -1;

  const string firms[NUM_FIRMS] = {"Firm A", "Firm B", "Firm C", "Firm D", "Firm E", "Firm F", "Firm G", "Firm H", "Firm J"};

  const string workers[NUM_WORKERS] = {"W-1", "W-2", "W-3", "W-4", "W-5", "W-6", "W-7", "W-8", "W-9", "W-10",
                                       "W-11", "W-12", "W-13", "W-14", "W-15", "W-16", "W-17", "W-18", "W-19", "W-20",
                                       "W-21", "W-22", "W-23", "W-24", "W-25", "W-26", "W-27", "W-28", "W-29", "W-30",
                                       "W-31", "W-32", "W-33", "W-34", "W-35", "W-36", "W-37", "W-38", "W-39", "W-40",
                                       "W-41", "W-42", "W-43", "W-44", "W-45", "W-46", "W-47"};
  const string leadWorkers[NUM_LEAD_WORKERS] = {"LW-1", "LW-2", "LW-3", "LW-4", "LW-5", "LW-6", "LW-7", "LW-8", "LW-9", "LW-10"};

  const int worker_counts_for_firms[NUM_FIRMS] = {4, 8, 8, 6, 3, 2, 5, 1, 1};
  const int lead_worker_counts_for_firms[NUM_FIRMS] = {1, 1, 2, 2, 1, 1, 1, 0, 0};

  bool *worker_is_appointed = create_1D_bool_array(NUM_WORKERS);
  bool *lead_worker_is_appointed = create_1D_bool_array(NUM_LEAD_WORKERS);
  bool **worker_was_appointed_firms = create_2D_array_init_false(NUM_WORKERS, NUM_FIRMS);
  bool **lead_worker_was_appointed_firms = create_2D_array_init_false(NUM_LEAD_WORKERS, NUM_FIRMS);
  int *index_firm_for_lead_workers = create_1D_array_init_value(NUM_LEAD_WORKERS, NaN_Firm_Index);

  int total_requested_worker_count = 0;
  bool isMaximumIterationReached = false;
  bool lead_worker_rotation_need = true;
  int iterationCounter = 20;
  int localIteration = 1;

  srand(time(0));
  while (iterationCounter) // for 20 worker appointment iterations
  {
    cout << endl;
    cout << endl;
    cout << "Local Iteration is " << localIteration << endl;
    cout << "General Iteration is " << 21 - iterationCounter << endl;

    if (lead_worker_rotation_need) // lead workers appointments
    {
      lead_worker_rotation_need = false;
      reset_array_to_false_1D(lead_worker_is_appointed, NUM_LEAD_WORKERS);
      reset_array_to_false_2D(worker_was_appointed_firms, NUM_WORKERS, NUM_FIRMS);
      reset_array_to_false_2D(lead_worker_was_appointed_firms, NUM_LEAD_WORKERS, NUM_FIRMS);
      reset_array_to_false_1D_init_value(index_firm_for_lead_workers, NUM_LEAD_WORKERS, NaN_Firm_Index);

      int *temp_lead_worker_counts_for_firms = create_1D_int_array(NUM_FIRMS);
      int total_requested_lead_worker_count = 0;
      for (int i = 0; i < NUM_FIRMS; i++) // calculate requested lead workers number
      {
        total_requested_lead_worker_count += lead_worker_counts_for_firms[i];
        temp_lead_worker_counts_for_firms[i] = lead_worker_counts_for_firms[i];
      }

      while (total_requested_lead_worker_count) // iteration for lead workers
      {
        int selectedFirm = rand() % NUM_FIRMS;
        int randomLeadWorker = rand() % NUM_LEAD_WORKERS;

        if (lead_worker_is_appointed[randomLeadWorker] == false) // worker is appointed ?
        {
          if (temp_lead_worker_counts_for_firms[selectedFirm] > 0) // work need appointment ?
          {
            if (lead_worker_was_appointed_firms[randomLeadWorker][selectedFirm] == false) // the worker worked the firm ?
            {
              lead_worker_is_appointed[randomLeadWorker] = true;
              temp_lead_worker_counts_for_firms[selectedFirm]--;
              index_firm_for_lead_workers[randomLeadWorker] = selectedFirm;
              lead_worker_was_appointed_firms[randomLeadWorker][selectedFirm] = true;
              total_requested_lead_worker_count--;
            }
          }
        }
      }
      delete_1D_int_array(temp_lead_worker_counts_for_firms);

      // print_was_appointed_for_lead_workers(lead_worker_was_appointed_firms, NUM_LEAD_WORKERS, NUM_FIRMS);
    }

    reset_array_to_false_1D(worker_is_appointed, NUM_WORKERS);

    int temp_worker_counts_for_firms[NUM_FIRMS];
    copy_array_values(worker_counts_for_firms, temp_worker_counts_for_firms, NUM_FIRMS);
    int total_requested_worker_count = total_requested_worker_count = get_total_array_values(temp_worker_counts_for_firms, NUM_FIRMS);

    int *index_firm_for_workers = create_1D_array_init_value(NUM_WORKERS, NaN_Firm_Index);

    unsigned long long int endlessLoopChecker = 0;
    int temp_total_requested_worker_count = total_requested_worker_count;
    while (temp_total_requested_worker_count) // 1 worker appointment for one iteration
    {
      int selectedFirm = rand() % NUM_FIRMS;
      int randomWorker = rand() % NUM_WORKERS;

      if (worker_is_appointed[randomWorker] == false) // worker is appointed ?
      {
        if (temp_worker_counts_for_firms[selectedFirm] > 0) // work need appointment ?
        {

          if (worker_was_appointed_firms[randomWorker][selectedFirm] == false) // the worker worked the firm ?
          {
            worker_is_appointed[randomWorker] = true;
            worker_was_appointed_firms[randomWorker][selectedFirm] = true;
            temp_worker_counts_for_firms[selectedFirm]--;        // decrease firm request
            index_firm_for_workers[randomWorker] = selectedFirm; // save worker to firm
            temp_total_requested_worker_count--;                 // decrease requested total worker
          }
        }
      }

      endlessLoopChecker++;
      if (endlessLoopChecker > 1000000) // check infinite number
      {
        cout << endl;
        cout << "[INFO] Maximumum Iteration Reached" << endl;
        cout << endl;
        isMaximumIterationReached = true;
        localIteration = 1;
        break;
      }
    }

    int numberOfAppointedWorkers = get_filled_index_count_by_minus1(index_firm_for_workers, NUM_WORKERS);

    bool iterationIsFinished = false;
    if (numberOfAppointedWorkers == total_requested_worker_count) // checks iteration is finished successfully
    {
      iterationIsFinished = true;
      iterationCounter--;
      localIteration++;
    }

    if (iterationIsFinished)
    {
      print_all_workers_for_itaretion(index_firm_for_workers, index_firm_for_lead_workers, lead_worker_counts_for_firms, NUM_FIRMS, NUM_WORKERS, NUM_LEAD_WORKERS, firms, workers, leadWorkers);
      // print_was_appointed_for_lead_workers(worker_was_appointed_firms, NUM_LEAD_WORKERS, NUM_FIRMS);
    }
    delete_1D_int_array(index_firm_for_workers);

    if (isMaximumIterationReached) // iteration can finish ?
    {
      lead_worker_rotation_need = true;
      isMaximumIterationReached = false;
    }

    endlessLoopChecker = 0; // if iteration is finished, reset infinite loop checker to 0
  }

  delete_1D_bool_array(worker_is_appointed);
  delete_1D_bool_array(lead_worker_is_appointed);
  delete_2D_bool_array(worker_was_appointed_firms, NUM_WORKERS);
  delete_2D_bool_array(lead_worker_was_appointed_firms, NUM_LEAD_WORKERS);
  delete_1D_int_array(index_firm_for_lead_workers);

  cout << "** Program finished succesfully **" << endl;
  cout << endl;

  return 0;
}
