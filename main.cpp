//I affirm that all code given below was written solely by me, Steven Anderson, and that any help I received adhered to the rules stated for this exam.
#include <iostream>
#include <fstream>
#include <vector>
#include "Runner.h"

void colorfiles(vector<Runner> runner, string color, string upper, int &i);

using namespace std;
int main(){
    //making variables and vector
    vector <Runner> runner;
    string line;
    int i=0;
    int runners=0;
    
    //read in line from file
    fstream fin("registrants.txt", ios::in);
    if (!fin)
    {cout << "File not found" << endl;
    }
    else{
        
    while (getline(fin,line))
    {//chars and strings get reset every loop
        string first, last;
        char firstchar[10];
        char lastchar[15];
        char newpace[8];
        string pace;
        
                //puts the first word into first name
                for (i=0; line[i]!=' '; i++){
                    firstchar[i]=line[i];
                    first+=firstchar[i];
                }
                i++;//skippping blank space
        
                // puts the second word into last name
                for (int j=0; line[i]!=' '; j++){
                   lastchar[j]=line[i];
                    last+=lastchar[j];
                    i++;}
                
                i++;//skippping blank space
        
        
                //couldnt figure out how to put the
                //puts the last part into pace
                for (int j=0; line[i]!='\r'; j++){
                    newpace[j]=line[i];
                    pace+=newpace[j];
                    i++;}
                //lastly in the loop, assigns values into one runner object
                Runner r(first, last, pace);
                // adds newly made object to runner array
                runner.push_back(r);
        runners++;
        }
       
        }
    //sorting array by speed
    for (int i=0; i<runners;i++) {
        for (int i=0; i<runners;i++)
        {
        //swapping the cells if not in ascending order
            {           //checking for blank spot (thousands place) 1000 vs 500
                if (runner[i].get_pace()[3]!='\0' && runner[i+1].get_pace()[3]=='\0')
                    {
                        Runner temprunner = runner[i];
                        runner[i]=runner[i+1];
                        runner[i+1]=temprunner;
                    }  //checking for blank spot (thousands place) 1000 vs 1100
                else if (runner[i].get_pace()[3]!='\0' && runner[i+1].get_pace()[3]!='\0'&& runner[i].get_pace()>runner[i+1].get_pace())
                {
                    Runner temprunner = runner[i];
                    runner[i]=runner[i+1];
                    runner[i+1]=temprunner;
                }//         200 vs 500
                else if (runner[i].get_pace()>runner[i+1].get_pace() && runner[i+1].get_pace()!="")
                {  Runner temprunner = runner[i];
                    runner[i]=runner[i+1];
                    runner[i+1]=temprunner;
                }
                
                
            }
        }
    }
    
    fin.close();//closing original runners file
    
     i=0;
    //function calling for placing runners in specific files
    colorfiles(runner, "white", "360",i);
    colorfiles(runner, "yello", "420",i);
    colorfiles(runner, "green", "480",i);
    colorfiles(runner, "orange", "540",i);
    colorfiles(runner, "blue", "600",i);
    colorfiles(runner, "lilac", "720",i);
    colorfiles(runner, "red", "1200",i);
    
   
  
    
    //test program - displays a few runners in 3 files
    fstream white("white.txt", ios::in);
    if (!white)
    {cout << "File not found" << endl;
    }
    else {
        string first;
        getline(white,  first);
        cout << "The first runner in 'white.txt' is: " << first << endl;
        string second;
        getline(white,  second);
        cout << "The second runner in 'white.txt' is: " << second << endl;
    }
    white.close();
    
    fstream green("green.txt", ios::in);
    if (!green)
    {cout << "File not found" << endl;
    }
    else {
        string first;
        getline(green,  first);
        cout << "The first runner in 'green.txt' is: " << first << endl;
    }
    green.close();
    
    fstream red("red.txt", ios::in);
    if (!red)
    {cout << "File not found" << endl;
    }
    else {
        string first;
        getline(red,  first);
        cout << "The first runner in 'red.txt' is: " << first << endl;
    }
    red.close();
    
    
    
    
    
    return 0;
    
}
//function for placing the runners in their individual files

void colorfiles(vector<Runner> runner,string color, string upper, int &i){
    
    {//connecting to file
        fstream iofile(color+".txt", ios::in|ios::out);
        //if file isnt found, makes one
        if (!iofile)
        {//makes name of file with specified color
            iofile.open(color+".txt", ios::out);
            //checks to see if the runner meets criteria then outputs him to file
             
            //if statement because sorting gets weird for 700<1000 (for strings)
            if (color=="red"){
                    iofile << runner[i].toString()<< endl;
            }
            
            else
            {
                for (;runner[i].get_pace()<=upper;i++)
                iofile << runner[i].toString()<< endl;
            }
        }
        else
        {            //checks to see if the runner meets criteria then outputs him to file
            
            //if statement because sorting gets weird for 700<1000 (for strings)
            if (color=="red"){
                    iofile << runner[i].toString()<< endl;
            }
            
            else
            {
                for (;runner[i].get_pace()<=upper;i++)
                iofile << runner[i].toString()<< endl;
            }
            
        }
        iofile.close();

    }
    
}