#ifndef ARDUINO_CLOUD_THING_H_
#define ARDUINO_CLOUD_THING_H_

#include "ArduinoCloudProperty.hpp"
#include "ArduinoCloudPropertyContainer.hpp"

#include "lib/LinkedList/LinkedList.h"

/* Constants for backwards compatibility */

static bool ON  = true;
static bool OFF = false;

static long const ON_CHANGE = -1;
static long const SECONDS   = 1;
static long const MINUTES   = 60;
static long const HOURS     = 3600;
static long const DAYS      = 86400;

class ArduinoCloudThing {
    public:
        ArduinoCloudThing();
        void begin();

        ArduinoCloudProperty<bool>   & addProperty(bool   & property, String const & name, Permission const permission);
        ArduinoCloudProperty<int>    & addProperty(int    & property, String const & name, Permission const permission);
        ArduinoCloudProperty<float>  & addProperty(float  & property, String const & name, Permission const permission);
        ArduinoCloudProperty<String> & addProperty(String & property, String const & name, Permission const permission);

        // poll should return > 0 if something has changed
        int poll(uint8_t * data, size_t const size);
        // decode a CBOR payload received from the Cloud.
        void decode(uint8_t const * const payload, size_t const length);

    private:

        bool                          _status = OFF;
        char                          _uuid[33];
        ArduinoCloudPropertyContainer _property_cont;

};

#endif /* ARDUINO_CLOUD_THING_H_ */
