# Notation Converter

This C++ program implements a powerful notation converter that supports converting mathematical expressions between infix, prefix, and postfix notations. It uses deque-based data structures to efficiently parse and manipulate expressions.

---

## **Features**
1. **Supported Conversions**:
   - **Infix to Prefix**: Converts infix expressions to prefix notation.
   - **Infix to Postfix**: Converts infix expressions to postfix notation.
   - **Prefix to Infix**: Converts prefix expressions to infix notation.
   - **Prefix to Postfix**: Converts prefix expressions to postfix notation.
   - **Postfix to Infix**: Converts postfix expressions to infix notation.
   - **Postfix to Prefix**: Converts postfix expressions to prefix notation.

2. **Dynamic Parsing**:
   - Handles complex expressions with proper operator precedence and parenthesis grouping.

3. **Comprehensive Tests**:
   - Validates the correctness of all conversions using a suite of test cases in `converterDriver.cpp`.

---

## **How to Build and Run**

### **Requirements**
- C++ Compiler (e.g., `g++`).
- All files in the same directory:
  - `NotationConverter.cpp`
  - `NotationConverter.hpp`
  - `Deque.hpp`
  - `DLinkedList.hpp`
  - `DNode.hpp`
  - `EmptyExcept.hpp`
  - `RuntimeExcept.hpp`
  - `converterDriver.cpp`

### **Build Instructions**
1. Compile the program:
   ```bash
   g++ converterDriver.cpp NotationConverter.cpp -o notation_converter
