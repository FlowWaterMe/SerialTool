//
//  AppDelegate.h
//  SerialPortTool
//
//  Created by Hogan on 17/8/29.
//  Copyright © 2017年 com.Young. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SerialportEx.h"
#import "SerialPortView.h"
#import "mSerialPort.h"
@interface AppDelegate : NSObject
{
    IBOutlet NSComboBox *mCBFixtureAddress  ;
    IBOutlet NSTextField *mTFFixtureSetting ;
    IBOutlet SerialPortView * m_SerialPortView;
    IBOutlet NSTextView *mTVOutput  ;
    IBOutlet NSTextField *mTFInput  ;
    NSMutableArray * m_arrCmdHistory;
    NSMutableDictionary *dicConfiguration ;
    NSString * strCfgFile;
    NSMutableString *retResult;
    @private
    NSLock *channelLock;
    SerialportEx *mFixtureComm ;
    CSerialPort   *Fixture;
}
@property (assign) NSMutableDictionary * dicConfiguration;
@property (copy) NSString * strCfgFile;
-(IBAction)btn_SearchFixtureDevice:(id)sender ;
-(IBAction)btn_Open:(id)sender ;
-(IBAction)btn_Send:(id)sender ;

@end

