#ifndef LOG_H
#define LOG_H

#define NUM_LOGS 12

typedef struct Log {
    int initial_x;
    int velocity;
    bool exists;
} Log;

extern Log logs[NUM_LOGS];

void set_log(int y);
void move_log(Log *log);

#endif