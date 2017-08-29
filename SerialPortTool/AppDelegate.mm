//
//  AppDelegate.m
//  SerialPortTool
//
//  Created by Hogan on 17/8/29.
//  Copyright © 2017年 com.Young. All rights reserved.
//

#import "AppDelegate.h"
#define KEY_FixtureAddress         @"FixtureAddress"
#define KEY_FixtureSetting         @"FixtureSetting"
@interface AppDelegate ()

@property  IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}
-(id)init
{
    self = [super init];
    if(self)
    {
        Fixture = new CSerialPort();
        dicConfiguration = [[NSMutableDictionary alloc] init] ;
        m_arrCmdHistory=[NSMutableArray new];
        retResult = [[NSMutableString  alloc] initWithString:@"00000"];
        [m_arrCmdHistory addObject:@"Help"];
        [m_arrCmdHistory addObject:@"Version"];
        [m_arrCmdHistory addObject:@"Test pass"];
        [m_arrCmdHistory addObject:@"Test fail"];
//        NSString *config_dir  = [[PathManager sharedManager] configPath];
//        NSString *config_file = [config_dir stringByAppendingPathComponent:@"/GT_Fixture_Config.plist"];
//        [[NSFileManager defaultManager] createDirectoryAtPath:config_dir withIntermediateDirectories:YES attributes:nil error:nil];
//        self.strCfgFile = config_file;
    }
    return self;
}

-(void)alloc
{
    [super dealloc];
}

-(void)awakeFromNib
{
    NSString *strTmp = [dicConfiguration objectForKey:KEY_FixtureAddress] ;
    if (strTmp)
        [mCBFixtureAddress setStringValue:strTmp];
    else
        [mCBFixtureAddress setStringValue:@"/dev/cu.usbserial-Fixture"] ;
    
    strTmp = [dicConfiguration objectForKey:KEY_FixtureSetting] ;
    if (strTmp)
        [mTFFixtureSetting setStringValue:strTmp];
    else
        [mTFFixtureSetting setStringValue:@"9600,n,8,1"] ;
    //    [self GetMaxNeedlePressCount];
}
-(IBAction)btn_SearchFixtureDevice:(id)sender
{
    [mCBFixtureAddress removeAllItems] ;
    
    NSEnumerator *enumerator = [AMSerialPortList portEnumerator];
    AMSerialPort *aPort;
    while (aPort = [enumerator nextObject]) {
        // print port name
        [mCBFixtureAddress addItemWithObjectValue:[aPort bsdPath]];
    }
    
    return ;
}
-(IBAction)btn_Open:(id)sender
{
    if (mCBFixtureAddress.stringValue.length<=0)
    {
        NSRunAlertPanel(@"Fixture Config", @"invalible Fixture Address,Please input again...", @"OK", nil, nil) ;
        return ;
    }
    
    [dicConfiguration setValue:[NSString stringWithFormat:@"%@",mCBFixtureAddress.stringValue] forKey:KEY_FixtureAddress] ;
    [dicConfiguration setValue:[NSString stringWithFormat:@"%@",mTFFixtureSetting.stringValue] forKey:KEY_FixtureSetting] ;
    [self FixtureDeviceInitial] ;
    [dicConfiguration writeToFile:strCfgFile atomically:YES];
    return ;
}
-(void)FixtureDeviceInitial
{
    [mFixtureComm close] ;
    NSString *strFixtureAddr = [dicConfiguration valueForKey:KEY_FixtureAddress] ;
    NSString *strFixtureSetting = [dicConfiguration valueForKey:KEY_FixtureSetting] ;
    if (strFixtureAddr==nil || strFixtureAddr.length==0)
        strFixtureAddr = @"/dev/cu.usbserial-Fixture" ;
    
    if (strFixtureSetting==nil || strFixtureSetting.length==0)
        strFixtureAddr = @"9600,n,8,1" ;
    mFixtureComm = [[SerialportEx alloc] init:strFixtureAddr withName
                                             :strFixtureAddr type
                                             :(NSString*)CFSTR(kIOSerialBSDModemType)] ;
    NSFileHandle *handle = [mFixtureComm open] ;
    if (!handle)
        NSRunAlertPanel(@"Fixture Device",@"%@",@"Prompt", nil, nil,[NSString stringWithFormat:@"Device Open Fail with name:\r%@",strFixtureAddr]) ;
    
    [mFixtureComm PortSetting:strFixtureSetting] ;
    Fixture->AttachSerialPort(mFixtureComm);//bind 对象
    [mFixtureComm AttachView:m_SerialPortView];// bind 视图对象

}
-(IBAction)btn_Send:(id)sender
{
    if (mTFInput.stringValue.length<=0)
        return ;
    NSString * cmd =mTFInput.stringValue;
    
    if ([m_arrCmdHistory indexOfObject:cmd]==NSNotFound)
    {
        [m_arrCmdHistory addObject:cmd];
    }
    
    if (mFixtureComm.isOpen==FALSE)
    {
        NSRunAlertPanel(@"Serial Tip", @"please open serial port first", nil, nil, nil);
        return;
    }
    cmd = [NSString stringWithFormat:@"%@",mTFInput.stringValue] ;
    
    [mFixtureComm WriteStringValue:cmd];
    //    if ([mFixtureComm WriteStringValue:cmd])
    //    {
    [[[mTVOutput textStorage] mutableString] appendFormat:@"\nSend :%@",cmd] ;
    //    }

}
@end
