# Arbitrary Precision Calculator

## 📌 Description

Arbitrary Precision Calculator (APC) is a C-based project that performs arithmetic operations on very large numbers that cannot be handled by the normal integer data types such as int or long long.

The project represents large numbers using linked lists and performs arithmetic operations digit by digit.

---

## 🚀 Features

- Addition of very large numbers
- Subtraction of very large numbers
- Multiplication of very large numbers
- Division of very large numbers
- Supports numbers larger than the range of standard C data types
- Handles positive and negative numbers
- Uses dynamic memory allocation
- Performs operations without relying on built-in large integer data types

---

## 🛠️ Technologies Used

- C Programming
- Data Structures
- Doubly Linked List
- Pointers
- Dynamic Memory Allocation
- Command Line Arguments
- File/Modular Programming

---

## 📚 Data Structure Used

### Doubly Linked List

A *doubly linked list* is used to store the digits of large numbers.

Each node stores a digit and contains links to the previous and next nodes.

```text
NULL <- [1] <-> [2] <-> [6] <-> [5] <-> [5] -> NULL

For example:

12655

can be stored as:

1 <-> 2 <-> 6 <-> 5 <-> 5

This allows the program to process numbers digit by digit.


---

➕ Arithmetic Operations

The calculator supports:

Addition

123456789012345
+
987654321098765
----------------
1111111110111110

Subtraction

987654321
-
123456789
-----------
864197532

Multiplication

12345 × 678

Division

The project can divide large numbers and calculate the quotient and remainder.


---

⚙️ Compilation

Compile the project using:

gcc *.c


---

▶️ How to Run

The calculator accepts the operands and operator through command-line arguments.

Example:

./a.out 12655 + 852

Output:

13507

Another example:

./a.out 12655 - 852

Output:

11803


---

📂 Project Structure

APC/
│
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── apc.h
├── types.h
└── README.md

> File names may vary depending on the project skeleton.




---

💡 Concepts Learned

Doubly linked lists

Large number representation

Dynamic memory allocation

Pointers

Structures

Command-line arguments

Arithmetic algorithms

Carry and borrow handling

Quotient and remainder

Modular programming

Debugging



---

🎯 Project Objective

The main objective of this project is to implement arithmetic operations on numbers of arbitrary size using C programming and data structures.

Since standard C data types have limited ranges, the project uses a doubly linked list to store and process large numbers digit by digit.


---

👨‍💻 Author

Raj Chilshetty
