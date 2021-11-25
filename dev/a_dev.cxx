/*
 * a_dev.cxx
 * 
 * Copyright 2021 Mike <mike@fedora35>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * Write the set S(k) where S contains 2,5 and first k primes ending in 7
 */


#include <iostream>

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	const ul n = 1000; // Guess at a high prime
	const ul k = 3;
	ul Nk = 1;	// product of all elements of Sk
	std::vector<ul> Sk = {2,5}; // Given data
    std::vector<ul> primes;
    SieveOfEratosthenes(primes,n+2);
    // Add additional primes to Sk
    ul count = 1;
    for(auto i = std::next(primes.begin(), 3); i != primes.end(); ++i){
		if((*i % 10) == 7){
			Sk.push_back(*i);
			if(++count >k) break;
		}
	}
	// Calc limiting product Nk
	for(auto i = Sk.begin(); i != Sk.end(); ++i) Nk *= *i;
	std::cout << "Nk: " << Nk << std::endl;
	// Set up an array for sieving numbers < Nk
	const size_t size = (const size_t)Nk;
	std::array<bool, 44030> sieve;	// Assume all elements are False - zero.
	size_t idx = 0;	// general purpose index for sieve
	// now sieve out all primes and multiples from Sk
	for(auto i = Sk.begin(); i != Sk.end(); ++i){
		idx = size_t(*i);
		while(idx < size){
			sieve[idx] = true;
			idx += *i;
		}
	}
    NL;
    // test that all false elements of sieve are not divisible by any element of Sk
    ul F = 0;
	size_t j = 2;
	while(j < size){
		if((!sieve[j])&&((j % 10) == 7)){
			F += j;
			//std::cout << j << "  ";
		}
		j++;
	}
	NL;
	std::cout << "F(3): " << F << std::endl;
	return 0;
}

