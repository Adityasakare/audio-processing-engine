
#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

#include "audio/AudioBuffer.h"

TEST(AudioBufferTest, EmptyBufferHasZeroSamples)
{
	AudioBuffer buffer({}, 44100);

	EXPECT_EQ(buffer.getSampleCount(), 0);
}

TEST(AudioBufferTest, BufferWithFourSamplesReturnsFour)
{
	std::vector<float> samples(4, 0.0F);
	AudioBuffer buffer(samples, 44100);

	EXPECT_EQ(buffer.getSampleCount(), 4);
}

TEST(AudioBufferTest, BufferWithLargeNumberOfSamplesReturnsCorrectCount)
{
	std::vector<float> samples(1000, 0.0F);
        AudioBuffer buffer(samples, 44000);

        EXPECT_EQ(buffer.getSampleCount(), 1000);

}

TEST(AudioBufferTest, ZeroSampleRateThrowsException)
{
	EXPECT_THROW(
		AudioBuffer buffer({}, 0),
		std::invalid_argument		
	);
}

TEST(AudioBufferTest, ReturnsConfiguredSampleRate)
{
	std::vector<float> samples(1000, 0.5F);
	AudioBuffer buffer(samples, 44000);
	EXPECT_EQ(buffer.getSampleRate(), 44000);

}

