#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLog() << "Hello Pen!" << endl;
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
	ofDrawBitmapString("Hello Pen", 100, 100);

	if (penMessage.length() ) {
		ofDrawBitmapString("Last pen: " + penMessage, 100, 200);
	}

}

//--------------------------------------------------------------

void ofApp::onPen(penEvent & args)
{
	penMessage = args.penID;
	ofLog() << "PEN!: " << args.penID << endl;
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
