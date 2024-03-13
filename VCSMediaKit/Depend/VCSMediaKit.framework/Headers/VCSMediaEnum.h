//
//  VCSMediaEnum.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/3/4.
//  Copyright © 2022 SailorGa. All rights reserved.
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
    VCSErrorOK = 0,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       系统级错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 系统内部错误
    VCSErrorSystemFail = 1,
    /// 未初始化
    VCSErrorNotInitialized = 2,
    /// 媒体模块尚未初始化
    VCSErrorMediaNotInitialized = 3,
    /// 外部视频设备错误
    VCSErrorVideoCapturerFail = 100,
    /// 外部音频设备错误
    VCSErrorAudioCapturerFail = 101,
    /// 外部扬声器错误
    VCSErrorAudioPlayerFail = 102,
    /// 设备访问无权限
    VCSErrorDeviceNoRights = 103,
    /// 设备不存在
    VCSErrorDeviceNotfound = 104,
    /// 协议解析错误
    VCSErrorProtocolParsingFail = 200,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       通用错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 超时
    VCSErrorTimeout = 1000,
    /// 参数错误
    VCSErrorInvalidArgs = 1001,
    /// 重复操作冲突
    VCSErrorConflict = 1002,
    /// 尚未加入房间
    VCSErrorNotYetInRoom = 1003,
    /// 网络测试时拒绝操作
    VCSErrorForbiddenInNetTesting = 1004,
    /// 查找的资源不存在
    VCSErrorNotFound = 1100,
    /// 用户不存在
    VCSErrorUserNotFound = 1101,
    /// 房间不存在
    VCSErrorRoomNotFound = 1102,
    /// 码流不存在
    VCSErrorStreamNotFound = 1103,
    /// 会话不存在
    VCSErrorSessionNotFound = 1104,
    /// 被踢出
    VCSErrorSessionKickout = 1105,
    /// 用户签名失效
    VCSErrorUserSigInvalid = 1106,
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       网络类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 网络错误
    VCSErrorNetFail = 2000,
    /// 媒体网络错误
    VCSErrorMediaNetFail = 2001,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       应用相关错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 无效的AppID
    VCSErrorInvalidAppId = 3001,
    /// 签名错误
    VCSErrorApiSignatureFail = 3002,
    /// Api请求时间戳错误
    VCSErrorApiTimestampeFail = 3003,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       权限类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 操作未授权
    VCSErrorUnauthorized = 4000,
    /// 操作不允许
    VCSErrorForbidden = 4001,
    /// 并发不足
    VCSErrorConcLimit = 4002,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       服务端错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 服务器内部错误
    VCSErrorServerFail = 5000,
    /// MQTT服务器资源不足
    VCSErrorMQTTServerLess = 5010,
    /// MQTT没有服务器线路
    VCSErrorMQTTServerLineLess = 5011,
    /// 流媒体服务器资源不足
    VCSErrorUploadServerLess = 5020,
    /// 流媒体没有服务器线路
    VCSErrorUploadServerLineLess = 5021,
    /// 流媒体服务器绑定的WebVCS网关不足
    VCSErrorUploadWebVCSLess = 5022,
    /// 流媒体服务器绑定的RTMP网关不足
    VCSErrorUploadRtmpLess = 5023,
    /// WebVCS服务器资源不足
    VCSErrorWebVCSServerLess = 5030,
    /// WebVCS没有服务器线路
    VCSErrorWebVCSServerLineLess = 5031,
    /// RTMP服务器资源不足
    VCSErrorRTMPServerLess = 5040,
    /// RTMP没有服务器线路
    VCSErrorRTMPServerLineLess = 5041,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       第三方自定义错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 第三方平台鉴权错误
    VCSErrorThirdPartyRefused = 100000,
} VCSError;


#pragma mark - 日志等级
/**
 日志等级

 - VCSLogLevelTrace: TRACE
 - VCSLogLevelDebug: DEBUG
 - VCSLogLevelInfo: INFO
 - VCSLogLevelWarn: WARN
 - VCSLogLevelError: ERROR
 - VCSLogLevelCritical: CRITICAL
 - VCSLogLevelOff: OFF
*/
typedef enum : NSInteger {
    
    VCSLogLevelTrace = 0,
    VCSLogLevelDebug = 1,
    VCSLogLevelInfo = 2,
    VCSLogLevelWarn = 3,
    VCSLogLevelError = 4,
    VCSLogLevelCritical = 5,
    VCSLogLevelOff = 6,
} VCSLogLevel;


