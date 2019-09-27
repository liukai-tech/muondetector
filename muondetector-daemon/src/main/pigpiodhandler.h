#ifndef PIGPIODHANDLER_H
#define PIGPIODHANDLER_H

#include <QObject>
#include <QVector>
#include <QDateTime>
#include <QElapsedTimer>

#include <gpio_mapping.h>
#include <gpio_pin_definitions.h>

#define XOR_RATE 0
#define AND_RATE 1
#define COMBINED_RATE 2

static QVector<unsigned int> DEFAULT_VECTOR;
class PigpiodHandler : public QObject
{
	Q_OBJECT
public:
	explicit PigpiodHandler(QVector<unsigned int> gpio_pins = DEFAULT_VECTOR,
        QObject *parent = nullptr);
    // can't make it private because of access of PigpiodHandler with global pointer
    QDateTime startOfProgram, lastSamplingTime; // the exact time when the program starts (Utc)
    QElapsedTimer elapsedEventTimer;
	GPIO_PIN samplingTriggerSignal=EVT_XOR;
	
signals:
    void signal(uint8_t gpio_pin);
    void samplingTrigger();
	void eventInterval(quint64 nsecs);
	void timePulseDiff(qint32 usecs);

    // spi related signals
    void spiData(uint8_t reg, std::string data);

public slots:
	void stop();
    bool initialised();
    void setInput(unsigned int gpio);
    void setOutput(unsigned int gpio);
    void setPullUp(unsigned int gpio);
    void setPullDown(unsigned int gpio);
    void setGpioState(unsigned int gpio, bool state);
    void setSamplingTriggerSignal(GPIO_PIN signalName) { samplingTriggerSignal=signalName; }

    // spi related slots
    void writeSpi(uint8_t command, std::string data);
    void readSpi(uint8_t command, unsigned int bytesToRead);

private:
    bool isInitialised = false;
    bool spiInitialised = false;
    bool spiInitialise(); // will be executed at first spi read/write command
    bool isSpiInitialised();
    unsigned int spiClkFreq = 9600;
    /*
     * spi_flags consists of the least significant 22 bits.

            21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
            b  b  b  b  b  b  R  T  n  n  n  n  W  A u2 u1 u0 p2 p1 p0  m  m
            word size bits  msb msb only-3wire 3wire aux CEx?  activ-low? spi-mode
    */
    unsigned int spiFlags = 0b11000000;  // fixed value for now
};


#endif // PIGPIODHANDLER_H
