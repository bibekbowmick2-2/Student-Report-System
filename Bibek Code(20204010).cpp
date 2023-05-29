#include<bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int phy;
    int chem;
    int math;
    int eng;
    int cs;

    void new_record()
    {
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter roll: "<<endl;
        cin>>roll;
        cout<<"Enter physics: "<<endl;
        cin>>phy;
        cout<<"Enter Chemistry marks: "<<endl;
        cin>>chem;
        cout<<"Enter Math mark: "<<endl;
        cin>>math;
        cout<<"Enter English mark: "<<endl;
        cin>>eng;
        cout<<"Enter Computer Science Mark: "<<endl;
        cin>>cs;

        fstream write;
        write.open("student.txt",ios::out|ios::app);
        write<<name<<endl;
        write<<roll<<endl;
        write<<phy<<endl;
        write<<chem<<endl;
        write<<math<<endl;
        write<<eng<<endl;
        write<<cs<<endl;
        cout<<"New record added to the file successfully"<<endl;
        cout<<"---------------------"<<endl;
        write.close();


    }


    void display_all()
    {
        fstream xy;
        xy.open("student.txt",ios::in);
        xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
        while(!xy.eof())
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Roll:  "<<roll<<endl;
            cout<<"Obtained Numbers and Grade"<<endl;
            cout<<"Physics:  "<<phy<<endl;
            cout<<"Chemistry: "<<chem<<endl;
            cout<<"Math:   "<<math<<endl;
            cout<<"English:  "<<eng<<endl;
            cout<<"Computer Science: "<<cs<<endl;
            double total=0;
            total=phy+chem+math+eng+cs;
            total/=5;
            cout<<"Percentage: "<<total<<"%"<<endl;
            string grade;
            grade=grade_count(total);
            cout<<"Grade:  "<<grade<<endl;
            cout<<"-----------------------"<<endl;
            xy>>name>>roll>>phy>>chem>>math>>eng>>cs>>grade;

        }
        xy.close();
    }


    void search_data()
    {
        cout<<"Please enter roll or name of the student you want to search"<<endl;
        int flag=0;
        string r1;
        cin>>r1;
        fstream xy;
        xy.open("student.txt",ios::in);
        xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
        while(!xy.eof())
        {
            stringstream xx(r1);
            int x=0;
            xx>>x;
            if(r1==name||x==roll)
            {
                cout<<"Name: "<<name<<endl;
                cout<<"Roll: "<<roll<<endl;
                cout<<"Obtained Numbers and Grade"<<endl;
                cout<<"Physics:  "<<phy<<endl;
                cout<<"Chemistry: "<<chem<<endl;
                cout<<"Math:   "<<math<<endl;
                cout<<"English:  "<<eng<<endl;
                cout<<"Computer Science: "<<cs<<endl;
                double total=0;
                total=phy+chem+math+eng+cs;
                total/=5;
                cout<<"Percentage: "<<total<<"%"<<endl;
                string grade;
                grade=grade_count(total);
                cout<<"Grade:  "<<grade<<endl;
                cout<<"-----------------------"<<endl;
                xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
                flag=1;
                break;

            }

            xy>>name>>roll>>phy>>chem>>math>>eng>>cs;

        }

        if(flag==0)
        {
            cout<<"Student not found!!!";
        }

        xy.close();

    }

    void show_grade()
    {
        cout<<setw(10)<<"Grade Report"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<left<<setw(10)<<"Name"<<right<<setw(7)<<"Roll";
        cout<<setw(10)<<"Physics"<<setw(12)<<"Chemistry"<<setw(7)<<"Math";
        cout<<setw(10)<<"Engish  "<<setw(14)<<"Computer Science."<<setw(13)<<"Percentage"<<setw(8)<<"Grade"<<endl;
        fstream xy;
        xy.open("student.txt",ios::in);
        xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
        while(!xy.eof())
        {
            double total=0;
            total=phy+chem+math+eng+cs;
            total/=5;
            string grade;
            grade=grade_count(total);
            cout<<left<<setw(10)<<name<<right<<setw(7)<<roll;
            cout<<setw(10)<<phy<<setw(12)<<chem<<setw(7)<<math;
            cout<<setw(10)<<eng<<setw(14)<<cs<<setw(12)<<total<<"%"<<setw(8)<<grade<<endl;
            xy>>name>>roll>>phy>>chem>>math>>eng>>cs;

        }

        xy.close();
        cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;

    }



    void modify_record()
    {
        //  system("cls");
        int id;
        int check=0;
        ifstream d;
        cout<<"ENTER YOUR ID NUMBER : ";
        cin>>id;
        d.open("student.txt");
        ofstream e;
        e.open("temp.txt");
        d>>name>>roll>>phy>>chem>>math>>eng>>cs;

        while(!d.eof())
        {
            if(roll!=id)
            {
                e<<name<<endl;
                e<<roll<<endl;
                e<<phy<<endl;
                e<<chem<<endl;
                e<<math<<endl;
                e<<eng<<endl;
                e<<cs<<endl;
            }

            else
            {
                cout<<"ENTER YOUR FULL NAME :";

                cin>>name;
                e<<name<<endl;

                cout<<"ENTER YOUR ID NUMBER : ";

                cin>>roll;
                e<<roll<<endl;

                cout<<"ENTER YOUR PHYSICS MARK :";

                cin>>phy;
                e<<phy<<endl;



                cout<<"ENTER YOUR CHEMISTRY MARK :";

                cin>>chem;
                e<<chem<<endl;

                cout<<"ENTER YOUR MATH MARK :";

                cin>>math;
                e<<math<<endl;



                cout<<"ENTER YOUR COMPUTER SCIENCE MARK :";

                cin>>cs;
                e<<cs<<endl;

                cout<<"ENTER YOUR ENGLISH MARK :";

                cin>>eng;
                e<<eng<<endl;
                cout<<"Record Updated!!"<<endl;
                check=1;
            }
            d>>name>>roll>>phy>>chem>>math>>eng>>cs;
        }

        if(check==0)
        {
            cout<<"Record not found"<<endl;
        }

        e.close();
        d.close();
        remove("student.txt");
        rename("temp.txt","student.txt");
    }

    void delete_record()
    {
        cout<<"Please enter Roll or Name of the student you want to delete"<<endl;
        int flag=0;
        string r1;
        cin>>r1;
        fstream xy;
        xy.open("student.txt",ios::in);
        fstream tm;
        tm.open("temp.txt",ios::out);
        xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
        while(!xy.eof())
        {
            stringstream xx(r1);
            int x=0;
            xx>>x;
            if(r1!=name&&x!=roll)
            {
                tm<<name<<endl;
                tm<<roll<<endl;
                tm<<phy<<endl;
                tm<<chem<<endl;
                tm<<math<<endl;
                tm<<eng<<endl;
                tm<<cs<<endl;

            }


            else
            {
                flag=1;
            }

            xy>>name>>roll>>phy>>chem>>math>>eng>>cs;
        }

        xy.close();
        tm.close();
        if(flag==1)
        {
            cout<<"Student Data Delete Succesfully"<<endl;
            remove("student.txt");
            rename("temp.txt","student.txt");
        }

        else
        {
            cout<<"Student not FOUND"<<endl;
            remove("temp.txt");
        }

    }


    string grade_count(double x)
    {
        if(x>=80  && x<=100)
        {
            return "A+";
        }

        else if(x>=70&&x<80)
        {
            return "A";
        }

        else if(x>=60&&x<70)
        {
            return "A-";
        }


        else if(x>=50&&x<60)
        {
            return "B";
        }

        else if(x>=40&&x<50)
        {
            return "C";
        }

        else
        {
            return "F";
        }
    }

};
int main()
{

    int i=0;
	time_t t;
	time(&t);

    system("color 02");
   // system("Color 7A");
    cout<<"\n\n";
    cout<<"\t\t\t\t*************************************************\n";
    cout<<"\t\t\t\t*                                               *\n";
    cout<<"\t\t\t\t*       --------------------------------        *\n";
    cout<<"\t\t\t\t*       Student Report Management System        *\n";
    cout<<"\t\t\t\t*       --------------------------------        *\n";
    cout<<"\t\t\t\t*                                               *\n";
    cout<<"\t\t\t\t*                                               *\n";
    cout<<"\t\t\t\t*                                               *\n";
    cout<<"\t\t\t\t*************************************************\n\n";



      for(i=0;i<80;i++)
		 cout<<"-";
	     cout<<"\nCurrent date and time : "<<ctime(&t);
	    for(i=0;i<80;i++)
		cout<<"-";


    Student obj1;
    cout<<"\n\t\t\t\t1. ADD STUDENT REPORT \n\n"<<endl;
    cout<<"\t\t\t\t2. VIEW ALL STUDENTs REPORT CARD\n\n"<<endl;
    cout<<"\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;
    cout<<"\t\t\t\t4. Student Data in Tabular Mode\n\n"<<endl;
    cout<<"\t\t\t\t5. MODIFY REPORT CARD\n\n"<<endl;
    cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
    while(true)
    {
        cout<<endl<<"Enter you choice from the MENU"<<endl;
        int n;
        cin>>n;
        switch(n)
        {
        case 0:
        {
            cout<<"Program Closed!";
            break;
        }

        case 1:
        {
            obj1.new_record();
            break;
        }


        case 2:
        {
            obj1.display_all();
            break;
        }



        case 3:
        {
            obj1.search_data();
            break;
        }


        case 4:
        {
            obj1.show_grade();
            break;
        }



        case 5:
        {
            obj1.modify_record();
            break;
        }




        case 6:
        {
            obj1.delete_record();
            break;
        }



        default:
        {
            cout<<"Enter correct data"<<endl;
            break;
        }

        }

        if(n==0)
        {
            break;
        }
    }
    return 0;
}
