/*
 * copyright Abderrahmen Rakez
 *
 * */


#ifndef NCURSESINIT_H_
#define NCURSESINIT_H_

class NcursesInit {
 private:
 public:
     NcursesInit();

     // init Terminal
     void initTerminal(void);

     // define game field
     void gameFieldInit(const unsigned int x, const unsigned int y);

     // show steps
     void stepsCounter(unsigned int step);
};

#endif  // NCURSESINIT_H_
