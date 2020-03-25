#include <cmath>
#include<iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int roundToNearestInt(float x){
    if (x >= 0)
    {
        return x + 0.5;
    } return x - 0.5;
    
}

int get_fahrenheit(){
    cout << "Please enter temperature in Fahrenheit: " << endl;
    double temp;
    cin >> temp;
    if (temp > 40){
        cerr << "Temperature larger than 40 fahrenheit is not defined, try again." << endl;
        temp = get_fahrenheit();
    }
    return roundToNearestInt(temp);
}

int get_wind(){
    cout << "Please enter wind speed in miles per hour: " << endl;
    double wind;
    cin >> wind;
    return roundToNearestInt(wind);
}

int wind_chill(double temp, double wind){
    double temp_feel = 35.74 + 0.6215 * temp - 35.75 * pow(wind, 0.16) + 0.4275 * temp * pow(wind, 0.16);
    return roundToNearestInt(temp_feel);
}

void get_data(string fileName, string & temps, string & winds){
    ifstream input;
    if (!input.fail())
    {
        input.open(fileName);
        getline(input, temps);
        getline(input, winds);
        input.close();
    } else{
        cerr << "Cannot open file!" << endl;
    }
    
}

int main(){
    vector<vector<int>> matrix;
    vector<int> Temps;
    vector<int> Winds;
    string fileName = "wind_chill_test";
    string temps, winds;
    get_data(fileName, temps, winds);
    for (auto s:temps){
        int temp = (int) s - '0';
        if (temp > 40){
            cerr << "Temperature larger than 40 degrees fahrenheit not defined, TRY AGAIN." << endl;
            exit(1);
        }else{
            Temps.push_back(temp);
        }
    }
    for(auto s:winds){
        int wind = (int) s - '0';
        Winds.push_back(wind);       
    }



    return 0;
}