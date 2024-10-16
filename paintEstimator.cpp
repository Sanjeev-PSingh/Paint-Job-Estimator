/*
	Sanjeev Singh

	paintEstimator.cpp

	Take input for price per gallon of paint and number of room to be painted and 
	the square footage of each room the displays the 
	number of gallons needed to paint, the cost of the paint, 
	the hours of labour required, the labour charges and the total cost.

*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototyes
double getPricePerGallon();
int getRooms();
int calcWallSpace(int);
void calcPaint(int, double, int&, double&);
void calcLabour(double, double&, double&);

//Variables

double sqrFeet;
int gallons;
double priceofpaint;
double hours;
double costoflabour;
double total;

int main()
{
	cout << "Paint Job Estimator ...\n";
	cout << "\n";
	double pricePaint = getPricePerGallon();
	int rooms = getRooms();
	sqrFeet = calcWallSpace(rooms);
	cout << "\n";
	cout << "        Paint Job Estimate\n";
	cout << "\n";
	cout << "Paint ...\n";
	calcPaint(sqrFeet, pricePaint, gallons, priceofpaint);
	cout << "Gallons of paint:        " << gallons << endl;
	cout << "Cost of Paint:           $ " << priceofpaint << endl;
	cout << "\n";
	calcLabour(sqrFeet, hours, costoflabour);
	cout << "Labor ...\n";
	cout << "Hours of Labor:          " << hours << endl;
	cout << "Cost of Labor:           $ " << costoflabour << endl;
	total = costoflabour + priceofpaint;
	cout << "                         ----------" << endl;;
	cout << "Total Cost:              $ " << total << endl;
}

// Finds price per gallon of paint
double getPricePerGallon()
{
	double Pricepergal;
	do
	{
		cout << "Price per gallon of paint (>=0): ";
		cin >> Pricepergal;
		if (Pricepergal < 0)
		{
			cout << "Error ... Invalid price per gallon of paint. Try again.\n";
		}
	} while (Pricepergal < 0);
	cout << "\n";
	
	return Pricepergal;
}

// Finds the number of rooms to be painted
int getRooms()
{
	int rooms;
	do
	{
		cout << "Number of rooms to be painted (>=1): ";
		cin >> rooms;
		if (rooms < 1)
		{
			cout << "Error ... Invalid number of rooms. Try again.\n";
		}
	} while (rooms < 1);

	cout << "\n";
	return rooms;
}

// Calculates the total number of square feet to be painted
int calcWallSpace(int rooms)
{
	double sqrfeet = 0;
	double sqrfeet1;

	cout << "Square feet of wall space (>=25)" << endl;
	
	for (int c = 1; c < rooms + 1; c++) {
		cout << "        Room " << c << ": ";
		cin >> sqrfeet1;
		while (sqrfeet1 < 25)
		{
			cout << "        Error ... Incorrect wall space for the room. Try again.\n";
			cout << "        Room " << c << ": ";
			cin >> sqrfeet1;
		}
		sqrfeet = sqrfeet + sqrfeet1;
	}

	return sqrfeet;
}

// Calculates the number of gallons of paint needed and the cost of the paint
void calcPaint(int sqrF, double Pricepaint, int& gals, double& cost)
{
	gals = (sqrF / 115) + 1;
	cost = Pricepaint * gals;

}

// Calculates the number of hours of labour and the cost of the labour
void calcLabour(double sqrF, double& hour, double& cost)
{
	double square = (sqrF / 115);
	hour = 8 * square;
	cost = hour * 25.00;
}

