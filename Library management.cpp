#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

class book
{
  long bno;
  char bname[30];
  char authorname[30];
  int di,mi,dr,mr,status;
  public:
  book()
  { status=0;
  }
  void getdateissue()												//to get the date and month of issue
    { cout<<"Enter Date of Issue"<<endl;
      cin>>di;
      cout<<endl;
      cout<<"Enter Month of Issue"<<endl;
      cin>>mi;
      cout<<endl;
     if(di>1 && di<=24)
	cout<<"RETURN ON-"<<di+3;
     else
	cout<<"SORRY. ISSUE YOUR BOOK NEXT MONTH.";
    }
  void getdatedeposit()												//to get the date and month of deposit
    { cout<<"Enter Date of Return"<<endl;
       cin>>dr;
      cout<<"Enter Month of Return"<<endl;
       cin>>mr;
     }


  void getdata()													// to get information of Book
  {   clrscr();
   cout<<" ENTER THE BOOK NUMBER "<<endl;
   cin>>bno;
   cout<<" ENTER THE NAME OF THE BOOK "<<endl;
   gets(bname);
   cout<<" ENTER THE NAME OF THE AUTHOR "<<endl;
   gets(authorname);
   cout<<" BOOK RECORD CREATED "<<endl;
   cout<<" ------------------------------------ "<<endl;
  }
  void mydisplay()
  {
  cout<<bno<<"   "<<bname<<"   "<<authorname<<endl;
  }
  void display()													// to display information of book
  {
  //clrscr();
   cout<<" THE BOOK NUMBER "<<endl;
   cout<<bno<<endl;
   cout<<" THE NAME OF THE BOOK "<<endl;
   puts(bname);
   cout<<" THE NAME OF THE AUTHOR "<<endl;
   puts(authorname);
   cout<<" ------------- "<<endl;
  }

  long retbno()														// to return book no
  {
   return bno;
  }
int retname( char n[20])
{
	if(strcmpi(bname,n)==0)
 return 1;
 else
 return 0;
}

int retmi()
{ return mi;
}

int retdi()
{ return di;
}

int retmr()
{ return mr;
}

int retdr()
{ return dr;
}

int retstatus()
{ return status;
}

void resetstatus()
{ status=0;
}

void updatestatus()
{ status=1;
}


};
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class student
{
   long admno;
  char sname[30];
  long stbno;
   int issue;

 public:
 student()
  { issue=0;
  }

  void getdata()
  {
   clrscr();
   cout<<"             NEW STUDENT ENTRY            "<<endl;
   cout<<" ENTER THE ADMISSION NUMBER OF THE STUDENT "<<endl;
   cin>>admno;
   cout<<" ENTER THE NAME OF THE STUDENT "<<endl;
   gets(sname);

   stbno=0;
   cout<<" NEW STUDENT RECORD CREATED "<<endl;
   cout<<" ----------------------------------- "<<endl;
  }
  void display()
  { clrscr();
   cout<<" THE STUDENT ADMISSION NUMBER IS : "<<endl;
   cout<<admno;
   cout<<" THE STUDENT NAME IS : "<<endl;
   puts(sname);

   cout<<" ------------------------------------ "<<endl;
  }
  void mydisplays()
  {
  cout<<admno<<"   "<<sname<<"   "<<endl;
  }

  long retadmno()
  {
   return admno;
  }

  long retstbno()
  {
   return stbno;
  }



 void resetissue()
  {
   issue=0;
  }


void updateissue()
   {issue=1;
   }


  int retissue()
    { return issue;
    }

  void getstbno(long t)
  {
   stbno=t;
  }


};
///////////////////////////////////////////////////////////////////////


char ans;
fstream fb,fs,temp,temp1,file;
book b1,b2;
student s1,s2;

void display_all_books();

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


void create_book()
{   clrscr();
    fb.open("book.dat",ios::out|ios::binary);
	 do
	     {
		  b1.getdata();
		  fb.write((char*)&b1,sizeof(b1));
		   cout<<"do want to enter another book record?(y/n)"<<endl;
		  cin>>ans;
	      }while(ans=='y'||ans=='Y');
      fb.close();
}


