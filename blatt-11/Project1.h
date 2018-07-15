/*
 * copyright Abderrahmen Rakez
 *
 * */

#ifndef PROJECT1_H_
#define PROJECT1_H_

class Project1 {
 private:
 public:
     Project1();

     // check neighbors
     const unsigned int checkNeighbouts(struct cell);

     // draw bridge
     void bridge(void);
};

#endif  // PROJECT1_H_
