SUM=sum
OARRAY=one_array
NARRAY=numpy_array
VARRAY=vector_to_array


all: sum oarray earray


sum:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` $(SUM).cpp -o $(SUM)`python3-config --extension-suffix`

oarray:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` $(OARRAY).cpp -o $(OARRAY)`python3-config --extension-suffix`
	python3 $(OARRAY).py
	
narray:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` $(NARRAY).cpp -o $(NARRAY)`python3-config --extension-suffix`
	python3 $(NARRAY).py

varray:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` $(VARRAY).cpp -o $(VARRAY)`python3-config --extension-suffix`
	python3 $(VARRAY).py


clean:
	rm *.so



