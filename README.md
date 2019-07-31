`make` with each of the following to build a import-able Python module (the `*array` ones also runs the Python test file)

`sum`: the most basic add-two-numbers function

`oarray`: create an uninitialized numpy array of certain size

`narray`: create a C++ array and let Python use it as a numpy array, without copying

`varray`: create a C++ vector and let Python use it as a numpy array, and then make a C++ function that adds two same-size numpy arrays together, without copying