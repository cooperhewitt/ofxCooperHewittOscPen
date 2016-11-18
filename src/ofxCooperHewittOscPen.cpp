#include "ofMain.h"
#include "ofxCooperHewittOscPen.h"

ofxCooperHewittOscPen::ofxCooperHewittOscPen() {
	oscReceiver.setup(8000);
}

ofxCooperHewittOscPen::~ofxCooperHewittOscPen() {

}

string ofxCooperHewittOscPen::getPenMessages()
{
	while (oscReceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscReceiver.getNextMessage(&m);
		string msg = "";
		for (int i = 0; i < m.getNumArgs(); i++) {
			msg += m.getArgAsString(i);
			msg += " ";
			ofLog() << msg << endl;
		}
	}

	return string();
}
