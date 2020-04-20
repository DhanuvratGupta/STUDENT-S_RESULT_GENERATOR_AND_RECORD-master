#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include <cstring>
#include <cstdio>
#include<cstdlib>
#include <sstream>
using namespace std;
class student_record
{
public:
    string fname,lname,father_fname,father_lname,ph,stu_gmail,sem,str2,stu_id;
    char str_sem[4];
    int s=0;


public:
    //function for taking student information
    void stu_info()
    {
        ofstream student;
        //student is
        cout<<"ENTER STUDENT ID:- ";
        cin>>stu_id;
        //student sem
        cout<<"ENTER SEM(EX:1-SEM):-";
        cin>>sem;
        std::ostringstream stream;
        stream <<sem;
        std::string sem_str = stream.str();
        str2=sem_str+".txt";
        str2="SEM_WISE_STUDENT_NAME\\"+str2;
        student.open(str2.c_str(),ios::app);

        //student name
        cout<<"ENTER YOUR FIRST NAME:- ";
        cin>>fname;
        cout<<"ENTER YOUR LAST NAME:- ";
        cin>>lname;
        student<<"\nSTUDENT NAME:- ";
        student<<fname+" "+lname;
        student<<"\nSTUDENT ID:- ";
        student<<stu_id;
        student<<"\nSEM:-";
        student<<sem;
        //student's father name
        cout<<"ENTER YOUR FATHER FIRST NAME:-  ";
        cin>>father_fname;
        cout<<"ENTER YOUR FATHER LAST NAME:-  ";
        cin>>father_lname;
        student<<"\nFATHER's NAME:- ";
        student<<father_fname+" "+father_lname;
        //stdent ph no.
        cout<<"ENTER PH-NO:-";
        student<<"\nPH-NO:-";
        p:
        cin>>ph;
        if(ph.size()!=10)
        {
            cout<<"\nINVAILED PH.NO.IT SHOULD BE ONLY 10 DIGHT.PLEASE TRY AGAIN";
            goto p;
        }
        else{


            student<<ph;


        }
        student.close();

    }
    friend void email_adderss(student_record);

};

