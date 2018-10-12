#include <string>
#include <vector>
#ifndef WEATHER_H
#define WEATHER_H
using namespace std;


class Weather{
  private:
    string weather;
  public:
    void setWeather(string);  
    string getWeather()const;
	vector<string>clothing;
};

void Weather::setWeather(string w){
  weather = w;
}
string Weather::getWeather()const{
  return weather;
}
#endif