void create_student()
{
    fs.open("student.dat",ios::out|ios::binary);
	 do
	     {
		  s1.getdata();
		  fs.write((char*)&s1,sizeof(s1));
		   cout<<"do want to enter another student record?(y/n)"<<endl;
		  cin>>ans;
	      }while(ans=='y'||ans=='Y');
      fs.close();
}
void display_all_books()
{

long n;
 cout<<"     BOOK DETAILS       "<<endl;
 fb.open("book.dat",ios::in|ios::binary);
 while(fb.read((char*)&b1,sizeof(b1)))
 {
   b1.mydisplay();
   cout<<endl;
 }
 fb.close();
 getch();
}
void stud_display_all_books()
{

long n;
 cout<<"     STUDENT DETAILS       "<<endl;
 fs.open("student.dat",ios::in|ios::binary);
 while(fs.read((char*)&s1,sizeof(s1)))
 {
   s1.mydisplays();
   cout<<endl;
 }
 fs.close();
 getch();
}

void display_book()
{ clrscr();
 long n;
 cout<<"ENTER BOOK NUMBER"<<endl;
 cin>>n;
 cout<<"     BOOK DETAILS       "<<endl;
 int flag=0;
 fb.open("book.dat",ios::in|ios::binary);
 while(fb.read((char*)&b1,sizeof(b1)))
 {
  if(b1.retbno()==n)
  {
   b1.display();
   flag=1;
  }
 }
 fb.close();
 if(flag==0)
 {
  cout<<" BOOK IS NOT PRESENT IN THE LIBRARY "<<endl;
 }
 getch();
}



void display_student()
{ clrscr();
 long n;
 cout<<"ENTER ADMISSION NUMBER OF STUDENT"<<endl;
 cin>>n;
 cout<<"     STUDENT DETAILS        "<<endl;
 int flag=0;
 fs.open("student.dat",ios::in|ios::binary);
 while(fs.read((char*)&s1,sizeof(s1)))
 {
  if(s1.retadmno()==n)
  {
   s1.display();
   flag=1;
  }
 }
 fs.close();
 if(flag==0)
 {
  cout<<" STUDENT RECORD NOT PRESENT "<<endl;
 }
 getch();
}


////////////////////////////////////////////////////////////////////////////


void modify_book()
{
 long n;
 int found=0;
 clrscr();
 cout<< "   MODIFY LIBRARY BOOK RECORD   "<<endl;
 cout<<" ENTER THE BOOK NUMBER TO EDIT "<<endl;
 cin>>n;
 fb.open("book.dat",ios::in|ios::binary);
 temp.open("new.dat",ios::out|ios::binary);
 while(fb.read((char*)&b2,sizeof(b2)))
   {
      if(b2.retbno()==n)
	 {
	     cout<<"ENTER NEW DETAILS\n";
	     b2.getdata();
               found=1;
           cout<<"     RECORD UPDATED          "<<endl;
          }
	 temp.write((char*)&b2,sizeof(b2));


    }
	  temp.close();
	  fb.close();
	  remove("book.dat");
	  rename("new.dat","book.dat");


 if(found==0)
 {
  cout<<" RECORD NOT FOUND "<<endl;
 }
 getch();
}



void modify_student()
{
 long n;
 int found=0;
 clrscr();
 cout<< "   MODIFY STUDENT RECORD   "<<endl;
 cout<<" ENTER THE ADMISSION NUMBER OF THE STUDENT "<<endl;
 cin>>n;
 fs.open("student.dat",ios::in|ios::binary);
 temp.open("new.dat",ios::out|ios::binary);
 while(fs.read((char*)&s2,sizeof(s2)))
   {
      if(s2.retadmno()==n)
	 {
	     cout<<"ENTER NEW DETAILS\n";
	     s2.getdata();
	     cout<<"     RECORD UPDATED          "<<endl;
              found=1;
	 }
	 temp.write((char*)&s2,sizeof(s2));

   }
	  temp.close();
	  fs.close();
	  remove("student.dat");
	  rename("new.dat","student.dat");


 if(found==0)
 {
  cout<<" RECORD NOT FOUND "<<endl;
 }
 getch();
}


/////////////////////////////////////////////////////////////////////////////

