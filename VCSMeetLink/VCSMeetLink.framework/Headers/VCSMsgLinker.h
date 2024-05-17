//
//  VCSMsgLinker.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/5/17.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Qos等级
typedef enum : NSInteger {
    
    VCSQosLevelAtMostOnce = 0,
    VCSQosLevelAtLeastOnce = 1,
    VCSQosLevelExactlyOnce = 2
} VCSQosLevel;

/// 连接状态
typedef enum : NSInteger {
    
    VCSMsgLinkerStateStarting,
    VCSMsgLinkerStateConnecting,
    VCSMsgLinkerStateError,
    VCSMsgLinkerStateConnected,
    VCSMsgLinkerStateClosing,
    VCSMsgLinkerStateClosed
} VCSMsgLinkerState;

/// 操作结果回调
/// @param error 错误信息
typedef void (^VCSMsgLinkerResultBlock)(NSError *error);

/// 连接状态回调
/// @param state 连接状态
typedef void (^VCSMsgLinkerChangeStateBlock)(VCSMsgLinkerState state);

/// 接收数据回调
/// @param data 数据
/// @param topic 主题
typedef void(^VCSMsgLinkerReceiveDataBlock)(NSData *data, NSString *topic);

#pragma mark - 消息连接器
@interface VCSMsgLinker : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 连接状态回调
/// 连接状态回调
/// 注：当网络异常导致重连成功后，需要重新订阅相关主题
@property (nonatomic, copy) VCSMsgLinkerChangeStateBlock changeStateBlock;

#pragma mark 获取消息连接器
/// 获取消息连接器
+ (VCSMsgLinker *)sharedInstance;

#pragma mark 订阅主题
/// 订阅主题
/// - Parameters:
///   - topic: 目标主题
///   - qosLevel: Qos等级
///   - resultBlock: 操作结果回调
///   - receiveDataBlock: 接收数据回调
- (void)subscribeMsgLinkerWithTopic:(NSString *)topic qosLevel:(VCSQosLevel)qosLevel resultBlock:(nullable VCSMsgLinkerResultBlock)resultBlock receiveDataBlock:(nullable VCSMsgLinkerReceiveDataBlock)receiveDataBlock;

#pragma mark 取消订阅主题
/// 取消订阅主题
/// - Parameters:
///   - topic: 目标主题
///   - resultBlock: 操作结果回调
- (void)unsubscribeMsgLinkerWithTopic:(NSString *)topic resultBlock:(nullable VCSMsgLinkerResultBlock)resultBlock;

#pragma mark 发送数据
/// 发送数据
/// - Parameters:
///   - topic: 目标主题
///   - qosLevel: Qos等级
///   - data: 发送数据
///   - resultBlock: 操作结果回调
- (void)publishMsgLinkerWithTopic:(NSString *)topic qosLevel:(VCSQosLevel)qosLevel data:(NSData *)data resultBlock:(nullable VCSMsgLinkerResultBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
