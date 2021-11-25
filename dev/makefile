# makefile for dev folder

a_dev : ../inc/toolbox.o a_dev.cxx
	g++ --std=c++11 -g -Wall -o a_dev ../inc/toolbox.o a_dev.cxx
	
../inc/toolbox.o : toolbox.cxx
	g++ --std=c++11 -g -Wall -c -o ../inc/toolbox.o toolbox.cxx
