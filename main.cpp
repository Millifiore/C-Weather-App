#include "Weather.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int findIndex(string[], int, string);
string PrintVec(vector<string> );

int main(){			
  Weather Rain;																		// Objects are maid for each weather condition.
  Rain.clothing = {"Poncho", "Rain Boots", "Hat", "Rain Jacket", "Hood"};			// clothing attribute holds the strings for the clothing
  Rain.setWeather("Rain");															//Ever weather condition is also an attribute for itself.										
  Weather Snow;
  Snow.clothing = {"Snow boots", "Snow Coat", "Hat", "Long Clothing", "Gloves"};
  Snow.setWeather("Snow");
  Weather Extreme_Cold;
  Extreme_Cold.clothing = { "Snow Suit", "Winter Boots", "Winter Gloves", "Sweater", "Winter coat" };
  Extreme_Cold.setWeather("Extreme Cold");
  Weather Blizzard;
  Blizzard.clothing = { "Snowsuit","Snow Boots", "Heavy Duty Gloves", "Heatpacks", "Thermals", "Goggles", "Winter Hat", "Scarf", "Ear Warmers" };
  Blizzard.setWeather("Blizzard");
  Weather Heatwave;
  Heatwave.clothing = { "Shorts", "Sandals", "Loose Clothing", "Dress/Skirts"};
  Heatwave.setWeather("Heatwave");
  Weather Windy;
  Windy.clothing = {"Jacket", "Long Sleeve Top"};
  Windy.setWeather("Windy");
  Weather Hail;
  Hail.clothing = {"Helmet", "Caution: Try to stay inside"};
  Hail.setWeather("Hail");
  Weather Flooding;
  Flooding.clothing = {"High Water Pants","Maybe a boat"};
  Flooding.setWeather("Flooding");
  Weather Cloudy;
  Cloudy.clothing = { "Light Jacket", "Jeans", "Leggings" };
  Cloudy.setWeather("Cloudy");
  Weather Sunny;
  Sunny.clothing = {"Hat","Sunglasses","Sunscreen"};
  Sunny.setWeather("Sunny");
  Weather Chilly;
  Chilly.clothing = {"Warm Jacket", "Long Sleeve Clothes","Long Pants"};
  Chilly.setWeather("Chilly");
  Weather Weatherlist[11] = { Rain,Snow,Extreme_Cold,Blizzard,Heatwave, Windy, Hail, Flooding, Cloudy, Sunny, Chilly };

  cout << " *****************************************************************************" << endl;
  cout << " *                                                                           *" << endl;
  cout << " *                                                                           *" << endl; 
  cout << " *                   Hello and Welcome to our Weather App                    *" << endl;
  cout << " *                                                                           *" << endl;
  cout << " *                                                                           *" << endl;
  cout << " *                                                                           *" << endl;
  cout << " *****************************************************************************" << endl;

  struct Date{
  string month, day1,day2,day3;				//Structs holds the month and days that the user inputs.
  string day1W, day2W, day3W;				//holds the weather thats determined for each day.
  };

  Date info;
  Weather instance;
  tuple <string, string> day1t;				//Tuples are made so that we can connect weather conditions to their appropriate days.
  tuple <string, string> day2t;
  tuple <string, string> day3t;
  srand(5000);								// This is for the random number generator. It dictates how long rand will take to execute. (5000 = 5seconds)
  string best_weather;						// This is a varaible made to holds the most optimal weather condition chosen.

  cout << "Enter Month" << endl;			//Prompt added to get the month.
  cin >> info.month;
  cout << "----------------------------------------------" << endl;
  cout << "Enter three days of the week you would like to go out: " << endl;		//Prompts are used to ask for the tree days
  cin >> info.day1;
  cin >> info.day2;
  cin >> info.day3;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  
  if (info.month == "January" || info.month == "December" || info.month == "February" || info.month == "january" || info.month == "december" || info.month == "february"){
    const int SIZE = 5;
    string arr[SIZE] = {"Windy", "Snow" ,"Extreme Cold", "Hail", "Blizzard"}; 
    info.day1W = arr[(rand() % SIZE)];		//Chooses three random weather conditions based on the array given to us for specific months.
    info.day2W = arr[(rand() % SIZE)];
    info.day3W = arr[(rand() % SIZE)];

    day1t = make_tuple(info.day1,info.day1W); //These tuples are used to connect the day and weather associated with it. (Ex. Friday,Rain )
    day2t = make_tuple(info.day2,info.day2W);
    day3t = make_tuple(info.day3,info.day3W);
   
    int value1 = findIndex(arr, SIZE, info.day1W); // Finds the index of the weather condition chosen by rand().
    int value2 = findIndex(arr, SIZE, info.day2W);
    int value3 = findIndex(arr, SIZE, info.day3W);

    int min = std::min({value1, value2, value3});	// Chooses the least index out of all of them.
	best_weather = arr[min];						// arr[min] is saved because it represents the optimal weather condition.
    if (arr[min] == get<1>(day1t)){		// Uses if statements to check which tuple the best weather condition resides in.
      cout << get<0>(day1t) << " is the best day to go out because the weather condition " << " " << get<1>(day1t) << " is better than " << get<1>(day2t) << " and " << get<1>(day3t) << "." << endl;
	  cout << endl; //Prints day and corresponding weather.
    } 
    else if (arr[min] == get<1>(day2t)){
      cout << get<0>(day2t) << " is the best day to go out because the weather condition " << get<1>(day2t) <<" is better than " << get<1>(day1t) << " and " << get<1>(day3t) << "." << endl;
	  cout << endl;
    } 
    else{
      cout << get<0>(day3t) << " is the best day to go out because the weather condition "<< get<1>(day3t) << " is better than " << get<1>(day1t) << " and " << get<1>(day2t) << "." << endl;
	  cout << endl;
    }
  }
  if (info.month == "March" || info.month == "April" || info.month == "May" || info.month == "march" || info.month == "april" || info.month == "may"){
    const int SIZE = 4;
    string arr[SIZE] = {"Cloudy", "Windy", "Rain", "Flooding"};
    info.day1W = arr[(rand() % SIZE)];
    info.day2W = arr[(rand() % SIZE)];
    info.day3W = arr[(rand() % SIZE)];

    int value1 = findIndex(arr, SIZE, info.day1W);
    int value2 = findIndex(arr, SIZE, info.day2W);
    int value3 = findIndex(arr, SIZE, info.day3W);

    day1t = make_tuple(info.day1,info.day1W);
    day2t = make_tuple(info.day2,info.day2W);
    day3t = make_tuple(info.day3,info.day3W);

    int min = std::min({value1, value2, value3});
	best_weather = arr[min];
    if (arr[min] == get<1>(day1t)){
      cout << get<0>(day1t) << " is the best day to go out because the weather condition  " << get<1>(day1t) << " is better than " << get<1>(day2t) << " and " << get<1>(day3t) << "." << endl;
	  cout << endl;
    } 
    else if (arr[min] == get<1>(day2t)){
      cout << get<0>(day2t) << " is the best day to go out because the weather condition " << get<1>(day2t) << " is better than " << get<1>(day1t) << " and " << get<1>(day3t) << "." << endl;
      cout << endl; 
    } 
    else{
      cout << get<0>(day3t) << " is the best day to go out because the weather condition " << get<1>(day3t) << " is better than " << get<1>(day1t) << " and " << get<1>(day2t) << "." << endl;
      cout << endl;
   }
  }
  if (info.month == "June" || info.month == "July" || info.month == "August" || info.month == "june" || info.month == "july" || info.month == "august"){
    const int SIZE = 4;
    string arr[SIZE] = {"Heatwave","Rain","Sunny","Cloudy"};
    info.day1W = arr[(rand() % SIZE)];
    info.day2W = arr[(rand() % SIZE)];
    info.day3W = arr[(rand() % SIZE)];

    int value1 = findIndex(arr, SIZE, info.day1W);
    int value2 = findIndex(arr, SIZE, info.day2W);
    int value3 = findIndex(arr, SIZE, info.day3W);

    day1t = make_tuple(info.day1,info.day1W);
    day2t = make_tuple(info.day2,info.day2W);
    day3t = make_tuple(info.day3,info.day3W);
  
    int min = std::min( {value1, value2, value3});
	best_weather = arr[min];
    if (arr[min] == get<1>(day1t)){
      cout << get<0>(day1t) << " is the best day to go out because the weather condition  " << get<1>(day1t) << " is better than " << get<1>(day2t) << " and " << get<1>(day3t) << "." << endl;
      cout << endl;
    } 
    else if (arr[min] == get<1>(day2t)){
      cout << get<0>(day2t) << " is the best day to go out because the weather condition " << get<1>(day2t) << " is better than " << get<1>(day1t) << " and " << get<1>(day3t) << "." << endl;
      cout << endl;
    } 
    else{
      cout << get<0>(day3t) << " is the best day to go out because the weather condition " << get<1>(day3t) << " is better than " << get<1>(day1t) << " and " << get<1>(day2t) << "." << endl;
      cout << endl;
   }
 }
  if (info.month == "September" || info.month == "Novemeber" || info.month == "October" || info.month == "september" || info.month == "novemeber" || info.month == "october"){
    const int SIZE = 4;
    string arr[SIZE] = {"Chilly", "Windy", "Hail", "Blizzard"};
    info.day1W = arr[int(rand() % SIZE)];
    info.day2W = arr[int(rand() % SIZE)];
    info.day3W = arr[int(rand() % SIZE)];

    day1t = make_tuple(info.day1,info.day1W);
    day2t = make_tuple(info.day2,info.day2W);
    day3t = make_tuple(info.day3,info.day3W); //get<0>(geek) = 'b'; 
    int value1 = findIndex(arr, SIZE, info.day1W);
    int value2 = findIndex(arr, SIZE, info.day2W);
    int value3 = findIndex(arr, SIZE, info.day3W);
  
    int min = std::min({value1, value2, value3});
	best_weather = arr[min];
    if (arr[min] == get<1>(day1t)){
      cout << get<0>(day1t) << " is the best day to go out because the weather condition " << get<1>(day1t) << " is better than " << get<1>(day2t) << " and " << get<1>(day3t) << "." << endl;
      cout << endl;
    } 
    else if (arr[min] == get<1>(day2t)){
      cout << get<0>(day2t) << " is the best day to go out because the weather condition " << get<1>(day2t) << " is better than " << get<1>(day1t) << " and " << get<1>(day3t) << "." << endl;
      cout << endl; 
    } 
    else{
      cout << get<0>(day3t) << " is the best day to go out because the weather condition " << get<1>(day3t) << " is better than " << get<1>(day1t) << " and " << get<1>(day2t) << "." << endl;
      cout << endl;
   }
 }
 
 cout << info.day1 << " : " << info.day1W << endl;
 cout << info.day2 << " : " << info.day2W << endl;
 cout << info.day3 << " : " << info.day3W << endl;

 for (int i = 0; i < 11; i++) {	// Loops through the array Weatherlist and if the best weather is a part of one of the objects it prints that objects clothing vector.
	 if (best_weather == Weatherlist[i].getWeather())
		 cout << "Make sure you are prepared with " << PrintVec(Weatherlist[i].clothing) << "when you go outside.";
 }
 return 0;
}
string PrintVec(vector<string> clothing) {// A function that prints everything in a vector as a string.
	string clothingret;
	for (auto s : clothing) {
		clothingret += s + ", ";
	}
	return clothingret;
}

int findIndex(string arr[], int SIZE, string word){ // A function that finds the index of an element.
  for (int i = 0; i < SIZE; i++){
    if (arr[i] == word)
    {
      return i;
    }
  
  }
  return -1;
}





