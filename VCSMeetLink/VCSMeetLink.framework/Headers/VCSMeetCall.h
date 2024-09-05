//
//  VCSMeetCall.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/4/7.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMeetLink/VCSMeetLink.h>)
#import <VCSMeetLink/VCSMeetObjects.h>
#import <VCSMeetLink/RoomServer.pbobjc.h>
#import <VCSMeetLink/Register.pbobjc.h>
#import <VCSMeetLink/Models.pbobjc.h>
#else
#import "VCSMeetObjects.h"
#import "RoomServer.pbobjc.h"
#import "Register.pbobjc.h"
#import "Models.pbobjc.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSMeetCall;

#pragma mark - 呼叫组件回调代理
@protocol VCSMeetCallDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 呼叫连接状态变化
/// 呼叫连接状态变化
/// - Parameters:
///   - meetCall: 呼叫实例
///   - status: 连接状态，YES-连接 NO-断开
- (void)meetCall:(VCSMeetCall *)meetCall onConnectChangeStatus:(BOOL)status;

#pragma mark 呼叫响应结果
/// 呼叫响应结果
/// - Parameters:
///   - meetCall: 呼叫实例
///   - command: 指令类型
///   - result: 响应结果
- (void)meetCall:(VCSMeetCall *)meetCall onRespondCommand:(Command)command result:(Result)result;

#pragma mark 呼叫邀请通知
/// 呼叫邀请通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onInviteNotify:(InviteNotification *)notify error:(NSError *)error;

#pragma mark 呼叫邀请确认通知
/// 呼叫邀请确认通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onInviteConfirmNotify:(InviteConfirm *)notify error:(NSError *)error;

#pragma mark 成员通话状态变更通知
/// 成员通话状态变更通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onMemberChangeCallStatusNotify:(WaitingRoomBroadcast *)notify error:(NSError *)error;

#pragma mark 自己通话状态变更通知
/// 自己通话状态变更通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onSelfChangeCallStatusNotify:(WaitingRoomUpdate *)notify error:(NSError *)error;

#pragma mark 应用内推送通知
/// 应用内推送通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onInAppPushNotificationNotify:(PushNotification *)notify error:(NSError *)error;

#pragma mark 聊天消息通知
/// 聊天消息通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onChatMessagehNotify:(RegChatNotify *)notify error:(NSError *)error;

#pragma mark 会议开始通知
/// 会议开始通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onMeetingBeginNotify:(MeetingBeginNotify *)notify error:(NSError *)error;

#pragma mark 会议结束通知
/// 会议结束通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onMeetingEndNotify:(MeetingEndNotify *)notify error:(NSError *)error;

#pragma mark 会议邀请通知
/// 会议邀请通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onMeetingInviteNotify:(InviteConfNoticeNotify *)notify error:(NSError *)error;

#pragma mark 发送聊天消息回执通知
/// 发送聊天消息回执通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onSendChatReceiptNotify:(RegChatResponse *)notify error:(NSError *)error;

#pragma mark 聊天消息撤回通知
/// 聊天消息撤回通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onChatRevokeNotify:(RegChatRevokeNotify *)notify error:(NSError *)error;

#pragma mark 会议预约通知
/// 会议预约通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onMeetingPrepareNotify:(RoomPrepareNotify *)notify error:(NSError *)error;

#pragma mark 呼叫卡片消息通知
/// 呼叫卡片消息通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetCall:(VCSMeetCall *)meetCall onCallCardNotify:(CallCardMsgNotify *)notify error:(NSError *)error;

#pragma mark 事件透传通知
/// 事件透传通知
/// - Parameters:
///   - meetCall: 呼叫实例
///   - event: 事件类型
///   - content: 事件内容
- (void)meetCall:(VCSMeetCall *)meetCall onTransparentEvent:(VCSMeetCommandEvent)event content:(NSString *)content;

@end

#pragma mark - VCSMeetCall
@interface VCSMeetCall : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 账户信息
@property (nonatomic, strong, readonly) VCSMeetCallAccount *accountModel;

#pragma mark 获取呼叫单例
/// 获取呼叫单例
+ (VCSMeetCall *)sharedInstance;

#pragma mark 初始化会控呼叫
/// 初始化会控呼叫
/// - Parameters:
///   - accountModel: 账号信息
///   - delegate: 代理回调
- (void)initializeWithAccountModel:(VCSMeetCallAccount *)accountModel delegate:(nullable id <VCSMeetCallDelegate>)delegate;

#pragma mark 变更账号信息
/// 变更账号信息
/// - Parameter accountModel: 账号信息
- (void)changeWithAccountModel:(VCSMeetCallAccount *)accountModel;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;


#pragma mark 发起邀请
/// 发起邀请
/// @param roomNo 房间号码
/// @param targetId 目标账号ID
- (void)inviteWithRoomNo:(NSString *)roomNo targetId:(NSString *)targetId;

