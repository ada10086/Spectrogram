#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup the Window
    //
    //  ofClear(backgroundColor.get());;
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofClear(0);
    
    ofSetWindowTitle("Spectrogram");
    

    frameTime = frameSize/sampleRate; // how much time per frame analysis

//    spectrogram.assign(1000,vector<Real>());
    soundStream.setup(numberOfOutputChannels, numberOfInputChannels, sampleRate, frameSize, numberOfBuffers);
    mltk.setup(frameSize, sampleRate, hopSize);
//    mltk.accumulating = true;
    mltk.run();
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle(to_string(ofGetFrameRate()));
    mltk.run();
    spectrogram.push_back(mltk.getData("Spectrum"));
    rms = mltk.getValue("RMS");
    for(int i =0 ; i < spectrogram[spectrogram.size()-1].size(); i++){
        spectrogram[spectrogram.size()-1][i] /= rms;  //each frame of spectrum divided by the frame's rms(total energy) to scale up, the spectrum values/total energy = %
    }

//    spectrogramSize++;
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

//    ofBackground(0);
    //    double frameWidth = ofGetWidth()*frameTime/totalTrackTime;
    //    int nOfFrames = ofGetWidth()/frameWidth;

    frameWidth = float(ofGetWidth())/float(spectrogram.size());
    frameHeight = float(ofGetHeight())/float(mltk.getData("Spectrum").size());

//    cout << to_string(spectrogram.size()) << endl;
//    for(int i = 0; i< spectrogramSize; i++){
     for(int i = 0; i < spectrogram.size(); i++){
       for(int j = 0 ; j < spectrogram[i].size(); j++){
//            cout << spectrogram[i][j]/rms << endl; //ofLog
            ofSetColor(ofMap(spectrogram[i][j],1,0,0,255,true));
            ofDrawRectangle(float(i)*frameWidth, frameHeight*float(j), frameWidth, frameWidth);

        }

    }
}

void ofApp::audioIn(ofSoundBuffer &inBuffer){
    inBuffer.getChannel(mltk.leftAudioBuffer, 0);
    inBuffer.getChannel(mltk.rightAudioBuffer, 1);
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
