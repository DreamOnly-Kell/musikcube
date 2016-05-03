#pragma once

#include <core/sdk/IDecoder.h>

#include "FrameSplitter.h"
#include "Layer3Decoder.h"

using namespace musik::core::audio;

class MP3Decoder : public IDecoder
{
public:

	MP3Decoder();
	~MP3Decoder();

    bool Open(musik::core::io::IDataStream *dataStream);
	double SetPosition(double seconds, double totalLength);
	bool GetBuffer(IBuffer *buffer);
    void Destroy();

private:
    bool GetXingHeader(unsigned char * XingBuffer);
    bool GetStreamData();
    unsigned long GetID3HeaderLength(unsigned char * buffer);

    musik::core::io::IDataStream *dataStream;

    IMPEGDecoder *decoder;
    Frame frame;

    unsigned long lastLayer;
    unsigned long sampleRate;
    unsigned long numChannels;
    unsigned long id3v2Length;
    unsigned long streamLengthMs;
    unsigned long numFrames;
    unsigned long streamDataLength;
    unsigned long vbrScale;
    unsigned char toc[100];
    bool xingValid;
};
