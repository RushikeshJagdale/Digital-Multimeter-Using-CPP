// Digital Multimeter Using CPP

Executable CODE:
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
class multimeter{
private:
double volt, curr, res,buzzer, array_res[], array_volt[];// Define Variables required for the object
public:
multimeter()//Default Constructor
{
volt = 0;
curr = 0;
res = 0;
buzzer = 0;
}
///////////////////////////////// GRAPHICS FUNCTIONS /////////////////////////////////////////////
void draw()
{
initwindow(900,900);
setcolor(GREEN);
rectangle(400,150,650,650);// Outer Rectangle for Multimeter
setfillstyle(SOLID_FILL,YELLOW);
floodfill(500,500,GREEN);
rectangle(405,155,645,645);// Inner Rectangle for Multimeter
setfillstyle(SOLID_FILL,DARKGRAY);
floodfill(500,500,GREEN);
rectangle(410,160,640,310);//Rectangle for LED Display
setfillstyle(SOLID_FILL,BLACK);
floodfill(500,200,GREEN);
circle(525,500,75);//Circle for Rotary Dial
setfillstyle(SOLID_FILL,RED);
floodfill(525,500,GREEN);
rectangle(523,425,528,500);//Rectangle for Rotary Dial
setfillstyle(XHATCH_FILL,RED);
floodfill(525,450,GREEN);
rectangle(410,330,450,350);//Rectangle for Row 1 Button 1 (POWER Button)
setfillstyle(SOLID_FILL,YELLOW);
floodfill(420,340,GREEN);
rectangle(470,330,510,350);//Rectangle for Row 1 Button 2
setfillstyle(SOLID_FILL,RED);
floodfill(480,340,GREEN);
rectangle(530,330,570,350);//Rectangle for Row 1 Button 3
setfillstyle(SOLID_FILL,RED);
floodfill(540,340,GREEN);
rectangle(590,330,630,350);//Rectangle for Row 1 Button 4
setfillstyle(SOLID_FILL,RED);
floodfill(610,340,GREEN);
circle(430,390,10);
setfillstyle(SOLID_FILL,RED);
floodfill(430,390,GREEN);
rectangle(470,380,510,400);//Rectangle for Row 2 Button 1
setfillstyle(SOLID_FILL,RED);
floodfill(480,390,GREEN);
rectangle(530,380,570,400);//Rectangle for Row 2 Button 2
setfillstyle(SOLID_FILL,RED);
floodfill(540,390,GREEN);
rectangle(590,380,630,400);//Rectangle for Row 2 Button 3
setfillstyle(SOLID_FILL,RED);
floodfill(610,390,GREEN);
circle(430,620,10);//Circle for Port 1
setfillstyle(SOLID_FILL,RED);
floodfill(430,620,GREEN);
circle(493,620,10);//Circle for Port 2
setfillstyle(SOLID_FILL,RED);
floodfill(493,620,GREEN);
circle(556,620,10);//Circle for Port 3
setfillstyle(CLOSE_DOT_FILL,RED);
floodfill(556,620,GREEN);
circle(619,620,10);//Circle for Port 4
setfillstyle(SOLID_FILL,RED);
floodfill(619,620,GREEN);
while (!kbhit())
{
delay(200);
if (GetKeyState(VK_LBUTTON))
{
// line(410,250,640,250);
settextstyle(1,0,6);//Display Reading upon Left Mouse Button Click
outtextxy(430,200,"250.0");
}
if (GetKeyState(VK_SPACE))
{
setfillstyle(SOLID_FILL,BLUE);
floodfill(430,390,GREEN);
delay(2000);
}
}
closegraph();
}
//////////////////////////////////// DIFFERENT CUSTOM FUNCTIONS //////////////////////////////////////////////
double continuity()//Custom Function to Check Continuity Test
{
double p,q;
p = get_volt();
q = get_curr();
if(p==0 ||q == 0)
{
cout<<"\n The Circuit Passes in Continuity Test and Buzzer = "<<!buzzer;
PlaySound("C:/Windows/Media/buzz.wav",NULL,SND_FILENAME| SND_SYNC);
}
else
{
cout<<"\n The Circuit Fails in Continuity Test";
}
return 0;
}
double resistance()//Custom Function to calculate Resistance
{
res = volt / curr;
return res;
}
double voltage()// Custom Function to calculate Voltage
{
volt = res * curr;
return volt;
}
double current()// Custom function to calculate Current
{
curr = volt / res;
return curr;
}
double Average_voltage()// Custom Function for Calculating Average Volatge Value using Array
{
double total = 0.0,avg, temp;//Define variable for holding temporary data and total value
cout<<"\n Enter 5 Voltage Values:- "<<endl;
for(int i=0;i<5;i++)
{
cin>>array_volt[i];//Get the Voltage input from the User and store it in array
}
for(int i=0;i<5;i++)
{
total = array_volt[i] + total;//Calculate total of the voltages
}
avg = total/5;
cout<<"\nAverage Volatge Value is: "<<avg<<" Volts";//Display the Average Value
}
double Average_resistance()// Custom Function for Calculating Average Resistance Value using Array
{
double total = 0.0,avg, temp;//Define variable for holding temporary data and total value
cout<<"\n Enter 5 Resistance Values:- "<<endl;
for(int i=0;i<5;i++)
{
cin>>array_res[i];;//Get the Resistance input from the User and store it in array
}
for(int i=0;i<5;i++)
{
total = array_res[i] + total;//Calculate total of the resistance
}
avg = total/5;
cout<<"\nAverage Resistance Value is: "<<avg<<" Ohms";//Display the Average Value
}
void write_file()
{
ofstream myfile;
myfile.open ("Manipulate.txt", ios::out | ios::app);
myfile << "\nWriting the Measured Values to the file"<<endl;
myfile << "The Resistance measured: "<<res<<endl;// Write the Measured Resistance Values to Text file
myfile << "The Voltage measured: "<<volt<<endl;// Write the Measured Volatge Values to Text file
myfile.close();
}
void read_file()
{
ifstream infile;
string STRING;
infile.open ("Help.txt",ios::in);
while(!infile.eof())// To get you all the lines.
{
getline(infile,STRING);// Saves the line in STRING.
cout<<STRING<<"\n\n";// Prints our STRING.
}
infile.close();
}
///////////////////////////////////// FUNCTION OVERLOADING ////////////////////////////////////////////
double voltage(double r, double c)//Custom Function to calculate Voltage
{
double volt;
volt = r * c;
cout<<"\n The Measured Voltage of the circuit using function overloading : "<<volt<<endl;
}
//////////////////////////////////////// ACCESSORS ////////////////////////////////////////////////////////
double get_volt()// Get the Values for Volatge from User
{
cout<<"\n Enter the Value of Voltage: ";
cin>>volt;
return volt;
}
double get_res()// Get the Values for Resistance from User
{
cout<<"\n Enter the Value of Resistance: ";
cin>>res;
return res;
}
double get_curr()// Get the Values for Current from User
{
cout<<"\n Enter the Value of Current: ";
cin>>curr;
return curr;
}
void display_volt()// Display Volatge Measured
{
cout<<"\n Voltage Measured is : "<<volt<<" Volts"<<endl;
}
void display_res()// Display Resistance Measured
{
cout<<"\n Resistance Measured is : "<<res<<" Ohms"<<endl;
}
void display_curr()
{
cout<<"\n Current Measured is : "<<curr<<" Ampere"<<endl;// Display Current Measured
}
void set_res(double x)// Set the Resistance to deafult value
{
x = volt;
}
void set_curr(double x) // Set the Current to default value
{
x = curr;
}
void set_volt(double x)// Set the voltage to deafult value
{
x = volt;
}
~multimeter()//Destructor
{
}
};
int main()
{
system("color f5");// Change the background and font color of the console window
cout<<"\t\t\t\t WELCOME"<<endl;
multimeter m1;// Declare Object to Multimeter
int choice;
do
{
cout<<"\n Menu Selection Option"<<endl<<endl;// Menu Option for Slecting the operations to be performed
cout<<"\n 1. Set all Parameterws to Zero and Read File for Multimeter Information";
cout<<"\n 2. Calculate Voltage";
cout<<"\n 3. Calculate Resistance";
cout<<"\n 4. Calculate Current";
cout<<"\n 5. Calculate Average Resistance Using Array ";
cout<<"\n 6. Calculate Average Volatge Using Array ";
cout<<"\n 7. Calculate Voltage by function overloading ";
cout<<"\n 8. Writing in file";
cout<<"\n 9. Display Graphics";
cout<<"\n 10. Continuity Test";
cout<<"\n 0. EXIT";
cout<<"\n Enter the operation to be performed by the Multimeter Class:- ";
cin>>choice;
switch(choice)
{
case 1 : m1.set_curr(0);// Set All Parameters to Zero and read the file
m1.set_volt(0);
m1.set_res(0);
cout<<"\n All the Parameters are set to Zero and the Text File is been Read "<<endl;
cout<<"\n Voltage = 0 \n Current = 0 \n Resistance = 0 \n";
m1.read_file();// Read Text File for Description of the Object
break;
case 2 : m1.get_res();
m1.get_curr();
m1.voltage();//Calculate Voltage using default function
m1.display_volt();
break;
case 3 : m1.get_curr();
m1.get_volt();
m1.resistance();// Calculate Resistance of the circuit
m1.display_res();
break;
case 4 : m1.get_res();
m1.get_volt();
m1.current();// Calculate Current of the circuit
m1.display_curr();
break;
case 5: m1.Average_resistance();// Calculation of Average Resistance Value Using Array
break;
case 6: m1.Average_voltage();// Calculation of Average Resistance Value Using Array
break;
case 7: double a ,b;
a = m1.get_res();
b = m1.get_curr();
m1.display_res();
m1.voltage(a,b);// Voltage Calculation using Function Overloading
break;
case 8: m1.get_curr();
m1.get_volt();
m1.resistance();
m1.write_file();// Writing the measured value to file
break;
case 9: m1.draw();// Display Gaphics of Multimeter
break;
case 10: m1.continuity();// Check Continuity of the circuit
break;
default: exit;
}
}while(choice!=0);
getch();
system("PAUSE");
return 0;
}
