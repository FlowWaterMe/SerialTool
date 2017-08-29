//
//  Common.h
//  CoreLib
//
//  Created by Ryan on 12-7-25.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#pragma once
#ifndef CoreLib_Common_h
#define CoreLib_Common_h

typedef enum __TEST_PROCESS {
    TEST_PROCESS_START = 0,
    TEST_PROCESS_PAUSE,
    TEST_PROCESS_RESUME,
    TEST_PROCESS_STOP,
    TEST_PROCESS_FINISH,
    }TEST_PROCESS;

#define     UUTSelectCount    @"UUTSelectCount"


#define     NF_LOG_TESTDATA     @"SaveLog"      //Notificaiton for save the log

#define     KEY_NF_UARTPATH     @"uart_logpath"
#define     KEY_NF_TESTFLOW     @"testflow_path"
#define     KEY_NF_CSV          @"csv_filepath"

//#define     NF_TEST_PROCESS       @"TestStart"    //start test initial
#define     KEY_TEST_PROCESS      @"TestStatus"

//Key of register module dictionary
#define     KEY_TESTENGINE      @"TestEngine"
#define     KEY_FIXTURE_ID      @"id"           //fixture ID
#define     KEY_SCRIPT_HANDLE   @"lua"
#define     KEY_INSTR_MENU      @"InstrumentMenu"
#define     KEY_USERINFOR      @"UserInfor"
    
//BSCAN Notification
//#define     NOTIFY_BSCAN_DOTEST              @"SOC_NCT"                  //bscan send test request to ict
//#define     NOTIFY_BSCAN_RESULT              @"SOC_NCT_RESULT"           //ict send test result to bscan


//Module Notification Center
#define     NOTIFY_ICT_DOTEST           @"ICT_DoTest"
#define     NOTFIY_BSCAN_SCT            @"BSCAN_"


//Notification message ID
#define kNotificationLog                @"message_log"      //test flow log
#define kNotificationAttachMenu         @"Attach_Menu"
#define kNotificationSaveLog            @"SaveLog"

#define kNotificationMDASaveResult          @"MDA test item"
#define kNotificationOpenShortSaveResult    @"Openshort test item"
#define kNotificationOpenSaveResult         @"Open test item"
#define kNotificationShortSaveResult        @"Short test item"
#define kNotificationClearPromptLog           @"ClearPrompt_log"        //debug message log
#define kNotificationPromptLog           @"Prompt_log"        //debug message log
#define kNotificationDebugLog           @"debug_log"        //debug message log
//#define kNotificationPromptLog           @"prompt_log"      //prompt message log,this log use to prompt some thing for operator


#define kNotificationStartupLog         @"Startup_log"      //this log will send to the start up flash windows.
#define kStartupMessageBuffer           @"msg"
#define kStartupMessageLevel            @"level"

typedef enum {
    MSG_LEVEL_NORMAL,
    MSG_LEVEL_WARNNING,
    MSG_LEVEL_ERROR,
}MSG_LEVEL;




//UI Notification
//Handle : kNotificationUIMessage
//Description of UI Notification Message
//Message Type : 

#define kNotificationUIMessage          @"UI_Message"

//UI post notification
#define kNotificationOnEngineStart      @"On_EngineStart"
#define kNotificationOnEngineFinish     @"On_EngineFinish"
#define kNotificationOnTestStart        @"On_TestStart"
#define kNotificationOnTestStop         @"On_TestStop"
#define kNotificationOnTestFinish       @"On_TestFinish"
#define kNotificationOnTestPause        @"On_TestPause"
#define kNotificationOnTestResume       @"On_TestResume"
#define kNotificationOnTestItemStart    @"On_TestItemStart"
#define kNotificationOnTestItemFinish   @"On_TestItemFinish"
#define kNotificationOnTestError        @"On_TestError"
#define kNotificationOnSwitchView       @"On_SwitchView" //add by John Zeng

#define kIsAbortTest                    @"Test_Abort?"

//Automation Notification
#define kNotificationAumationReadSN     @"Aumation_ReadSN"

//UI Notification
#define kNotificationDUTOUTSHOWINFO     @"DO_DUTOUTSHOWINFO"
#define kNotificationDUTOUTCHGUI        @"DO_DUTOUTCHGUI"

#define kNotificationDoTestStart        @"DO_TestStart"
#define kNotificationDoTestStop         @"DO_TestStop"
#define kNotificationDoTestFinish       @"DO_TestFinish"
#define kNotificationDoTestPause        @"DO_TestPause"
#define kNotificationDoTestResume       @"DO_TestResume"
#define kNotificationDoTestItemStart    @"DO_TestItemStart"
#define kNotificationDoTestItemFinish   @"DO_TestItemFinish"
#define kNotificationDoTestError        @"DO_TestError"
#define kNotificationDoScanBarcode      @"DO_ScanBarcode"

#define KNotificationSFCErrorMsgTip     @"SFCErrorMsgTip"

#define kNotificationInsertView         @"DO_InsertView"  //defined by louis ,it used to control

#define kNotificationEnableUUTCtrl      @"UUT_EnableCtrl"  //defined by louis ,it used to control which uut will test .

#define kNotificationDoUiCtrl           @"Do_UiCtrl"  //defined by louis ,it used to control which uut will test .

