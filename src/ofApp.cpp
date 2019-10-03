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
    //set image to black
    img.allocate(1,(frameSize/2)+1, OF_IMAGE_GRAYSCALE);
    int i = 0;
    while ( i < img.getPixels().size() ) {
        img.getPixels()[i] = 0;
        i++;
    }
    img.update();
//    frameTime = frameSize/sampleRate; // how much time per frame analysis

//    spectrogram.assign(1000,vector<Real>());
    soundStream.setup(numberOfOutputChannels, numberOfInputChannels, sampleRate, frameSize, numberOfBuffers);
    mltk.setup(frameSize, sampleRate, hopSize);
    mltk.accumulating = true;
    mltk.run();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetFrameNum() > 300 ){
//        ofSetWindowTitle(to_string(ofGetFrameRate()));
        mltk.run();
    //    spectrogram.push_back(mltk.getData("Spectrum"));
        spectrogram = mltk.getRaw("Spectrum");
    //    rms = mltk.getValue("RMS");
        rms = mltk.pool.value<vector<Real>>("RMS");
        
        img.resize(spectrogram.size(),(frameSize/2)+1);

    //    for(int i =0 ; i < spectrogram[spectrogram.size()-1].size(); i++){
    //        spectrogram[spectrogram.size()-1][i] /= rms;  //each frame of spectrum divided by the frame's rms(total energy) to scale up, the spectrum values/total energy = %
    //    }

        for(int i = 0; i < spectrogram.size(); i++){
            for(int j = 0 ; j < (frameSize/2)+1; j++){
//            for(int j = 0 ; j < spectrogram[i].size(); j++){
    //            cout << "i:"+ to_string(i)+" j:" + to_string(j) << endl; //ofLog
//                    img.setColor(i, j, ofMap(spectrogram[i][j]/rms[i],0,1,0,255,true));
                img.setColor(i, j, ofMap(spectrogram[i][j]*10000,1,0,0,255,true));

    //                cout << "map" << ofMap(spectrogram[i][j]/rms[i],1,0,0,255,true) << endl; //ofLog
    //                cout << spectrogram[i][j] << endl; //ofLog

            }
        }
        img.update();
    }

}


//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(0);
//    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//
////    ofBackground(0);
//    //    double frameWidth = ofGetWidth()*frameTime/totalTrackTime;
//    //    int nOfFrames = ofGetWidth()/frameWidth;
//
//    frameWidth = float(ofGetWidth())/float(spectrogram.size());
//    frameHeight = float(ofGetHeight())/float(mltk.getData("Spectrum").size());
//
////    cout << to_string(spectrogram.size()) << endl;
////    for(int i = 0; i< spectrogramSize; i++){
//     for(int i = 0; i < spectrogram.size(); i++){
//       for(int j = 0 ; j < spectrogram[i].size(); j++){
////            cout << spectrogram[i][j]/rms << endl; //ofLog
//            ofSetColor(ofMap(spectrogram[i][j],1,0,0,255,true));
//            ofDrawRectangle(float(i)*frameWidth, frameHeight*float(j), frameWidth, frameWidth);
//
//        }
//
//    }
    
    
    img.draw(0,0,ofGetWidth(),ofGetHeight());

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
