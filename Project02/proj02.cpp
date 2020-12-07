/*
 * Abhiram Durgaraju
 * CSE 232
 * Project 02 - K-Hyperperfect Numbers
 */

#include <iostream>
#include <cmath>

using std::cin; using std::cout; using std::endl; using std::sqrt; using std::floor;

int main() {
	long chk = 0,												//integer entered which will be chked for k-hyperperfectness
		 max_k = 0;												//integer entered as an inclusive upper bound for k

	cin >> chk >> max_k;										//store inputs

	if (chk < 6 || max_k < 1) {
		cout << 0;												//no number less than 6 can ever be k-hyperperfect, and k must be at least one
	} else {
		long output = 0;										//will serve as the default output if no k is found such that chk is k-hyperperfect; will be reassigned if chk is k-hyperperfect for some k
		for (long k = 1; k <= max_k; ++k) {						//iterate through all k's less than or equal to max_k and chk if k-hyperperfectness applies 
			long sum = 0;										//variable to store sum of all divisors of the number being chked; will reset with each k being chked
			for (long i = 2; i <= floor(sqrt(chk)); ++i) {	//sum all divisors which are not 1 nor the number being chked
				if ((chk % i == 0) && (i == (chk / i))){
					sum += i;									//here we have a perfect square - only add divisor once, as divisor == factor
				} else if (chk % i == 0) {
					sum += i + (chk / i);						//here we add both the divisor and its factor on the same iteration to avoid redundancy and increase efficiency; we now must only chk for divisors <= floor(sqrt(chk))
				}
			}

			long res = sum * k + 1;							//multiply sum of divisors by k and add one to chk for k-hyperperfectness

			if (res == chk) {								//then, the integer input is k-hyperperfect for the k of this iteration; assign to output to print and break
				output = k;
				break;
			}
		}
		cout << output;
	}
	return 0;
}