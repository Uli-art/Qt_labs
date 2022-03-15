// Task_5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value) : value(value) {}
    ~Number() {};
    double evaluate() { return value; }
    virtual double evaluate() const { return value; }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        if (op == '+') {
            return (left->evaluate() + right->evaluate());
        }
        else if (op == '-') {
            return (left->evaluate() - right->evaluate());
        }
        else if (op == '*') {
            return (left->evaluate() * right->evaluate());
        }
        else if (op == '/') {
            return (left->evaluate() / right->evaluate());
        }
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};

bool check_equals(Expression const* left, Expression const* right)
{
    return (*((size_t*)left) == *((size_t*)right));
}

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    Expression* thi = new Number(4);
    std::cout << expr->evaluate() << std::endl << check_equals(thi, expr);
        ;
}

