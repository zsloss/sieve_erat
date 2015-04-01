#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <ctime>

std::vector<int> vec_sieve(const int max) {

	// Fill new collection with sequence up to MAX
	std::vector<int> nums(max - 1);
	std::iota(nums.begin(), nums.end(), 2);
	
	auto it = nums.begin();

	while (it != nums.end()) {
		int curr_prime = *it;

		// Remove all numbers divisible by current prime.
		nums.erase(std::remove_if(it, nums.end(), [curr_prime](const int i){ return i != curr_prime && i % curr_prime == 0; }), nums.end());
		it = std::find(nums.begin(), nums.end(), curr_prime) + 1;
	}
	return nums;
}

std::list<int> list_sieve(const int max) {

	// Fill new collection with sequence up to MAX
	std::list<int> nums(max - 1);
	std::iota(nums.begin(), nums.end(), 2);

	auto it = nums.begin();

	while (it != nums.end()) {
		int curr_prime = *it;

		// Remove all numbers divisible by current prime.
		nums.remove_if([curr_prime](const int i){ return i != curr_prime && i % curr_prime == 0; });
		it = std::next(std::find(nums.begin(), nums.end(), curr_prime));
	}
	return nums;
}

// Print the primes to stdout.
template<typename T>
void print_primes(const T& primes) {
	for (auto it = primes.begin(); it != primes.end(); ++it) {
		std::cout << *it;
		std::cout << (std::next(it) != primes.end() ? ", " : ".\n\n");
	}	
}

int main() {

	clock_t t;

	// LIST
	t = clock();
	auto list_primes = list_sieve(10000);	
	t = clock() - t;

	std::cout << "list\n\n";	
	print_primes(list_primes);	
	std::cout << "That took " << ((float)t) / CLOCKS_PER_SEC << " seconds.\n\n\n";

	// VECTOR
	t = clock();
	auto vec_primes = vec_sieve(10000);
	t = clock() - t;

	std::cout << "vector\n\n";
	print_primes(vec_primes);
	std::cout << "That took " << ((float)t) / CLOCKS_PER_SEC << " seconds.\n\n\n";
}

