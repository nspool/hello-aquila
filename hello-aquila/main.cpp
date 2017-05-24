//
//  main.cpp
//  hello-aquila
//
//  Created by nsp on 24/5/17.
//  Copyright © 2017 nspool. All rights reserved.
//

#include <iostream>

#include "aquila/global.h"
#include "aquila/source/WaveFileHandler.h"
#include "aquila/source/generator/WhiteNoiseGenerator.h"

int main(int argc, const char * argv[]) {

    // Write some white noise out to a file to make sure it works..
    
    Aquila::WaveFileHandler filehandle("whitenoise.wav");
    
    Aquila::WhiteNoiseGenerator whiteNoiseGenerator(10000);
    
    whiteNoiseGenerator.setAmplitude(8192);
    
    whiteNoiseGenerator.generate(100000);
    
    filehandle.save(whiteNoiseGenerator);
    
    return 0;
}
