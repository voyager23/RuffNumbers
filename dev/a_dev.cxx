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

void prt_vector(std::vector<ul> v);
void prt_vector(std::vector<ul> v){
	NL;
	for(auto i = v.begin(); i != v.end(); ++i) std::cout << *i << "  ";
	NL;
}

void gen_Sk(ul k, std::vector<ul> &S);
void gen_Sk(ul k, std::vector<ul> &S){
	// generate a vector of primes e.g. S(3) = {2,5,7,17,37}
	// Sanity check 3<=k<=97
	S.clear();
	if((k < 3)||(k > 97)) return;
	// make a list of primes
	std::vector<ul> primes;
	SieveOfEratosthenes(primes, 10000);
	S.assign({2,5,7});
	k -= 1;
	for(auto i = std::next(primes.begin(),6); i != primes.end(); ++i){
		if((*i % 10) != 7) continue;
		S.push_back(*i);
		if(!(--k)) break;
	}
	primes.clear();
}


int main(int argc, char **argv)
{
	std::vector<ul> S;
	gen_Sk(97, S);
	prt_vector(S);
	ul Nk = 1;
	for(auto i = S.begin(); i != S.end(); ++i){
		Nk *= *i;
		if(Nk > 1000000000000000) break;
		std::cout << *i << ":" << Nk << std::endl;
	}
	return 0;
}

