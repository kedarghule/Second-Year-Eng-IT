#include <iostream>
using namespace std;
class Weather_Report
{
     int days;
     float hightemp[31],lowtemp[31],amtrain[31],amtsnow[31];
    public:
        Weather_Report();
        void accept();
        void display();
        void average();
};
Weather_Report::Weather_Report()
{
    days=0;
    for(int i=0;i<31;i++)
    {
        hightemp[i]=0;
        lowtemp[i]=0;
        amtrain[i]=0;
        amtsnow[i]=0;
    }
}
void Weather_Report::accept()
{
    cout<<"\nEnter number of days\n";
    cin>>days;
    for(int i=0;i<days;i++)
    {
        cout<<"\nEnter high temperature for day"<<(i+1)<<" : "; cin>>hightemp[i];
        cout<<"\nEnter low temperature for day"<<(i+1)<<" : "; cin>>lowtemp[i];
        cout<<"\nEnter amount of rainfall for day"<<(i+1)<<" : "; cin>>amtrain[i];
        cout<<"\nEnter amount of snowfall for day"<<(i+1)<<" : "; cin>>amtsnow[i];
    }
}
void Weather_Report::display()
{
    cout<<"\nDay\tMax\tMin\tRain\tSnow";
    for(int i=0;i<days;i++)
    {
        cout<<"\n"<<(i+1)<<"\t"<<hightemp[i]<<"\t"<<lowtemp[i]<<"\t"<<amtrain[i]<<"\t"<<amtsnow[i];
    }
}
void Weather_Report::average()
{
    Weather_Report W;
    cout<<"\nAverage Report of the days :\n";
    for(int i=0;i<days;i++)
    {
        W.hightemp[0]+=hightemp[i];
        W.lowtemp[0]+=lowtemp[i];
        W.amtrain[0]+=amtrain[i];
        W.amtsnow[0]+=amtsnow[i];
    }
    cout<<"\nMax\tMin\tRain\tSnow"<<endl;
    cout<<"\n"<<W.hightemp[0]/days<<"\t"<<W.lowtemp[0]/days<<"\t"<<W.amtrain[0]/days<<"\t"<<W.amtsnow[0]/days<<endl;
}
int main()
{
    Weather_Report w[12],avg;
    int ch,month;
    char ans;
    do
    {
        cout<<"\nEnter \n1. To Input Month Data\n2. To Display Monthly Average Report"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter month number(1-Jan, 2- Feb.....12-Dec\n";
                    cin>>month;
                    w[month-1].accept();
                    w[month-1].display();
                    break;
            case 2: cout<<"\nEnter month number(1-Jan, 2- Feb.....12-Dec\n";
                    cin>>month;
                    w[month-1].average();
                    break;
            default:cout<<"\nWrong choice\n";
        }
        cout<<"\nDo you want to enter more data? (Y/N)";
        cin>>ans;
    }while(ans=='Y'|| ans=='y');
    return 0;
}
