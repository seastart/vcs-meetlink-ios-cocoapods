//
//  VCSMeetEnum.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/3/14.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 错误码
typedef enum : NSInteger {
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       基础错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 无错误
    VCSMeetErrorOK = 0,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       系统级错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 系统内部错误
    VCSMeetErrorSystemFail = 1,
    /// 未初始化
    VCSMeetErrorNotInitialized = 2,
    /// 媒体模块尚未初始化
    VCSMeetErrorMediaNotInitialized = 3,
    /// 外部视频设备错误
    VCSMeetErrorVideoCapturerFail = 100,
    /// 外部音频设备错误
    VCSMeetErrorAudioCapturerFail = 101,
    /// 外部扬声器错误
    VCSMeetErrorAudioPlayerFail = 102,
    /// 设备访问无权限
    VCSMeetErrorDeviceNoRights = 103,
    /// 设备不存在
    VCSMeetErrorDeviceNotfound = 104,
    /// 协议解析错误
    VCSMeetErrorProtocolParsingFail = 200,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       通用错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 超时
    VCSMeetErrorTimeout = 1000,
    /// 参数错误
    VCSMeetErrorInvalidArgs = 1001,
    /// 重复操作冲突
    VCSMeetErrorConflict = 1002,
    /// 尚未加入房间
    VCSMeetErrorNotYetInRoom = 1003,
    /// 网络测试时拒绝操作
    VCSMeetErrorForbiddenInNetTesting = 1004,
    /// 查找的资源不存在
    VCSMeetErrorNotFound = 1100,
    /// 用户不存在
    VCSMeetErrorUserNotFound = 1101,
    /// 房间不存在
    VCSMeetErrorRoomNotFound = 1102,
    /// 码流不存在
    VCSMeetErrorStreamNotFound = 1103,
    /// 会话不存在
    VCSMeetErrorSessionNotFound = 1104,
    /// 被踢出
    VCSMeetErrorSessionKickout = 1105,
    /// 用户签名失效
    VCSMeetErrorUserSigInvalid = 1106,
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       网络类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 网络错误
    VCSMeetErrorNetFail = 2000,
    /// 媒体网络错误
    VCSMeetErrorMediaNetFail = 2001,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       应用相关错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 无效的AppID
    VCSMeetErrorInvalidAppId = 3001,
    /// 签名错误
    VCSMeetErrorApiSignatureFail = 3002,
    /// Api请求时间戳错误
    VCSMeetErrorApiTimestampeFail = 3003,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       权限类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 操作未授权
    VCSMeetErrorUnauthorized = 4000,
    /// 操作不允许
    VCSMeetErrorForbidden = 4001,
    /// 并发不足
    VCSMeetErrorConcLimit = 4002,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       服务端错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 服务器内部错误
    VCSMeetErrorServerFail = 5000,
    /// MQTT服务器资源不足
    VCSMeetErrorMQTTServerLess = 5010,
    /// MQTT没有服务器线路
    VCSMeetErrorMQTTServerLineLess = 5011,
    /// 流媒体服务器资源不足
    VCSMeetErrorUploadServerLess = 5020,
    /// 流媒体没有服务器线路
    VCSMeetErrorUploadServerLineLess = 5021,
    /// 流媒体服务器绑定的WebVCS网关不足
    VCSMeetErrorUploadWebVCSLess = 5022,
    /// 流媒体服务器绑定的RTMP网关不足
    VCSMeetErrorUploadRtmpLess = 5023,
    /// WebVCS服务器资源不足
    VCSMeetErrorWebVCSServerLess = 5030,
    /// WebVCS没有服务器线路
    VCSMeetErrorWebVCSServerLineLess = 5031,
    /// RTMP服务器资源不足
    VCSMeetErrorRTMPServerLess = 5040,
    /// RTMP没有服务器线路
    VCSMeetErrorRTMPServerLineLess = 5041,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       第三方自定义错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 第三方平台鉴权错误
    VCSMeetErrorThirdPartyRefused = 100000,
} VCSMeetError;


#pragma mark - 终端类型
/**
 终端类型
 
 - VCSMeetTerminalTypeUnknown: 未知终端
 - VCSMeetTerminalTypeWindows: Windows端
 - VCSMeetTerminalTypeAndroid: 安卓端
 - VCSMeetTerminalTypeIOS: iOS端
 - VCSMeetTerminalTypeEmbeddedAndroid: 安卓一体机
 */
typedef enum : NSInteger {
    
    VCSMeetTerminalTypeUnknown = 0,
    VCSMeetTerminalTypeWindows = 1,
    VCSMeetTerminalTypeAndroid = 2,
    VCSMeetTerminalTypeIOS = 3,
    VCSMeetTerminalTypeEmbeddedAndroid = 4
} VCSMeetTerminalType;


NS_ASSUME_NONNULL_END
