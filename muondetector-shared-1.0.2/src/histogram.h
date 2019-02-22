#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <map>
#include <string>
#include <cmath>


class Histogram 
{
public:
    Histogram()=default;
    Histogram(const std::string& name, int nrBins, double min, double max)
    : fName(name), fNrBins(nrBins), fMin(min), fMax(max)
    { }
    ~Histogram() { fHistogramMap.clear(); }
	void clear() { fHistogramMap.clear(); fUnderflow=fOverflow=0.; }
	void setName(const std::string& name) { fName=name; }
	void setNrBins(int bins) { fNrBins = bins; clear(); }
	int getNrBins() const { return fNrBins; }
	void setMin(double val) { fMin=val; }
	double getMin() const { return fMin; }
	void setMax(double val) { fMax=val; }
	double getMax() const { return fMax; }
	void fill(double x, double mult = 1.) {
		int bin=value2Bin(x);
		if (bin<0) {
			fUnderflow+=mult;
		} else if (bin>=fNrBins) {
			fOverflow+=mult;
		} else fHistogramMap[bin]+=mult;
	}
	void setBinContent(int bin, double value) {
		if (bin>=0 && bin<fNrBins) fHistogramMap[bin]=value;
	}
	double getBinContent(int bin) const {
		if (bin>=0 && bin<fNrBins) return fHistogramMap.at(bin);
		else return double();
	}
	double getMean() {
		double sum = 0., entries=0.;
		for (const auto &entry : fHistogramMap) {
			entries+=entry.second;
			sum+=bin2Value(entry.first)*entry.second;
		}
		if (entries>0.)	return sum/entries;
		else return 0.;
	}
	double getUnderflow() const { return fUnderflow; }
	double getOverflow() const { return fOverflow; }
	double getEntries() {
		double sum = fUnderflow+fOverflow;
		//	foreach (double value, fHistogramMap) sum+=value;
		// this should also work, but it doesn't compile. reason unclear
		for (const auto &entry : fHistogramMap) {
			sum+=entry.second;
		}
/*
		// this should also work, but it doesn't compile. reason unclear
		sum += std::accumulate(fHistogramMap.begin(), fHistogramMap.end(), 0.,
                                          [](double previous, const QPair<const int, double>& p)
                                          { return previous + p.second; });
*/
		return sum;
	}
	
	friend QDataStream& operator << (QDataStream& out, const Histogram& h);
	friend QDataStream& operator >> (QDataStream& in, Histogram& h);

private:
	int value2Bin(double value) {
		double range=fMax-fMin;
		if (range<=0.) return -1;	
		int bin=value/range*fNrBins+0.5;
		return bin;
	}
	double bin2Value(int bin) {
		double range=fMax-fMin;
		if (range<=0.) return -1;	
		double value=range*(bin)/fNrBins;
		return value;
	}
	std::string fName = "defaultHisto";
	int fNrBins=100;
	double fMin=0.0;
	double fMax=1.0;
	double fOverflow=0;
	double fUnderflow=0;
	std::map<int, double> fHistogramMap;
};


#endif // HISTOGRAM_H