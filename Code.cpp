#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Patient
{
protected:
    char name[100];
    char age[20];
    char gender[100];
    char phone[20];
    char type[100];
    char med[100];
    char room[30];
    char date[30];
    char bill[100];
public:
    virtual void display_msg()
    {
        cout<<endl;
    }
};

class DoctorInfo //doctor base class
{

protected:
    char doctorName[100];
    char department[30];
    char id[15];
    char docPhoneNum[15];
    char time[20];

public:

    void get_doc()  //taking doctor info
    {
        fstream doctorInfo;

        doctorInfo.open("Doctor Info.txt",ios::app);

        cin.ignore();


        cout<<"\n\t\tEnter Doctor's ID : ";
        cin.getline(id,15);

        cout<<"\t\tEnter Doctor's Name : ";
        cin.getline(doctorName,100);

        cout<<"\t\tEnter Department : ";
        cin.getline(department,30);

        cout<<"\t\tEnter Phone Number : ";
        cin.getline(docPhoneNum,15);

        cout<<"\t\tEnter Availability : ";
        cin.getline(time,20);

        doctorInfo<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;

        doctorInfo.close();

    }

    void display_msg()
    {
        cout<<"\n\t\tYour Input Has Successfully Added"<<endl;
    }

    virtual void disp_msg()
    {
        cout<<endl;
    }

};

class SearchD : public DoctorInfo  //for searching doctor records
{


public:

    void search()
    {
        fstream searchDoc;
        searchDoc.open("Doctor Info.txt",ios::in);
        cin.ignore();

        char a[15];
        cout<<"\n\t\tEnter Doctor's ID : ";
        //cin.ignore();
        cin.getline(a,15);
        int x=0;
        while(!searchDoc.eof())
        {
            searchDoc.getline(id,15,'|');
            searchDoc.getline(doctorName,100,'|');
            searchDoc.getline(department,30,'|');
            searchDoc.getline(docPhoneNum,15,'|');
            searchDoc.getline(time,20);
            if(strcmp(id, a)==0)
            {
                cout<< "\n\t\tDoctor's ID : "<< id <<endl;
                cout<< "\t\tDoctor's Name : "<<doctorName<<endl;
                cout<<"\t\tDepartment : "<<department<<" Department"<<endl;
                cout<<"\t\tPhone Number : "<<docPhoneNum<<endl;
                cout<<"\t\tAvailability : "<<time<<endl;

                x=1;
                break;
            }

        }
        if(x==0)
        {
            cout<<"\n\t\tRecord not found!";
        }
        searchDoc.close();

    }

    void disp_msg()
    {
        cout<<"\n\t\tDone!"<<endl;
    }


};

class ModD : public DoctorInfo  //for modifying doctor records
{
public:

