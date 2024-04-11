//
//  VCSMeetControl.h
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

@class VCSMeetControl;

#pragma mark - 会控组件回调代理
@protocol VCSMeetControlDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 重连成功回调
/// 重连成功回调
/// - Parameter meetControl: 会控实例
- (BOOL)onReconnectedSucceed:(VCSMeetControl *)meetControl;

#pragma mark 响应结果回调
/// 响应结果回调
/// - Parameters:
///   - meetControl: 会控实例
///   - command: 指令类型
///   - result: 错误类型
- (void)meetControl:(VCSMeetControl *)meetControl onRespondCommand:(Command)command result:(Result)result;

#pragma mark 房间状态通知
/// 房间状态通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onRoomStateNotify:(RoomNotify *)notify error:(NSError *)error;

#pragma mark 成员状态通知
/// 成员状态通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onMemberStateNotify:(AccountNotify *)notify error:(NSError *)error;

#pragma mark 踢出房间通知
/// 踢出房间通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onKickoutNotify:(KickoutNotify *)notify error:(NSError *)error;

#pragma mark 成员进入房间通知
/// 成员进入房间通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onMemberEnterNotify:(EnterNotify *)notify error:(NSError *)error;

#pragma mark 成员离开房间通知
/// 成员离开房间通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onMemberLeaveNotify:(ExitNotify *)notify error:(NSError *)error;

#pragma mark 会议开始通知
/// 会议开始通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onMeetingBeginNotify:(RoomBeginNotify *)notify error:(NSError *)error;

#pragma mark 会议结束通知
/// 会议结束通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onMeetingFinishNotify:(RoomEndedNotify *)notify error:(NSError *)error;

#pragma mark 自己状态变化通知
/// 自己状态变化通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
///   - firstNotify: 是否是首次回调进入
- (void)meetControl:(VCSMeetControl *)meetControl onSelfStateNotify:(MyAccountNotify *)notify error:(NSError *)error firstNotify:(BOOL)firstNotify;

#pragma mark 码流信息变化通知
/// 码流信息变化通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onChangedStreamNotify:(StreamNotify *)notify error:(NSError *)error;

#pragma mark 透传消息通知
/// 透传消息通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onPassthroughNotify:(PassthroughNotify *)notify error:(NSError *)error;

#pragma mark 聊天消息通知
/// 聊天消息通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onChatNotify:(ChatNotify *)notify error:(NSError *)error;

#pragma mark 举手发言通知
/// 举手发言通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onHandUpNotify:(HandUpNotify *)notify error:(NSError *)error;

#pragma mark 主持人操作码流信息通知
/// 主持人操作码流信息通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onAdminChangedStreamNotify:(HostCtrlStreamNotify *)notify error:(NSError *)error;

#pragma mark 回收主持人通知
/// 回收主持人通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onAdminRecoveryHostNotify:(RoomRecoveryHostNotify *)notify error:(NSError *)error;

#pragma mark 转移主持人通知
/// 转移主持人通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onAdminMoveHostNotify:(RoomMoveHostNotify *)notify error:(NSError *)error;

#pragma mark 联席主持人设置通知
/// 联席主持人设置通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onAdminUnionHostNotify:(RoomUnionHostNotify *)notify error:(NSError *)error;

#pragma mark 接收聊天通知
/// 接收聊天通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onChatEventNotify:(XChatEvent *)notify error:(NSError *)error;

#pragma mark 云录制状态通知
/// 云录制状态通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onCloudRecordStateNotify:(McuRunStateNotify *)notify error:(NSError *)error;

#pragma mark 网络研讨会角色变更通知
/// 网络研讨会角色变更通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onWebinarChangedMemberRoleNotify:(WebinarRoleNotify *)notify error:(NSError *)error;

#pragma mark 网络研讨会人数通知
/// 网络研讨会人数通知
/// - Parameters:
///   - meetControl: 会控实例
///   - notify: 通知对象
///   - error: 错误信息
- (void)meetControl:(VCSMeetControl *)meetControl onWebinarAudienceCountNotify:(WebinarAudienceNumNotify *)notify error:(NSError *)error;

