#ifndef _QUEUE_
#define _QUEUE_

template <typename E>
class Queue {
    private:
        void operator =(const Queue&) {}
        Queue(const Queue&) {}
    public:
        Queue() {}
        virtual ~Queue() {}
        virtual void clear() = 0;

        virtual void enqueue(const E& item) = 0;
        virtual void dequeue() = 0;
        virtual const E& frontValue() const = 0;
        virtual int length() const = 0;
};

#endif