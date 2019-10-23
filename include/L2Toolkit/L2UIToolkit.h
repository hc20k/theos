#import "HapticHelper.h"
#import <UIKit/UIKit.h>
#import <objc/runtime.h>

@interface L2CKPill : UIView <UITableViewDelegate,UITableViewDataSource>
@property(nonatomic,retain) NSDictionary* buttonsActionsDictionary;
@property(nonatomic,retain) UITableView* buttonTableView;
@property(nonatomic,retain) UIVisualEffectView* backgroundBlurView;
@property(nonatomic,retain) id responder;
@property(nonatomic,assign) bool hideAfterAction;
-(void)initializeUI;
-(void)updateFrame;
-(void)hidePill;
-(void)setButtonsActionsDictionary:(NSDictionary*)dictionary;
@end

@interface L2Banner : UIView <UIScrollViewDelegate>
@property(nonatomic,retain) UILabel* titleLabel;
@property(nonatomic,retain) UILabel* messageLabel;
@property(nonatomic,retain) UIVisualEffectView* vev;
@property(nonatomic,retain) UIScrollView* buttonScrollView;
@property(nonatomic,assign) bool bannerTapped;
@property(nonatomic,retain) UITapGestureRecognizer* tapRecognizer;
@property(nonatomic,retain) NSTimer* hideTimer;
@property (nonatomic, copy) void (^l2_block)(void);
-(void)hide;
-(void)l2_callblock;
@end

@interface L2Alert : NSObject
@property(nonatomic,retain) UIViewController* modalViewController;
@property(nonatomic,assign) bool useModalAlert;
@property(nonatomic,retain) UITextField* textField;
@property(nonatomic,retain) NSString* prompt;
@property(nonatomic,assign) bool addTextField;
@property(nonatomic,retain) NSString* placeholder;
@property(nonatomic,retain) NSString* message;
@property(nonatomic,retain) L2Banner* mockBanner;
@property (nonatomic, copy) void (^block)(UITextField *tf);
-(void)callBlock;
@end

@interface L2Config : NSObject
+(L2Config *)sharedInstance;
@property(nonatomic,assign) NSMutableArray* activeToasts;
@property(nonatomic,assign) bool useDarkMode;
@property(nonatomic,assign) bool useHapticFeedback;
@property(nonatomic,assign) bool forceRoundedBanners;
@property(nonatomic,retain) UIColor* tintColor;
@end

@interface UIViewController (L2)
-(void)l2_banner:(NSString*)message;
-(void)l2_banner:(NSString*)message withTitle:(NSString*)title;
-(void)l2_banner:(NSString*)message withTitle:(NSString*)title tapBlock:(void (^)(void))block;
-(void)l2_banner:(NSString*)message withTitle:(NSString*)title duration:(NSInteger)duration tapBlock:(void (^)(void))block;
-(void)l2_banner:(NSString*)message withTitle:(NSString*)title duration:(NSInteger)duration withButtons:(NSArray<NSString*>*)buttons tapBlock:(void (^)(void))block;
-(void)showL2Alert:(L2Alert*)alert;
@end

@interface UIWindow (L2)
-(void)showL2Alert:(L2Alert*)alert;
@end

@interface UIScreen (L2)
-(void)l2_flashStatusBarMessage:(NSString*)message duration:(NSInteger)duration keepTime:(BOOL)keepTime animated:(BOOL)animated;
-(void)l2_flashStatusBarMessage:(NSString*)message duration:(NSInteger)duration animated:(BOOL)animated;
@end

@interface _UIStatusBar : UIView
@end

@interface _UIStatusBar (L2)
@property(nonatomic,retain) UIView* foregroundView;
-(void)updateWithData:(id)arg1;
@end

@interface UIView (L2)
-(UIViewController*)findParentViewController;
@end
