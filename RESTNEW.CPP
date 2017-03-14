/*
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                                                  																																																																																																																				                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

		  PROJECT REPORT ON RETAURANT MANAGEMENT

  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
//HEADER  FILES DECLARATION

#include<dos.h>
#include<stdio.h>
#include<time.h>
#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
enum boolean {false,true};
   class rt
     {
       private:
	 char item[25];
	 long int code;
	 float price;
	 char avail;
      public:
	  void getdata()
	      {
		cout<<"\nENTER ITEM CODE NUMBER  : ";
		cin>>code;
		cout<<"\nENTER ITEM NAME  : ";
		cin>>item;
		cout<<"\nENTER ITEM PRICE  : ";
		cin>>price;
	       }
	void getdat1(int codei)
	       {
		  code=codei;
		  cout<<"\n\t Enter item name : ";
		  cin>>item;
		  cout<<"\n\n\t Enter item price : ";
		  cin>>price;
		   }
	void showdat1()
	    {
	    cout<<"\n\t   "<<code<<"\t\t\t"<<item<<"\t\t\t"<<price;
	    }
	void showdat2()
	    {
	    cout<<"  "<<code<<"  \t\t\t";
	    cout<<item<<"\t\t\t\t";
	    cout<<price<<"\n";
	    }

	 int findeq()
	    {
	      return code;
	     }
	 int less(int codei)
	     {
	       return(code<codei);
	     }
	 int sumcal(int sum,int q,int p)
		  {
		    return(sum+q*p);
		  }
       }rt1;

	    void creation();
	    void append(rt rt1);
	    void deletion();
	    void display();
	    void searching();
	    void sorting();
	    void modification();
	    void order();

	    void timer();
	    void MAKESOUNDTE();

// ######################################################################
//                  THIS FUNCTION IS FOR CREATION
// ######################################################################

   void creation()
   {
     char ch;
     fstream one;
     one.open("o1.dat",ios::binary|ios::out);
     cout<<"\n\n\n\n\n\t\t\t\ enter master data";
     do
	{
	  rt1.getdata();
	  one.write((char*)&rt1,sizeof(rt));
	  cout<<"Do you want more data(y/n) :";
	  cin>>ch;
	}
	 while(ch=='y');
     one.close();
   }
// #####################################################################
//                   THIS FUNCTION IS FOR DISPLAY
// #####################################################################

   void display()
    {
      cout<<"\n\n\n Information is -> ";
      cout<<"\n\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ";
      cout<<"\n\t CODE\t\t\t ITEM\t\t\t PRICE \n";
      cout<<"\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n";

    ifstream two("o1.dat",ios::binary|ios::in);
    two.read((char*)&rt1,sizeof(rt));
    do
     {
      rt1.showdat1();
      two.read((char*)&rt1,sizeof(rt));
     }while(two);
     getch();
     }

// #####################################################################
//                THIS FUNCTION IS FOR APPENDING
// #####################################################################

   void append()
 {
	 long int codei,coder;
	 fstream infile,outfile;
	 rt rt1;
	 infile.open("o1.dat",ios::in|ios::app|ios::binary);
	 cout<<"Enter code no. you want to insert : \n";
	 cin>>codei;
	 rt1.getdat1(codei);
	 infile.write((char*)&rt1,sizeof(rt));
	 infile.close();
  }


// ####################################################################
//                   THIS FUNCTION IS FOR DELETION
// ####################################################################

   void deletion()
   {
     boolean found=false;
     rt rt1;
     long int coded,coder;

     ifstream infile("o1.dat",ios::binary);
     ofstream outfile("o3.dat",ios::binary);
     cout<<"\n Enter the code number you want to delete : ";
     cin>>coded;
     infile.read((char*)&rt1,sizeof(rt));
     do
      {
     if((rt1.findeq())==coded)
	{
	 found=true;
      cout<<"\n\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ";
      cout<<"\n\t   CODE\t\t\t ITEM\t\t\t PRICE \n";
      cout<<"\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n";
      rt1.showdat1();
	}
	 else
	   outfile.write((char*)&rt1,sizeof(rt));
	   infile.read((char*)&rt1,sizeof(rt));
     } while(infile);
     if(found==true)
	cout<<"\n The record was found and deleted.";
      else
	cout<<"Record for code number"<<coded<<" not found";
      infile.close();
      outfile.close();
      ifstream i1f("o3.dat",ios::binary);
      ofstream o2f("o1.dat",ios::binary);
      i1f.read((char*)&rt1,sizeof(rt));
      do
       {
	  o2f.write((char*)&rt1,sizeof(rt));
	  i1f.read((char*)&rt1,sizeof(rt));
       }
       while(i1f);
      i1f.close();
      o2f.close();
      }

// #####################################################################
//                 THIS FUNCTION IS FOR SEARCHING
// #####################################################################

   void searching()
 {
   char ch;
   boolean found=false;
   rt rt1;
   long int codes,coder;
   fstream infile;
   infile.open("o1.dat",ios::in);
   clrscr();
   cout<<"\n Enter the code number you want to search : ";
   cin>>codes;
   infile.read((char*)&rt1,sizeof(rt));
   while(!infile.eof())
    {
     if((rt1.findeq()) == codes)
       {
       found=true;
       cout<<"\n Item with code no."<<codes<<" is found";
       cout<<"\n \t\tItem Detail";
      cout<<"\n\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ";
      cout<<"\n\t   CODE\t\t\t ITEM\t\t\t PRICE \n";
      cout<<"\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n";

      rt1.showdat1();
      return;
     }
     else
      infile.read((char*)&rt1,sizeof(rt));
    }
     if (found==false)
       cout<<"\n The item is not found...";
    infile.close();
   }

// #####################################################################
//              THIS FUNCTION IS FOR MODIFICATION
// #####################################################################

   void modification()
    {
     boolean found=false;
     rt rt1;
     long int coded,coder;
     fstream infile,outfile;
     infile.open("o1.dat",ios::in|ios::binary);
     outfile.open("o2.dat",ios::out|ios::binary);
     cout<<"\n Enter the code number you want to update : ";
     cin>>coded;
     infile.read((char*)&rt1,sizeof(rt));
     while(!infile.eof() && rt1.findeq()<coded)
       {
	  outfile.write((char*)&rt1,sizeof(rt));
	  infile.read((char*)&rt1,sizeof(rt));
      }

       if(rt1.findeq() == coded)
	 {
	  found=true;
	  rt1.getdat1(coded);
	  outfile.write((char*)&rt1,sizeof(rt));
	 }
       infile.read((char*)&rt1,sizeof(rt));
       while(!infile.eof())
       {
       outfile.write((char*)&rt1,sizeof(rt));
       infile.read((char*)&rt1,sizeof(rt));
	}
       if(found)
	  cout<<"\n The record was found and updated.";
       if(!found)
	  cout<<"Record for code number"<<coded<<"not found";
       infile.close();
       outfile.close();
       ifstream of1("o2.dat",ios::in|ios::binary);
       of1.read((char*)&rt1,sizeof(rt));
      cout<<"\n\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ";
      cout<<"\n\t   CODE\t\t\t ITEM\t\t\t PRICE \n";
      cout<<"\t þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n";

    do
     {
      rt1.showdat1();
      of1.read((char*)&rt1,sizeof(rt));
     } while(of1);
     getch();
   }

// ####################################################################
//                  THIS FUNCTION IS FOR ORDER
// ####################################################################

  void order()
   {
   rt rt1;
   char tch='n';
     int c,q,p;
   cout<<"\t\t\t\t  MENU CARD\n\n";
cout<<"ÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈ\n";
cout<<"  CODE\t\t\tITEM    \t\t\t  PRICE\n";
cout<<"ÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈÈ\n";
    int sum=0;
    ifstream two("o1.dat",ios::binary|ios::in);
    two.read((char*)&rt1,sizeof(rt));

    do
     {

      rt1.showdat2();
      two.read((char*)&rt1,sizeof(rt));
      }while(two);
     int fl2=0;
     refer:ifstream t3("o1.dat",ios::binary|ios::in);
	   t3.read((char*)&rt1,sizeof(rt));
	   cout<<"\n\n\n\n\n ENTER YOUR  CODE= ";
	   cin>>c;
	  do
	    {
	     if(c==rt1.findeq())
	       {
		fl2=1;
		rt1.showdat1();
		cout<<"\nprice is Rs. = ";
		cin>>p;
		cout<<" ENTER NUMBERS OF PLATE : ";
		cin>>q;
		break;
	       }
	     else
	       t3.read((char*)&rt1,sizeof(rt));
	   }while(t3);
     sum=rt1.sumcal(sum,q,p);
     cout<<"do you want to enter more deshes (y/n)  ";
     cin>>tch;
     if (tch!='n') goto refer;
       if (fl2==1)
	 {
	 cout<<"\n order has been placed \n";
	 }
      else
	{
	 cout<<"code not found\n";
	}
       cout<<"\ntotal bill ="<<sum;
       getch();

// #####################################################################
// INDIVIDUAL FUNCTION USED TO CALCULATE TOTAL BILL AND DISPLAY IT.
//                FOR ORDER AND BILLING
// #####################################################################
   clrscr();
   cout<<"\n\n\n\n\t\t\tplease enter date and month (d/m):";
   char sd[10];
   cin>>sd;
   float bg,ba,y,g;
   cout<<"\n\tTotal Bill is : Rs "<<sum;
   cout<<"\n\tEnter the amount tendered by guest : Rs ";
   cin>>bg;
   ba=bg-sum;
   clrscr();
   cout<<"\n\n\t\t\t  JALSA RESTAURANT ";
   cout<<"\n\n\t\t\t\tCASH MEMO";
   struct date d;
    getdate(&d);
    cout<<"\n    DATE <";
    cout<<sd<<"/"<<d.da_year<<">\n";
cout<<"   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n";
cout<<"     Code No.\tÛ\tPrice\tÛ\tQty.\tÛ\tTotal\n";
cout<<"   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n";
cout<<"\t"<<c<<"\t\t"<<p<<"\t\t"<<q<<"\t\t"<<sum<<endl;
cout<<"\n\n\n\n\n\n\t\t\t\t\t     Grand Total : Rs "<<sum;
cout<<"\n\t\t\t\tAmount tendered by guest : Rs "<<bg;
cout<<"\n\t\t\t\t\t  Balance Amount : Rs "<<ba;
getch();
//
delay(100);
clrscr();
timer();
cout<<"\t\t ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
cout<<"\t\t º         OVERALL BILL = Rs "<<sum;
gotoxy(64,3);
    cout<<" º"<<endl;
	   g=(sum)*(0.025);
cout<<"\t\t º         SALES TAX    = Rs "<<g;
gotoxy(64,4);
    cout<<" º"<<endl;
    sum=sum+g;
cout<<"\t\t º         TOTAL BILL   = Rs "<<sum;
gotoxy(64,4);
    cout<<" º"<<endl;
  b :
  gotoxy(17,5);
  clreol();
    cout<<" º    AMOUNT TENDERED BY THE GUEST : Rs ";
	   cin>>bg;
	   y=bg;
	   if(y<=0)

	   goto b;
	   if(y<sum)
	    {
	     gotoxy(17,5);
	     clreol();
	     cout<<" --> AMOUNT TENDERED IS LESS THAN THE TOTAL BILL ! <--";
	     getch();
	     gotoxy(17,6);
	     clreol();
	     cout<<" *-*   PLEASE ENTER AGAIN *-* ";
	     getch();
	     goto b;
	    }
	   else
	    {
	     gotoxy(64,5);
	     cout<<" º"<<endl;
	     cout<<"\t\t º    BALANCE AMOUNT RETURNED      : Rs "<<y-sum;
	     gotoxy(64,6);
	     cout<<" º";
	     cout<<"\n\t\t ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	     cout<<endl;
	     gotoxy(17,23);
	     cout<<"  Press Any Key Continue ... ";
	     getch();
	     clrscr();
	     cout<<"\n\n";
	     cout<<"\t\t ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
	     cout<<"\t\t º         THANKS FOR VISITING JALSA'S !        º"<<endl;
	     cout<<"\t\t ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
	     cout<<endl<<endl<<endl<<endl<<endl;

	     cout<<"\n\n\n Press Any Key Continue ... ";
	     cout<<"\n\n\n\t\tHave a nice day...Thank you!";
	   }
	 getch();
}

     void MAKESOUNDTE()
     {
      int sp;
	     do
	      {
	      sound(sp);
	      sp=sp+30;
	      delay(200);
	      nosound();
	      }
	   while(sp<1000);
   }

    // INDIVIDUAL FUNCTION USED TO DISPLAY THE SYSTEM TIME.
    void timer()
       {
	 char datebuf[9];
	 _strdate(datebuf);
	 printf("Date : %s ",datebuf);
	 cout<<"                CASHIER : ABCD"<<endl;
       }

  int main()
     {

       long int code,codei;
       int choice;
       clrscr();




	    gotoxy(23,24);
	 cout<<"Jalsa\tThe land of food";

	 delay(5000);




	 clrscr();
   do
   {

	   clrscr();
	  textbackground(YELLOW);
	  textcolor(WHITE);
	  delay(100);
	 cout<<"\n\n\n";
	 cout<<"\t\t     ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"<<endl;
	 cout<<"\t\t     º          MAIN MENU             º"<<endl;
	 cout<<"\t\t     ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
	 cout<<"\t\t     º                                º"<<endl;
	 cout<<"\t\t     º     1.CREATION OF ITEM         º"<<endl;
	 cout<<"\t\t     º     2.APPEND (ADD ITEM)        º"<<endl;
	 cout<<"\t\t     º     3.VIEW LIST ITEM           º"<<endl;
	 cout<<"\t\t     º     4.SEARCHING                º"<<endl;
	 cout<<"\t\t     º     5.DELETE ITEMS             º"<<endl;
	 cout<<"\t\t     º     6.MODIFICATION             º"<<endl;
	 cout<<"\t\t     º     7.ORDER AND BILL           º"<<endl;
	 cout<<"\t\t     º     8.EXIT                     º"<<endl;
	 cout<<"\t\t     º                                º"<<endl;
	 cout<<"\t\t     ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹"<<endl;
	 cout<<"\t\t     º    ENTER YOUR CHOICE :         º"<<endl;
	 cout<<"\t\t     ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"<<endl;
	 gotoxy(47,18);
	 cin>>choice;
	 clrscr();
	 switch(choice)
	  {
	  case 1:

		  clrscr();
		  creation();
		  break;

	  case 2:
		  textbackground(BLACK);
		  textcolor(CYAN);
		  clrscr();
		  append();
		  break;

	  case 3:
		  textbackground(MAGENTA);
		  textcolor(WHITE);
		  clrscr();
		  display();
		  getch();
		  break;

	  case 4:
		  textbackground(LIGHTGREEN);
		  textcolor(BLACK);
		  searching();
		  getch();
		  break;

	  case 5:
		  textbackground(BLACK);
		  textcolor(YELLOW);
		  deletion();
		  getch();
		  break;

	  case 6:
		  textbackground(BLACK);
		  textcolor(BROWN);
		  clrscr();
		  modification();
		  getch();
		  break;

	  case 7:
		  textbackground(MAGENTA);
		  textcolor(CYAN);
		  clrscr();
		  order();
		  getch();
		  break;

	  case 8:
		  exit(0);
		  break;

	  default: cout<<"INVALID OPTION \n";
	 }
   }
	while(choice<8);
	return 0;
  }













