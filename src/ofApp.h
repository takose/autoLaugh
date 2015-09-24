#pragma once
#define BUFSIZE 512
#include "ofMain.h"

class ofApp : public ofBaseApp{
    private:
        float buffer[BUFSIZE];
        int bufferSize;
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioReceived(float *buf, int bufSize, int nChan);
    
    int noSound;
    int noSoundCount;
    ofSoundPlayer mySound;
};
