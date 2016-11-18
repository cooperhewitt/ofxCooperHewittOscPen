#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLog() << "Hello Pen!" << endl;

	myFont.loadFont("arial.ttf", 64);

	ch_pen.setup(8000);

	// register events
	ofAddListener(ch_pen.onPen, this, &ofApp::onPen);
}

//--------------------------------------------------------------
void ofApp::update(){
	ch_pen.getPenMessages();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofClear(0);
	myFont.drawString("Tap your pen", 100, 100);

	if (penMessage.length() ) {
		myFont.drawString("Your pen: " + penMessage, 100, 200);
	}

}

//--------------------------------------------------------------

void ofApp::onPen(penEvent & args)
{
	string shortcode = args.visitID;
	int found = args.visitID.find_first_of("#");
	if (found > 0 && found < shortcode.length()) {
		shortcode = args.visitID.substr(0, found);
	}

	penMessage = shortcode;
	ofLog() << "This pen is paired with shortcode: " << shortcode << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}



//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
