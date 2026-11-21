#include <gtest/gtest.h>
#include "audio/AudioAnalyzer.h"

TEST(AudioAnalyzerTest, ReturnsExpectedMessage)
{
	AudioAnalyzer analyzer;

	EXPECT_EQ(
		analyzer.getMessage(),
		"AudioAnalyzer library is working"
	);

}

TEST(AudioAnalyzerTest, ReturnNonEmptyMessage)
{
	AudioAnalyzer analyzer;
	std::string value = analyzer.getMessage();
	EXPECT_FALSE(value.empty());
	
}

