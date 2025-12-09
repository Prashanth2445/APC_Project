#🧮 Arbitrary Precision Calculator (APC)#

An Arbitrary Precision Calculator implemented in C, capable of performing arithmetic on numbers far beyond the limits of standard integer data types.
This project was developed as part of my Embedded Systems training at Emertxe Information Technologies.

🚀 Features

✔ Handles numbers of any size using Doubly Linked Lists
✔ Supports the following operations:

Addition

Subtraction

Multiplication

Division

Modulus

Power

✔ Implements digit-wise arithmetic (similar to manual calculations)
✔ Handles carry, borrow, sign management, and input validation
✔ Works without relying on long long int / BigInt libraries
✔ Structured, modular, memory-safe C implementation

🛠 Data Structure Used

The calculator represents each number as a Doubly Linked List (DLL), where each node stores a single digit.

Example

12345 → 1 <-> 2 <-> 3 <-> 4 <-> 5


Benefits:

Efficient traversal from both ends

Easy implementation of carry/borrow logic

Supports arbitrary-length numbers

📁 Project Structure
APC_Project/
│── include/
│     └── head.h
│── src/
│     ├── addition.c
│     ├── subtraction.c
│     ├── multiplication.c
│     ├── division.c
│     ├── utility.c
│── main.c
│── README.md
│── Makefile (optional)

📌 How It Works

The program reads the operator and operands from the command line.

Each number is converted into a linked list (digit by digit).

The required arithmetic function is executed.

The result is printed from the final linked list.

▶️ Example Usage
Command
./a.out 12345678901234567890 + 98765432109876543210

Output
111111111011111111100

🧠 Learning Outcomes

This project helped me understand:

Big integer representation

Manual arithmetic algorithm design

Dynamic memory management in C

Pointers, structures, and linked lists

Error handling and modular programming

Complexity analysis of arithmetic operations

🏫 Acknowledgements

Special thanks to my mentors and instructors at Emertxe Information Technologies for their continuous support and guidance during this project.

🔗 Repository Link

(Replace with your actual repo link)
👉 [https://github.com/Prashanth2445/APC_Project/new/main?filename=README.md]

📜 License

This project is open-source and available under the MIT License.
