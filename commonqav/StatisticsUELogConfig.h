//
//  StatisticsUELogConfig.h
//  CommonQAV
//
//  Created by pingchao on 16/8/3.
//  Copyright © 2016年 Qunar.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 如果APP有自己的VC管理栈或者需要设置其他配置信息，需实现StatisticsUELogConfig协议，该协议可选
 */
@protocol StatisticsUELogConfig <NSObject>

@optional

/**
 *  获取当前VC栈的最上层VC，默认获取window.rootViewController是UINavigationController/UIViewController/UITabBarViewController的栈顶VC。
 *  如果APP有自己的VC管理栈需实现此方法返回对应VC。
 */
+ (UIViewController *)getTopVC;

/**
 *  获取RequestID, 该id是用来唯一标识QAV的一次操作事件，方便用来定位用户的某一次操作。
 */
+ (NSString *)getRequestID;

/**
 *  更新RequestID, 当QAV记录一条统计事件时会触发更新此id。
 */
+ (NSString *)updateRequestID;

/**
 *  获取当前服务器时间，该时间将转换为时间戳拼接到统计字符串中用于唯一标识一条统计信息，默认获取手机本地时间[NSDate date]。
 */
+ (NSDate *)nowServerTime;

/**
 *  获取当前网络类型
 */
+ (NSString *)curNetType;

/**
 *  获取当前定位信息
 */
+ (CLLocation *)location;

/**
 *  获取自定义公共参数
 */
+ (NSDictionary *)extCommonParam;

@end
