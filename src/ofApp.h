#pragma once

#include "ofMain.h"
#include "ofxMLTK.h"

class ofApp : public ofBaseApp{

	public:
    ofSoundStream soundStream;
    ofSoundStreamSettings soundStreamSettings;
    
    MLTK mltk;
    
    int numberOfOutputChannels = 0;
    int numberOfInputChannels = 2;
    double sampleRate = 44100;
    double frameSize = 1024;
    int hopSize = 512;
    int numberOfBuffers = 1;
    double totalTrackTime = 20;
//    double frameTime;
    
    float frameWidth;
    float frameHeight;
    
    vector<Real> spectrum;
    vector<vector<Real>> spectrogram;
//    Real rms;  //total energy
    vector<float> rms;
    
    ofImage img;
    
		void setup();
		void update();
		void draw();

        void audioIn(ofSoundBuffer &inBuffer);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
