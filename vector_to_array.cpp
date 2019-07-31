#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
/*
	References:
	https://stackoverflow.com/questions/49582252/pybind-numpy-access-2d-nd-arrays
	https://github.com/pybind/pybind11/issues/1042
	https://github.com/cjaques/pybind_examples/blob/master/example0/add_vectors.cpp
*/

namespace py = pybind11;

auto v = new std::vector<int>(3, 42);


PYBIND11_MODULE(vector_to_array, m) {
    m.def("get_vector", []() {
		auto capsule = py::capsule(v, [](void *v) { delete reinterpret_cast<std::vector<int>*>(v); });
		return py::array_t<int>(v->size(), v->data(), capsule);
		});
	
	m.def("add_arrays", [](py::array_t<int> input1, py::array_t<int> input2) {
		auto buf1 = input1.request(), buf2 = input2.request();
		
		if (buf1.ndim != 1 || buf2.ndim != 1)
			throw std::runtime_error("Number of dimensions must be one");
		if (buf1.size != buf2.size)
			throw std::runtime_error("Input shapes must match");
		
		/*  allocate the buffer */
		py::array_t<int> result = py::array_t<int>(buf1.size);

		auto buf3 = result.request();

		int *ptr1 = (int *) buf1.ptr, *ptr2 = (int *) buf2.ptr, *ptr3 = (int *) buf3.ptr;

		for (int idx = 0; idx < buf1.shape[0]; idx++)
			ptr3[idx] = ptr1[idx] + ptr2[idx];

		return result;
	});
}