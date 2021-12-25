//
//  lissajous.cpp
//  lissajous_grid
//
//  Created by Michelle Kirby on 12/5/17.
//
//

#include "lissajous.h"

//--------------------------------------------------------------
void Lissajous::setup(ofPoint _origin, float _ampA, float _ampB, int _freqA, int _freqB, float _phase){
    
    origin.set(_origin);
    ampA = _ampA;
    ampB = _ampB;
    freqA = _freqA;
    freqB = _freqB;
    phase = _phase;
    
    angle = 0;
    angle_adder = 0.09;
    theta = 360;
    
//    pct = 0;
//    pct_increment = 0.01f;
    
    if(freqA > freqB){
        gcd_remainder = freqA % freqB;
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = freqB % gcd_remainder;
            gcds.push_back(gcd_remainder);
        }
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = gcds[0] % gcds[1];
        }
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = gcds[1] % gcds[2];
        }
    }
    if(freqB > freqA){
        gcd_remainder = freqA % freqB; // 48, 18, remainder 12
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = freqB % gcd_remainder; //6
            gcds.push_back(gcd_remainder);
        }
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = gcds[0] % gcds[1];
        }
        if(gcd_remainder != 0){
            gcds.push_back(gcd_remainder);
            gcd = gcd_remainder;
            gcd_remainder = gcds[1] % gcds[2];
        }
    }
    theta = (TWO_PI / gcd) * 180 / PI;
    cout << theta << endl;
}

//--------------------------------------------------------------
void Lissajous::update(){
    angle += angle_adder;

    
    if(angle > 360){
        angle = 0;
    }
//    pct += pct_increment;
//    if(pct > 1){
//        pct = 1;
//        pct_increment *= -1;
//    }
//    if(pct < 0){
//        pct = 0;
//        pct_increment *= -1;
//    }
    
//    theta += theta_increment;
//    cout << theta << endl;
//    
//    if(theta > 360 || theta < 0){
//        theta_increment *= -1;
//    }

    //ampA_adder = ampB_adder *= 1.01;
    //    ampA += ampA_adder;
    //    ampB += ampB_adder;
    //
    //    if(ampA > ofGetHeight()/2 || ampA < 0){
    //        ampA_adder *= -1;
    //    }
    //    if(ampB > ofGetHeight()/2 || ampB < 0){
    //        ampB_adder *=-1;
    //    }
}

//--------------------------------------------------------------
void Lissajous::draw(){
    for(float i=0; i<theta; i+=1){
        radian = PI/180 * ((angle+i));
        
        point.x = origin.x + ampA * sin(freqA * radian + phase);
        point.y = origin.y + ampB * sin(freqB * radian);
        
        ofSetColor(255,0,0);
        ofDrawCircle(point.x, point.y, 1);
//        ofSetColor(0,255,0);
//        ofDrawCircle(point.x, point.y, 0.5);
    }
}

//--------------------------------------------------------------
void Lissajous::interpolateByPct(){
}
