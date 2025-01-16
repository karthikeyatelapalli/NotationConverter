#include "NotationConverter.hpp"
#include "Deque.hpp"
#include "EmptyExcept.hpp"
#include "RuntimeExcept.hpp"
#include <iostream>
#include <string>

class NotationConverter : public NotationConverterInterface {
public:
    std::string postfixToInfix(std::string inStr) override {
        std::string infx = "";
        LinkedDeque<std::string> *dq = new LinkedDeque<std::string>;
        for (char c : inStr) {
            std::string temp = "";
            temp += c;
            if (isAlphabetic(c)) { // check if character is alphabetic
                dq->insertFront(temp);
            } else if (c == ' ') { // ignore spaces
                continue;
            } else { // remaining case: c is an operator
                std::string x1 = dq->front();
                dq->removeFront();
                std::string x2 = dq->front();
                dq->removeFront();
                dq->insertFront("(" + x2 + " " + temp + " " + x1 + ")");
            }
        }
        while (!dq->empty()) {
            infx += dq->front();
            dq->removeFront();
        }
        return infx;
    }

    std::string postfixToPrefix(std::string inStr) override {
        std::string infx = postfixToInfix(inStr);
        std::string pfx = infixToPrefix(infx);
        return pfx;
    }

    std::string infixToPostfix(std::string inStr) override {
        std::string pofx = "";
        LinkedDeque<std::string> *dq = new LinkedDeque<std::string>;
        LinkedDeque<std::string> *operator_dq = new LinkedDeque<std::string>;
        operator_dq->insertFront("(");
        inStr += " )"; // Add a closing parenthesis to handle all operators
        for (char c : inStr) {
            std::string temp = "";
            temp += c;
            if (isAlphabetic(c)) {
                dq->insertBack(temp);
            } else if (c == ' ') {
                continue;
            } else if (c == '(') {
                operator_dq->insertFront(temp);
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!operator_dq->empty() && precedence(operator_dq->front()[0]) >= precedence(c)) {
                    dq->insertBack(operator_dq->front());
                    operator_dq->removeFront();
                }
                operator_dq->insertFront(temp);
            } else if (c == ')') {
                while (operator_dq->front() != "(") {
                    dq->insertBack(operator_dq->front());
                    operator_dq->removeFront();
                }
                operator_dq->removeFront();
            }
        }
        while (!operator_dq->empty()) {
            if (operator_dq->front() != "(" && operator_dq->front() != ")") {
                dq->insertBack(operator_dq->front());
            }
            operator_dq->removeFront();
        }
        while (!dq->empty()) {
            pofx += dq->front() + ' ';
            dq->removeFront();
        }
        pofx.pop_back(); // Remove the last space
        return pofx;
    }

    std::string infixToPrefix(std::string inStr) override {
        reverseString(inStr);
        for (char &c : inStr) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }
        std::string postfix = infixToPostfix(inStr);
        reverseString(postfix);
        return postfix;
    }

    std::string prefixToInfix(std::string inStr) override {
        std::string pofx = prefixToPostfix(inStr);
        std::string ifx = postfixToInfix(pofx);
        return ifx;
    }

    std::string prefixToPostfix(std::string inStr) override {
        LinkedDeque<std::string> *dq = new LinkedDeque<std::string>;
        for (auto it = inStr.rbegin(); it != inStr.rend(); ++it) {
            char c = *it;
            std::string temp = "";
            temp += c;
            if (isAlphabetic(c)) {
                dq->insertFront(temp);
            } else if (c == ' ') {
                continue;
            } else {
                std::string x1 = dq->front();
                dq->removeFront();
                std::string x2 = dq->front();
                dq->removeFront();
                dq->insertFront(x1 + " " + x2 + " " + temp);
            }
        }
        std::string pofx = "";
        while (!dq->empty()) {
            pofx += dq->front() + ' ';
            dq->removeFront();
        }
        pofx.pop_back(); // Remove the last space
        return pofx;
    }

private:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    bool isAlphabetic(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    void reverseString(std::string &str) {
        int n = str.length();
        for (int i = 0; i < n / 2; i++) {
            std::swap(str[i], str[n - i - 1]);
        }
    }
};
