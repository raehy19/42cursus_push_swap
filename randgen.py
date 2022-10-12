import numpy as np

numbers = np.random.choice(range(1, 555555), 500, replace=False)

for n in numbers:
    print(n),
