
#include "Runner.h"
//get first name
string Runner::get_firstname(){
    return firstname;
}
//get last name
string Runner::get_lastname(){
    return lastname;
}
//get pace
string Runner::get_pace(){
    return pace;
}
//setting first name
void Runner::set_firstname(string first){
    firstname=first;
}
//setting last name
void Runner::set_lastname(string last){
    lastname=last;
}
//setting pace
void Runner::set_pace(string pac){
    pace=pac;
}
//takes Runner class and turns it to string 
string Runner::toString(){
    string newstr;
    newstr+=get_firstname();
    newstr+=" " + get_lastname();
    newstr+=" "+pace;
    return newstr;
    
}