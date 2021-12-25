//
//  lissajous.h
//  lissajous_grid
//
//  Created by Michelle Kirby on 12/5/17.
//
//

#ifndef lissajous_h
#define lissajous_h

#include "ofMain.h"

class Lissajous{
    public:
        void setup(ofPoint _origin, float _ampA, float _ampB, int _freqA, int _freqB, float _phase);
        void update();
        void draw();
        void interpolateByPct();
    
        ofPoint origin, point;
        float ampA, ampB, phase;
        float angle_adder, angle, theta, theta_increment, radian, periodA, periodB, gcd, lcm;
    
    
        float pct, pct_increment;
    
        vector <int> gcds;
        int gcd_remainder, freqA, freqB;
};

#endif /* lissajous_h */
