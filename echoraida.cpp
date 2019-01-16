#include "raida.h"
#include <pthread.h>
#include <chrono>
#include <iostream>
using namespace std;

int main()
{
	// raida1, raida2, raida3 ... etc
	int indexes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
					10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
					20,	21, 22, 23, 24};

	// total number of RAIDAs
	unsigned int raida_count = (sizeof(indexes)/sizeof(*indexes));

	// Record start time
	auto start = std::chrono::high_resolution_clock::now();


	for (unsigned int i = 0; i < raida_count; i++)
	{
		Raida r;
		r.setIndex(indexes[i]);
		r.echo();
		r.displayOutput();
	}
	
	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	return 0;
}