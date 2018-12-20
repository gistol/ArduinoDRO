#include "Events.h"
#include "CONFIG.h"
//--------------------------------------------------------------------------------------------------------------------------------------
EventsClass Events;
//--------------------------------------------------------------------------------------------------------------------------------------
EventsClass::EventsClass()
{
  
}
//--------------------------------------------------------------------------------------------------------------------------------------
void EventsClass::raise(EventSender s, Event evt, void* param)
{
  sender = s;

  size_t to = list.size();
  for(size_t i=0;i<to;i++)
  {
    list[i]->onEvent(evt, param);
  }

}
//--------------------------------------------------------------------------------------------------------------------------------------
void EventsClass::setup()
{
  /*
  #ifdef USE_STEPPER_RUN_DIODE
    pinMode(STEPPER_RUN_DIODE_PIN,OUTPUT);
    digitalWrite(STEPPER_RUN_DIODE_PIN,!STEPPER_RUN_DIODE_ON);
  #endif
  */
}
//--------------------------------------------------------------------------------------------------------------------------------------
void EventsClass::subscribe(IEventSubscriber* s)
{
  if(!s)
    return;
    
  unsubscribe(s);
  list.push_back(s);
}
//--------------------------------------------------------------------------------------------------------------------------------------
void EventsClass::unsubscribe(IEventSubscriber* s)
{
  if(!s || !list.size())
    return;

  IEventSubscriberList cpy;
  size_t to = list.size();
  for(size_t i=0;i<to;i++)
  {
    if(list[i] != s)
      cpy.push_back(list[i]);
  }

  list = cpy;
}
//--------------------------------------------------------------------------------------------------------------------------------------
