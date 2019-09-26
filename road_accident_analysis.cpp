#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include<wchar.h>
#include<stdlib.h>
using namespace std;

class record1   //record for 2011 and 2012 data with 4 attributes
{
public:
    string city;
    int no_of_fatal,all_accidents,killed,injured;

    void setdata1(string city,int no_of_fatal,int all_accidents,int killed,int injured)
    {
        this->city=city;
        this->no_of_fatal=no_of_fatal;
        this->all_accidents=all_accidents;
        this->killed=killed;
        this->injured=injured;
    }

    void display1(int year)
    {
        cout<<"\tIn "<<year<<endl;
        cout<<"\t\tTotal accidents: \t\t"<<all_accidents<<endl;
        cout<<"\t\tNo. of fatal accidents: \t"<<no_of_fatal<<endl;
        cout<<"\t\tNo. of people killed: \t\t"<<killed<<endl;
        cout<<"\t\tNo. of people injured: \t\t"<<injured<<endl;
    }
};

class record2 : public record1  //record for 2013 data with 5 attributes
{
public:
    float severity;

    void setdata2(string city,int no_of_fatal,int all_accidents,int killed,int injured,float severity)
    {
        this->severity=severity;
        this->setdata1(city,no_of_fatal,all_accidents,killed,injured);
    };

    void display2(int year)
    {
        this->display1(year);
        cout<<"\t\tSeverity: \t\t\t"<<severity<<endl;
    }
};

class record3 : public record2  //record for 2014 and 2015 data with 6 attributes
{
public:
    int grevious_injured,minor_accidents,non_injurey;

    void setdata3(string city,int no_of_fatal,int grevious_injured,int minor_accidents,int non_injurey,int all_accidents,int killed,int injured,float severity)
    {
        this->grevious_injured=grevious_injured;
        this->minor_accidents=minor_accidents;
        this->non_injurey=non_injurey;
        this->setdata2(city,no_of_fatal,all_accidents,killed,injured,severity);
    };