//FRIEND FUN. OF E_MAIL ADDERSS
void email_adderss(student_record b3)
{
        ofstream student;
       student.open(b3.str2.c_str(),ios::app);
    //STUDENT GMAIL ADDERSS
        cout<<"ENTER E-MAIL ADDERSS:-";
        student<<"\nE-MAIL ADDERSS:-";
        l:
        cin>>b3.stu_gmail;
        for(int i=0;i!=b3.stu_gmail.size();i++)
        {
            if(b3.stu_gmail[i]=='@')
            {
                b3.s++;
            }
        }
        if(b3.s==0)
        {
            cout<<"INVALID E-MAIL ADDERSS";
            goto l;
        }

        student<<b3.stu_gmail;
        student<<"\n-----------------------------------------------------------------------";
        student.close();
}
//student result genrate
class  stu_res_info
{
public:
    string exam,stu_1_name,stu_2_name,stu_full_name,stu_file_name,year,year_sem,coll_id;

public:
    void exam_file()
    {

        cout<<"ENTER EXAM(EX:CIA-1):-";
        cin>>exam;
        cout<<"\nENTER YEAR(EX:1-YEAR):-";
        cin>>year;

        cout<<"\nENTER SEM(EX:1-SEM):-";
        cin>>year_sem;
        cout<<"\nENTER ID:-";
        cin>>coll_id;
        cout<<"\nENTER FIREST NAME:-";
        cin>>stu_1_name;
        cout<<"\nENTER LAST NAME:-";
        cin>>stu_2_name;
        stu_full_name=stu_1_name+" "+stu_2_name+".txt";
        stu_file_name="STUNDENT_RESULT\\"+year+"\\"+year_sem+"\\"+exam+"\\"+stu_full_name;
       ofstream res_file;
        res_file.open(stu_file_name.c_str(),ios::app);
        /*res_file<<"\t\t\t**STUDENT EXAM RECORD**\n\t\t\t-----------------------";
        res_file<<"\n\nENTER EXAM:-";
        res_file<<exam;
        res_file<<"\nENTER YEAR:-";
        res_file<<year;

        res_file<<"\nENTER SEM:-";
        res_file<<year_sem;
        res_file<<"\nENTER FIREST NAME:-";-*/
        res_file<<"\t\t\t**"<<exam<<" "<<"RESULT**\n\t\t\t----------------";
        res_file<<"\n\nNAME:-";
        res_file<<stu_1_name+" "+stu_2_name;

        res_file<<"\n\nYEAR:-"<<year;
        res_file<<"\t\t\t\t\tSEM:-"<<year_sem;
        res_file<<"\n\nCOLLEGE:-S.S.JAIN SUBODH PG COLLEGE";
        res_file<<"\t\tID:-";
        res_file<<coll_id<<"\n\n";
        res_file.close();
    }

};
class res_gen:public stu_res_info
{
private:
    int exam_1,exam_2,exam_3,exam_4,exam_5;
    float per1,per2,total_marks;
public:
    void sem_first(string first,string cia)
    {

        ofstream res_file;

        res_file.open(first.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t---------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t\*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-----------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.C LANGUAGE:-";
        res_file<<"\nC LANGUAGE";
        res_file<<"\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.PHYSICS:-";
        res_file<<"\nPHYSICS\t\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.FOC:-";
        res_file<<"\nFOC\t\t\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.MATHMETICS:-";
        res_file<<"\nMATHMETICS\t\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
        res_file<<"\n-----------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4;
        res_file<<"\n\TOTAL\t\t\t120\t\t"<<total_marks;
        per1=total_marks/120;
        per2=per1*100;
        res_file<<"\n-----------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t"<<per2<<"%"<<"\n-----------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();

    }
    void sem_secound(string secound,string cia)
    {
        ofstream res_file;

        res_file.open(secound.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 2-SEM OUT OF 30*\n\t\t-------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-----------------------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.C++ LANGUAGE:-";
        res_file<<"\nC++ LANGUAGE";
        res_file<<"\t\t\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.INTERNET AND WEB TECHNOLOGY:-";
        res_file<<"\nINTERNET AND WEB TECHNOLOGY\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.COMPUTER ARCHITECHER:-";
        res_file<<"\nCOMPUTER ARCHITECHER\t\t\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.DIGITAL ELECTRONICS AND CIRCUITS:-";
        res_file<<"\nDIGITAL ELECTRONICS AND CIRCUITS\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
        res_file<<"\n-----------------------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4;
        res_file<<"\n\TOTAL\t\t\t\t\t120\t\t"<<total_marks;
        per1=total_marks/120;
        per2=per1*100;
        res_file<<"\n-----------------------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t\t\t"<<per2<<"%"<<"\n-----------------------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();
    }
     void sem_third(string third,string cia)
    {
        ofstream res_file;

        res_file.open(third.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 2-SEM OUT OF 30*\n\t\t-------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-----------------------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.DATABASE MANEGMENT SYSTEM:-";
        res_file<<"\nDATABASE MANEGMENT SYSTEM";
        res_file<<"\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.ADVANCE JAVA PROGRAMMING:-";
        res_file<<"\nADVANCE JAVA PROGRAMMING\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.OPERATING SYSTEM FUNDAMENTALS:-";
        res_file<<"\nOPERATING SYSTEM FUNDAMENTALS\t\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.SYSTEM ANALYSIS & DESIGN:-";
        res_file<<"\nSYSTEM ANALYSIS & DESIGN\t\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
        res_file<<"\n-----------------------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4;
        res_file<<"\n\TOTAL\t\t\t\t\t120\t\t"<<total_marks;
        per1=total_marks/120;
        per2=per1*100;
        res_file<<"\n-----------------------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t\t\t"<<per2<<"%"<<"\n-----------------------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();

    }
    void sem_fourth(string fourth,string cia)
    {
        ofstream res_file;

        res_file.open(fourth.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 2-SEM OUT OF 30*\n\t\t-------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-----------------------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.DATA STRUCTURE AND ALGORITHMS:-";
        res_file<<"\nDATA STRUCTURE AND ALGORITHMS";
        res_file<<"\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.PHP PROGRAMMING:-";
        res_file<<"\nPHP PROGRAMMING\t\t\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.ADVANCE DATABASE CONCEPTS:-";
        res_file<<"\nADVANCE DATABASE CONCEPTS\t\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.DATA COMMUNICATION AND NETWORKING:-";
        res_file<<"\nDATA COMMUNICATION AND NETWORKING\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
        res_file<<"\n-----------------------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4;
        res_file<<"\n\TOTAL\t\t\t\t\t120\t\t"<<total_marks;
        per1=total_marks/120;
        per2=per1*100;
        res_file<<"\n-----------------------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t\t\t"<<per2<<"%"<<"\n-----------------------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();
    }
    void sem_fifth(string five,string cia)
    {
         ofstream res_file;

        res_file.open(five.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 2-SEM OUT OF 30*\n\t\t-------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-----------------------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.COMPUTER GRAPHICS:-";
        res_file<<"\nCOMPUTER GRAPHICS";
        res_file<<"\t\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.DOTNET TECHNOLOGIES:-";
        res_file<<"\nDOTNET TECHNOLOGIES\t\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.E-COMMERCE APPLICATION DEVELOPMENT:-";
        res_file<<"\nE-COMMERCE APPLICATION DEVELOPMENT\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.SOFTWARE ENGINEERING:-";
        res_file<<"\nSOFTWARE ENGINEERING\t\t\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
        res_file<<"\n-----------------------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4;
        res_file<<"\n\TOTAL\t\t\t\t\t120\t\t"<<total_marks;
        per1=total_marks/120;
        per2=per1*100;
        res_file<<"\n-----------------------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t\t\t"<<per2<<"%"<<"\n-----------------------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();
    }
    void sem_six(string six,string cia)
    {
        ofstream res_file;

        res_file.open(six.c_str(),ios::app);


        cout<<"\n\n\t\t*ENTER STUDENT MARKS FOR 2-SEM OUT OF 30*\n\t\t-------------------------------------------";
        //res_file<<"\n\n\t\t*ENTER STUDENT MARKS FOR 1-SEM OUT OF 30*\n\t\t-------------------------------------------";
        cout<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS\n\t\t\t\t-------------";
        res_file<<"\nSUBJECT\t\t\t\t\t\tTOTAL\t\tOBTAINED MARKS";
        res_file<<"\n-------------------------------------------------------------------------------";
        //res_file<<"\n\n\t\t\t\t*"<<cia<<" "<<"MARKS*\n\t\t\t\t-------------";
        cout<<"\n\n1.MANGEMENT INFORMATION SYSTEM:-";
        res_file<<"\nMANGEMENT INFORMATION SYSTEM";
        res_file<<"\t\t\t30";
         cin>>exam_1;
         res_file<<"\t\t"<<exam_1;

        cout<<"2.NETWORK SECURITY AND CRYPTOLOGY:-";
        res_file<<"\nNETWORK SECURITY AND CRYPTOLOGY\t\t\t30";
         cin>>exam_2;
         res_file<<"\t\t"<<exam_2;

        cout<<"3.DATA WAREHOUSING AND DATA MINING:-";
        res_file<<"\nDATA WAREHOUSING AND DATA MINING\t\t30";
        cin>>exam_3;
        res_file<<"\t\t"<<exam_3;

        cout<<"4.ARTIFICIAL INTELLIGENCE AND EXPERT SYSTEMS:-";
        res_file<<"\nARTIFICIAL INTELLIGENCE AND EXPERT SYSTEMS\t30";
        cin>>exam_4;
        res_file<<"\t\t"<<exam_4;
         cout<<"5.ANIMATION AND MULTIMEDIA:-";
         res_file<<"\nANIMATION AND MULTIMEDIA\t\t\t30";
         cin>>exam_5;
        res_file<<"\t\t"<<exam_5;
        res_file<<"\n-------------------------------------------------------------------------------";

        total_marks=exam_1+exam_2+exam_3+exam_4+exam_5;
        res_file<<"\n\TOTAL\t\t\t\t\t\t120\t\t"<<total_marks;
        per1=total_marks/150;
        per2=per1*100;
        res_file<<"\n-------------------------------------------------------------------------------";
        res_file<<"\nPERCENTAGE\t\t\t\t\t\t\t"<<per2<<"%"<<"\n------------------------------------------------------------------------------";
        cout<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2;
        //res_file<<"\n\nTOTAL MARKS:-"<< total_marks<<"\n\nPERCENTAGE:-"<< per2<<"\n\n------------------------------------------------------------------";
        res_file.close();

    }
};
//RESULT ENQUIRY
class stu_res_enquiry:public stu_res_info
{
private:
    string res_record;
public:
    void stu_res_Seen()
    {
        ifstream res_file;
        cout<<"\nENTER EXAM(EX:CIA-1):-";
        cin>>exam;
        cout<<"\nENTER YEAR(EX:1-YEAR):-";
        cin>>year;
        cout<<"\nENTER SEM(EX:1-SEM):-";
        cin>>year_sem;
        cout<<"\nENTER FIREST NAME:-";
        cin>>stu_1_name;
        cout<<"\nENTER LAST NAME:-";
        cin>>stu_2_name;
        stu_full_name=stu_1_name+" "+stu_2_name+".txt";
        stu_file_name="STUNDENT_RESULT\\"+year+"\\"+year_sem+"\\"+exam+"\\"+stu_full_name;

        res_file.open(stu_file_name.c_str(),ios::in);
        if(res_file=='\0')
        {
            cout<<"\n\n"<<stu_1_name<<" "<<stu_2_name<<" "<<"NOT AVALIBLE IN STUDENTS RESULT RECORD";
        }
        else
        {
             res_record=res_file.get();
            while(res_file!='\0')
            {

                cout<<res_record;
                res_record=res_file.get();
            }
        }

    }

};
class search_any_student
{
    public:
        int search_student(string fname,string search_name,int counter)
          {
               ifstream fin;
               fin.open(fname.c_str(),ios::in);
                if(fin.fail())
                {
                    exit(1);
                }
                search_name="STUDENT NAME:- "+search_name;
                bool isFound=0;
                while(!fin.eof())
                {
                    string temp = "";
                    getline(fin,temp);
                    for(int i=0;i<search_name.size();i++)
                    {
                        if(temp[i]==search_name[i])
                            isFound = 1;
                        else
                        {
                            isFound =0;
                            break;
                        }
                    }
                    if(isFound)
                    {
                        counter++;
                        string ph,email,fname,id,sem;
                        getline(fin,id);
                        getline(fin,sem);
                        getline(fin,fname);
                        getline(fin,ph);
                        getline(fin,email);
                        cout<<"("<<counter<<")."<<endl;
                        cout<<temp<<endl;
                        cout<<id<<endl;
                        cout<<sem<<endl;
                        cout<<fname<<endl;
                        cout<<ph<<endl;
                        cout<<email;
                        cout<<"\n\n";
                    }
                }
                fin.close();
                return counter;
        }
};
main()
{
    int b1;
    cout<<"\n\n\t\t\t--------------------------------------------\n\t\t\t\t\t****WELCOME****\n\n\t\t\t    **STUDENT REPORT CARD GENRATE SYSTEM**\n\t\t\t--------------------------------------------";
    cout<<"\n\n\n\t\t\tMENU:-\n\n\t\t\t\t1.ENTER STUDENT RECORD\n\t\t\t\t2.SEARCH ANY STUDENT\n\t\t\t\t3.GENRATE RESULT\n\t\t\t\t4.CHEAK ANY STUDENT RESULT";
    cout<<"\n";
    again:
    cout<<"\n\n\t\tCHOSSE YOUR OPTION:-";
    cin>>b1;
    switch(b1)
    {
        case 1:{
                cout<<"\n\n\n\t\t*WELCOME IN STUDENT RECORD*\n\t\t---------------------------\n";
                int b4;
                student_record b2;
                b2.stu_info();
                email_adderss(b2);
                cout<<"\n\nDO U WANT TO CONTINUE.PREES 1(ONE):-";
                cin>>b4;
                if(b4==1)
                {
                    goto again;
                }
                break;
              }
        case 2:{
                 cout<<"\n\n\t\t\t*WELCOME IN STUDENT ENQUIRY*\n\t\t\t----------------------------\n";
                 int b4;
                 string wwe,nxt,search_name;
                int counter=0;
                cout << "Please enter a name: ";
                cin  >> search_name;
                cout<<"STUDENT DETAIL IF AVAILABLE:- "<<endl<<endl;
                search_any_student obj;
                for(int i=1;i<=6;i++)
                {
                    std::ostringstream stream;
                    stream <<i;
                    std::string st_str = stream.str();
                    nxt=st_str+"-SEM";
                    wwe="SEM_WISE_STUDENT_NAME\\"+nxt;
                    wwe=wwe+".txt";
                    counter=obj.search_student(wwe,search_name,counter);
                }
                if(counter==0)
                {
                    cout<<"STUDENT DATA IS NOT AVAILABLE";
                }
                cout<<"\n\nDO U WANT TO CONTINUE.PREES 1(ONE):-";
                cin>>b4;
                if(b4==1)
                {
                    goto again;
                }
                 break;
               }
        case 3:{
                cout<<"\n\n\t\t\t*WELCOME IN GENRATE RESULT*\n\t\t\t----------------------------\n";
                int b4;
                stu_res_info info;
                student_record stu_id2;

                info.exam_file();

                res_gen marks;
                if(info.year_sem=="1-SEM")
                {
                    marks.sem_first(info.stu_file_name,info.exam);
                }
                else if(info.year_sem=="2-SEM")
                {
                    marks.sem_secound(info.stu_file_name,info.exam);
                }
                else if(info.year_sem=="3-SEM")
                {
                    marks.sem_third(info.stu_file_name,info.exam);
                }
                else if(info.year_sem=="4-SEM")
                {
                    marks.sem_fourth(info.stu_file_name,info.exam);
                }
                else if(info.year_sem=="5-SEM")
                {
                    marks.sem_fifth(info.stu_file_name,info.exam);
                }
                else if(info.year_sem=="6-SEM")
                {
                    marks.sem_six(info.stu_file_name,info.exam);
                }
                cout<<"\n\nDO U WANT TO CONTINUE.PREES 1(ONE):-";
                cin>>b4;
                if(b4==1)
                {
                    goto again;
                }
                break;

        }
        case 4:{
            cout<<"\n\n\t\t\t*WELCOME IN STUDENT RESULT ENQUIRY *\n\t\t\t-------------------------------------\n";
            int b4;
            stu_res_enquiry subodh;
            subodh.stu_res_Seen();
            cout<<"\n\nDO U WANT TO CONTINUE.PREES 1(ONE):-";
                cin>>b4;
                if(b4==1)
                {
                    goto again;
                }
                break;

        }

    }
}