void delete_book()
{  int flag=0;
  fb.open("book.dat",ios::in|ios::binary);
  temp.open("new.dat",ios::out|ios::binary);

 long d;
 clrscr();
 cout<<"    DELETE BOOK RECORD   "<<endl;
 cout<<" ENTER THE NUMBER OF THE BOOK TO BE DELETED "<<endl;
 cin>>d;
 fb.seekg(0);
    while(fb.read((char*)&b2,sizeof(b2)))
       {
	  if(d!=b2.retbno())
	  {
		 cout<<" BOOK NUMBER is "<<d<<endl;
		 temp.write((char*)&b2,sizeof(b2));
		}
	    }
 temp.close();
 fb.close();
 cout<<"Before updating the records"<<endl;
 display_all_books();
 remove("book.dat");
 rename("new.dat","book.dat");
 cout<<"After updating the records"<<endl;
 display_all_books();
 if(flag==0)
    cout<<"      RECORD DELETED      "<<endl;

 getch();
}


void delete_student()
{
   int flag=0;
  fs.open("student.dat",ios::in|ios::binary);
  temp.open("new.dat",ios::out|ios::binary);

 long d;
 clrscr();
 cout<<"    DELETE STUDENT RECORD   "<<endl;
 cout<<"ENTER THE ADMISSION NUMBER OF THE STUDENT "<<endl;
 cin>>d;
 fs.seekg(0);
    while(fs.read((char*)&s2,sizeof(s2)))
       {
	  if(d!=s2.retadmno())
	  {  cout<<" ADMISION NUMBER is "<<d<<endl;
		 temp.write((char*)&s2,sizeof(s2));
      }
	   }

 temp.close();
 fs.close();
 cout<<"Before updating the records"<<endl;
 stud_display_all_books();
 remove("student.dat");
 rename("new.dat","student.dat");
 cout<<"After updating the records"<<endl;
 stud_display_all_books() ;
  if(flag==0)
    { cout<<"      RECORD DELETED      "<<endl;}



 getch();
}

//////////////////////////////////////////////////////////////////////////////.

void search_no()
{

    long bno;
    fb.open("book.dat",ios::in|ios::binary);
    cout<<"ENTER BOOK NUMBER TO SEARCH"<<endl;
    cin>>bno;
     while(fb.read((char*)&b1,sizeof(b1)))
       {
	   if(b1.retbno()==bno)
	      {
		 b1.display();
	      }
       }
 }



void count_date()

{
   int cnt=0,date,month;
     cout<<"ENTER DATE TO COUNT";
      cin>>date;
      cout<<endl;
     cout<<"MONTH TO COUNT";
     cin>>month;

   fb.open("book.dat",ios::in|ios::binary);
    while(fb.read((char*)&b1,sizeof(b1)))
      {


	 if(b1.retdi()==date&&b1.retmi()==month)
	    ++cnt;


       }
   fb.close();

   cout<<"NUMBER OF BOOKS ISSUED ON- "<<date<<"/"<<month<<"/"<<"2015 IS "<<cnt;
}



void count_search()
{
  int cnt=0,flag=0;
   char bname[30];
    cout<<"ENTER BOOK NAME TO SEARCH"<<endl;
    gets(bname);
   fb.open("book.dat",ios::in|ios::binary);
     while(fb.read((char*)&b1,sizeof(b1)))
	  {
	      if(b1.retname(bname)==1)
		   {flag=1;
			++cnt;
		    }

	   }
    fb.close();

      if(flag==1)
	 { cout<<"BOOK WITH THE NAME "<<bname<<" EXIST"<<endl;
	   cout<<"NUMBER OF BOOKS WITH THE NAME "<<bname<<" IS "<<cnt;
	  }
       else

	  { cout<<"BOOK WITH NAME "<<bname<<" DOES NOT EXIST";
	  }

 }


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


