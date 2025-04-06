#ifndef _STACK_
#define _STACK_

// Abstract Data Type para estruturas de Pilha (Last-In Fisrt-Out)
template <typename E>
class Stack {
    private:
        void operator =(const Stack&) {}
        Stack(const Stack&) {}
    public:
        Stack() {}
        virtual ~Stack() {}
        
        virtual void clear() = 0;

        virtual void push(const E& item) = 0;
        virtual void pop() = 0;
        virtual const E& topValue() const = 0;
        virtual int length() const = 0;
};

#endif