#pragma mark 事件透传通知
/// 事件透传通知
/// - Parameters:
///   - meetControl: 会控实例
///   - event: 事件类型
///   - content: 事件内容
- (void)meetControl:(VCSMeetControl *)meetControl onTransparentEvent:(VCSMeetCommandEvent)event content:(NSString *)content;

@end

/// 释放完成回调
typedef void (^VCSMeetControlDestroyBlock)(void);

#pragma mark - VCSMeetCall
@interface VCSMeetControl : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 会控参数
@property (nonatomic, strong, readonly) VCSMeetControlParam *controlParam;
/// 用户信息
@property (nonatomic, strong, readonly) Account *account;
/// 房间信息
@property (nonatomic, strong, readonly) Room *room;
/// 进入房间是否成功
@property (nonatomic, assign, readonly) BOOL succeedEnterRoom;

#pragma mark 获取会控单例
/// 获取会控单例
+ (VCSMeetControl *)sharedInstance;

#pragma mark 初始化会控
/// 初始化会控
/// - Parameters:
///   - controlParam: 会控参数
///   - delegate: 代理回调
- (void)initializeWithControlParam:(VCSMeetControlParam *)controlParam delegate:(nullable id <VCSMeetControlDelegate>)delegate;

#pragma mark 重新建立服务连接
/// 重新建立服务连接
- (void)restartConnect;

#pragma mark 资源销毁
/// 资源销毁
/// @param finishBlock 释放完成回调
- (void)destroy:(VCSMeetControlDestroyBlock)finishBlock;


#pragma mark 发送心跳消息
/// 发送心跳消息
- (void)sendKeepAlive;

#pragma mark 设置音频状态
/// 设置音频状态
/// @param state 音频状态
- (void)enableSendAudio:(DeviceState)state;

#pragma mark 设置视频状态
/// 设置视频状态
- (void)enableSendVideo:(DeviceState)state;

#pragma mark 设置绑定数据
///  设置绑定数据
/// @param tag 绑定数据内容
- (void)setAccountTag:(NSString *)tag;

#pragma mark 设置举手状态
/// 设置举手状态
/// @param handUpStatus 举手类型
- (void)setHandupStatus:(HandUpStatus)handUpStatus;

#pragma mark 设置码流信息
/// 设置码流信息
/// @param streamLists 码流列表
- (void)setStreamsArray:(NSArray<Stream *> *)streamLists;

#pragma mark 发送聊天消息
/// 发送文本消息
/// @param message 消息内容
/// @param targetId 目标用户标识(不传，代表发送给房间全体人员)
/// @param type 消息类型
- (void)sendTextChatWithMessage:(nullable NSString *)message targetId:(nullable NSString *)targetId type:(MessageType)type;

#pragma mark 主持人踢人
/// 主持人踢人
/// @param targetId 目标用户标识
- (void)adminKickoutWithTargetId:(nullable NSString *)targetId;

#pragma mark 主持人操作成员音频
/// 主持人操作成员音频
/// @param targetidsArray 成员标识列表(为空时，表示全局禁用)
/// @param audioState 音频状态
- (void)adminKostCtrlMemberAudioWithTargetidsArray:(nullable NSMutableArray<NSString *> *)targetidsArray audioState:(DeviceState)audioState;

#pragma mark 主持人操作成员视频
/// 主持人操作成员视频
/// @param targetidsArray 成员标识列表(为空时，表示全局禁用)
/// @param videoState 视频状态
- (void)adminKostCtrlMemberVideoWithTargetidsArray:(nullable NSMutableArray<NSString *> *)targetidsArray videoState:(DeviceState)videoState;

#pragma mark 主持人操作成员聊天状态
/// 主持人操作成员聊天状态
/// @param targetidsArray 成员标识列表(为空时，表示全局禁用)
/// @param chatState 聊天状态
- (void)adminKostCtrlMemberChatWithTargetidsArray:(nullable NSMutableArray<NSString *> *)targetidsArray chatState:(DeviceState)chatState;

#pragma mark 主持人设置房间音频状态
/// 主持人设置房间音频状态
/// @param audioState 音频状态
- (void)adminKostCtrlRoomAudioWithAudioState:(DeviceState)audioState;

#pragma mark 主持人设置房间视频状态
/// 主持人设置房间视频状态
/// @param videoState 视频状态
- (void)adminKostCtrlRoomVideoWithVideoState:(DeviceState)videoState;

