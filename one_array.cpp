#include "pybind11/pybind11.h"
#include "pybind11/numpy.h"

namespace py = pybind11;

py::array_t<double> make(const py::ssize_t size) {
    return py::array_t<double>(size);
}

PYBIND11_MODULE(one_array, m) {
    m.def("make", &make);
}
