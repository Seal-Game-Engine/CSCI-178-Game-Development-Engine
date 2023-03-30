#include "AnimationClip.h"
#include <numeric>
using namespace SealEngine;

float AnimationClip::length() const { return _length; }

AnimationClip::AnimationClip(std::vector<AnimationFrame> frames, bool loopTime)
    : frames(frames), loopTime(loopTime), 
    _length(std::accumulate(frames.begin(), frames.end(), 0.0f, [](float sum, const AnimationFrame& currentFrame) { return sum + currentFrame.duration; })) {}