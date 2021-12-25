#pragma once

#include "ofMain.h"
#include "lissajous.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
    int grid_square_count;
    float grid_square_size;
    
        vector <Lissajous> _lissajous_curves;
    
        ofPoint _origin;
        vector <ofPoint> _origins;
    
        float _ampA;
        vector <float> _ampAs;
        
        float _ampB;
        vector <float> _ampBs;
        
        int _freqA;
        vector <int> _freqAs;
        
        int _freqB;
        vector <int> _freqBs;
    
        float _phase;
        vector <float> _phases;
	
};