void book_issue()
{
 long studno, bookno;
 int found=0, flag=0;
 clrscr();
 cout<<" BOOK ISSUE DEPARTMENT   "<<endl;

 cout<<" ENTER THE ADMISSION NUMBER OF THE STUDENT  "<<endl;
 cin>>studno;
 cout<<" ENTER THE BOOK NUMBER "<<endl;
 cin>>bookno;

temp.open("new.dat",ios::out|ios::binary);
file.open("fresh.dat",ios::out|ios::binary);
fs.open("student.dat",ios::in|ios::binary);
	while(fs.read((char*)&s1,sizeof(s1)))
	{
		 if(s1.retadmno()==studno)
			{
			  found=1;


			if(s1.retissue()==0)

			flag=1;


			}

    }

    fs.close();
	if(found==0)
{cout<<"STUDENT NOT FOUND";
 cout<<endl;
   return;}

if (flag==0)
{cout<<"YOU HAVE NOT RETURNED THE PREVIOUS BOOK. PLEASE RETURN THAT FIRST";
cout<<endl;
return;}



fb.open("book.dat",ios::in|ios::out|ios::binary);

       while(fb.read((char*)&b1,sizeof(b1)))
	    {
	      if(b1.retstatus()==0&&b1.retbno()==bookno)

			{
			    b1.display();
			    cout<<endl;



			cout<<" PLEASE ENTER THE DATE AND MONTH OF ISSUE "<<endl;
		        b1.getdateissue();
		        b1.updatestatus();
		        cout<<endl;
			}


		   temp.write((char*)&b1,sizeof(b1));

	    }

       temp.close();
      fb.close();
      remove("book.dat");
      rename("new.dat","book.dat");


		 fs.open("student.dat",ios::in|ios::out|ios::binary);
		   while(fs.read((char*)&s1,sizeof(s1)))
		       {
			     if(s1.retadmno()==studno&&s1.retissue()==0)
				   s1.updateissue();
			      file.write((char*)&s1,sizeof(s1));
			   }
		  fs.close();
		  file.close();
		  remove("student.dat");
		  rename("fresh.dat","student.dat");

	   cout<<"           THANKYOU!!                        "<<endl;


}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void book_deposit()
{


 long studno;
 long bookno;

 clrscr();
 cout<<" BOOK DEPOSIT DEPARTMENT   "<<endl;
 cout<<" ENTER THE ADMISSION NUMBER OF THE STUDENT  "<<endl;
 cin>>studno;
 fs.open("student.dat",ios::in|ios::out|ios::binary);
 fb.open("book.dat",ios::in|ios::out|ios::binary);
 temp.open("new.dat",ios::out|ios::binary);
  file.open("fresh.dat",ios::out|ios::binary);
  temp1.open("new1.dat",ios::out|ios::binary);
	 while(fs.read((char*)&s1,sizeof(s1)))
	 {
		if(s1.retadmno()==studno&&s1.retissue()==1)
		{



				cout<<" ENTER THE BOOK NUMBER "<<endl;
				cin>>bookno;
				s1.resetissue();


		}
		temp.write((char*)&s1,sizeof(s1));

	  }
	      fs.close();
	     temp.close();
		  remove("student.dat");
		  rename("new.dat","student.dat");




		while(fb.read((char*)&b1,sizeof(b1)))
		       {
			       if(b1.retbno()==bookno)
					  b1.getdatedeposit();
				  file.write((char*)&b1,sizeof(b1));
			   }


	     file.close();
	     fb.close();
	     remove("book.dat");
	     rename("fresh.dat","book.dat");




	fb.open("book.dat",ios::in|ios::out|ios::binary);


	  while(fb.read((char*)&b1,sizeof(b1)))
		       {

					 if(b1.retbno()==bookno)
						 {


						     if(b1.retmi()==b1.retmr())
								{
								  if(b1.retdr()>(b1.retdi()+3))
								  cout<<"FINE OF RS.10 TO BE GIVEN"<<endl;

								}

							 else

								  cout<<"FINE OF RS.50 TO BE GIVEN"<<endl;



							b1.resetstatus();
						 }
						temp1.write((char*)&b1,sizeof(b1));
			   }
			   fb.close();
			   temp1.close();
			   remove("book.dat");
			   rename("new1.dat","book.dat");

			   cout<<endl;

								 cout<<" BOOK DEPOSITED SUCCESSFULLY "<<endl;

						  cout<<endl;
 getch();


}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////





