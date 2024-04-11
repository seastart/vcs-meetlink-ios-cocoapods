//
//  VCSMeetLogin.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/4/7.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMeetLink/VCSMeetLink.h>)
#import <VCSMeetLink/VCSMeetObjects.h>
#else
#import "VCSMeetObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/// 结果回调
typedef void (^VCSMeetLoginResultBlock)(NSError * _Nullable error);

#pragma mark - VCSMeetLogin
@interface VCSMeetLogin : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 会控配置
@property (nonatomic, strong, readonly) VCSMeetConfig *meetConfig;
/// 会控连接状态
@property (nonatomic, assign, readonly) BOOL meetConnect;

#pragma mark 获取登录服务实例
/// 获取登录服务实例
+ (VCSMeetLogin *)sharedInstance;

#pragma mark 令牌登录
/// 令牌登录
/// - Parameters:
///   - meetConfig: 会控配置
///   - resultBlock: 结果回调
- (void)loginWithMeetConfig:(VCSMeetConfig *)meetConfig resultBlock:(nullable VCSMeetLoginResultBlock)resultBlock;

#pragma mark 退出登录
/// 退出登录
- (void)logout;

@end

NS_ASSUME_NONNULL_END
