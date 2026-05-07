# CODINGASSIGNMENT-5
## How To Run

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic CodingAssignment5.cpp -o coding5
```

Run the program:

```bash
./coding5
```

The assignment asks for `k` to be defined directly in the program. To test another value, change `int k = 5;` in `main`.

## Sample Output

For `k = 5`, the program produces:

```txt
Total Strings = 243
No Consecutive Same = 48
Probability = 0.1975
Strings with "CC" = 79
```

## Brief Note

The total number of strings is counted as `3^k` because each position can be `A`, `B`, or `C`. For the no-consecutive-same count, the first character has 3 choices and each later character has 2 choices because it cannot match the previous character. The probability is computed by dividing the no-consecutive-same count by the total number of strings. For strings containing `"CC"`, I used complement counting by first counting strings with no `"CC"` using dynamic programming, then subtracting that value from the total.
