//
//  VCSMeetObjects.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/3/14.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMeetLink/VCSMeetLink.h>)
#import <VCSMeetLink/VCSMeetEnum.h>
#import <VCSMeetLink/Models.pbobjc.h>
#else
#import "VCSMeetEnum.h"
#import "Models.pbobjc.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 会控服务配置
/// 会控服务配置
@interface VCSMeetConfig : NSObject

/// 用户登录令牌
@property (nonatomic, copy) NSString *token;

/// 服务地址
@property (nonatomic, copy) NSString *meetingHost;
/// 服务端口
@property (nonatomic, assign) NSInteger meetingPort;
/// 服务器标识
@property (nonatomic, copy) NSString *serverId;

/// 连接超时时间
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

@end


#pragma mark - 呼叫账号信息
/// 呼叫账号信息
@interface VCSMeetCallAccount : NSObject

/// 账号标识
@property (nonatomic, copy) NSString *accountId;
/// 账号名称
@property (nonatomic, copy) NSString *name;
/// 账号昵称
@property (nonatomic, copy) NSString *nickname;
/// 账号头像
@property (nonatomic, copy) NSString *portrait;

@end


#pragma mark - 会控参数
/// 会控参数
@interface VCSMeetControlParam : NSObject

/// 房间凭证
@property (nonatomic, copy) NSString *session;
/// 房间标识
@property (nonatomic, copy) NSString *roomId;
/// 房间流媒体标识
@property (nonatomic, copy) NSString *roomSdkNo;

/// 账号标识
@property (nonatomic, copy) NSString *accountId;
/// 账号流媒体标识
@property (nonatomic, assign) int accountSdkNo;
/// 账号名称
@property (nonatomic, copy) NSString *name;
/// 手机号码
@property (nonatomic, copy) NSString *mobile;
/// 账号昵称
@property (nonatomic, copy) NSString *nickname;
/// 账号头像(绝对路径)
@property (nonatomic, copy) NSString *portrait;
/// 账号头像(相对路径)
@property (nonatomic, copy) NSString *relativePortrait;
/// 音频状态
@property (nonatomic, assign) DeviceState audioState;
/// 视频状态
@property (nonatomic, assign) DeviceState videoState;
/// 主码流信息
@property (nonatomic, strong) Stream *streamMain;
/// 辅码流信息
@property (nonatomic, strong) Stream *streamSub;
/// 账号绑定数据
@property (nonatomic, copy) NSString *tag;
/// 账号扩展字段
@property (nonatomic, copy) NSString *extendInfo;

/// 服务标识
@property (nonatomic, copy) NSString *serverId;

@end


NS_ASSUME_NONNULL_END
