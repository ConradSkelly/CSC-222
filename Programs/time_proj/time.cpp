#include <stdio.h>
#include <iostream>
#include "time.h"
#include <string>
#include <cmath>

using namespace std;

Time::Time(int hour, int minute, int second){
  this->hour = hour;
  this->minute = minute;
  this->second = second;
}

Time::Time(int second){
  this->second = second;
}

Time::Time(){
  this->second = 0;
}

Time::Time(int hour, int minute){
  this->hour = hour;
  this->minute = minute;
  this->second = 0;
}

string Time::toString(){

  string minuteSeperater = ":";
  string secondSeperater = ":";
  if (log10(minute) < 1)
    minuteSeperater = ":0";
  if (log10(second) < 1)
	secondSeperater = ":0";
  string finalTime = to_string(hour)+minuteSeperater+to_string(minute)+secondSeperater+to_string(second);
  return finalTime;
}

string Time::secondToTime(){
  string minuteSeperater = ":";
  string secondSeperater = ":";
  hour = second/3600;
  second = second%3600;
  minute = second/60;
  second = second%60;

  if (log10(minute) < 1)
    minuteSeperater = ":0";
  if (log10(second) < 1)
	secondSeperater = ":0";
  string timeString = to_string(hour)+minuteSeperater+to_string(minute)+secondSeperater+to_string(second);
  return timeString;
}

string Time::print() {
  minute += second / 60; second %= 60;
  hour += minute / 60; minute %= 60;
  hour %= 24;

  minute += second / 60;
  if (minute > 59);
      minute %= 60;

  hour += (minute + (second / 60)) / 60;
  if (hour >= 24) {
      hour -= 24;
    }


  string outputTime = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
  return outputTime;
  cout << hour << ":" << minute  << ":" << second << endl;
}

double totalSeconds(const Time& time) {
  return time.second + (time.hour * 3600 + time.minute * 60);
}

bool Time::after(const Time& t2) {
  if (hour > t2.hour) return true;
  if (hour < t2.hour) return false;

  if (minute > t2.minute) return true;
  if (minute < t2.minute) return false;

  return (second > t2.second);
}