    void display3(int year)
    {
        this->display2(year);
        cout<<"\t\tNo. of greviously injured: \t"<<grevious_injured<<endl;
        cout<<"\t\tNo. of minor accidents: \t"<<minor_accidents<<endl;
        cout<<"\t\tNon_injurey: \t\t\t"<<non_injurey<<endl;
    }
};
int main()
{
    record1 r11[51],r12[51],t11,t12;
    record2 r13[51],t13;
    record3 r14[51],r15[51],t14,t15;
    string data,a[30];
    int i=0,j=0;

    ifstream myfile;
    myfile.open("road_accident.txt",ios::in);   //data file of road accident of 51 cities in 2011,2012,2013,2014 and 2015
    while(!myfile.eof())
    {
        myfile>>data;
        if(data=="NA")
            data='0';
        a[i]=data;
        i++;
        if(i==30)
        {
            i=0;
            r11[j].setdata1(a[0],stoi(a[1]),stoi(a[2]),stoi(a[3]),stoi(a[4]));
            r12[j].setdata1(a[0],stoi(a[5]),stoi(a[6]),stoi(a[7]),stoi(a[8]));
            r13[j].setdata2(a[0],stoi(a[9]),stoi(a[10]),stoi(a[11]),stoi(a[12]),stof(a[13]));
            r14[j].setdata3(a[0],stoi(a[14]),stoi(a[15]),stoi(a[16]),stoi(a[17]),stoi(a[18]),stoi(a[19]),stoi(a[20]),stof(a[21]));
            r15[j].setdata3(a[0],stoi(a[22]),stoi(a[23]),stoi(a[24]),stoi(a[25]),stoi(a[26]),stoi(a[27]),stoi(a[28]),stof(a[29]));
            j++;
        }
    }

    myfile.close();
    for(i=0;i<j;i++)    //Displaying the record of 255 objects where j=51(number of cities)
    {
        cout<<"Record of "<<r11[i].city<<endl;  //a particular city
        r11[i].display1(2011);  //displaying the record of 2011
        r12[i].display1(2012);  //displaying the record of 2012
        r13[i].display2(2013);  //displaying the record of 2013
        r14[i].display3(2014);  //displaying the record of 2014
        r15[i].display3(2015);  //displaying the record of 2015
        cout<<endl;
    }

    ofstream my_file;
    my_file.open("2011.txt");   //Inserting the 2011 data in this file
    if (my_file.is_open())
    {
        for(i=0;i<j;i++)
        {
            my_file<<r11[i].city<<"\t";
            my_file<<r11[i].all_accidents<<"\t";
            my_file<<r11[i].no_of_fatal<<"\t";
            my_file<<r11[i].killed<<"\t";
            my_file<<r11[i].injured<<"\t";
            if(r11[i].all_accidents==0)
                my_file<<0<<"\n";
            else
                my_file<<r11[i].killed*100.0/r11[i].all_accidents<<"\n";
        }
        my_file.close();
    }

    my_file.open("2012.txt");   //Inserting the 2012 data in this file
    if (my_file.is_open())
    {
        for(i=0;i<j;i++)
        {
            my_file<<r12[i].city<<"\t";
            my_file<<r12[i].all_accidents<<"\t";
            my_file<<r12[i].no_of_fatal<<"\t";
            my_file<<r12[i].killed<<"\t";
            my_file<<r12[i].injured<<"\t";
            if(r12[i].all_accidents==0)
                my_file<<0<<"\n";
            else
                my_file<<r12[i].killed*100.0/r12[i].all_accidents<<"\n";
        }
        my_file.close();
    }

    my_file.open("2013.txt");   //Inserting the 2013 data in this file
    if (my_file.is_open())
    {
        for(i=0;i<j;i++)
        {
            my_file<<r13[i].city<<"\t";
            my_file<<r13[i].all_accidents<<"\t";
            my_file<<r13[i].no_of_fatal<<"\t";
            my_file<<r13[i].killed<<"\t";
            my_file<<r13[i].injured<<"\t";
            my_file<<r13[i].severity<<"\n";
        }
        my_file.close();
    }

    my_file.open("2014.txt");   //Inserting the 2014 data in this file
    if (my_file.is_open())
    {
        for(i=0;i<j;i++)
        {
            my_file<<r14[i].city<<"\t";
            my_file<<r14[i].all_accidents<<"\t";
            my_file<<r14[i].no_of_fatal<<"\t";
            my_file<<r14[i].killed<<"\t";
            my_file<<r14[i].injured<<"\t";
            my_file<<r14[i].severity<<"\t";
            my_file<<r14[i].grevious_injured<<"\t";
            my_file<<r14[i].minor_accidents<<"\t";
            my_file<<r14[i].non_injurey<<"\n";
        }
        my_file.close();
    }

    my_file.open("2015.txt");   //Inserting the 2015 data in this file
    if (my_file.is_open())
    {
        for(i=0;i<j;i++)
        {
            my_file<<r15[i].city<<"\t";
            my_file<<r15[i].all_accidents<<"\t";
            my_file<<r15[i].no_of_fatal<<"\t";
            my_file<<r15[i].killed<<"\t";
            my_file<<r15[i].injured<<"\t";
            my_file<<r15[i].severity<<"\t";
            my_file<<r15[i].grevious_injured<<"\t";
            my_file<<r15[i].minor_accidents<<"\t";
            my_file<<r15[i].non_injurey<<"\n";
        }
        my_file.close();
    }

    i=0;
    myfile.open("total.txt",ios::in);
    while(!myfile.eof())
    {
        myfile>>data;
        a[i]=data;
        i++;
    }
    myfile.close();

    t11.setdata1(a[0],stoi(a[1]),stoi(a[2]),stoi(a[3]),stoi(a[4]));
    t12.setdata1(a[0],stoi(a[5]),stoi(a[6]),stoi(a[7]),stoi(a[8]));
    t13.setdata2(a[0],stoi(a[9]),stoi(a[10]),stoi(a[11]),stoi(a[12]),stof(a[13]));
    t14.setdata3(a[0],stoi(a[14]),stoi(a[15]),stoi(a[16]),stoi(a[17]),stoi(a[18]),stoi(a[19]),stoi(a[20]),stof(a[21]));
    t15.setdata3(a[0],stoi(a[22]),stoi(a[23]),stoi(a[24]),stoi(a[25]),stoi(a[26]),stoi(a[27]),stoi(a[28]),stof(a[29]));

    cout<<"Record of overall"<<endl;  //combining all cities
    t11.display1(2011);  //displaying the record of 2011
    t12.display1(2012);  //displaying the record of 2012
    t13.display2(2013);  //displaying the record of 2013
    t14.display3(2014);  //displaying the record of 2014
    t15.display3(2015);  //displaying the record of 2015

    my_file.open("totalall.txt");
    if(my_file.is_open())
    {
            //inserting overall the data of year 2011
            my_file<<2011<<"\t";
            my_file<<t11.all_accidents<<"\t";
            my_file<<t11.no_of_fatal<<"\t";
            my_file<<t11.killed<<"\t";
            my_file<<t11.injured<<"\t";
            my_file<<t11.killed*100.0/t11.all_accidents<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\n";

            //inserting overall the data of year 2012
            my_file<<2012<<"\t";
            my_file<<t12.all_accidents<<"\t";
            my_file<<t12.no_of_fatal<<"\t";
            my_file<<t12.killed<<"\t";
            my_file<<t12.injured<<"\t";
            my_file<<t12.killed*100.0/t12.all_accidents<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\n";

            //inserting overall the data of year 2013
            my_file<<2013<<"\t";
            my_file<<t13.all_accidents<<"\t";
            my_file<<t13.no_of_fatal<<"\t";
            my_file<<t13.killed<<"\t";
            my_file<<t13.injured<<"\t";
            my_file<<t13.severity<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\t";
            my_file<<0<<"\n";

            //inserting overall the data of year 2014
            my_file<<2014<<"\t";
            my_file<<t14.all_accidents<<"\t";
            my_file<<t14.no_of_fatal<<"\t";
            my_file<<t14.killed<<"\t";
            my_file<<t14.injured<<"\t";
            my_file<<t14.severity<<"\t";
            my_file<<t14.grevious_injured<<"\t";
            my_file<<t14.minor_accidents<<"\t";
            my_file<<t14.non_injurey<<"\n";

            //inserting overall the data of year 2015
            my_file<<2015<<"\t";
            my_file<<t15.all_accidents<<"\t";
            my_file<<t15.no_of_fatal<<"\t";
            my_file<<t15.killed<<"\t";
            my_file<<t15.injured<<"\t";
            my_file<<t15.severity<<"\t";
            my_file<<t15.grevious_injured<<"\t";
            my_file<<t15.minor_accidents<<"\t";
            my_file<<t15.non_injurey<<"\n";
        my_file.close();
    }
    return 0;
}