#pragma mark - 终端类型
/**
 终端类型
 
 - VCSTerminalTypeUnknown: 未知终端
 - VCSTerminalTypeWindows: Windows端
 - VCSTerminalTypeAndroid: 安卓端
 - VCSTerminalTypeIOS: iOS端
 - VCSTerminalTypeEmbeddedAndroid: 安卓一体机
 */
typedef enum : NSInteger {
    
    VCSTerminalTypeUnknown = 0,
    VCSTerminalTypeWindows = 1,
    VCSTerminalTypeAndroid = 2,
    VCSTerminalTypeIOS = 3,
    VCSTerminalTypeEmbeddedAndroid = 4
} VCSTerminalType;


#pragma mark - 编码类型
/**
 编码类型
 
 - VCSCodecTypeH264: H264
 - VCSCodecTypeH265: H265
 - VCSCodecTypeAAC: AAC
 - VCSCodecTypeOPUS: OPUS
 */
typedef enum : NSInteger {
    
    VCSCodecTypeH264 = 0x1b,
    VCSCodecTypeH265 = 0x24,
    VCSCodecTypeAAC = 0x0f,
    VCSCodecTypeOPUS = 0x5355504f
} VCSCodecType;


#pragma mark - 媒体流类型
/**
 媒体流类型
 
 - VCSStreamTypeAudio: 音频流类型
 - VCSStreamTypeVideo: 视频流类型
 */
typedef enum : NSInteger {
    
    VCSStreamTypeAudio = 0,
    VCSStreamTypeVideo = 1
} VCSStreamType;


#pragma mark - 媒体类型
/**
 媒体类型

 - VCSMediaTypeData: 数据类型
 - VCSMediaTypeVideo: 视频类型
 - VCSMediaTypeAudio: 音频类型
 */
typedef enum : NSInteger {
    
    VCSMediaTypeData = 0,
    VCSMediaTypeVideo = 1,
    VCSMediaTypeAudio = 2
} VCSMediaType;


#pragma mark - 码流轨道掩码
/**
 码流轨道掩码
 
 - VCSTrackMaskFlags0: 轨道0掩码
 - VCSTrackMaskFlags1: 轨道1掩码
 - VCSTrackMaskFlags2: 轨道2掩码
 - VCSTrackMaskFlags3: 轨道3掩码
 - VCSTrackMaskFlags4: 轨道4掩码
 - VCSTrackMaskFlags5: 轨道5掩码
 - VCSTrackMaskFlags6: 轨道6掩码
 */
typedef enum : NSInteger {
    
    VCSTrackMaskFlags0 = 1 << 0,
    VCSTrackMaskFlags1 = 1 << 1,
    VCSTrackMaskFlags2 = 1 << 2,
    VCSTrackMaskFlags3 = 1 << 3,
    VCSTrackMaskFlags4 = 1 << 4,
    VCSTrackMaskFlags5 = 1 << 5,
    VCSTrackMaskFlags6 = 1 << 6,
} VCSTrackMaskFlags;


#pragma mark - 码流轨道标识
/**
 码流轨道标识
 
 - VCSTrackIdentifierFlags0: 轨道0标识(子码流)
 - VCSTrackIdentifierFlags1: 轨道1标识(主码流)
 - VCSTrackIdentifierFlags2: 轨道2标识(共享码流)
 - VCSTrackIdentifierFlags3: 轨道3标识(可自定义码流)
 - VCSTrackIdentifierFlags4: 轨道4标识(可自定义码流)
 - VCSTrackIdentifierFlags5: 轨道5标识(可自定义码流)
 - VCSTrackIdentifierFlags6: 轨道6标识(可自定义码流)
 - VCSTrackIdentifierFlagsAudio: 音频轨道标识
 */
typedef enum : NSInteger {
    
    VCSTrackIdentifierFlags0 = 0,
    VCSTrackIdentifierFlags1 = 1,
    VCSTrackIdentifierFlags2 = 2,
    VCSTrackIdentifierFlags3 = 3,
    VCSTrackIdentifierFlags4 = 4,
    VCSTrackIdentifierFlags5 = 5,
    VCSTrackIdentifierFlags6 = 6,
    VCSTrackIdentifierFlagsAudio = -1
} VCSTrackIdentifierFlags;


