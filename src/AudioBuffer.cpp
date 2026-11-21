
#include "audio/AudioBuffer.h"
#include <utility>
#include <stdexcept>

AudioBuffer::AudioBuffer(std::vector<float> samples, unsigned int sampleRate)
	: samples_(std::move(samples)), 
	sampleRate_(sampleRate)
{
	if(sampleRate_ == 0)
		throw std::invalid_argument("Sample rate cannot be zero");
}

std::size_t AudioBuffer::getSampleCount() const
{
	return samples_.size();
}

unsigned int AudioBuffer::getSampleRate() const
{
	return sampleRate_;
}

