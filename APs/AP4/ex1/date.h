#ifndef _DATE_
#define _DATE_

class Date {
    private:
        short month, day, year;
    
    public:
        void init(void);
        void init(int month, int day, int year);
        void print(void);
};

#endif