    void modify()
    {
        fstream mod;
        fstream temp;

        mod.open("Doctor Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);
        char i[15];
        cin.ignore();
        cout<<"\n\t\tEnter Doctor's ID to Update Records : ";
        //cin.ignore();
        cin.getline(i,15);
        while(!mod.eof())
        {
            mod.getline(id,15,'|');
            mod.getline(doctorName,100,'|');
            mod.getline(department,30,'|');
            mod.getline(docPhoneNum,15,'|');
            mod.getline(time,20);

            if(strcmp(id,i)==0)
            {
                cout<<"\n\t\tEnter New Records "<<endl;
                cout<<"\n\t\tEnter Doctor's ID : ";
                cin.getline(id,15);
                cout<<"\t\tEnter Doctor's Name : ";
                cin.getline(doctorName,100);
                cout<<"\t\tEnter Department : ";
                cin.getline(department,30);
                cout<<"\t\tEnter Phone Number : ";
                cin.getline(docPhoneNum,15);
                cout<<"\t\tEnter Availability : ";
                cin.getline(time,20);

                temp<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;
            }
            else
            {
                temp<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;
            }
        }

        temp.close();
        mod.close();


        mod.open("Doctor Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);
        while(!temp.eof())
        {
            temp.getline(id,15,'|');
            temp.getline(doctorName,100,'|');
            temp.getline(department,30,'|');
            temp.getline(docPhoneNum,15);

            mod<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;
        }


        temp.close();
        mod.close();

        remove("temp.txt");



    }
    void disp_msg()
    {
        cout<<"\n\t\tYour Records Have Been Updated"<<endl;
    }

};


class DelD : public DoctorInfo  //for deleting doctor records
{
public:

    void del()
    {
        fstream delD;
        fstream temp;

        delD.open("Doctor Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);

        char i[15];
        cin.ignore();
        cout<<"\n\t\tEnter Doctor's ID to Delete Records : ";
        cin.getline(i,15);
        while(!delD.eof())
        {
            delD.getline(id,15,'|');
            delD.getline(doctorName,100,'|');
            delD.getline(department,30,'|');
            delD.getline(docPhoneNum,15,'|');
            delD.getline(time,20);
            if(strcmp(id,i)==0)
            {
                continue;
            }
            else
            {
                temp<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;
            }

        }

        temp.close();
        delD.close();

        delD.open("Doctor Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);

        while(!temp.eof())
        {
            temp.getline(id,15,'|');
            temp.getline(doctorName,100,'|');
            temp.getline(department,30,'|');
            temp.getline(docPhoneNum,15,'|');
            temp.getline(time,20);

            delD<<id<<'|'<<doctorName<<'|'<<department<<'|'<<docPhoneNum<<'|'<<time<<endl;
        }

        temp.close();
        delD.close();

        remove("Temp.txt");


    }

    void disp_msg()
    {
        cout<<"\n\t\tRecords Have Been Deleted"<<endl;
    }
};




class EmergencyInfo : public Patient //emergency base class.

{
protected:
    char serialE[10];


public:

    void get_pat()
    {
        fstream epatientInfo;
        epatientInfo.open("Emergency Patient Info.txt",ios::app);
        cin.ignore();

        cout<<"\n\t\tEnter Patient's Emergency Serial NO. : ";
        cin.getline(serialE,10);

        cout<<"\t\tEnter Patient's Name : ";
        cin.getline(name,100);

        cout<<"\t\tEnter Patient's Age : ";
        cin.getline(age,20);

        cout<<"\t\tEnter Patient's Gender : ";
        cin.getline(gender,100);

        cout<<"\t\tEnter Patient's Phone Number : ";
        cin.getline(phone,20);

        cout<<"\t\tEnter Disease Type : ";
        cin.getline(type,100);

        cout<<"\t\tEnter Required Medicines : ";
        cin.getline(med,100);

        cout<<"\t\tEnter Assigned Room NO. : ";
        cin.getline(room,30);

        cout<<"\t\tEnter Admit Date : ";
        cin.getline(date,30);

        cout<<"\t\tEnter Total Amount of Bill : ";
        cin.getline(bill,100);

        epatientInfo<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;

        epatientInfo.close();


    }

    void display_msg()
    {
        cout<<"\n\t\tYour Records Have Been Successfully Added!"<<endl;
    }

    virtual void disp_msg()
    {
        cout<<endl;
    }
};


class SearchE : public EmergencyInfo  //for searching emergency patients records
{
public:

    void search()
    {
        fstream searchEm;
        searchEm.open("Emergency Patient Info.txt",ios::in);
        cin.ignore();

        char a[10];
        cout<<"\n\t\tEnter Emergency Serial NO. : ";
        //cin.ignore();
        cin.getline(a,10);
        int x=0;

        while(!searchEm.eof())
        {
            searchEm.getline(serialE,10,'|');
            searchEm.getline(name,100,'|');
            searchEm.getline(age,20,'|');
            searchEm.getline(gender,100,'|');
            searchEm.getline(phone,20,'|');
            searchEm.getline(type,100,'|');
            searchEm.getline(med,100,'|');
            searchEm.getline(room,30,'|');
            searchEm.getline(date,30,'|');
            searchEm.getline(bill,100);

            if(strcmp(serialE,a)==0)
            {
                cout<<"\n\t\tPatient's Serial NO. : "<<serialE<<endl;
                cout<<"\t\tPatient's Name : "<<name<<endl;
                cout<<"\t\tPatient's Age : "<<age<<endl;
                cout<<"\t\tPatient's Gender : "<<gender<<endl;
                cout<<"\t\t Patient's Phone Number : "<<phone<<endl;
                cout<<"\t\tPatient's Disease Type : "<<type<<endl;
                cout<<"\t\tMedicines : "<<med<<endl;
                cout<<"\t\tAssigned Room NO. :"<<room<<endl;
                cout<<"\t\tDate of Admit : "<<date<<endl;
                cout<<"\t\tTotal Bill :"<<bill<<endl;

                x=1;
                break;


            }

        }

        if (x==0)
        {
            cout<<"\n\t\tRecord not found!"<<endl;
        }

        searchEm.close();
    }

    void disp_msg()
    {
        cout<<"\n\t\tDone!"<<endl;
    }


};


class ModE : public EmergencyInfo  //for updating emergency patients records
{
public:
    void modify()
    {
        fstream mod;
        fstream temp;

        mod.open("Emergency Patient Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);
        char i[10];
        cin.ignore();
        cout<<"\n\t\tEnter Emergency Serial NO. to Update Records : ";
        //cin.ignore();
        cin.getline(i,10);
        while(!mod.eof())
        {
            mod.getline(serialE,10,'|');
            mod.getline(name,100,'|');
            mod.getline(age,20,'|');
            mod.getline(gender,100,'|');
            mod.getline(phone,20,'|');
            mod.getline(type,100,'|');
            mod.getline(med,100,'|');
            mod.getline(room,30,'|');
            mod.getline(date,30,'|');
            mod.getline(bill,100);

            if(strcmp(serialE,i)==0)
            {
                cout<<"\n\t\tEnter New Records "<<endl;

                cout<<"\n\t\tEnter Patient's Emergency Serial NO. : ";
                cin.getline(serialE,10);

                cout<<"\t\tEnter Patient's Name : ";
                cin.getline(name,100);

                cout<<"\t\tEnter Patient's Age : ";
                cin.getline(age,20);

                cout<<"\t\tEnter Patient's Gender : ";
                cin.getline(gender,100);

                cout<<"\t\tEnter Patient's Phone Number : ";
                cin.getline(phone,20);

                cout<<"\t\tEnter Disease Type : ";
                cin.getline(type,100);

                cout<<"\t\tEnter Required Medicines : ";
                cin.getline(med,100);

                cout<<"\t\tEnter Assigned Room NO. : ";
                cin.getline(room,30);

                cout<<"\t\tEnter Admit Date : ";
                cin.getline(date,30);

                cout<<"\t\tEnter Total Amount of Bill : ";
                cin.getline(bill,100);

                temp<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;
            }
            else
            {
                temp<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;
            }
        }

        temp.close();
        mod.close();


        mod.open("Emergency Patient Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);
        while(!temp.eof())
        {
            temp.getline(serialE,10,'|');
            temp.getline(name,100,'|');
            temp.getline(age,20,'|');
            temp.getline(gender,100,'|');
            temp.getline(phone,20,'|');
            temp.getline(type,100,'|');
            temp.getline(med,100,'|');
            temp.getline(room,30,'|');
            temp.getline(date,30,'|');
            temp.getline(bill,100);


            mod<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;
        }


        temp.close();
        mod.close();

        remove("Temp.txt");

    }

    void disp_msg()
    {
        cout<<"\n\t\tYour Records Have Been Updated!"<<endl;
    }
};

class DelE : public EmergencyInfo  //for deleting emergency patients records
{
public:

    void del()
    {
        fstream delE;
        fstream temp;

        delE.open("Emergency Patient Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);

        char i[10];
        cin.ignore();
        cout<<"\n\t\tEnter Emergency Serial NO. to Delete Records : ";
        cin.getline(i,10);
        while(!delE.eof())
        {
            delE.getline(serialE,10,'|');
            delE.getline(name,100,'|');
            delE.getline(age,20,'|');
            delE.getline(gender,100,'|');
            delE.getline(phone,20,'|');
            delE.getline(type,100,'|');
            delE.getline(med,100,'|');
            delE.getline(room,30,'|');
            delE.getline(date,30,'|');
            delE.getline(bill,100);

            if(strcmp(serialE,i)==0)
            {
                continue;
            }
            else
            {
                temp<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;
            }

        }

        temp.close();
        delE.close();

        delE.open("Emergency Patient Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);

        while(!temp.eof())
        {
            temp.getline(serialE,10,'|');
            temp.getline(name,100,'|');
            temp.getline(age,20,'|');
            temp.getline(gender,100,'|');
            temp.getline(phone,20,'|');
            temp.getline(type,100,'|');
            temp.getline(med,100,'|');
            temp.getline(room,30,'|');
            temp.getline(date,30,'|');
            temp.getline(bill,100);

            delE<<serialE<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<room<<'|'<<date<<'|'<<bill<<endl;
        }

        temp.close();
        delE.close();

        remove("Temp.txt");
    }

    void disp_msg()
    {
        cout<<"\n\t\tRecords Have Been Deleted!"<<endl;
    }
};




class RegularInfo : public Patient  //regular base class
{
protected:
    char serialR[10];
    char roomtype[100];
    char condition[100];
    char rDate[50];
    char assignedDoc[100];
    char test[100];

public:
    void get_pat()
    {
        fstream rpatientInfo;
        rpatientInfo.open("Regular Patient Info.txt",ios::app);
        cin.ignore();

        cout<<"\n\t\tEnter Patient's Serial NO. : ";
        cin.getline(serialR,10);

        cout<<"\t\tEnter Patient's Name : ";
        cin.getline(name,100);

        cout<<"\t\tEnter Patient's Age : ";
        cin.getline(age,20);

        cout<<"\t\tEnter Patient's Gender : ";
        cin.getline(gender,100);

        cout<<"\t\tEnter Patient's Phone Number : ";
        cin.getline(phone,20);

        cout<<"\t\tEnter Disease Type : ";
        cin.getline(type,100);

        cout<<"\t\tEnter Medicines : ";
        cin.getline(med,100);

        cout<<"\t\tEnter Required Tests : ";
        cin.getline(test,100);

        cout<<"\t\tEnter Patient's Condition : ";
        cin.getline(condition,100);

        cout<<"\t\tEnter Assigned Room NO. : ";
        cin.getline(room,30);

        cout<<"\t\tEnter Room Type : ";
        cin.getline(roomtype,100);

        cout<<"\t\tEnter Assigned Doctor's Name : ";
        cin.getline(assignedDoc,100);

        cout<<"\t\tEnter Admit Date : ";
        cin.getline(date,30);

        cout<<"\t\tEnter Release Date : ";
        cin.getline(rDate,50);

        cout<<"\t\tEnter Total Amount of Bill : ";
        cin.getline(bill,100);

        rpatientInfo<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;

        rpatientInfo.close();
    }

    void display_msg()
    {
        cout<<"\n\t\tYour Records Have Been Successfully Added!"<<endl;
    }

    virtual void disp_msg()
    {
        cout<<endl;
    }

};


class SearchR : public RegularInfo  //for searching regular patients records
{
public:
    void search()
    {

        fstream searchReg;
        searchReg.open("Regular Patient Info.txt",ios::in);
        cin.ignore();

        char a[10];
        cout<<"\n\t\tEnter Serial NO. to Search : ";
        //cin.ignore();
        cin.getline(a,10);
        int x=0;

        while(!searchReg.eof())
        {
            searchReg.getline(serialR,10,'|');
            searchReg.getline(name,100,'|');
            searchReg.getline(age,20,'|');
            searchReg.getline(gender,100,'|');
            searchReg.getline(phone,20,'|');
            searchReg.getline(type,100,'|');
            searchReg.getline(med,100,'|');
            searchReg.getline(test,100,'|');
            searchReg.getline(condition,100,'|');
            searchReg.getline(room,30,'|');
            searchReg.getline(roomtype,100,'|');
            searchReg.getline(assignedDoc,100,'|');
            searchReg.getline(date,30,'|');
            searchReg.getline(rDate,50,'|');
            searchReg.getline(bill,100);

            if(strcmp(serialR,a)==0)
            {
                cout<<"\n\t\t Patient's Serial NO. : "<<serialR<<endl;
                cout<<"\t\tPatient's Name : "<<name<<endl;
                cout<<"\t\tPatient's Age : "<<age<<endl;
                cout<<"\t\tPatient's Gender : "<<gender<<endl;
                cout<<"\t\tPatient's Phone Number : "<<phone<<endl;
                cout<<"\t\tDisease Type : "<<type<<endl;
                cout<<"\t\tRequired Medicines : "<<med<<endl;
                cout<<"\t\tRequired Tests : "<<test<<endl;
                cout<<"\t\tPatient's Condition : "<<condition<<endl;
                cout<<"\t\tAssigned Room No. : "<<room<<endl;
                cout<<"\t\tRoom Type : "<<roomtype<<endl;
                cout<<"\t\tAssigned Doctor's Name : "<<assignedDoc<<endl;
                cout<<"\t\tDate of Admit : "<<date<<endl;
                cout<<"\t\tDate of Release : "<<rDate<<endl;
                cout<<"\t\tTotal Bill : "<<bill<<endl;

                x=1;
                break;


            }

        }

        if (x==0)
        {
            cout<<"\n\t\tRecord Not Found!"<<endl;
        }

        searchReg.close();




    }

    void disp_msg()
    {
        cout<<"\n\t\tDone!"<<endl;
    }
};


class ModR : public RegularInfo  //for updating regular patients records
{
public:

    void modify()
    {
        fstream mod;
        fstream temp;

        mod.open("Regular Patient Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);
        char i[10];
        cin.ignore();
        cout<<"\n\t\tEnter Patient's Serial NO. to Update Records : ";
        //cin.ignore();
        cin.getline(i,10);
        while(!mod.eof())
        {
            mod.getline(serialR,10,'|');
            mod.getline(name,100,'|');
            mod.getline(age,20,'|');
            mod.getline(gender,100,'|');
            mod.getline(phone,20,'|');
            mod.getline(type,100,'|');
            mod.getline(med,100,'|');
            mod.getline(test,100,'|');
            mod.getline(condition,100,'|');
            mod.getline(room,30,'|');
            mod.getline(roomtype,100,'|');
            mod.getline(assignedDoc,100,'|');
            mod.getline(date,30,'|');
            mod.getline(rDate,50,'|');
            mod.getline(bill,100);

            if(strcmp(serialR,i)==0)
            {
                cout<<"\n\t\tEnter new records  "<<endl;

                cout<<"\n\t\tEnter Patient's Serial NO. : ";
                cin.getline(serialR,10);

                cout<<"\t\tEnter Patient's Name : ";
                cin.getline(name,100);

                cout<<"\t\tEnter Patient's Age : ";
                cin.getline(age,20);

                cout<<"\t\tEnter Patient's Gender : ";
                cin.getline(gender,100);

                cout<<"\t\tEnter Patient's Phone Number : ";
                cin.getline(phone,20);

                cout<<"\t\tEnter Disease Type : ";
                cin.getline(type,100);

                cout<<"\t\tEnter Medicines : ";
                cin.getline(med,100);

                cout<<"\t\tEnter Required Tests : ";
                cin.getline(test,100);

                cout<<"\t\tEnter Patient's Condition : ";
                cin.getline(condition,100);

                cout<<"\t\tEnter Assigned Room NO. : ";
                cin.getline(room,30);

                cout<<"\t\tEnter Room Type : ";
                cin.getline(roomtype,100);

                cout<<"\t\tEnter Assigned Doctor's Name : ";
                cin.getline(assignedDoc,100);

                cout<<"\t\tEnter Admit Date : ";
                cin.getline(date,30);

                cout<<"\t\tEnter Release Date : ";
                cin.getline(rDate,50);

                cout<<"\t\tEnter Total Amount of Bill : ";
                cin.getline(bill,100);

                temp<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;
            }
            else
            {
                temp<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;
            }
        }

        temp.close();
        mod.close();


        mod.open("Regular Patient Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);
        while(!temp.eof())
        {
            temp.getline(serialR,10,'|');
            temp.getline(name,100,'|');
            temp.getline(age,20,'|');
            temp.getline(gender,100,'|');
            temp.getline(phone,20,'|');
            temp.getline(type,100,'|');
            temp.getline(med,100,'|');
            temp.getline(test,100,'|');
            temp.getline(condition,100,'|');
            temp.getline(room,30,'|');
            temp.getline(roomtype,100,'|');
            temp.getline(assignedDoc,100,'|');
            temp.getline(date,30,'|');
            temp.getline(rDate,50,'|');
            temp.getline(bill,100);


            mod<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;
        }


        temp.close();
        mod.close();

        remove("Temp.txt");



    }

    void disp_msg()
    {
        cout<<"\n\t\tYour Records Have Been Updated!"<<endl;
    }
};



class DelR : public RegularInfo  //for deleting regular patient records
{
public:

    void del()
    {
        fstream delR;
        fstream temp;

        delR.open("Regular Patient Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);

        char i[10];
        cin.ignore();
        cout<<"\n\t\tEnter Patient's Serial NO. to Delete Records : ";
        cin.getline(i,10);
        while(!delR.eof())
        {
            delR.getline(serialR,10,'|');
            delR.getline(name,100,'|');
            delR.getline(age,20,'|');
            delR.getline(gender,100,'|');
            delR.getline(phone,20,'|');
            delR.getline(type,100,'|');
            delR.getline(med,100,'|');
            delR.getline(test,100,'|');
            delR.getline(condition,100,'|');
            delR.getline(room,30,'|');
            delR.getline(roomtype,100,'|');
            delR.getline(assignedDoc,100,'|');
            delR.getline(date,30,'|');
            delR.getline(rDate,50,'|');
            delR.getline(bill,100);

            if(strcmp(serialR,i)==0)
            {
                continue;
            }
            else
            {
                temp<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;
            }

        }

        temp.close();
        delR.close();

        delR.open("Regular Patient Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);

        while(!temp.eof())
        {
            temp.getline(serialR,10,'|');
            temp.getline(name,100,'|');
            temp.getline(age,20,'|');
            temp.getline(gender,100,'|');
            temp.getline(phone,20,'|');
            temp.getline(type,100,'|');
            temp.getline(med,100,'|');
            temp.getline(test,100,'|');
            temp.getline(condition,100,'|');
            temp.getline(room,30,'|');
            temp.getline(roomtype,100,'|');
            temp.getline(assignedDoc,100,'|');
            temp.getline(date,30,'|');
            temp.getline(rDate,50,'|');
            temp.getline(bill,100);

            delR<<serialR<<'|'<<name<<'|'<<age<<'|'<<gender<<'|'<<phone<<'|'<<type<<'|'<<med<<'|'<<test<<'|'<<condition<<'|'<<room<<'|'<<roomtype<<'|'<<assignedDoc<<'|'<<date<<'|'<<rDate<<'|'<<bill<<endl;
        }

        temp.close();
        delR.close();

        remove("Temp.txt");
    }
    void disp_msg()
    {
        cout<<"\n\t\tRecords Have Been Deleted!"<<endl;
    }

};




int main()
{

    int main;

    cout<<"\t \t \t \t \t Hospital Management System"<<endl;
    cout<<"\n \n\t \tMain Menu"<<endl;
    cout<<"\n\t\tPress 1 to Continue\n\t\tPress 0 to Exit"<<endl;
    cout<<"\n\t\tEnter Your Choice : ";
    cin>>main;
    if(main==1)
    {
        int k;

        do
        {
            cout<<"\n\t\t1. Add New Record"<<endl;
            cout<<"\t\t2. Search for Records"<<endl;
            cout<<"\t\t3. Update Existing Records"<<endl;
            cout<<"\t\t4. Delete Records"<<endl;
            cout<<"\n\t\tEnter Your Choice : ";

            int main_option;
            cin>>main_option;

            switch(main_option)
            {
            case 1:
            {

                int j;

                do
                {
                    cout<<"\n\t\t1. Patient info"<<endl<<"\t\t2. Doctor Info"<<endl;
                    cout<<"\n\t\tEnter Your Choice : ";
                    int opt1;
                    cin>>opt1;

                    switch(opt1)
                    {
                    case 1:
                    {

                        int i;

                        do
                        {
                            cout<<"\n\t\t1. Emergency"<<endl;
                            cout<<"\t\t2. Regular"<<endl;
                            cout<<"\n\t\tEnter Your Choice : ";

                            int optP;
                            cin>>optP;


                            switch(optP)
                            {
                            case 1:
                            {
                                EmergencyInfo e1;
                                Patient *p1;
                                p1=&e1;
                                e1.get_pat();
                                p1->display_msg();
                                break;
                            }

                            case 2:
                            {
                                RegularInfo r1;
                                Patient *p2;
                                p2=&r1;
                                r1.get_pat();
                                p2->display_msg();

                                break;
                            }


                            default:
                            {
                                cout<<"\n\n\t\t\tWrong Input!"<<endl;
                                i=0;
                            }
                            }

                            cout<<"\n\t\t0. Continue"<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                            cout<<"\n\t\tEnter Your Choice : ";
                            cin>>i;
                        }
                        while (i!=1);

                        break;
                    }
                    case 2:
                    {
                        DoctorInfo d;
                        d.get_doc();
                        d.display_msg();
                        break;
                    }

                    default:
                    {
                        cout<<"\n\n\t\t\tWrong input"<<endl;
                        j=0;
                    }
                    }

                    cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                    cin>>j;


                }
                while (j!=1);

                k=0;
                break;

            }

            case 2:
            {
                int a;

                do
                {
                    cout<<"\n\t\t1. Patient Info"<<endl;
                    cout<<"\t\t2. Doctor Info"<<endl;
                    cout<<"\n\t\tEnter Your Choice : ";

                    int opt2;
                    cin>>opt2;

                    switch (opt2)
                    {
                    case 1:
                    {
                        int b;

                        do
                        {
                            cout<<"\n\t\t1. Emergency"<<endl;
                            cout<<"\t\t2. Regular"<<endl;
                            cout<<"\n\t\tEnter Your Choice : ";

                            int optp;
                            cin>>optp;

                            switch(optp)
                            {
                            case 1:
                            {
                                SearchE se1;
                                EmergencyInfo *e11;
                                e11=&se1;
                                se1.search();
                                e11->disp_msg();

                                break;
                            }

                            case 2:
                            {
                                SearchR sr1;
                                RegularInfo *r11;
                                r11=&sr1;
                                sr1.search();
                                r11->disp_msg();

                                break;
                            }

                            default:
                            {
                                cout<<"\n\t\tWrong Input!"<<endl;
                                b=0;
                            }
                            }

                            cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                            cin>>b;

                        }
                        while (b!=1);

                        a=1;

                        break;
                    }

                    case 2:
                    {
                        SearchD sd;
                        DoctorInfo *d11;
                        d11=&sd;
                        sd.search();
                        d11->disp_msg();
                        break;
                    }

                    default:
                    {
                        cout<<"\n\t\tWrong Input!"<<endl;
                        a=0;
                    }
                    }

                    cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                    cin>>a;
                }
                while (a!=1);

                k=0;
                break;
            }

            case 3:
            {
                int m;

                do
                {
                    cout<<"\n\t\t1. Patient Info"<<endl;
                    cout<<"\t\t2. Doctor Info"<<endl;
                    cout<<"\n\t\tEnter Your Choice : ";

                    int opt3;
                    cin>>opt3;

                    switch (opt3)
                    {
                    case 1:
                    {
                        int n;

                        do
                        {
                            cout<<"\n\t\t1. Emergency"<<endl;
                            cout<<"\t\t2. Regular"<<endl;
                            cout<<"\n\t\tEnter Your Choice : ";

                            int opp;
                            cin>>opp;

                            switch(opp)
                            {
                            case 1:
                            {
                                ModE me;
                                EmergencyInfo *e22;
                                e22=&me;
                                me.modify();
                                e22->disp_msg();
                                break;
                            }

                            case 2:
                            {
                                ModR m1;
                                RegularInfo *r22;
                                r22=&m1;
                                m1.modify();
                                r22->disp_msg();

                                break;
                            }


                            default:
                            {
                                cout<<"\n\t\tWrong Input!"<<endl;
                                n=0;
                            }
                            }

                            cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                            cin>>n;

                        }
                        while (n!=1);

                        m=0;

                        break;
                    }

                    case 2:
                    {
                        ModD md;
                        DoctorInfo *d22;
                        d22=&md;
                        md.modify();
                        d22->disp_msg();

                        break;
                    }

                    default:
                    {
                        cout<<"\n\t\tWrong Input!"<<endl;
                        m=0;
                    }
                    }

                    cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                    cin>>m;
                }
                while (m!=1);

                k=0;
                break;
            }

            case 4:
            {
                int x;

                do
                {
                    cout<<"\n\t\t1. Patient Info"<<endl;
                    cout<<"\t\t2. Doctor Info"<<endl;
                    cout<<"\n\t\tEnter Your Choice : ";

                    int opt4;
                    cin>>opt4;

                    switch (opt4)
                    {
                    case 1:
                    {
                        int y;

                        do
                        {
                            cout<<"\n\t\t1. Emergency"<<endl;
                            cout<<"\t\t2. Regular"<<endl;
                            cout<<"\n\t\tEnter Your Choice : ";

                            int opt;
                            cin>>opt;

                            switch(opt)
                            {
                            case 1:
                            {
                                DelE de;
                                EmergencyInfo *e33;
                                e33=&de;
                                de.del();
                                e33->disp_msg();

                                break;
                            }

                            case 2:
                            {
                                DelR dr;
                                RegularInfo *r33;
                                r33=&dr;
                                dr.del();
                                r33->disp_msg();

                                break;
                            }

                            default:
                            {
                                cout<<"\n\t\tWrong Input!"<<endl;
                                y=0;
                            }
                            }

                            cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                            cin>>y;

                        }
                        while (y!=1);

                        x=0;

                        break;
                    }

                    case 2:
                    {
                        DelD dd;
                        DoctorInfo *d33;
                        d33=&dd;
                        dd.del();
                        d33->disp_msg();

                        break;
                    }

                    default:
                    {
                        cout<<"\n\t\tWrong Input!"<<endl;
                        x=0;
                    }
                    }

                    cout<<"\n\t\t0. Continue "<<endl<<"\t\t1. Go Back to Previous Menu"<<endl;
                    cin>>x;
                }
                while (x!=1);

                k=0;
                break;
            }


            default:
            {
                cout<<"\n\t\t\tWrong Input!"<<endl;
                k=0;
            }
            }


        }
        while (k!=1);

        return 0;



    }
    else
    {
        return 0;
    }


}


