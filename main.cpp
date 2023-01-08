#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  const int NUM_FIRMS = 9;
  const int NUM_WORKERS = 47;
  const int NUM_LEAD_WORKERS = 10;

  const string firms[NUM_FIRMS] = {"Firm A", "Firm B", "Firm C", "Firm D", "Firm E", "Firm F", "Firm G", "Firm H", "Firm J"};

  const string workers[NUM_WORKERS] = {"W-1", "W-2", "W-3", "W-4", "W-5", "W-6", "W-7", "W-8", "W-9", "W-10",
                                       "W-11", "W-12", "W-13", "W-14", "W-15", "W-16", "W-17", "W-18", "W-19", "W-20",
                                       "W-21", "W-22", "W-23", "W-24", "W-25", "W-26", "W-27", "W-28", "W-29", "W-30",
                                       "W-31", "W-32", "W-33", "W-34", "W-35", "W-36", "W-37", "W-38", "W-39", "W-40",
                                       "W-41", "W-42", "W-43", "W-44", "W-45", "W-46", "W-47"};
  const string leadWorkers[NUM_LEAD_WORKERS] = {"LW-1", "LW-2", "LW-3", "LW-4", "LW-5", "LW-6", "LW-7", "LW-8", "LW-9", "LW-10"};

  const int worker_counts_for_firms[NUM_FIRMS] = {4, 8, 8, 6, 3, 2, 5, 1, 1};
  const int lead_worker_counts_for_firms[NUM_FIRMS] = {1, 1, 2, 2, 1, 1, 1, 0, 0};

  bool worker_is_appointed[NUM_WORKERS];
  bool lead_worker_is_appointed[NUM_WORKERS];

  bool worker_was_appointed_firms[NUM_WORKERS][NUM_FIRMS];

  for (int i = 0; i < NUM_LEAD_WORKERS; i++)
    lead_worker_is_appointed[i] = false;

  for (int i = 0; i < NUM_WORKERS; i++)
  {
    for (int j = 0; j < NUM_FIRMS; j++)
    {
      worker_was_appointed_firms[i][j] = false;
    }
  }

  int temp_worker_counts_for_firms[NUM_FIRMS];
  int total_requested_worker_count = 0;
  for (int i = 0; i < NUM_FIRMS; i++)
  {
    total_requested_worker_count += worker_counts_for_firms[i];
    temp_worker_counts_for_firms[i] = worker_counts_for_firms[i];
  }

  srand(time(0));
  cout << "Appointed Workers List" << endl;
  bool isMaximumIterationReached = false;
  for (int k = 0; k < 30; k++)
  {
    for (int i = 0; i < NUM_WORKERS; i++)
      worker_is_appointed[i] = false;

    int temp_worker_counts_for_firms[NUM_FIRMS];
    int total_requested_worker_count = 0;
    for (int i = 0; i < NUM_FIRMS; i++)
    {
      total_requested_worker_count += worker_counts_for_firms[i];
      temp_worker_counts_for_firms[i] = worker_counts_for_firms[i];
    }
    unsigned long long int endlessLoopChecker = 0;
    while (total_requested_worker_count)
    {
      int selectedFirm = rand() % NUM_FIRMS;
      int randomWorker = rand() % NUM_WORKERS;

      if (worker_is_appointed[randomWorker] == false)
      {
        if (temp_worker_counts_for_firms[selectedFirm] > 0)
        {
          selectedFirm++;
          if (worker_was_appointed_firms[randomWorker][selectedFirm] == false)
          {
            worker_is_appointed[randomWorker] = true;
            worker_was_appointed_firms[randomWorker][selectedFirm] = true;
            temp_worker_counts_for_firms[selectedFirm]--;
            cout << firms[selectedFirm] << " : " << workers[randomWorker] << endl;
            total_requested_worker_count--;
          }
        }
      }
      endlessLoopChecker++;
      if (endlessLoopChecker > 300000)
      {
        cout << "Maximumum Iteration Reached" << endl;
        isMaximumIterationReached = true;
        break;
      }
    }
    if (isMaximumIterationReached)
      break;
    cout << "Iteration is " << k << endl;
    endlessLoopChecker = 0;
    for (int i = 0; i < NUM_WORKERS; i++)
    {
      for (int j = 0; j < NUM_FIRMS; j++)
      {
        cout << worker_was_appointed_firms[i][j] << "  ";
      }
      cout << endl;
    }

    cout << k << endl;
  }

  int temp_lead_worker_counts_for_firms[NUM_FIRMS];
  int total_requested_lead_worker_count = 0;
  for (int i = 0; i < NUM_FIRMS; i++)
  {
    total_requested_lead_worker_count += lead_worker_counts_for_firms[i];
    temp_lead_worker_counts_for_firms[i] = lead_worker_counts_for_firms[i];
  }

  cout << "Appointed Lead Workers List" << endl;
  while (total_requested_lead_worker_count)
  {
    int selectedFirm = rand() % NUM_FIRMS;
    int randomLeadWorker = rand() % NUM_LEAD_WORKERS;

    if (lead_worker_is_appointed[randomLeadWorker] == false)
    {
      if (temp_lead_worker_counts_for_firms[selectedFirm] > 0)
      {
        lead_worker_is_appointed[randomLeadWorker] = true;
        temp_lead_worker_counts_for_firms[selectedFirm]--;
        cout << firms[selectedFirm] << " : " << leadWorkers[randomLeadWorker] << endl;
        total_requested_lead_worker_count--;
      }
    }
  }

  return 0;
}

// İşçiler random olarak dağıtılacak, dağıtılan işçiler için şirketi var veya yok şeklinde bir ifade tutulacak
// eğer o işçi yerleştirilmişse veya o firma talep ettiği sayıda işçiye sahip ise random bir şekilde tekrar işlemler gerçekleşecek
// Random seçilen bir işçi random seçilen bir firmaya yerleştirilecek

// işçilerin önceki çalıştıkları firmalar kontrol edilerek buna göre yeni firmalara yerleştirilecek. bu sayede tüm işçiler tüm firmalarda çalışması sağlanacak
