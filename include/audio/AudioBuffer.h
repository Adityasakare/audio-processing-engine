
#pragma once

#include <cstddef>
#include <vector>

class AudioBuffer
{
	public:
		AudioBuffer(std::vector<float> samples, unsigned int sampleRate);

		std::size_t getSampleCount() const;
		unsigned int getSampleRate() const;

	private:
		std::vector<float> samples_;
		unsigned int sampleRate_;

};

