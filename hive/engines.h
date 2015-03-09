
#ifndef engines_h
#define engines_h

class enginesLib
{
  public:
    enginesLib();
    void init(int front, int back, int left, int right);
    void engineSetup();
    void runAll();
    void setEngine(int engine, int speed);
    int frontEngine;
    int backEngine;
    int leftEngine;
    int rightEngine;

    int throttle;
    int yaw;
    int pitch;
};

#endif