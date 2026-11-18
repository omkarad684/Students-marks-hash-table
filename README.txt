# Question 2 – Student Marks Hashing Project

**PRN:** 202501100155  
**Scenario:** Student Marks (PRN mod 3 = 1)  
**Dataset size:** 20 values  
**Hash table size:** 29  
**Hash function:** Mid-square  
**Collision handling:** Separate chaining

## 1. Dataset generation

Use:

`v[i] = (S + 13*i) % 100`, where `S = 155` and `i = 0...19`.

Dataset:

`55, 68, 81, 94, 7, 20, 33, 46, 59, 72, 85, 98, 11, 24, 37, 50, 63, 76, 89, 2`

## 2. Hash function

For each key:
1. Calculate `key * key`.
2. Pad the result with leading zeroes until it has at least four digits.
3. Extract the middle two digits.
4. Calculate `middle_two_digits % 29`.

Example: key 55 -> square 3025 -> middle digits 02 -> index 2.

## 3. Compile and run

With g++:

```bash
g++ -std=c++17 -Wall -Wextra -o question2 main.cpp
./question2
```

On Windows:

```bash
g++ -std=c++17 -Wall -Wextra -o question2.exe main.cpp
question2.exe
```

## 4. Expected final hash table

See `expected_output.txt`. Run the program yourself and compare its output.

## 5. Submission reminders

- Add your own name, class, and other required details if your instructor asks for them.
- Capture your actual program output.
- Complete the debugging log with issues you genuinely encountered.
- Make at least six genuine Git commits as you develop the project; do not fabricate commit history.
- Record the required screen demonstration yourself.
- Confirm whether your assignment specifies a different table-size rule. This project uses size 29, carried over from the personalized Q1 setup.
