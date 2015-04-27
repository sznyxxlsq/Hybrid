#ifndef RAG_NODE_H
#define RAG_NODE_H 1

#include <inttypes.h>
#include <map>

#include "misc.h"

class RAGNode
{
private:
    std::map<int, rgb> pixels;
    uint8_t *hist;

// Constructor and Destructor
public:
//    RAGNode(int offset, rgb rgbData);
    RAGNode();
    ~RAGNode() {};

// Getter and Setter
public:
    std::map<int, rgb>& get_pixel() { return pixels; };

// Some public methods and Overrides
public:
    void addPixel(int offset, rgb rgbData);
    void calculateHist(int numBin);
    float calEntropy();
    float calFreqEntropy();
};

#define cube(x) (x * x * x)
#define sqrt(x) (x * x)

//RAGNode::RAGNode(int offset, rgb rgbData)
//{
//    pixels[offset] = rgbData;
//    hist = NULL;
//}

RAGNode::RAGNode()
{
    pixels.clear();
    hist = NULL;
}

void RAGNode::addPixel(int offset, rgb rgbData)
{
    pixels[offset] = rgbData;
}

void RAGNode::calculateHist(int numBin)
{
    if(hist)
        delete hist;
    hist = new uint8_t[cube(numBin)];
    for(int i = 0; i < cube(numBin); i++)
        hist[i] = 0;

    float binSize = (float)256/numBin;

    for(std::map<int, rgb>::const_iterator it = pixels.begin();
        it != pixels.end(); it++)
    {
        int binR = it->second.r/binSize;
        int binG = it->second.g/binSize;
        int binB = it->second.b/binSize;

        hist[binR * sqrt(numBin) + binG * numBin + binB]++;
    }
}

float RAGNode::calEntropy()
{
    //not implemented
    uint8_t *h = hist;
    return 0;
}

float RAGNode::calFreqEntropy()
{
    //not implemented
    uint8_t *hFreq = hist;
    return 0;
}

#endif // RAG_NODE_H
