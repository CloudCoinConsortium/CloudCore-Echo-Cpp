#include "raida.h"
#include <pthread.h>
#include <sys/sysinfo.h>	//	For get_nprocs()
#include <chrono>	// For calculating elapsed time
#include <iostream>
using namespace std;

#define MIN_THREADS	2	//	Minimum number of Threads
#define MAX_THREADS	16	//	Maximum number of Threads

// total number of RAIDAs
const unsigned int RAIDA_COUNT = 25;
// unsigned int RAIDA_COUNT = (sizeof(indexes)/sizeof(*indexes));
// Create all the RAIDA objects
Raida raidas[RAIDA_COUNT];
int max_threads = 2;

void* echoCaller(void *arg);

int main()
{
	// Record start time
	auto start = std::chrono::high_resolution_clock::now();

	// raida1, raida2, raida3 ... etc
	int indexes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
					10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
					20,	21, 22, 23, 24};	

	// the number of processors currently available in the system
	int nprocs = get_nprocs();
	pthread_t threads[RAIDA_COUNT];
	int error_number = 0;
	int i = 0;

	for (i = 0; i < RAIDA_COUNT; i++)
	{
		raidas[i].setIndex(indexes[i]);
	}

	max_threads = MIN_THREADS;
	if ((nprocs >= MIN_THREADS) && (nprocs <= MAX_THREADS))
		max_threads = nprocs;
	else if (nprocs < MIN_THREADS)
		max_threads = MIN_THREADS;
	else
		max_threads = MAX_THREADS;

	int task_ids[max_threads];

	for (i = 0; i < max_threads; i++)
	{
		task_ids[i] = i;
		error_number = pthread_create(&(threads[i]), NULL, echoCaller, (void *)&(task_ids[i]));
		if (error_number)
		{
			cout << "ERROR; return code from pthread_create() is " << error_number << endl;
			exit(EXIT_FAILURE);
		}
	}

	if ((RAIDA_COUNT % max_threads) != 0)
	{
		// Master thread needs to processes remaining entries of the raidas array
		int items_per_thread = RAIDA_COUNT / max_threads;
		int start_index = max_threads * items_per_thread;
		int end_index = RAIDA_COUNT - 1;

		for (i = start_index; i <= end_index; i++)
		{
			// cout << "Master Thread: ";
			// raidas[i].echo();
			cout << raidas[i].getIndex() << "\n";
		}
	}

	//	Wait for the Resolver threads to terminate
	for (i = 0; i < max_threads; i++)
	{
		error_number = pthread_join(threads[i], NULL);
	}

	// for (unsigned int i = 0; i < RAIDA_COUNT; i++)
	// {
	// 	Raida r;
	// 	r.setIndex(indexes[i]);
	// 	r.echo();
	// 	r.displayOutput();
	// }
	
	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	return 0;
}


void* echoCaller(void *arg)
{
	int task_id = *((int *)arg);
	int items_per_thread = RAIDA_COUNT / max_threads;
	int start_index = task_id * items_per_thread;
	int end_index = start_index + items_per_thread - 1;

	for (int i = start_index; i <= end_index; i++)
	{
		// cout << "Thread " << task_id << ": ";
		// raidas[i].echo();
		cout << raidas[i].getIndex() << "\n";
	}


	return NULL;
}

/**
 * 6 threads
 *
 * 27 raidas - 0 - 26
 *
 * thread 0: 0 - 3
 * thread 1: 4 - 7
 * thread 2: 8 - 11
 * thread 3: 12 - 15
 * thread 4: 16 - 19
 * thread 5: 20 - 23
 *  	balance of 3 raidas 
 * 
 */