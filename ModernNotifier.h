#ifndef MODERN_NOTIFIER_H
#define MODERN_NOTIFIER_H

#include <string>
#include "Colleague.h"
using namespace std;


// target interface expected by modern CG subsystems
class ModernNotifier : public Colleague {
public:
virtual ~ModernNotifier() = default; // default destructor
virtual void sendAlert( const string& zone , const string& message ) = 0; // pure virtual
virtual void cancelAlert( string location);
virtual bool handleEvent( const string& event, const string& payload);

};

#endif