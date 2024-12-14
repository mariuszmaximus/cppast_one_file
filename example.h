#pragma once

class MyClass {
public:
    void doSomething();
};

class AnotherClass {
private:
    int value;
public:
    AnotherClass(int val) : value(val) {}
    void printValue() const;
};


class Excample1
{
public:
    virtual int test1(int par1) = 0;
};


class Excample2
{
public:
    virtual int test2(int par1) = 0;

};

