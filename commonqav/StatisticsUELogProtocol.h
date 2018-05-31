//
//  StatisticsUELogProtocol.h
//  CommonFramework
//
//  Created by fyx.liu on 2016-02-19.
//  Copyright © 2016年 Qunar.com. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 该协议是为了支持一些无法区分的控件、页面或者控件有多种状态时无法区分多种状态的扩展接口，使用方可在需要时实现该协议
 */
@protocol StatisticsUELogProtocol <NSObject>

@optional

/**
 *  说明：QAV获取统计日志会从当前响应控件向父级视图逐层遍历拼接信息来获取当前响应控件所在视图层级的路径(xpath)，在这个过程中会获取此协议方法返回值来进行信息补充或者实现特定的功能：
 *
 *  1.可用于为统计的页面附加唯一标识信息，当统计的时候需要区分页面时，可在当前页面(视图控制器)实现此方法，此时sender即为当前页面，需要判断sender类型来返回对应的标识信息。
 *  格式：页面key:页面ID,自定义信息，如：FlightVC,Inter
 *
 *  2.在遍历当前响应控件所在的层级结构时，可以为当前所在视图提供提取index(位置信息)到位置字段区域的能力，此时sender即为当前视图，可判断下sender是否为想要提取index的视图返回一个标识信息即可，该标识信息建议返回能表明当前提取的一组视图的特征。
 *  格式：事件类型(click、longclick等)*被操作的控件在列表中的位置*被操作的控件唯一标识(尽可能唯一)*被操作的控件包含的文本
 *  如：click*0_0*HomeVC:in:/UIWindow[0_0_0_0]/RootVCController[0_0_0_0_#FFFFFFFF]/ListView[0_0_0_0_#F2F8FBFF]/ListItem[-]_list(list即为此方法返回的标识)/HomeButton[0_0_0_0_#03A9F4FF_HomeVC_HomeButton_iconTouchUpInside:_23]*机票
 *
 *  3.提供自定义组合控件的标识，在组合控件视图实现此方法可以屏蔽掉该视图里面的实现细节，xpath只会拼接到当前视图层级，建议返回的信息可以区分出来组合控件的此时点击的状态，比如TabBar的selectedIndex。
 *  格式：事件类型(click、longclick等)*被操作的控件在列表中的位置*被操作的控件唯一标识(尽可能唯一)*被操作的控件包含的文本
 *  如：click**HomeVC:in:/UIWindow[0_0_0_0]/RootVCController[0_0_0_0_#FFFFFFFF]/HomeVC[0_0_0_0_#F2F8FBFF]/QWCommonTabBarNormal[0_0_0_0_#FFFFFFFF]_0(0即为此方法返回的标识)*首页
 *
 *  ⚠️  该方法请谨慎使用，如果不是为了解决上述3种这些必须要使用该方法的场景时，请优先考虑使用customValueWithSender：方法来解决问题。
 *
 *  @param sender: 当前遍历所在视图或页面。
 *
 *  @return 实现以上功能时要返回的标识信息。
 */
- (NSString *)uniqueIdWithSender:(id)sender;


/**
 *  用于统计的组件附加标识信息。当组件可能需要附加一些标识信息来进行区分统计时，可实现此方法；或所在的控制器实现此方法，
 *  该值会拼接到组件的附加标识信息(如文案，状态值等)字段区域里面，可供查询时筛选
 *  例如:控制器状态标识:文本信息，NomalState:机票...
 *
 *  ⚠️ 推荐使用此方法来区分不同业务类型的组件。
 *
 *  @param sender: 需要附加标识信息的组件。
 *
 *  @return 组件的附加标识信息。说明：如果要附加多个信息，请使用半角冒号:拼接返回。
 */
- (NSString *)customValueWithSender:(id)sender;

/**
 *  手动标识控件的唯一标识，该唯一标识的优先级比QAV自动生成的唯一标识更高。
 *
 *  代码示例：
  - (NSString *)globalUniqueIdWithSender:(id)sender
 {
    if ([sender isEqual:self.qavButton])
    {
        return "corp/alexhome/jipiao";
    }
 
    return  nil;
 }
 *
 *  ⚠️ 说明：为了保证该标识的唯一性，该唯一标识需要根据一定的规则来生成，具体流程详见：http://wiki.corp.qunar.com/pages/viewpage.action?pageId=150569401
 *
 *  @param sender: 需要进行手动唯一标识的控件视图。
 *
 *  @return 按规则生成的组件的全局唯一标识信息。
 */
- (NSString *)globalUniqueIdWithSender:(id)sender;

@end









