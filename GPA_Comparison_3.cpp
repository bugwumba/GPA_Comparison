#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include "highlander3.h"
#include <string>

using namespace std;

//Function to get Mentor Information With Multiple Majors Winter
inline void Output_CSV_File_Winter(string fileName, string mentorName, vector<Highlander3> mentorVector_Winter, vector<Highlander3> TTP_AP_vector ){
        ofstream outFS;
        outFS.open(fileName);

    if(!outFS.is_open()){
        std::cout << "Could not open file\n";
    }
    else{
         outFS << "First Name" << "," << "Last Name" << "," << "Email" << "," << "Major" << "," << "Spring 2021" << "," << "Cumulative" << endl;
        for(unsigned int c = 0; c < mentorVector_Winter.size(); c++){    
            outFS << mentorVector_Winter.at(c).getFirstName() << "," << mentorVector_Winter.at(c).getlastName() << "," << mentorVector_Winter.at(c).getEmail()//
            << "," << mentorVector_Winter.at(c).getMajor() << "," << mentorVector_Winter.at(c).getcurrGPA() << "," << mentorVector_Winter.at(c).getcumGPA() << endl;
        }
        for(unsigned int d = 0; d < TTP_AP_vector.size(); d++){
            if(TTP_AP_vector.at(d).getMentor() == mentorName && TTP_AP_vector.at(d).getCohort() == "21W"){
                outFS << TTP_AP_vector.at(d).getFirstName() << "," << TTP_AP_vector.at(d).getlastName() << "," << TTP_AP_vector.at(d).getEmail()//
                << "," << TTP_AP_vector.at(d).getMajor() << "," << TTP_AP_vector.at(d).getcurrGPA() << "," << TTP_AP_vector.at(d).getcumGPA() <<endl;
            }
        }
    }

    outFS.close();
}

//Function to print mentor/mentee information for Fall with multiple majors
inline void Output_CSV_File_Fall(string fileName, string mentorName, vector<Highlander3> mentorVector_Fall, vector<Highlander3> TTP_AP){
    ofstream outFS;
    outFS.open(fileName);

    if(!outFS.is_open()){
        std::cout << "Could not open file\n";
    }
    else{
         outFS << "First Name" << "," << "Last Name" << "," << "Email" << "," << "Major" << ","//
         << "Spring 2021 GPA" << "," << "Cumulative GPA" << endl;
         for(unsigned int c = 0; c < mentorVector_Fall.size(); c++){    
             outFS << mentorVector_Fall.at(c).getFirstName() << "," << mentorVector_Fall.at(c).getlastName() << "," << mentorVector_Fall.at(c).getEmail()//
              << "," << mentorVector_Fall.at(c).getMajor() << "," //
              << mentorVector_Fall.at(c).getcurrGPA() << "," << mentorVector_Fall.at(c).getcumGPA() << endl;
         }
         for(unsigned int d = 0; d < TTP_AP.size(); d++){
             if(TTP_AP.at(d).getMentor() == mentorName && TTP_AP.at(d).getCohort() == "20F"){
                 outFS << TTP_AP.at(d).getFirstName() << "," << TTP_AP.at(d).getlastName() << "," << TTP_AP.at(d).getEmail()//
                 << "," << TTP_AP.at(d).getMajor() << ","//
                 << TTP_AP.at(d).getcurrGPA() << "," << TTP_AP.at(d).getcumGPA() << endl;
             }
         }
    }

    outFS.close();
}

