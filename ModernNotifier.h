#ifndef MODERN_NOTIFIER_H
#define MODERN_NOTIFIER_H

#include <string>
using namespace std;


// target interface expected by modern CG subsystems
class ModernNotifier {
public:
virtual ~ModernNotifier() = default; // default destructor
virtual void sendAlert( const string& zone , const string& message ) = 0; // pure virtual

};

#endif