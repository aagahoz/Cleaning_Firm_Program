# Proje Tanımı:	  47 adet işçi ve 10 adet kıdemli işçi 10 adet firmaya dağıtılacaktır. Dağılım şu koşullara göre olacaktır.

            •	Kıdemli işçilerin talep edilen sayıda görevlendirmesi rastgele bir şekilde yapılır.

            •	Normal işçiler rastgele firmalara görevlendirilir.

            •	Bir işçi aynı firmada tekrar çalışabilmesi için tüm firmalarda 1 kez çalışması gerekmektedir.

            •	Normal işçilerin olabildiğince tüm firmalarda çalışmalıdır. 
                     Eğer artık olasılık yoksa “Maksimum İterasyon” durumu gerçekleşmiştir.

            •	Bu durumda tüm işçilerin önceki firmalarda çalışma kaydı silinir ve en baştan dağılım rastgele 
                     bir şekilde gerçekleşir. Ve ardından kıdemli işçiler de daha önce çalışmadıkları 
                     bir firmaya rastgele bir şekilde görevlendirilir.

            •	Normal işçiler 20 kez görevlendirilene kadar program devam eder.


# Program Algoritması:

###      1.  Kıdemli işçiler görevlendirilmesi yapılır.
                    
                a. Rastgele kıdemli işçi ve rastgele bir firma seçilir.
                    
```cpp
                               int selectedFirm = rand() % NUM_FIRMS;
                               int randomLeadWorker = rand() % NUM_LEAD_WORKERS;
```
                    
                b. Seçilen işçinin görevli olup olmadığı kontrol edilir.
```cpp
                               if (lead_worker_is_appointed[randomLeadWorker] == false) // worker is appointed ?
```                
             
                c. Seçilen firmanın işçi ihtiyacı olup olmadığı kontrol edilir.
                    
```cpp
                               if (temp_lead_worker_counts_for_firms[selectedFirm] > 0) // work need appointment ?
```    
                d. Seçilen işçinin seçilen firmada daha önce görev alıp almadığı “lead_worker_was_appointed_firms” kontrol edilir.
```cpp
                               if (lead_worker_was_appointed_firms[randomLeadWorker][selectedFirm] == false) // the worker worked the firm ?
```    
                e.  b, c, d koşullanır sağlanıyor ise görevlendirme gerçekleşir.
```cpp
                                 lead_worker_is_appointed[randomLeadWorker] = true;
                                 temp_lead_worker_counts_for_firms[selectedFirm]--;
                                 index_firm_for_lead_workers[randomLeadWorker] = selectedFirm;
                                 lead_worker_was_appointed_firms[randomLeadWorker][selectedFirm] = true;
                                 total_requested_lead_worker_count--;
```    

###      2.  Kıdemli işçiler görevlendirilmesi yapılır.
                    
                a. Rastgele işçi ve rastgele bir firma seçilir.
                    
```cpp
                               int selectedFirm = rand() % NUM_FIRMS;
                               int randomWorker = rand() % NUM_WORKERS;
```
                    
                b. Seçilen işçinin görevli olup olmadığı kontrol edilir.
```cpp
                                if (worker_is_appointed[randomWorker] == false) // worker is appointed ?
```                
             
                c. Seçilen firmanın işçi ihtiyacı olup olmadığı kontrol edilir.
                    
```cpp
                                if (temp_worker_counts_for_firms[selectedFirm] > 0) // work need appointment ?
```    
                d. Seçilen işçinin seçilen firmada daha önce görev alıp almadığı “worker_was_appointed_firms” kontrol edilir.
```cpp
                                if (worker_was_appointed_firms[randomWorker][selectedFirm] == false) // the worker worked the firm ?
```    
                e.  b, c, d koşullanır sağlanıyor ise görevlendirme gerçekleşir.
```cpp
                                 worker_is_appointed[randomLeadWorker] = true;
                                 temp_worker_counts_for_firms[selectedFirm]--;
                                 index_firm_for_workers[randomWorker] = selectedFirm;
                                 worker_was_appointed_firms[randomWorker][selectedFirm] = true;
                                 total_requested_worker_count--;
```    

###      3. İkinci aşama maksimum iterasyona ulaşana kadar tekrarlanır. 
###      Maksimum İterasyon: Rastgele seçilen işçilerin artık yeni bir firmaya yerleşememesi.
###      Programda bu durum döngünün sonsuz hale gelmesi ile kontrol edilmiştir. 
###     Eğer döngü bitmiyorsa maksimum iterasyon durumu gerçekleşmiştir.

```cpp
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
```

###      4. Normal işçiler 20 kez şirket değiştikleri zaman program sonlandırılır.
```cpp
                                  while (iterationCounter) // for 20 worker appointment iterations
                                  {
                                    .
                                    .
                                    .
                                  }
```  