//Configuration Keys
#define kConfigScanBarcode              @"scan_barcode?"
#define kConfigScanCFG                  @"Scan_Cfg?"
#define kConfigPuddingPDCA              @"Pudding_PDCA?"
#define kConfigPuddingBlob              @"Pudding_Blob"
#define kConfigPuddingBlobUart          @"Pudding_Blob_Uart"
#define kConfigPuddingBlobTestFlow      @"Pudding_Blob_TestFlow"
#define kConfigRemoveLocalBlob          @"Remove_Local_Blob"
#define kConfigTriggerType              @"Trigger_Type"
#define kConfigTriggerString            @"Trigger_String"
#define kConfigProfilePath              @"profile_path"
#define kConfigFailCount                @"approve_fail_count"  //-1:continue test,0:stop if fail,N:stop if fail count==N
#define kConfigLogDir                   @"log_directory"
#define kConfigQueryResult              @"Query_Station_Result"
#define kConfigQeryStationName          @"Query_Station_Name"
#define kConfigCheckEECode              @"Check_EECode"
#define kConfigSN1Format                @"SN1_FORMAT"
#define kConfigSN2Format                @"SN2_FORMAT"
#define kConfigSN3Format                @"SN3_FORMAT"
#define kConfigSN4Format                @"SN4_FORMAT"
#define kConfigSN5Format                @"SN5_FORMAT"
#define kConfigSN6Format                @"SN6_FORMAT"
#define kConfigPuddingBlob              @"Pudding_Blob"
#define kConfigPuddingBlobUart          @"Pudding_Blob_Uart"
#define kConfigPuddingBlobTestFlow      @"Pudding_Blob_TestFlow"
#define kConfigRemoveLocalBlob          @"Remove_Local_Blob"


#define KNotficationSFCStateEnable      @"SFCStateEnable"
#define KNotficationSFCStateNoEnable    @"SFCStateNoEnable"
#define kNotificationSFCSOn             @"SFCSOn"
#define kNotificationSFCSOff            @"SFCSOff"


#define kConfigAutomationMode           @"Automation_Mode"

#define kConfigFixtureID                @"FixtureID"
#define kConfigFixtureVER               @"FixtureVER"

#define kConfigPriority                 @"Pudding_Priority"

#define kConfigInitTestView             @"InitTestView"

//TestFlowMode
//Add by Yuekie
#define kConfigTestFlowMode             @"TestFlowMode"
#define kConfigKeyBoardType             @"KeyBoardType"
#define kConfigKeyBoardTypeBranch       @"KeyBoardTypeBranch"
#define kConfigSFCSwitch                @"SFCSwitch"
#define kConfigCheckSNOverSFC           @"CheckSNOverSFC"
#define kConfigScanSNManual             @"ScanSNManual"
#define kConfigTestPassCount            @"TestPassCount"
#define kConfigTestFailCount            @"TestFailCount"
#define kConfigCheckDebugOut            @"CheckDebugOut"
#define kConfigEnableBottomSN           @"EnableBottomSN"
#define kConfigEnableSpace5Point        @"EnableSpace5Point"
#define kConfigScanCarrierSN            @"ScanCarrierSN"

//Login
#define kLoginUserName                  @"Login_UserName"
#define kLoginUserPassword              @"Login_Password"
#define kLoginUserAuthority             @"Login_Authority"


#define kNotificationDoChangeUser              @"Do_ChangeUser"
//Add by Yuekie
#define kNotificationAppDidFinishLaunching     @"AppDidFinishLaunching"
//#define kNotificationTestFlowChange            @"TestFlowChange"
#define kNotificationSFCState                  @"SFCStateNot"
//#define kNotificationCheckEECodeState          @"CheckEECodeState"
//#define kNotificationCheckSNOverSFCState       @"CheckSNOverSFCState"
//#define kNotificationBoardTypeChange           @"BoardTypeChange"
//#define kNotificationSerialPortReady           @"SerialPortReady"
#define kNotificationShowErrorTipOnUI          @"ShowErrorTipOnUI"
#define kNotificationShowPlungerTipOnUI        @"ShowPlungerTipOnUI"
#define kNotificationReSetTestCountOnUI        @"ReSetTestCountOnUI"
#define kNotificationLoadDifferentProfile      @"LoadDifferentProfile"
#define kNotificationScanSNManualComplete      @"ScanSNManualComplete"

//Add by Tom Start
#define kNotification_Call_isTestable            @"kNotification_Call_isTestable"
#define kNotification_GET_DAQ_FORCEDATA          @"GET_DAQ_FORCEDATA"
#define kNotification_GET_ARM_WAVEDATA           @"GET_ARM_WAVEDATA"
#define kNotification_GET_FIXTURE_TESTFINISHSIG  @"GET_FIXTURE_TESTFINISHSIG"
#define kNotification_UI_Keyboard_KeyDown        @"kNotification_UI_Keyboard_KeyDown"

#define kConfig_Enable_KeyTestGroup_From_KeyboardUI     @"kConfig_Enable_KeyTestGroup_From_KeyboardUI"
#define kConfig_Array_KeyTestGroup_From_KeyboardUI      @"kConfig_Array_KeyTestGroup_From_KeyboardUI"
#define kUserKeyInfo_KeyID                       @"kUserKeyInfo_KeyID"
#define kUserKeyInfo_Key_Count_of_POS            @"kUserKeyInfo_Key_Count_of_POS_%d"
#define kNotification_CHK_En_Group_UI_CHG        @"kNotification_CHK_En_Group_UI_CHG"
//Add by Tom End
#define kNotificationChangePreferences         @"ChangePreference"

typedef enum __USER_AUTHORITY {
    AUTHORITY_ADMIN = 0,
    AUTHORITY_ENGINEER = 1,
    AUTHORITY_OPERATOR = 2,
} USER_AUTHORITY;

typedef struct __USER_INFOR {
    char szName[32];
    char szPassword[32];
    USER_AUTHORITY Authority;
}USER_INFOR;


#define kNotificationProfileEditor      @"ProfileEditor"
#define kPFMainWindow                   @"MainWindow"
#define kPFProfileName                  @"ProfileName"

#endif
