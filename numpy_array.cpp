#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

PYBIND11_MODULE(numpy_array, m) {
    m.def("f", []() {
        // Allocate and initialize some data; make this big so
        // we can see the impact on the process memory use:
        constexpr size_t size = 10*10*10;
        double *foo = new double[size];
        for (size_t i = 0; i < size; i++) {
            foo[i] = (double) i;
        }

        // Create a Python object that will free the allocated
        // memory when destroyed:
        py::capsule free_when_done(foo, [](void *f) {
            double *foo = reinterpret_cast<double *>(f);
            std::cerr << "Element [0] = " << foo[0] << "\n";
            std::cerr << "freeing memory @ " << f << "\n";
            delete[] foo;
        });

        return py::array_t<double>(
            {10, 10, 10}, // shape
            foo, // the data pointer
            free_when_done); // numpy array references this parent
    });
}