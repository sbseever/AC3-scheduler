#include "meeting.h"

meeting::meeting() {
    projector = false;
    europe = false;
    deadline = false;
    dayDeadline = NUM_OF_DAYS2;
    numAttendees = 0;
    day = 0;
    start = 0;
    end = 0;
}

void meeting::setProjector(bool hasProjector) {
    projector = hasProjector;
}

void meeting::setRecurring(bool isRecurring) {
    recurring = isRecurring;
}

void meeting::setDeadline(bool hasDeadline, int dayOf) {
    deadline = hasDeadline;
    dayDeadline = dayOf;
}

void meeting::setEurope(bool needEurope) {
    europe = needEurope;
}

void meeting::setStart(int newStart) {
  if(newStart < 9) {newStart += 12;}
  start = newStart;
}

void meeting::setEnd(int newEnd) {
  if(newEnd < 9) {newEnd += 12;}
  end = newEnd;
}

void meeting::setDay(int newDay) {
  day = newDay-1;
}

void meeting::setAttendees(int number) {
  numAttendees = number;
}
bool meeting::operator==(const meeting& other) {
    if(this->projector != other.projector) return false;
    if(this->recurring != other.recurring) return false;
    if(this->deadline != other.deadline) return false;
    if(this->dayDeadline != other.dayDeadline) return false;
    if(this->day != other.day) return false;
    if(this->europe != other.europe) return false;
    if(this->numAttendees != other.numAttendees) return false;
    if(this->start != other.start) return false;
    if(this->end != other.end) return false;
    return true;
}
