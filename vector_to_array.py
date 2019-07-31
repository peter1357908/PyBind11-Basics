from vector_to_array import get_vector, add_arrays
import numpy as np

a = get_vector()

print(a)

b = np.arange(3)

print(b)

print(add_arrays(a,b))

del a