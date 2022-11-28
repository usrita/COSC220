// SomeOther.h header file
// Composition: Objects as Members of Classes
#ifndef SOMEOTHER_H
#define SOMEOTHER_H

class Some {
    private:
        int some;
    public:
        Some (int = 0);
        ~Some();
};
class Others {
    private:
        int other;
        Some Assoc; // an object is a member of a class
    public:
        Others (int, int);
        ~Others ();
};
#endif