#pragma mark - 屏幕共享状态
/**
 屏幕共享状态
 
 - VCSScreenRecordStatusNormal: 屏幕共享常规状态
 - VCSScreenRecordStatusError: 屏幕共享连接错误
 - VCSScreenRecordStatusStop: 屏幕共享已经停止
 - VCSScreenRecordStatusStart: 屏幕共享已经开始
 */
typedef enum : NSInteger {
    
    VCSScreenRecordStatusNormal = 1000,
    VCSScreenRecordStatusError = -1,
    VCSScreenRecordStatusStop = 0,
    VCSScreenRecordStatusStart = 1
} VCSScreenRecordStatus;


#pragma mark - 网络延时抗抖动等级
/**
 网络延时抗抖动等级
 
 - VCSNetworkQosShakeLevelUltraShort: 超短(0) 单向延迟120ms左右 这种模式下没有丢包补偿机制 并且编码关闭了B帧 一般不建议实际使用
 - VCSNetworkQosShakeLevelShort: 短(1) 单向延迟200ms左右 单次丢包补偿 B帧为1 双向对讲环境下可以使用
 - VCSNetworkQosShakeLevelMedium: 中(2) 单向延迟350ms左右 两次丢包补偿 B帧为1 双向对讲环境下推荐使用
 - VCSNetworkQosShakeLevelLong: 长(3) 单向延迟600ms左右 三次丢包补偿 B帧为3 这种模式仅用于单向收看 双向对讲环境下不建议使用 该参数无法动态设置
 */
typedef enum : NSInteger {
    
    VCSNetworkQosShakeLevelUltraShort = 0,
    VCSNetworkQosShakeLevelShort = 1,
    VCSNetworkQosShakeLevelMedium = 2,
    VCSNetworkQosShakeLevelLong = 3
} VCSNetworkQosShakeLevel;


#pragma mark - 音频路由类型
/**
 音频路由类型
 
 - VCSAudioRouteUnknown: 未知
 - VCSAudioRouteSpeaker: 扬声器
 - VCSAudioRouteReceiver: 听筒
 - VCSAudioRouteBluetooth: 蓝牙耳机
 - VCSAudioRouteHeadset: 有线耳机
 */
typedef enum : NSInteger {
    
    VCSAudioRouteUnknown = 0,
    VCSAudioRouteSpeaker = 1,
    VCSAudioRouteReceiver = 2,
    VCSAudioRouteBluetooth = 3,
    VCSAudioRouteHeadset = 4
} VCSAudioRoute;


#pragma mark - 网络状况
/**
 网络状况
 
 - VCSNetworkStateNormal: 良好
 - VCSNetworkStatePoor: 不佳
 - VCSNetworkStateBad:  较差
 - VCSNetworkStateVeryBad: 极差
 */
typedef enum : NSInteger {
    
    VCSNetworkStateNormal = 0,
    VCSNetworkStatePoor = 1,
    VCSNetworkStateBad = 2,
    VCSNetworkStateVeryBad = 3
} VCSNetworkState;


#pragma mark - 订阅远程流类型
/**
 订阅远程流类型
 
 - VCSPickerStateClose: 关闭订阅
 - VCSPickerStateAudio: 订阅音频流
 - VCSPickerStateVideo: 订阅视频流
 - VCSPickerStateAudioAndVideo: 订阅音视频流
 - VCSPickerStateBesides: 订阅除某个人的流
 */
typedef enum : NSInteger {
    
    VCSPickerStateClose = 0,
    VCSPickerStateAudio = 1,
    VCSPickerStateVideo = 2,
    VCSPickerStateAudioAndVideo = 3,
    VCSPickerStateBesides = 0x2000
} VCSPickerState;


#pragma mark - 下行码率自适应状态
/**
 下行码率自适应状态
 
 - VCSDownBitrateAdaptiveStateNormal: 正常
 - VCSDownBitrateAdaptiveStatePoor: 较差
 - VCSDownBitrateAdaptiveStateBad: 很差
 - VCSDownBitrateAdaptiveStateVeryBad: 极差
 - VCSDownBitrateAdaptiveStateLose: 下行链路状态不存在
 */
typedef enum : NSInteger {
    
    VCSDownBitrateAdaptiveStateNormal = 0,
    VCSDownBitrateAdaptiveStatePoor = -1,
    VCSDownBitrateAdaptiveStateBad = -2,
    VCSDownBitrateAdaptiveStateVeryBad = -3,
    VCSDownBitrateAdaptiveStateLose = -4
} VCSDownBitrateAdaptiveState;


