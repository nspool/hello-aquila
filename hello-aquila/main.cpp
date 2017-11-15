//
//  main.cpp
//  hello-aquila
//
//  Created by nsp on 24/5/17.
//  Copyright © 2017 nspool. All rights reserved.
//
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "aquila/global.h"
#include "aquila/source/WaveFileHandler.h"
#include "aquila/source/generator/WhiteNoiseGenerator.h"
#include "aquila/source/generator/TriangleGenerator.h"

int main(int argc, const char * argv[]) {

    // Write some white noise out to a file to make sure it works..
    
    Aquila::WaveFileHandler whitenoise("whitenoise.wav");
    
    Aquila::WhiteNoiseGenerator whiteNoiseGenerator(10000);
    
    whiteNoiseGenerator.setAmplitude(8192);
    
    whiteNoiseGenerator.generate(100000);
    
    whitenoise.save(whiteNoiseGenerator);
    
    // Attempt to play the audio directly from SDL
    
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        return -1;
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 ) {
        return -1;
    }

    // TODO: Convert into a buffer that SDL can use
    
//    auto whitenoiseWav = Mix_QuickLoad_WAV(whitenoise);
//
//    Mix_PlayChannel(-1, whitenoiseWav, 0);

    Mix_CloseAudio();

    // Use the sawtooth generator to generate the sound of a plane from an old flight sim
    
    Aquila::WaveFileHandler sawtooth("sawtooth.wav");
    
    Aquila::TriangleGenerator triangleGenerator1(10000);
    triangleGenerator1.setAmplitude(8192).setFrequency(100).setAmplitude(8192).generate(10000);
    
    Aquila::TriangleGenerator triangleGenerator2(10000);
    triangleGenerator2.setAmplitude(8192).setFrequency(50).setAmplitude(8192).generate(10000);
    
    sawtooth.save(triangleGenerator1 + triangleGenerator2);
    
    return 0;
}
