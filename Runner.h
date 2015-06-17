#ifndef __Exam_2__Runner__
#define __Exam_2__Runner__
#include <iostream>
using namespace std;
//create Runner class
class Runner {
private:
    //private variables of first, last, and pace
    string firstname;
    string lastname;
    string pace;
    
public:
    //two constructors
    Runner(){
        firstname="Steven";
        lastname="Anderson";
        pace=100;}
    Runner(string first, string last, string pac){
        firstname=first;
        lastname=last;
        pace=pac;}
    //get functions
    string get_firstname();
    string get_lastname();
    string get_pace();
    //set functions (not needed in this case)
    void set_firstname(string first);
    void set_lastname(string last);
    void set_pace(string pac);
    //turns class to string
    string toString();
    
    
    
    
    
    
};
#endif
