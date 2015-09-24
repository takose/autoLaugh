#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mySound.loadSound("sound.mp3");
    mySound.setLoop(false);
    
    ofSetWindowShape(600, 400);
    ofSetFrameRate(30);
    ofBackground(0, 0, 0);
    bufferSize = 0;
    ofSoundStreamSetup(0, 1, this, 44100, BUFSIZE, 4);
}

void ofApp::audioReceived (float *buf, int bufSize, int nChan) {
    bufferSize = bufSize;
    for (int i = 0; i < bufferSize; i++)
        buffer[i] = buf[i];
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < bufferSize; i++) {
        int dy = buffer[i] * 100;
        ofSetColor(255, 127, 127);
        ofLine(i, 200, i, 200 - dy);
        if (buffer[i] <= 0.1 && buffer[i] >= -0.1){ //静かさの調整
            noSound++;
        }
    }
    if(noSound >= 500){ //精度の調整
        noSoundCount++;
    } else {
        noSoundCount=0;
    }
    
    noSound=0;
    cout << noSoundCount << endl;
    if(noSoundCount>=100){ //間の調整
        mySound.play();
        noSoundCount=0;
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