inline void Output_By_Major_Fall(string fileName, vector<Highlander3> Non_TTP_major, vector<Highlander3> Non_TTP_AP, string cohort){
    ofstream outFS;
    outFS.open(fileName);

    if(!outFS.is_open()){
        std::cout << "Could not open file\n";
    }
    else{
         outFS << "First Name" << "," << "Last Name" << ","//
         << "Spring 2021 GPA" << "," << "Cumulative GPA" << endl;
         for(unsigned int c = 0; c < Non_TTP_major.size(); c++){    
             outFS << Non_TTP_major.at(c).getFirstName() << "," << Non_TTP_major.at(c).getlastName() << ","//
              << Non_TTP_major.at(c).getcurrGPA() << "," << Non_TTP_major.at(c).getcumGPA() << endl;
         }
         for(unsigned int d = 0; d < Non_TTP_AP.size(); d++){
             if(Non_TTP_AP.at(d).getCohort() == cohort){
                outFS << Non_TTP_AP.at(d).getFirstName() << "," << Non_TTP_AP.at(d).getlastName() <<//
                "," << Non_TTP_AP.at(d).getcurrGPA() << "," << Non_TTP_AP.at(d).getcumGPA() << endl;
             }
         }
    }

    outFS.close();
}

int main(){
    //Good
    //Import .csv file that contains list of mentor names and mentee emails
    //Group mentees with the mentors in vectors
    //Vectors contain email address of mentees
    string Mentee_MentorList = "2020_2021_Transfer_Transition_Program _MASTER_LIST.csv";
    string mentorName = "";
    string menteeFirst, menteeLast = "";

    int ttpCount = 0;
    vector<Highlander3> Sarahs_Mentees;
    vector<Highlander3> Buddys_Mentees;    
    vector<Highlander3> Beas_Mentees;
    vector<Highlander3> Arthors_Mentees;       
    vector<Highlander3> James_Mentees;
    ifstream fin;
    fin.open(Mentee_MentorList);
    if(!fin.is_open()){
        std::cout << "Could not open " << Mentee_MentorList << endl;
    }
    else{
        string line = "";
        while(getline(fin,line)){
            istringstream ssin(line);
            getline(ssin, mentorName, ',');
            getline(ssin, menteeFirst, ',');
            getline(ssin, menteeLast, ',');
            if(mentorName == "Sarah"){
                Sarahs_Mentees.push_back(Highlander3(menteeFirst, menteeLast));
            }
            if(mentorName == "Buddy"){
                Buddys_Mentees.push_back(Highlander3(menteeFirst, menteeLast));
            } 
            if(mentorName == "Bea"){
                Beas_Mentees.push_back(Highlander3(menteeFirst, menteeLast));
            }
            if(mentorName == "Arthor"){
                Arthors_Mentees.push_back(Highlander3(menteeFirst, menteeLast));
            } 
            if(mentorName == "James"){
                James_Mentees.push_back(Highlander3(menteeFirst, menteeLast));
            }  
        }
        fin.close();
    }

    //This portion checks the above code
    //Check that the the combined size of the vectors is equal to the number of trasnfer students in TTP - 101
    ttpCount = Sarahs_Mentees.size() + Buddys_Mentees.size() + Beas_Mentees.size() + Arthors_Mentees.size() + James_Mentees.size();
    std::cout << endl << "The number of transfer students in TTP with mentors is: " << ttpCount << endl;

    //Import Spring GPA .csv file and sift through
    //Separate TTP from non-TTP transfers 

    //.csv Files to be iterrated through 
    string GPA_file = "Spring 21 Transfer GPA.csv";

    //Vectors that will storre total GPAs 
    vector<Highlander3> nonTTP_F;
    vector<Highlander3> TTP_AP;
    vector<Highlander3> nonTTP_AP;  
    //Vectors to hold GPA's for each cohort for each mentor
    vector<Highlander3> Sarah_F;
    vector<Highlander3> Buddy_F;
    vector<Highlander3> Bea_F;
    vector<Highlander3> Arthor_F;       
    vector<Highlander3> James_F;
    vector<Highlander3> Sarah_W;
    vector<Highlander3> Buddy_W;
    vector<Highlander3> Bea_W;
    vector<Highlander3> Arthor_W;       
    vector<Highlander3> James_W;
    //Variables to store data
    string firstName, lastName, email, major, cohort, mentor = ""; 
    string currGPA, cumGPA = "";
    float currentGPA, cumulativeGPA;

    //Vectors to contain GPA's by major for TTP
    vector<Highlander3> ENCS_F, ENCS_W, ENCS_AP;
    vector<Highlander3> CHEN_F, CHEN_W, CHEN_AP;
    vector<Highlander3> BIEN_F, BIEN_W, BIEN_AP;
    vector<Highlander3> MCEN_F, MCEN_W, MCEN_AP;
    vector<Highlander3> CEN_F, CEN_W, CEN_AP;
    vector<Highlander3> CSBA_F, CSBA_W, CSBA_AP;
    vector<Highlander3> ELEN_F, ELEN_W, ELEN_AP;
    vector<Highlander3> MSE_F, MSE_W, MSE_AP;
    vector<Highlander3> ENEN_F, ENEN_W, ENEN_AP;

    //Vectors to contain GPA's by major for Non-TTP
    vector<Highlander3> NonTTP_ENCS_F, NonTTP_ENCS_AP;
    vector<Highlander3> NonTTP_CHEN_F, NonTTP_CHEN_AP;
    vector<Highlander3> NonTTP_BIEN_F, NonTTP_BIEN_AP;
    vector<Highlander3> NonTTP_MCEN_F, NonTTP_MCEN_AP;
    vector<Highlander3> NonTTP_CEN_F,  NonTTP_CEN_AP;
    vector<Highlander3> NonTTP_CSBA_F, NonTTP_CSBA_AP;
    vector<Highlander3> NonTTP_ELEN_F, NonTTP_ELEN_AP;
    vector<Highlander3> NonTTP_MSE_F,  NonTTP_MSE_AP;
    vector<Highlander3> NonTTP_ENEN_F, NonTTP_ENEN_AP;
    
    //Open Spring 21 GPA file and store in vector 
    fin.open(GPA_file);
    if(!fin.is_open()){
        std::cout << "Could not open " << GPA_file << endl;
    }
    else{
        string line = "";
        while(getline(fin, line)){
            istringstream ssin(line);
            getline(ssin, firstName, ',');
            getline(ssin, lastName, ',');
            getline(ssin, email, ',');
            getline(ssin, major, ',');
            getline(ssin, currGPA, ',');
            getline(ssin, cumGPA, ',');
            getline(ssin, cohort, ',');
            std::string::size_type sz;
            currentGPA = stof(currGPA, &sz);
            cumulativeGPA = stof(cumGPA, &sz);
            //Iterate through vectors containing email address of mentees to match them 
            mentor = "";
            for(unsigned int o = 0; o < 1; o++){
                //Good
                for(unsigned int i = 0; i < Sarahs_Mentees.size(); i ++){
                    //Everything works as it should
                    //Good
                    if(Sarahs_Mentees.at(i).getFirstName() == firstName && Sarahs_Mentees.at(i).getlastName() == lastName){
                        mentor = "Sarah";
                        if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Sarah_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "CHEN"){
                                CHEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "BIEN"){
                                BIEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "ENEN"){
                                ENEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "CEN"){
                                CEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                        }
                        //Good
                        if(cohort == "21W" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Sarah_W.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "CHEN"){
                                CHEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "BIEN"){
                                BIEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "ENEN"){
                                ENEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "CEN"){
                                CEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }                     
                        }
                        //Good
                        if(currentGPA < 2 || cumulativeGPA < 2){
                            TTP_AP.push_back(Highlander3(firstName, lastName, email, major, mentor, currentGPA, cumulativeGPA, cohort));
                            if(major == "BIEN"){
                                BIEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "CHEN"){
                                CHEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "ENEN"){
                                ENEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "CEN"){
                                CEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                        }
                        break;
                    }
                }
                if(mentor != ""){
                    break;
                }
                //Everything works as it should
                for(unsigned int j = 0; j < Buddys_Mentees.size(); j++){
                    //Good
                    if(Buddys_Mentees.at(j).getFirstName() == firstName && Buddys_Mentees.at(j).getlastName() == lastName){
                        mentor = "Buddy";
                        //Good
                        if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Buddy_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "CEN"){
                                CEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "ELEN"){
                                ELEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "CSBA"){
                                CSBA_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                        }
                        //Good
                        if(cohort == "21W" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Buddy_W.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));    
                            if(major == "CEN"){
                                CEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "ELEN"){
                                ELEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "CSBA"){
                                CSBA_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }                    
                        }
                        //Good
                        if(currentGPA < 2 || cumulativeGPA < 2){
                            TTP_AP.push_back(Highlander3(firstName, lastName, email, major, mentor, currentGPA, cumulativeGPA, cohort));
                            if(major == "CEN"){
                                CEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "ELEN"){
                                ELEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "CSBA"){
                                CSBA_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                        }
                        break;
                    }
                }
                if(mentor != ""){
                    break;
                }
                //Everything here works as it should
                for(unsigned int k = 0; k < Beas_Mentees.size(); k++){
                    //Good
                    if(Beas_Mentees.at(k).getFirstName() == firstName && Beas_Mentees.at(k).getlastName() == lastName){
                        mentor = "Bea";
                        //Good
                        if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Bea_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "ENCS"){
                                ENCS_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                        }
                        //Good
                        if(cohort == "21W" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Bea_W.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "ENCS"){
                                ENCS_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }                        
                        }
                        //Good
                        if(currentGPA < 2 || cumulativeGPA < 2){
                            TTP_AP.push_back(Highlander3(firstName, lastName, email, major, mentor, currentGPA, cumulativeGPA, cohort));
                            if(major == "ENCS"){
                                ENCS_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                        }
                        break;
                    }
                }
                if(mentor != ""){
                    break;
                }
                //Everything here works as it shoould!
                for(unsigned int m = 0; m < Arthors_Mentees.size(); m++){
                    if(Arthors_Mentees.at(m).getFirstName() == firstName && Arthors_Mentees.at(m).getlastName() == lastName){
                        mentor = "Arthor";
                        if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Arthor_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "MCEN"){
                                MCEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                        }
                        if(cohort == "21W" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            Arthor_W.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "MCEN"){
                                MCEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }                        
                        }
                        if(currentGPA < 2 || cumulativeGPA < 2){
                            TTP_AP.push_back(Highlander3(firstName, lastName, email, major, mentor, currentGPA, cumulativeGPA, cohort));
                            if(major == "MCEN"){
                                MCEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                        }
                        break;
                    }
                }
                if(mentor != ""){
                    break;
                }
                //Everythiing Here is good
                for(unsigned int n = 0; n < James_Mentees.size(); n++){
                    if(James_Mentees.at(n).getFirstName() == firstName && James_Mentees.at(n).getlastName() == lastName){
                        mentor = "James";
                        if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            James_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "MCEN"){
                                MCEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                            if(major == "MSE"){
                                MSE_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                            }
                        }
                        if(cohort == "21W" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                            James_W.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                            if(major == "MCEN"){
                                MCEN_W.push_back(Highlander3(firstName, lastName, email, currentGPA));
                            }
                            if(major == "MSE"){
                                MSE_W.push_back(Highlander3(firstName, lastName, email, currentGPA));
                            }                        
                        }
                        if(currentGPA < 2 || cumulativeGPA < 2){
                            TTP_AP.push_back(Highlander3(firstName, lastName, email, major, mentor, currentGPA, cumulativeGPA, cohort));
                            if(major == "MCEN"){
                                MCEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                            if(major == "MSE"){
                                MSE_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                            }
                        }
                        break;
                    }
                }
            }
            //The value here should be 200, however i am not picking up three students for some reason
            //Populate NonTTP vector
            if(mentor == ""){
                if(cohort == "20F" && (currentGPA >= 2 && cumulativeGPA >= 2)){
                    nonTTP_F.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA));
                    if(major == "ENCS"){
                        NonTTP_ENCS_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "BIEN"){
                        NonTTP_BIEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "CEN"){
                        NonTTP_CEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "CSBA"){
                        NonTTP_CSBA_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "ELEN"){
                        NonTTP_ELEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "ENEN"){
                        NonTTP_ENEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "MSE"){
                        NonTTP_MSE_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "CHEN"){
                        NonTTP_CHEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                    if(major == "MCEN"){
                        NonTTP_MCEN_F.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA));
                    }
                }
                if(cumulativeGPA < 2 || currentGPA < 2){
                    nonTTP_AP.push_back(Highlander3(firstName, lastName, email, major, currentGPA, cumulativeGPA, cohort));
                    if(major == "ENCS"){
                        NonTTP_ENCS_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "BIEN"){
                        NonTTP_BIEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "CEN"){
                        NonTTP_CEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "CSBA"){
                        NonTTP_CSBA_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "ELEN"){
                        NonTTP_ELEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "ENEN"){
                        NonTTP_ENEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "MSE"){
                        NonTTP_MSE_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "CHEN"){
                        NonTTP_CHEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                    if(major == "MCEN"){
                        NonTTP_MCEN_AP.push_back(Highlander3(firstName, lastName, email, currentGPA, cumulativeGPA, cohort));
                    }
                }
            }

        }
        fin.close();
    }

    //Everything above works correctly
    //This portion of the code is meant to test the code above 
    int TTPcount2 = Sarah_F.size() + Sarah_W.size() + Buddy_F.size() + Buddy_W.size()+ Bea_F.size() + Bea_W.size()+//
                    Arthor_F.size() + Arthor_W.size() + James_F.size() + James_W.size();
    int TTP_APcount = TTP_AP.size();                    
    int nonTTPcount = nonTTP_F.size();
    int nonTTP_APcount = nonTTP_AP.size();
    //The outcome should be or be close to the differrence between those in TTP and the whole list which is 279
    std::cout << "The number of TTP members not on AP is: " << TTPcount2 << endl;
    std::cout << "The number of TTP members on AP is: " << TTP_APcount << endl;
    std::cout << "The number of transfers not in TTP not on AP is: " << nonTTPcount << endl;
    std::cout << "The number of transfers not in TTP on AP is: " << nonTTP_APcount << endl;

    //So far everything here is good except that the by major portion of the code is not catching on TTP member
    //I have to track down that mentor and figure out why
    //This portion of the code checks to the breakdown by major portion of the code
    //If this is correct I should have the same values for the the sums by major as I did by mentor
    int byMajorTTPCount = ENCS_F.size() + ENCS_W.size()+//
    CHEN_F.size() + CHEN_W.size() + BIEN_F.size() + BIEN_W.size() +//
    MCEN_F.size() + MCEN_W.size() + CEN_F.size() + CEN_W.size() +//
    CSBA_F.size() + CSBA_W.size() + ELEN_F.size() + ELEN_W.size()+//
    MSE_F.size() + MSE_W.size() + ENEN_F.size() + ENEN_W.size();

    int byMajorAPCount = ENCS_AP.size() + CHEN_AP.size() + BIEN_AP.size()+//
    MCEN_AP.size() + CEN_AP.size() + CSBA_AP.size() + ELEN_AP.size() +//
    MSE_AP.size() + ENEN_AP.size();

    int byMajorNonTTPCount = NonTTP_ENCS_F.size() +//
    NonTTP_CHEN_F.size() + NonTTP_BIEN_F.size() +//
    NonTTP_MCEN_F.size() + NonTTP_CEN_F.size() +//
    NonTTP_CSBA_F.size() + NonTTP_ELEN_F.size() +//
    NonTTP_MSE_F.size() + NonTTP_ENEN_F.size();

    int byMajorNonTTP_APCount = NonTTP_ENCS_AP.size() + NonTTP_CHEN_AP.size() + NonTTP_BIEN_AP.size()+//
    NonTTP_MCEN_AP.size() + NonTTP_CEN_AP.size() + NonTTP_CSBA_AP.size() + NonTTP_ELEN_AP.size() +//
    NonTTP_MSE_AP.size() + NonTTP_ENEN_AP.size();

    std::cout << endl << "The number of TTP members by major not on AP is: " << byMajorTTPCount << endl;
    std::cout << "The number of TTP members by major on AP is: " << byMajorAPCount << endl;
    std::cout << "The number of transfers not in TTP by major not on AP is: " << byMajorNonTTPCount << endl;
    std::cout << "The number of transfers not in TTP by major on AP is: " << byMajorNonTTP_APCount << endl;

    //Output Non-TTP Transfer Information by Major
    string fallcoohort = "20F";
    string ENCS_Fall_Transfers = "Computer_Science_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(ENCS_Fall_Transfers, NonTTP_ENCS_F, NonTTP_ENCS_AP, fallcoohort);    
    string CHEN_Fall_Transfers = "Chemical_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(CHEN_Fall_Transfers, NonTTP_CHEN_F, NonTTP_CHEN_AP, fallcoohort);   
    string BIEN_Fall_Transfers = "Bioengineering_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(BIEN_Fall_Transfers, NonTTP_BIEN_F, NonTTP_BIEN_AP, fallcoohort);    
    string CEN_Fall_Transfers = "Computer_Engineering_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(CEN_Fall_Transfers, NonTTP_CEN_F, NonTTP_CEN_AP, fallcoohort); 
    string CSBA_Fall_Transfers = "Computer_Sci_Bus_Applications_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(CSBA_Fall_Transfers, NonTTP_CSBA_F, NonTTP_CSBA_AP, fallcoohort);    
    string ELEN_Fall_Transfers = "Electrical_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(ELEN_Fall_Transfers, NonTTP_ELEN_F, NonTTP_ELEN_AP, fallcoohort);   
    string MSE_Fall_Transfers = "Material_Science_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(MSE_Fall_Transfers, NonTTP_MSE_F, NonTTP_MSE_AP, fallcoohort);    
    string ENEN_Fall_Transfers = "Environmental_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(ENEN_Fall_Transfers, NonTTP_ENEN_F, NonTTP_ENEN_AP, fallcoohort); 
    string MCEN_Fall_Transfers = "Mechancial_Fall_Cohort_Non_TTP.csv";
    //Output_By_Major_Fall(MCEN_Fall_Transfers, NonTTP_MCEN_F, NonTTP_MCEN_AP, fallcoohort); 

    //Output .csv file for mentors by cohort
    string Sarah = "Sarah_Fall_Cohort.csv";
    string Sarah1 = "Sarah_Winter_Cohort.csv";
    string sarah = "Sarah";
    //Output_CSV_File_Fall(Sarah, sarah, Sarah_F, TTP_AP);
    //Output_CSV_File_Winter(Sarah1, sarah, Sarah_W, TTP_AP);    
    string buddy = "Buddy";
    string Buddy = "Buddy_Fall_Chort.csv";
    string Buddy1 = "Buddy_Winter_Cohort.csv";
    //Output_CSV_File_Fall(Buddy, buddy, Buddy_F, TTP_AP);
    //Output_CSV_File_Winter(Buddy1, buddy, Buddy_W, TTP_AP); 
    string bea = "Bea";   
    string Bea = "Bea_Fall_Cohort.csv";
    string Bea1 = "Bea_Winter_Cohort.csv";
    //Output_CSV_File_Fall(Bea, bea, Bea_F, TTP_AP);
    //Output_CSV_File_Winter(Bea1, bea, Bea_W, TTP_AP);
    string arthor = "Arthor";
    string Arthor = "Arthor_Fall_Chort.csv";
    string Arthor1 = "Arthor_Winter_Cohort.csv";
    //Output_CSV_File_Fall(Arthor, arthor, Arthor_F, TTP_AP);
    //Output_CSV_File_Winter(Arthor1, arthor, Arthor_W, TTP_AP); 
    string james = "James";   
    string James = "James_Fall_Cohort.csv";
    string James1 = "James_Winter_Cohort.csv";
    //Output_CSV_File_Fall(James, james, James_F, TTP_AP);
    //Output_CSV_File_Winter(James1, james, James_W, TTP_AP);


    return 0;
}