void admin_menu ()
{
 clrscr();
 int ch1,ch2,choice;
 cout<<"					                                                                 "<<endl ;
 cout<<"		          ADMINISTRATOR MENU                                                 "<<endl;

 cout<<"                  1. STUDENT                                                         "<<endl;
 cout<<"                  2. BOOK        						                             "<<endl;
 cout<<"     	          3. RETURN TO MAIN MENU	                                         "<<endl;
 cout<<" ENTER CHOICE" <<endl;
 cin>>choice;
  switch(choice)
  { case 1:    clrscr();
		cout<<"               1. CREATE STUDENT RECORD                                         "<<endl;

		cout<<"               2. DISPLAY STUDENT RECORD                                         "<<endl;

		cout<<"     	      3. MODIFY STUDENT RECORD                                          "<<endl;

		cout<<"      	      4. DELETE STUDENT RECORD                                           "<<endl;


		 cout<<"         ENTER YOUR CHOICE :                     "<<endl;
		 cin>>ch2;
		 switch(ch2)
			 {
			  case 1:
				 {
					clrscr();
					create_student();
					break;
				}

			case 2:
				{
					 clrscr();
					display_student();
					 break;
				 }

			case 3:
				{
				  clrscr();
				 modify_student();
				 break;
				}

			case 4:
				{
				clrscr();
				 delete_student();
				break;
				 }
			    }
    break;



    case 2:  clrscr();
	     cout<<"              1. CREATE BOOK RECORD                                            "<<endl;
	     cout<<"              2. DISPLAY BOOK RECORD                                           "<<endl;
	     cout<<"	          3. MODIFY BOOK RECORD                                            "<<endl;
	     cout<<"              4. DELETE BOOK RECORD                                            "<<endl;
	     cout<<"	          5. COUNT NUMBER OF BOOKS ISSUED ON A PARTICULAR DATE             "<<endl;
	     cout<<"	          6. SEARCH BOOK ON THE BASIS OF BOOK NAME	     	           "<<endl;
	     cout<<"	          7. SEARCH  AND COUNT BOOK ON THE BASIS OF BOOK NUMBER	           "<<endl;
 cout<<"ENTER CHOICE"<<endl;
 cin>>ch1;
	switch(ch1)
	   {  case 1:
		 {
		   clrscr();
		   create_book();
		   break;
		}

	    case 2:
		 {
		  clrscr();
		  display_book();
		  break;
		}

	   case 3:
		 {
		  clrscr();
		  modify_book();
		  break;
		}

	case 4:
	      {
		clrscr();
		delete_book();
		break;
	     }
	case 5:
	    {
		clrscr();
		count_date();
		break;
	    }
	case 6:
	    {
		clrscr();
		count_search();
		 break;
	    }
	case 7:
	    {
		clrscr();
		search_no();
		break;
	    }
	  }
    break;


	case 3:
	 {
	 return;

	 }
	default:
	{
	 cout<<" ENTER A VALID CHOICE "<<endl;
	}
    }
}
void main()
{ char opt;
 int ch,ch2,am;
 do
 {
  clrscr();
  cout<<"||--------------------------------------||"<<endl;
  cout<<"||             MAIN MENU                ||"<<endl;
  cout<<"||--------------------------------------||"<<endl;
  cout<<"||            1. ADMINISTRATOR MENU     ||"<<endl;
  cout<<"||            2. BOOK ISSUE             ||"<<endl;
  cout<<"||            3. BOOK DEPOSIT           ||"<<endl;
  cout<<"||            4. EXIT                   ||"<<endl;
  cout<<"||--------------------------------------||"<<endl;
  cout<<"||------------------------------------- ||"<<endl;

  cout<<" ENTER YOUR CHOICE "<<endl;
  cin>>ch;

  switch(ch)
  {
   case 1:

    clrscr();
    admin_menu();
    break;

   case 2:

    clrscr();
    book_issue();
    break;

   case 3:

    clrscr();
    book_deposit();
    break;

   case 4:

    exit(0);

   default:
   {
    cout<<" ENTER A VALID CHOICE "<<endl;
   }
  }
  cout<<endl;
  cout<<" DO YOU WANT TO CONTINUE ?";
  cout<<endl;
  cin>>opt;
 } while(opt=='y'||opt=='Y');
 getch();
}
