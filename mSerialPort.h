//
//  mSerialPort.h
//  SerialPortTool
//
//  Created by Hogan on 17/8/29.
//  Copyright © 2017年 com.Young. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#include <iostream>
#import "SerialportEx.h"
class CSerialPort{
public:
    CSerialPort();
    ~CSerialPort();
public:
    void AttachSerialPort(SerialportEx *FixtureComm) ;
    
    bool WriteString(char *szCMD);
    char* ReadString();
    int ShowMeasurePanel(char *msg) ;
    int SendCmd(char* szCmd, int timeout);
    int SetDetectString(char * regex);
    int DetectString(char * regex);
    int WaitForString(int iTimeout);
    int ClearBuffer();
private:
    SerialportEx *mFixtureComm ;
    pthread_mutex_t mMutexLock ;
};
