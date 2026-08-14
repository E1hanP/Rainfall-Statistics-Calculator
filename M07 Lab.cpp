/*	Name: Ethan Phimmasone
	M07 Lab

Module Main
	//Declare Constant for the array size
	Declare Constant Integer SIZE = 12

	//Declare an array to hold the 12 months
	Declare Integer monthlyRainfall[12]

	//Call the function to get all user input
	Call getRainfallData(monthlyRainfall, SIZE)

	//Call the function to perform calculations and display results.
	Call calculateAndDisplay(monthlyRainfall, SIZE)
End Module

Module getRainfallData(Real rainfall[], Constant Integer size)
	Declare Integer monthIndex

    For monthIndex FROM 0 TO size - 1 
		
        Declare Real inputRain
        
        // Initial prompt
        Display "Enter the rainfall (in inches) for month #", (monthIndex + 1), ": "
        Input inputRain

        // Validation loop
        While (inputRain < 0.0)
            OUTPUT "Rainfall cannot be a negative number."
            OUTPUT "Enter a valid quantity:"
            INPUT inputRain
        End While
        
        // Storing the input in the array
        rainfall[monthIndex] = inputRain
    End For
End Module

Module calculateAndDisplay(Constant Real rainfall[], Constant Integer size)
	//Declaring variables
    Declare Real highestRain
    Declare Real lowestRain
    Declare Integer highestMonth
    Declare Integer lowestMonth
    Declare Integer index
    Declare Real totalRainfal
    Declare Real averageRainfall
    
    highestRain = rainfall[0]
    lowestRain = rainfall[0]
    highestMonth = 0
    lowestMonth = 0
    totalRainfall = rainfall[0]
    
	For index FROM 1 TO size - 1
        //Adding to total
        totalRainfall = totalRainfall + rainfall[index]

        //Finding highest rainfall
        If (rainfall[index] > highestRain) THEN
            highestRain = rainfall[index]
            highestMonth = index //Storing the index of the month
        End If

        //Finding the lowest rainfall
        If (rainfall[index] < lowestRain) THEN
            lowestRain = rainfall[index]
            lowestMonth = index //Storing the index of the month
        End If
    End For
    
    //Calculating average rainfall
    averageRainfall = totalRainfall / size
    
    //This will display the results
    
    Display "The total rainfall for the year is ", totalRainfall, " inches."
    Display "The average rainfall for the year is ", averageRainfall, " inches."
    
    Display "The largest amount of rainfall was ", highestRain, " inches in month ", (highestMonth + 1), "."
    Display "The smallest amount of rainfall was ", lowestRain, " inches in month ", (lowestMonth + 1), "."
End Module
*/

#include <iostream>

using namespace std;

void getRainfallData(double rainfall[], const int size);
void calculateAndDisplay(const double rainfall[], const int size);

int main()
{
    //Declaring Constant for the array size
    const int SIZE = 12;
    
    //Declaring an array to hold the 12 months
    double monthlyRainfall[SIZE];
    
    //Calling the function to get all user input
    getRainfallData(monthlyRainfall, SIZE);
    
    //Call the function to perform calculations and display results.
    calculateAndDisplay(monthlyRainfall, SIZE);
    
    return 0;
}

void getRainfallData(double rainfall[], const int size) 
{
    int monthIndex; 

    for (monthIndex = 0; monthIndex < size; monthIndex++)
    {
        double inputRain;
        
        // Initial prompt
        cout<<"Enter the rainfall (in inches) for month #" <<(monthIndex + 1)<<":"<<endl;
        cin>>inputRain;

        // Validation loop
        while (inputRain < 0.0) 
        {
            
            cout<<"Rainfall cannot be a negative number."<<endl;
            cout<<"Enter a valid quantity:"<<endl;
            
            cin>>inputRain;
        }
        
        //Storing the input
        rainfall[monthIndex] = inputRain;
    }
}

void calculateAndDisplay(const double rainfall[], const int size) 
{
    //Declaring variables
    double highestRain;
    double lowestRain;
    int highestMonth;
    int lowestMonth;
    int index;
    
    highestRain = rainfall[0];
    lowestRain = rainfall[0];
    
    highestMonth = 0;
    lowestMonth = 0;
    
    double totalRainfall = rainfall[0];

    for (index = 1; index < size; index++)
    {
        //Adding to total
        totalRainfall = totalRainfall + rainfall[index];

        //Finding highest rainfall
        if (rainfall[index] > highestRain)
        {
            highestRain = rainfall[index];
            highestMonth = index; //Storing the index of the month
        }

        // Finding the lowest rainfall
        if (rainfall[index] < lowestRain)
        {
            lowestRain = rainfall[index];
            lowestMonth = index; //Storing the index of the month
        }
    }
    
    // Calculating average rainfall
    double averageRainfall = totalRainfall / size;
    
    //This will display the results
    cout<<endl; //This is so we can seperate the user input and the
    			//results so it can be easily read.

    cout<<"The total rainfall for the year is "<< totalRainfall<<" inches."<<endl;
    cout<<"The average rainfall for the year is "<< averageRainfall<<" inches."<<endl;
    

    cout<<"The largest amount of rainfall was "<<highestRain<<" inches in month "<<(highestMonth + 1)<<"."<<endl;
    cout<<"The smallest amount of rainfall was "<<lowestRain<<" inches in month "<<(lowestMonth + 1)<<"." <<endl;
}