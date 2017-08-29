//
//  mSerialPort.m
//  SerialPortTool
//
//  Created by Hogan on 17/8/29.
//  Copyright © 2017年 com.Young. All rights reserved.
//

#import "mSerialPort.h"

CSerialPort::CSerialPort()
{
    mFixtureComm = nil ;
    pthread_mutex_init(&mMutexLock, NULL) ;
}
CSerialPort::~CSerialPort()
{
    if (mFixtureComm)
    {
        [mFixtureComm close] ;
        [mFixtureComm release] ;
    }
    
    pthread_mutex_destroy(&mMutexLock) ;
    return ;
}

void CSerialPort::AttachSerialPort(SerialportEx *FixtureComm)
{
    SerialportEx *old = mFixtureComm ;
    mFixtureComm = [FixtureComm retain] ;
    [old release] ;
    
    return ;
}

bool CSerialPort::WriteString(char *szCMD)
{
    if (mFixtureComm==nil)
        return false ;
    pthread_mutex_lock(&mMutexLock) ;
    [mFixtureComm ClearInBuffer] ;
    bool rtn = [mFixtureComm WriteStringValue:[NSString stringWithFormat:@"%s",szCMD]];
    pthread_mutex_unlock(&mMutexLock) ;
    
    return rtn ;
}
char* CSerialPort::ReadString()
{
    if (mFixtureComm==nil)
        return NULL ;
    
    pthread_mutex_lock(&mMutexLock) ;
    NSData *receData = [mFixtureComm GetInBuffer];
    pthread_mutex_unlock(&mMutexLock) ;
    
    if (receData==nil || receData.length==0)
        return NULL ;
    
    NSString *rtnStr = [[[NSString alloc]initWithData:receData encoding:NSASCIIStringEncoding] autorelease];
    
    return (char*)rtnStr.UTF8String;
}
int CSerialPort::ShowMeasurePanel(char *msg)
{
    return 1;
}
int CSerialPort::SendCmd(char* szCmd, int timeout)
{
    if([mFixtureComm isOpen])
    {
        [mFixtureComm SetDetectString:@"\n"];
        [mFixtureComm WriteStringValue:[NSString stringWithFormat:@"%s\n",szCmd]];
        return [mFixtureComm WaitDetect:timeout];
    }
    else return -999;
}
int CSerialPort::SetDetectString(char * regex)
{
    if([mFixtureComm isOpen])
    {
        [mFixtureComm SetDetectString:[NSString stringWithUTF8String:regex]];
        return 0;
    }
    else return -1;
}
int CSerialPort::DetectString(char * regex)
{
    if([mFixtureComm isOpen])
    {
        SetDetectString(regex);
        return [mFixtureComm WaitDetect];
    }
    else  return -1;
}
int CSerialPort::WaitForString(int iTimeout)
{
    if([mFixtureComm isOpen])
    {
        return [mFixtureComm WaitDetect:iTimeout];
    }
    else  return -1;
}
int CSerialPort::ClearBuffer()
{
    if([mFixtureComm isOpen])
    {
        [mFixtureComm ClearInBuffer];
        return 0;
    }
    else  return -1;
}
