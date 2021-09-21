#include <iostream>
#include <string>
#include <vector>

#ifndef HIGHLANDER3_H
#define HIGHLANDER3_H

using namespace std;

class Highlander3{
    private:
        string firstName;
        string lastName;
        string mentor;
        string major;
        string email;
        string cohort;
        float currrGPA;
        float cumGPA;
    public:
        Highlander3(string first, string last, string their_email, string their_major,//
        string their_mentor, float currentGPA, float cumulativeGPA){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->major = their_major;
            this->mentor = their_mentor;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
        }

        Highlander3(string first, string last, string their_email, string their_major,//
        string their_mentor, float currentGPA, float cumulativeGPA, string their_cohort){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->major = their_major;
            this->mentor = their_mentor;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
            this->cohort = their_cohort;
        }

        //Constructor based on major Fall
        Highlander3(string first, string last, string their_email,//
        float currentGPA, float cumulativeGPA){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
        }

        //Constructor based on major Winter
        Highlander3(string first, string last, string their_email,//
        float currentGPA){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->currrGPA = currentGPA;
        }

        //Constructor based on major AP
        Highlander3(string first, string last, string their_email,//
        float currentGPA, float cumulativeGPA, string their_cohort){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
            this->cohort = their_cohort;
        }   

        //Constructor based on Mentee
        Highlander3(string first, string last, string their_email, string their_major,//
        float currentGPA, float cumulativeGPA){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->major = their_major;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
        }

        //Constructor based on Mentor Winter
        Highlander3(string first, string last, string their_email, string their_major,//
        float currentGPA){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->major = their_major;
            this->currrGPA = currentGPA;
        }


        //Constructor for nonTTP_AP
        Highlander3(string first, string last, string their_email, string their_major,//
        float currentGPA, float cumulativeGPA, string their_cohort){
            this->firstName = first;
            this->lastName = last;
            this->email = their_email;
            this->major = their_major;
            this->currrGPA = currentGPA;
            this->cumGPA = cumulativeGPA;
            this->cohort = their_cohort;
        }

        //Constructor to store mentor/menee information
        Highlander3(string first, string last){
            this->firstName = first;
            this->lastName = last;
        }

        //Accessor functions
        string getFirstName(){
            return firstName;
        }

        string getEmail(){
            return email;
        }

        string getlastName(){
            return lastName;
        }
    
        string getMentor(){
            return mentor;
        }

        string getMajor(){
            return major;
        }
    
        string getCohort(){
            return cohort;
        }

        // float getFall2020GPA(float cumulativeGPA, float currentGPA){
        //     return (2*cumulativeGPA - currentGPA);
        // }

        float getcurrGPA(){
            return currrGPA;
        }

        float getcumGPA(){
            return cumGPA;
        }

        void setFirstNmae(string firstName){
            this->firstName = firstName;
        }

        void setlastName(string lastName){
            this->lastName = lastName;
        }

        void setMenor(string mentor){
            this->mentor = mentor;
        }

        void setMajor(string major){
            this->major = major;
        }

        void setCohort(string cohort){
            this->cohort = cohort;
        }

        void setcurrGPA(float currrGPA){
            this->currrGPA = currrGPA;
        }

        void setcumGPA(float cumGPA){
            this->cumGPA = cumGPA;
        }
};

#endif