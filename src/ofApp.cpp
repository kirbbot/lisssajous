#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    ofSetWindowShape(810, 810);
    ofBackground(0,13,25);
    ofSetFrameRate(29);
    
    grid_square_count = 10;
    grid_square_size = ofGetWidth() / grid_square_count;
    
    for (int x=0; x<grid_square_count; x++) {
        for (int y=0; y<grid_square_count; y++) {
            _origin.set(grid_square_size/2 + grid_square_size * x, grid_square_size/2 + grid_square_size * y);
            _origins.push_back(_origin);
          
            _ampA = _ampB = grid_square_size/2 - 10;
            _ampAs.push_back(_ampA);
            _ampBs.push_back(_ampB);
            
            _freqA = x + 1;
            //_freqA = ofRandom(9);
            _freqAs.push_back(_freqA);
            
            _freqB = y + 1;
            //_freqB = ofRandom(9);
            _freqBs.push_back(_freqB);
            
            _phase = 0;
            _phases.push_back(_phase);
        }
    }
    
    for(int i=0; i< _origins.size(); i++){
        Lissajous _lissajous;
        _lissajous.setup(_origins[i], _ampAs[i], _ampBs[i], _freqAs[i], _freqBs[i], _phases[i]);
        _lissajous_curves.push_back(_lissajous);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<_lissajous_curves.size(); i++){
        _lissajous_curves[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<_lissajous_curves.size(); i++){
        _lissajous_curves[i].draw();
    }
}