#pragma mark 发送邀请入会确认
/// 发送邀请入会请求
/// @param initiatorId 邀请发起者ID
/// @param roomNo 房间号码
/// @param response 邀请响应
- (void)inviteConfirmWithInitiatorId:(NSString *)initiatorId roomNo:(NSString *)roomNo response:(InviteResponse)response;

#pragma mark 发起呼叫
/// 发起呼叫
/// @param accountsArray 呼叫列表
/// @param currentMember 当前成员
/// @param roomNo 房间ID
/// @param restart 是否重新开始(YES-忽略上次的呼叫 NO-叠加上次的呼叫)
- (void)callWithAccountsArray:(nullable NSMutableArray<WaitingAccount *> *)accountsArray currentMember:(WaitingAccount *)currentMember roomNo:(NSString *)roomNo restart:(BOOL)restart;

#pragma mark 发起呼叫
/// 发起呼叫
/// @param accountsArray 呼叫列表
/// @param currentMember 当前成员
/// @param roomNo 房间ID
/// @param restart 是否重新开始(YES-忽略上次的呼叫 NO-叠加上次的呼叫)
/// @param role 参会角色
- (void)callWithAccountsArray:(nullable NSMutableArray<WaitingAccount *> *)accountsArray currentMember:(WaitingAccount *)currentMember roomNo:(NSString *)roomNo restart:(BOOL)restart role:(ConferenceRole)role;

#pragma mark 取消呼叫
/// 取消呼叫
/// @param accountsArray 取消呼叫列表
/// @param roomNo 房间ID
- (void)callCancelNewWithAccountsArray:(nullable NSMutableArray<WaitingAccount *> *)accountsArray roomNo:(NSString *)roomNo;

#pragma mark 从呼叫中移除
/// 从呼叫中移除
/// @param accountsArray 移除目标用户列表(空集合则移除所有人)
/// @param roomNo 房间ID
- (void)callRemoveNewWithAccountsArray:(nullable NSMutableArray<RemoveAccount *> *)accountsArray roomNo:(NSString *)roomNo;

#pragma mark 更新呼叫帐户信息
/// 更新呼叫帐户信息
/// @param account 账户信息
- (void)updateWaitingAccountInfo:(WaitingAccount *)account;

#pragma mark 发送应用内推送
/// 发送应用内推送
/// @param receiversArray 接收者用户标识集合
/// @param message 推送消息内容
- (void)inAppPushWithReceiversArray:(NSMutableArray<NSString *> *)receiversArray message:(NSData *)message;

#pragma mark 发送单聊文本消息
/// 发送单聊文本消息
/// @param message 文本消息
/// @param receiverId 接收者标识
- (ImBody *)sendTextWithMessage:(NSString *)message receiverId:(NSString *)receiverId;

#pragma mark 发送群聊文本消息
/// 发送群聊文本消息
/// @param message 文本消息
/// @param groupId 群组标识
- (ImBody *)sendTextGroupWithMessage:(NSString *)message groupId:(NSString *)groupId;

#pragma mark 发送单聊图片消息
/// 发送群聊图片消息
/// @param imagePath 图片地址
/// @param receiverId 接收者标识
- (ImBody *)sendImageWithImagePath:(NSString *)imagePath receiverId:(NSString *)receiverId;

#pragma mark 发送群聊图片消息
/// 发送单聊图片消息
/// @param imagePath 图片地址
/// @param groupId 群组标识
- (ImBody *)sendImageGroupWithImagePath:(NSString *)imagePath groupId:(NSString *)groupId;

#pragma mark 发送单聊语音消息
/// 发送单聊语音消息
/// @param audioPath 语音地址
/// @param receiverId 接收者标识
- (ImBody *)sendAudioWithAudioPath:(NSString *)audioPath receiverId:(NSString *)receiverId;

#pragma mark 发送群聊语音消息
/// 发送单聊语音消息
/// @param audioPath 语音地址
/// @param groupId 群组标识
- (ImBody *)sendAudioGroupWithAudioPath:(NSString *)audioPath groupId:(NSString *)groupId;

#pragma mark 发送单聊视频消息
/// 发送单聊视频消息
/// @param videoPath 视频地址
/// @param receiverId 接收者标识
- (ImBody *)sendVideoWithVideoPath:(NSString *)videoPath receiverId:(NSString *)receiverId;

#pragma mark 发送群聊视频消息
/// 发送单聊视频消息
/// @param videoPath 视频地址
/// @param groupId 群组标识
- (ImBody *)sendVideoGroupWithVideoPath:(NSString *)videoPath groupId:(NSString *)groupId;

#pragma mark 发送单聊文件消息
/// 发送单聊文件消息
/// @param filePath 文件地址
/// @param receiverId 接收者标识
- (ImBody *)sendFileWithFilePath:(NSString *)filePath receiverId:(NSString *)receiverId;

#pragma mark 发送群聊文件消息
/// 发送单聊文件消息
/// @param filePath 文件地址
/// @param groupId 群组标识
- (ImBody *)sendFileGroupWithFilePath:(NSString *)filePath groupId:(NSString *)groupId;

@end

NS_ASSUME_NONNULL_END