#pragma mark 主持人设置房间聊天状态
/// 主持人设置房间聊天状态
/// @param webinarChat 聊天状态
- (void)adminKostCtrlRoomChatWithWebinarChat:(WebinarState)webinarChat;

#pragma mark 主持人设置房间截屏状态
/// 主持人设置房间截屏状态
/// @param webinarScreenShot 截屏状态
- (void)adminKostCtrlRoomScreenShotWithWebinarScreenShot:(WebinarState)webinarScreenShot;

#pragma mark 变更码流信息
/// 变更码流信息
/// @param operation 操作指令
/// @param stream 码流信息
- (void)changedRoomStreamWithOperation:(Operation)operation stream:(Stream *)stream;

#pragma mark 发送透传消息
/// 发送透传消息
/// @param targetId 目标用户
/// @param message 自定义消息
- (void)sendRoomPassthroughWithTargetId:(NSString *)targetId message:(NSString *)message;

#pragma mark 主持人变更码流信息
/// 主持人变更码流信息
/// @param targetId 目标用户
/// @param operation 操作指令
/// @param stream 码流信息
- (void)adminChangedRoomStreamWithTargetId:(NSString *)targetId operation:(Operation)operation stream:(Stream *)stream;

#pragma mark 主持人处理举手
/// 主持人处理举手
/// @param targetId 目标用户
/// @param hus 举手类型
/// @param result 处理结果(YES-同意，NO-不同意)
/// @param isAudience 是否设置成观众角色(YES-观众，NO-嘉宾)
- (void)adminDisposeRoomRaiseHandWithTargetId:(NSString *)targetId hus:(HandUpStatus)hus result:(BOOL)result isAudience:(BOOL)isAudience;

#pragma mark 开始分享
/// 开始分享
/// @param sharingType 分享类型
/// @param sharingPicURL 分享图片时的图片地址
/// @param sharingRelativePicURL 分享图片时的图片相对地址
- (void)startRoomStartToShareWithSharingType:(SharingType)sharingType sharingPicURL:(nullable NSString *)sharingPicURL sharingRelativePicURL:(nullable NSString *)sharingRelativePicURL;

#pragma mark 停止分享
/// 停止分享
- (void)stopRoomStopSharing;

#pragma mark 设置房间水印
/// 设置房间水印
/// @param openState YES-开启 NO-关闭
- (void)setRoomWaterMarkWithOpenState:(BOOL)openState;

#pragma mark 转移房间主持人
/// 转移房间主持人
/// @param targetId 目标用户
- (void)adminRoomMoveHostWithTargetId:(NSString *)targetId;

#pragma mark 设置房间联席主持人
/// 设置房间联席主持人
/// @param targetId 目标用户
/// @param state 状态(YES-设置，NO-回收)
- (void)adminRoomUnionHostWithTargetId:(NSString *)targetId state:(BOOL)state;

#pragma mark 回收房间主持人
/// 回收房间主持人
/// @param targetId 目标用户
- (void)adminRoomRecoveryHostWithTargetId:(nullable NSString *)targetId;

#pragma mark 设置房间静音状态
/// 设置房间静音状态
/// @param state 静音状态
- (void)adminRoomMuteWithState:(MuteState)state;

#pragma mark 设置房间成员昵称
/// 设置房间成员昵称
/// @param targetId 目标用户标识(目标为自己时，为修改自己的昵称)
/// @param nickname 目标昵称
- (void)setRoomMemberNicknameWithTargetId:(NSString *)targetId nickname:(NSString *)nickname;

#pragma mark 设置房间是否允许自行解除禁音
/// 设置房间是否允许自行解除禁音
/// @param state 解除禁音状态
- (void)adminRoomRelieveAstateWithState:(RelieveAstate)state;

#pragma mark 设置房间成员扩展信息
/// 设置房间成员扩展信息
/// - Parameters:
///   - targetId: 目标用户标识(目标为自己时，为修改自己的扩展信息)
///   - extendInfo: 扩展信息
- (void)admindRoomMemberExtendWithTargetId:(NSString *)targetId extendInfo:(NSString *)extendInfo;

@end

NS_ASSUME_NONNULL_END