#pragma mark - 下行平均丢包档位
/**
 下行平均丢包档位
 
 - VCSDownLossLevelStateInvalid: 无效
 - VCSDownLossLevelStateNormal: 正常
 - VCSDownLossLevelStatePoor: 较差
 - VCSDownLossLevelStateBad:  很差
 - VCSDownLossLevelStateVeryBad: 极差
 */
typedef enum : NSInteger {
    
    VCSDownLossLevelStateInvalid = -1,
    VCSDownLossLevelStateNormal = 0,
    VCSDownLossLevelStatePoor = 1,
    VCSDownLossLevelStateBad = 2,
    VCSDownLossLevelStateVeryBad = 3
} VCSDownLossLevelState;


#pragma mark - 上行码率自适应状态
/**
 上行码率自适应状态
 
 - VCSUploadBitrateAdaptiveStateStart: 码率自适应开始工作
 - VCSUploadBitrateAdaptiveStateNormal: 码率恢复到最初设置
 - VCSUploadBitrateAdaptiveStateHalf:  码率变为原来的一半
 - VCSUploadBitrateAdaptiveStateQuarter: 码率变为原来的四分之一
 - VCSUploadBitrateAdaptiveStateVeryBad: 当前网络环境及其差劲情况
 */
typedef enum : NSInteger {
    
    VCSUploadBitrateAdaptiveStateStart = 1000,
    VCSUploadBitrateAdaptiveStateNormal = 0,
    VCSUploadBitrateAdaptiveStateHalf = -1,
    VCSUploadBitrateAdaptiveStateQuarter = -2,
    VCSUploadBitrateAdaptiveStateVeryBad = -3,
} VCSUploadBitrateAdaptiveState;


#pragma mark - 投屏状态
/**
 投屏状态
 
 - VCSScreenCastingStatusNormal: 默认状态
 - VCSScreenCastingStatusAccept: 允许投屏
 - VCSScreenCastingStatusRefuse: 拒绝投屏
 - VCSScreenCastingStatusFailed: 投屏失败
 - VCSScreenCastingStatusWarning: 投屏预警
 */
typedef enum : NSInteger {
    
    VCSScreenCastingStatusNormal = -1,
    VCSScreenCastingStatusAccept = 0,
    VCSScreenCastingStatusRefuse = 1,
    VCSScreenCastingStatusFailed = 2,
    VCSScreenCastingStatusWarning = 3
} VCSScreenCastingStatus;


#pragma mark - 溢出状态
/**
 溢出状态
 
 - VCSScreenCastingOverflowStatusNormal: 默认状态
 - VCSScreenCastingOverflowStatusIntermit: 中断状态
 - VCSScreenCastingOverflowStatusRecover: 恢复状态
 */
typedef enum : NSInteger {
    
    VCSScreenCastingOverflowStatusNormal = 0,
    VCSScreenCastingOverflowStatusIntermit = 1,
    VCSScreenCastingOverflowStatusRecover = 2
} VCSScreenCastingOverflowStatus;


#pragma mark - 弱网档位
/**
 弱网档位
 
 - VCSScreenCastingWeaknet0: 0档位，20帧
 - VCSScreenCastingWeaknet1: 1档位，15帧
 - VCSScreenCastingWeaknet2: 2档位，10帧
 - VCSScreenCastingWeaknet3: 3档位，5帧
 - VCSScreenCastingWeaknet4: 4档位，2帧
 */
typedef enum : NSInteger {
    
    VCSScreenCastingWeaknet0 = 0,
    VCSScreenCastingWeaknet1 = 1,
    VCSScreenCastingWeaknet2 = 2,
    VCSScreenCastingWeaknet3 = 3,
    VCSScreenCastingWeaknet4 = 4
} VCSScreenCastingWeaknet;


#pragma mark - 日志组件等级
/**
 日志组件等级
 
 - VCSLoggerLevelTrace: Trace
 - VCSLoggerLevelDebug: Debug
 - VCSLoggerLevelInfo: Info
 - VCSLoggerLevelWarn: Warn
 - VCSLoggerLevelError: Error
 - VCSLoggerLevelFatal: Fatal
 */
typedef enum : NSInteger {
    
    VCSLoggerLevelTrace = 1,
    VCSLoggerLevelDebug = 5,
    VCSLoggerLevelInfo = 9,
    VCSLoggerLevelWarn = 13,
    VCSLoggerLevelError = 17,
    VCSLoggerLevelFatal = 21
} VCSLoggerLevel;


NS_ASSUME_NONNULL_END
