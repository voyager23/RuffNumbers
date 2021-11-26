# makefile for dev folder

a_dev : ../inc/toolbox.o a_dev.cxx
	g++ --std=c++11 -g -Wall -o a_dev ../inc/toolbox.o a_dev.cxx
	
../inc/toolbox.o : toolbox.cxx
	g++ --std=c++11 -g -Wall -c -o ../inc/toolbox.o toolbox.cxx
	
s3 : ../inc/toolbox.o s3.cxx
	g++ --std=c++11 -g -Wall -o s3 ../inc/toolbox.o s3.cxx
	
s3_s8 : ../inc/toolbox.o s3_s8.cxx
	g++ --std=c++11 -g -Wall -o s3_s8 ../inc/toolbox.o s3_s8.cxx
	
